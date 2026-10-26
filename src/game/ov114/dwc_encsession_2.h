#ifndef GAME_OV114_DWC_ENCSESSION_2_H
#define GAME_OV114_DWC_ENCSESSION_2_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_encsession_2.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov114/dwc_encsession_types.h"

void DWCi_EncSessionCompleteCallback(char *buffer, int bufferLen, int result, void *param);
int DWCi_EncSessionEncrypt(u8 *outBuffer, u8 *header, u32 headerLen, u8 *source, u32 sourceLen);
void DWCi_EncSessionInitialize(int server, char *initData);
void DWCi_EncSetError(void);
int DWCi_EncSessionProcess(void);
void DWCi_EncSessionCancel(void);
void DWCi_EncSessionShutdown(void);
void *DWCi_EncSessionGetResponse(u32 *outLen);
int DWCi_EncSessionGetPrivateAsync(char *url, long pid, void *data, u32 size, DWCEncResponseCallback callback, int reuseHash);
int DWCi_EncSessionGetAsync(char *url, long pid, void *data, u32 size, DWCEncResponseCallback callback);
/* END mkheaders: generated region */

#endif
