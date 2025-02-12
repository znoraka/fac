#include <stdio.h>

#include "../lib_c/image_ppm.h"
#include "math.h"
#include "../lib_c/utils.h"

int size = 8;

int at(int x, int y, int lignes) {
	return y+x*lignes;
}


void split(OCTET *in, OCTET *blacks, int lignes, int colonnes) {
	int i, j;
	for (i = 0; i < lignes; i+=8)
	{
		for (j = 0; j < colonnes; j+=8)
		{
			int index = at(i, j, lignes);
		}
	}
}


float getAvg(OCTET *in, int index, int lignes, int colonnes) {
	float avg = 0;
	int i;
	int j;

	int ** v = malloc(8 * sizeof(int));

	indexE(index, lignes, colonnes);

	for (i = 0; i < 8; ++i)
	{
		v[i] = malloc(8 * sizeof(int));
		v[i][0] = 
		for (j = 1; j < 8; ++j)
		{
			v[i][j]
		}
	}
	
}
 int seuil = 50;

// struct region {
// 	OCTET* data;
// 	int size;
// 	struct region *c1;
// 	struct region *c2;
// 	struct region *c3;
// 	struct region *c4;
// 	int startIndex;
// 	int avg;
// 	int rec;
// };

// void init(OCTET* in, int size, struct region* r, int startIndex) {
// 	r->size = size;
// 	r->startIndex = startIndex;

// 	r->data = in;

// 	r->c1 = NULL;
// 	r->c2 = NULL;
// 	r->c3 = NULL;
// 	r->c4 = NULL;
// 	r->rec = 1;
// }

// int esperance(struct region *r) {
// 	int variance = 0;
// 	int i, j;

// 	int side = sqrt(r->size);
// 	int avg = 0;

// 	for (i = 0; i < side; ++i) {
// 		for (j = 0; j < side; ++j) {
// 			avg += r->data[r->startIndex + i * (2 * side * r->rec) + j];
// 		}
// 	}

// 	avg /= r->size;

// 	r->avg = avg;

// 	for (i = 0; i < side; ++i) {
// 		for (j = 0; j < side; ++j) {
// 			variance += pow(r->data[r->startIndex + i * (2 * side * r->rec) + j] - avg, 2);
// 		}
// 	}
// 	return (int) sqrt(variance / r->size);
// }

// void sub_array(int index, int size, int *startIndex, int rec) {
// 	int i, j, l, k = 0;

// 	int side = sqrt(size);
// 	switch(index) {
// 		case 0 : *startIndex = 0; break;
// 		case 1 : *startIndex = side; break;
// 		case 2 : *startIndex = 2 * size * rec; break;
// 		case 3 : *startIndex = 2 * size * rec + side; break;
// 	}
// }

// void split(struct region* r) {
// 	if(r->size > 8) {
// 		struct region *c1 = malloc(sizeof(struct region));
// 		struct region *c2 = malloc(sizeof(struct region));
// 		struct region *c3 = malloc(sizeof(struct region));
// 		struct region *c4 = malloc(sizeof(struct region));


// 		int startIndex;
// 		sub_array(0, r->size / 4, &startIndex, r->rec);
// 		init(r->data, r->size / 4, c1, r->startIndex + startIndex);
// 		c1->rec = r->rec * 2;

// 		sub_array(1, r->size / 4, &startIndex, r->rec);
// 		init(r->data, r->size / 4, c2, r->startIndex + startIndex);
// 		c2->rec = r->rec * 2;

// 		sub_array(2, r->size / 4, &startIndex, r->rec);
// 		init(r->data, r->size / 4, c3, r->startIndex + startIndex);
// 		c3->rec = r->rec * 2;

// 		sub_array(3, r->size / 4, &startIndex, r->rec);
// 		init(r->data, r->size / 4, c4, r->startIndex + startIndex);
// 		c4->rec = r->rec * 2;

// 		c1->size = r->size / 4;
// 		c2->size = r->size / 4;
// 		c3->size = r->size / 4;
// 		c4->size = r->size / 4;

// 		c1->data = r->data; r->c1 = c1; 
// 		c2->data = r->data; r->c2 = c2;
// 		c3->data = r->data; r->c3 = c3;
// 		c4->data = r->data; r->c4 = c4;

// 		if(esperance(c1) > seuil) {
// 			split(c1);
// 		}
// 		if(esperance(c2) > seuil) {
// 			split(c2);
// 		}
// 		if(esperance(c3) > seuil) {
// 			split(c3);
// 		}
// 		if(esperance(c4) > seuil) {
// 			split(c4);
// 		}
// 	}
// }

// void merge(struct region* r, OCTET* in) {
// 	int i;

// 	if(r->c1 == NULL) {
// 		int avg = 0;

// 		int j, l, k = 0;
// 		int side = sqrt(r->size);

// 		for (i = 0; i < side; ++i) {
// 			for (j = 0; j < side; ++j) {
// 				l = r->startIndex + i * 2 * side * (r->rec / 2) + j;
// 				in[l] = r->avg;
// 			}
// 		}
// 	} else {
// 		merge(r->c1, in);
// 		merge(r->c2, in);
// 		merge(r->c3, in);
// 		merge(r->c4, in);
// 	}
// }

int main(int argc, char* argv[])
{
	char cNomImgLue[250];
	char out[250] = "out.pgm";

	int lignes, colonnes, nTaille, S;

	if (argc == 2) {
		sscanf (out, "%s", cNomImgLue);
		sscanf (argv[2], "%d", &seuil);
	} else if (argc == 3) {
		sscanf (argv[1],"%s",cNomImgLue);
		sscanf (argv[2], "%d", &seuil);
	} else {
		printf("to many arguments");
	}

	OCTET *ImgIn, *ImgOut, *seuil;

	lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &lignes, &colonnes);
	nTaille = lignes * colonnes;

	allocation_tableau(ImgIn, OCTET, nTaille);
	lire_image_pgm(cNomImgLue, ImgIn, lignes * colonnes);
	allocation_tableau(ImgOut, OCTET, nTaille);

	// //printf("size : %d\n", nTaille);
	// struct region root;
	// //printf("before init\n");
	// init(ImgIn, lignes * colonnes, &root, 0);
	// //printf("after init\n");
	// split(&root);
	// //printf("after split\n");
	// merge(&root, ImgOut);

	ecrire_image_pgm(out, ImgOut, lignes, colonnes);

	free(ImgIn);
	return 1;
}
