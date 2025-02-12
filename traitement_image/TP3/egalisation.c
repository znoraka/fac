#include <stdio.h>

#include "../lib_c/image_ppm.h"
#include "math.h"
#include "../lib_c/utils.h"

int* densiteProba(OCTET *in, int lignes, int colonnes) {
	int i;

	int *proba = malloc(256 * sizeof(int));
	int histo[256] = {0};

	bzero(proba, 256);

	for (i=0; i < lignes * colonnes; i++) {
		histo[in[i]]++;	
	}

	proba[0] = histo[0];

	for (i=1; i < 256; i++) {
		proba[i] = proba[i - 1] + histo[i];
	}


	return proba;
}

void egalisation(OCTET *in, OCTET *out, int lignes, int colonnes) {

	int i;

	int* proba = densiteProba(in, lignes, colonnes);

	for (i=0; i < lignes * colonnes; i++) {
		out[i] = (float) (proba[in[i]] * 255) / (float) (lignes * colonnes);
	}
}

int main(int argc, char* argv[])
{
	char cNomImgLue[250];
	char out[250] = "out.pgm";

	int lignes, colonnes, nTaille, S;

	if (argc == 1) {
		sscanf (out, "%s", cNomImgLue);
	} else if (argc == 2) {
		sscanf (argv[1],"%s",cNomImgLue);
	} else {
		printf("to many arguments");
	}


	OCTET *ImgIn, *ImgOut, *ImgOut1;

	lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &lignes, &colonnes);
	nTaille = lignes * colonnes;

	allocation_tableau(ImgIn, OCTET, nTaille);
	lire_image_pgm(cNomImgLue, ImgIn, lignes * colonnes);
	allocation_tableau(ImgOut, OCTET, nTaille);


	histo(ImgIn, lignes, colonnes);
	egalisation(ImgIn, ImgOut, lignes, colonnes);

	ecrire_image_pgm(out, ImgOut,  lignes, colonnes);
	free(ImgIn);

	return 1;
}
