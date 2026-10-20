#ifndef GAME_OV009_GT2BUFFER_H
#define GAME_OV009_GT2BUFFER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gt2buffer.c, prototypes copied from their definitions. */

#include "../ov009/gt2main_types.h"

int gti2AllocateBuffer(GTI2Buffer *buffer, int size);
int gti2GetBufferFreeSpace(const int *p);
void gti2BufferWriteByte(int *p, int v);
void gti2BufferWriteUShort(int *p, int v);
void gti2BufferWriteData(GTI2Buffer *buffer, unsigned char *data, int len);
void gti2BufferShorten(GTI2Buffer *buffer, int start, int shortenBy);
/* END mkheaders: generated region */

#endif
