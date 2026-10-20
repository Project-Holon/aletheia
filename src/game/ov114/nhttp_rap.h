#ifndef GAME_OV114_NHTTP_RAP_H
#define GAME_OV114_NHTTP_RAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of nhttp_rap.c, prototypes copied from their definitions. */

#include "../ov114/nhttp_types.h"
#include "../ov114/nhttp_rap_types.h"
#include "../types.h"

void *NHTTP_RAP_Alloc(unsigned long size, int align);
void NHTTP_RAP_Free(void *ptr_p);
int NHTTP_RAP_ConnectionCallback(NHTTPConnection *connection_p, int type, void *arg_p);
int NHTTP_RAP_CreateRequest(int index, NHTTPRapSession *session_p);
NHTTPConnection *NHTTP_RAP_GetConnection(NHTTPRapSession *session_p);
int NHTTP_RAP_StartConnection(NHTTPRapSession *session_p);
void NHTTP_RAP_DeleteConnection(NHTTPRapSession *session_p);
int NHTTP_RAP_PollConnection(NHTTPRapSession *session_p);
char *NHTTP_RAP_GetRecvBuffer(NHTTPRapSession *session_p);
NHTTPRapSession *NHTTP_RAP_Create(u16 heapId, u32 gameCode, char *source_p);
void NHTTP_RAP_Destroy(NHTTPRapSession *session_p);
void NHTTP_RAP_WritePostHeader(NHTTPRapSession *session_p, int id);
void NHTTP_RAP_AllocPostData(NHTTPRapSession *session_p, int alignment, int size, int id);
void NHTTP_RAP_AppendPostData(NHTTPRapSession *session_p, const void *src_p, int size);
int NHTTP_RAP_CreatePostRequest(NHTTPRapSession *session_p);
void NHTTP_RAP_FreePostData(NHTTPRapSession *session_p);
int NHTTP_RAP_GetResultCode(NHTTPRapSession *session_p);
int NHTTP_RAP_RecordList_GetCount(NHTTPRapRecordList *list_p);
u32 NHTTP_RAP_RecordList_GetValue(NHTTPRapRecordList *list_p, u32 index);
NHTTPRapRecord *NHTTP_RAP_RecordList_GetRecord(NHTTPRapRecordList *list_p, u32 index);
int NHTTP_RAP_VerifySignature(void *data_p, int elemSize, int count, char *sign_p, u16 heapId);
/* END mkheaders: generated region */

#endif
