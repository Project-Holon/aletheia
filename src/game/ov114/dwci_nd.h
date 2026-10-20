#ifndef GAME_OV114_DWCI_ND_H
#define GAME_OV114_DWCI_ND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwci_nd.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov114/dwci_nd_types.h"
#include "../ov114/dwci_nd_types.h"
#include "../ov114/dwci_nd_types.h"
#include "../ov114/nhttp_types.h"

void DWCi_Ndi_freeAttr(void);
int setAttr(int id, char *attr);
int DWCi_NdSetAttr(char *attr1, char *attr2, char *attr3);
int getNchar(unsigned char *dst, char *src, int count);
int decodeChar(unsigned char c);
u32 DWCi_Ndi_getDecodeLenBASE64(int len);
int DWCi_Ndi_getEncodeLenBASE64(int n);
int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);
int DWCi_Ndi_decodeBASE64(char *decbin, char *str, int length);
char *strAlloc(char *src);
int DWCi_NdStartup(NdAlloc alloc, NdFree free, char *url, char *token, char *gameCode, char *password, DWCNdCallback callback);
void nhttpCleanupCallback(void);
void DWCi_NdCleanupAsync(void (*callback)(void));
int DWCi_NdCleanupConnectionHandle(void *volatile handle);
void DWCi_NdSetError(int err, int serverError);
int DWCi_NdCancelAsync(void);
int DWCi_Ndi_getApInfo(char *apinfo);
int DWCi_Ndi_getDSdesc(char *gamecode, char *userid);
void DWCi_Ndi_getUserAgent(char *buffer);
int req_callback(NHTTPConnection *res, int event, void *arg);
void freeHttpParam(tagDWCi_Ndi_HTTPREQ *hrq);
void freeHttp(tagDWCi_Ndi_HTTPREQ *hrq, void *req);
int runHttp(tagDWCi_Ndi_HTTPREQ *hrq, void *req);
int DWCi_NdGetFileListAsync(DWCNdFileInfo *filelist, int offset, int num);
int DWCi_NdGetFileAsync(DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt);
int DWCi_NdGetProgress(unsigned long *received, unsigned long *contentlen);
int DWCi_Ndi_response_count(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int DWCi_Ndi_response_contents(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int DWCi_Ndi_response_list(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int DWCi_Ndi_initLockGlobal(void);
void DWCi_Ndi_freeLockGlobal(void);
void DWCi_Ndi_lockGlobal(void);
void DWCi_Ndi_unlockGlobal(void);
int DWCi_Ndi_initHttpCallback(void);
void DWCi_Ndi_freeHttpCallback(void);
int DWCi_Ndi_prepareHttpCallback(void);
void DWCi_Ndi_unprepareHttpCallback(void);
void DWCi_Ndi_kickThread(void *threadEvent);
void DWCi_Ndi_getMacAddress(char *macaddr);
unsigned long DWCi_Ndi_strlen(char *str);
int DWCi_Ndi_strncmp(char *str1, char *str2, unsigned long size);
void DWCi_Ndi_memclr(void *dst, int size);
void DWCi_Ndi_memcpy(void *dst, void *src, u32 size);
int DWCi_Ndi_strToInt(char *s, int len);
int DWCi_Ndi_intToStr(char *buf, unsigned long value);
/* END mkheaders: generated region */

#endif
