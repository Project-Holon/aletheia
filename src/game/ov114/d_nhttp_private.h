#ifndef GAME_OV114_D_NHTTP_PRIVATE_H
#define GAME_OV114_D_NHTTP_PRIVATE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of d_nhttp_private.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"
#include "../types.h"
#include "../ov114/nhttp_types.h"

NHTTPConnection *NHTTP_CreateConnection(char *url_p, int method, char *buf_p, u32 len, int (*callback)(NHTTPConnection *, int, void *), void *userParam_p);
int NHTTP_DeleteConnection(NHTTPConnection *handle_p);
int NHTTPi_DeleteConnection(NHTTPConnection *connection_p);
int NHTTP_WaitForConnection(NHTTPConnection *handle_p);
int NHTTP_StartConnection(void *handle);
int NHTTP_CancelConnection(void *handle);
int NHTTP_GetConnectionStatus(NHTTPConnection *handle_p);
int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);
void *NHTTP_GetUserParam(void *handle);
int NHTTP_GetConnectionError(NHTTPConnection *handle_p);
int NHTTP_GetConnectionProgress(void *handle, unsigned long *received_p, unsigned long *contentlen_p);
/* END mkheaders: generated region */

#endif
