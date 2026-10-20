#ifndef GAME_OV172_JPEGDEC_H
#define GAME_OV172_JPEGDEC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of jpegdec.c, prototypes copied from their definitions. */

#include "../types.h"

int Mel_JPEGDecodeExif(u8 *a, unsigned long length, int option);
int Mel_JPEGDecode(u8 *d, u8 *a, unsigned long length, long maxWidth, long maxHeight, int option);
void getmatrix(unsigned char *g, short *d, int *p, int n);
int get_matrix_sub(unsigned char *s, int *p, int ax, int cx);
void decode_block(short *d, short n);
void decode_block_sub(short *s, short *d, int n);
int loadbit(u8 *data, int *pos);
int hloadbit(u8 *b, int *p, int n);
void writeblock(u8 *d, int x, int y, int dx, int dy);
int SSP_StartJpegDecoder(unsigned char *data, unsigned long size, void *dst, short *width, short *height, unsigned long option);
/* END mkheaders: generated region */

#endif
