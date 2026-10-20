#ifndef GAME_OV172_JPEGENC_H
#define GAME_OV172_JPEGENC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of jpegenc.c, prototypes copied from their definitions. */

struct component_structure;
typedef struct component_structure component_structure;

#include "../types.h"

void Yos_BitInit(void);
int Yos_BitWrite(unsigned char *dst, unsigned long *ptr, unsigned long num, unsigned long size);
int Yos_JpegEncoderHuffmanEncoderPrintTable(u8 *huff, u8 *dst, u32 *pos);
int Yos_JpegEncoderHuffmanEncoderOutputSize(unsigned char *p);
void Yos_JpegEncodeSample2to2Component(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx);
void Yos_JpegEncodeSample2to1Component(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx);
void Yos_JpegEncodeSample1to1Component(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx);
unsigned long Yos_JPEGGetMemorySize(unsigned long width, unsigned long height, unsigned long sampling);
unsigned long SSP_GetJpegEncoderBufferSize(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option);
void SSP_JpegEncoderResample(const void *src, unsigned long srcWidth, unsigned long srcHeight, void *dst, unsigned long dstWidth, unsigned long dstHeight, unsigned long option);
void SSP_RGB555ToYUV888(void *src, unsigned long width, unsigned long height, void *dst);
void SSP_YUV422ToYUV888(void *src, unsigned long width, unsigned long height, void *dst);
int SSPi_JpegEncoderCheckWidthHeight(u32 width, u32 height, u32 samplingFormat);
unsigned long SSP_StartJpegEncoder(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option);
/* END mkheaders: generated region */

#endif
