#ifndef GAME_OV114_DWC_ENCSESSION_1_H
#define GAME_OV114_DWC_ENCSESSION_1_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_encsession_1.c, prototypes copied from their definitions. */

#include "../types.h"

unsigned long b64size(unsigned long len);
void my_randinit(u32 seed);
unsigned char my_rand(void);
int DWCi_EncValidateKey(char *gameName, const char *secretKey, unsigned long multiplier, unsigned long increment, unsigned long modulus, unsigned long checksumMask);
int DWCi_EncSessionValidateResponse(char *response, int responseLen);
void DWCi_EncSessionProgressCallback(int state, const char *buffer, int bufferLen, int bytesReceived, int totalSize, void *param);
/* END mkheaders: generated region */

#endif
