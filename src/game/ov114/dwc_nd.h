#ifndef GAME_OV114_DWC_ND_H
#define GAME_OV114_DWC_ND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_nd.c, prototypes copied from their definitions. */

#include "../ov114/dwci_nd_types.h"

void *DWCi_NdAlloc(unsigned long size, int align);
void DWCi_NdFree(void *ptr);
void DWCi_NdCleanupCallback(void);
void NdCallback(int reason, int error, int serverError);
int DWC_NdInitAsync(DWCNdCallback callback, char *gameCode, char *password);
void DWC_NdProcess(void);
int DWC_NdCleanupAsync(void);
int DWC_NdSetAttr(char *attr1, char *attr2, char *attr3);
int DWC_NdGetFileListAsync(void *fileList, unsigned int offset, unsigned int num);
int DWC_NdGetFileAsync(void *fileInfo, char *buffer, unsigned int size);
int DWC_NdCancelAsync(void);
int DWC_NdGetProgress(unsigned long *received, unsigned long *contentLength);
/* END mkheaders: generated region */

#endif
