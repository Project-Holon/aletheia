#ifndef GAME_OV114_D_NHTTP_H
#define GAME_OV114_D_NHTTP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of d_nhttp.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov114/nhttp_types.h"

int NHTTP_Startup(void *(*alloc)(unsigned long, int), void (*free)(void *), unsigned long threadprio);
void NHTTP_CleanupAsync(void (*callback)(void));
void NHTTP_Cleanup(void);
u32 NHTTP_GetError(void);
int NHTTP_AddHeaderField(void *handle_p, char *label_p, char *value_p);
int NHTTP_AddRequestHeaderField(NHTTPReq *req_p, char *label_p, char *value_p);
int NHTTP_AddPostDataAscii(void *handle_p, char *label_p, char *value_p);
int NHTTP_AddPostDataRaw(void *handle_p, void *value_p, unsigned long length);
int NHTTP_GetHeaderField(void *handle_p, char *label_p, char **value_pp);
int NHTTP_GetHeaderAll(void *handle_p, char **value_pp);
int NHTTP_GetResultCode(void *handle_p);
int NHTTP_SetVerifyOption(void *handle_p, int verifyOption);
int NHTTP_SetBasicAuthorization(void *handle_p, char *username_p, char *password_p);
int NHTTP_SetRootCA(void *handle_p, void *rootCA_p, int rootCALen);
int NHTTP_SetRequestRootCA(NHTTPReq *req_p, void *rootCA_p, int rootCALen);
/* END mkheaders: generated region */

#endif
