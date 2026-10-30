#ifndef GAME_OV175_WIFIBATTLEMATCH_NET_H
#define GAME_OV175_WIFIBATTLEMATCH_NET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifibattlematch_net.c, prototypes copied from their definitions. */

struct Proc;
struct WifiBattleMatchParams;
struct WifiBattleMatchNetTask;
struct WifibattlematchCallback;
struct WifiBattleMatchCompWork;
struct WifiBattleMatchStatRecord;
struct Party;
struct WifibattlematchNetSub;
struct WifiBattleMatchNetCtx;
struct WifiBattleMatchReportBlock;
struct GameData;
struct WifiBattleMatchReportPlayer;
struct WifiBattleMatchTeam;
struct RegDataA;
struct RegDataB;
struct WifibattlematchNetRecord;
struct NetErrRecord;
typedef struct WifibattlematchCallback WifibattlematchCallback;

#include "../types.h"
#include "../ov177/wifibattlematch_menu_types.h"
#include "../ov177/wifibattlematch_view_types.h"
#include "../ov175/wifibattlematch_net_types.h"
#include "../ov175/sake_types.h"

struct WifiBattleMatchNetCtx *WIFIBATTLEMATCH_NET_CreateNetContext(struct WifiBattleMatchReportBlock *netId, struct GameData *save, char *heapId, u16 heap);
void WIFIBATTLEMATCH_NET_DeleteNetContext(struct WifiBattleMatchNetCtx *ctx);
void WIFIBATTLEMATCH_NET_Noop(struct WifiBattleMatchNetCtx *unused);
void WIFIBATTLEMATCH_NET_SetTimingSyncRange(struct WifiBattleMatchNetCtx *obj, u32 v);
int WIFIBATTLEMATCH_NET_IsTimingSyncRange(struct WifiBattleMatchNetCtx *obj);
int WIFIBATTLEMATCH_NET_HandleNetError(struct WifiBattleMatchNetCtx *ctx, void *a, void *b);
void WIFIBATTLEMATCH_NET_ClearErrorFlags(struct WifiBattleMatchNetCtx *ctx);
int WIFIBATTLEMATCH_NET_StepGdbEnsureRecord(struct WifiBattleMatchNetCtx *ctx);
void WIFIBATTLEMATCH_NET_SetMatchKey(struct WifiBattleMatchNetCtx *obj, int mode, int extra, int group, int *rec);
int WIFIBATTLEMATCH_NET_StartMatchmaking(struct WifiBattleMatchNetCtx *obj);
void WIFIBATTLEMATCH_NET_DisconnectWifi();
void WIFIBATTLEMATCH_NET_ClearCancelFlag(struct WifiBattleMatchNetCtx *obj);
int WIFIBATTLEMATCH_NET_StopMatchmaking(struct WifiBattleMatchNetCtx *obj);
int WIFIBATTLEMATCH_NET_SendSessionQuery();
u32 WIFIBATTLEMATCH_NET_TakeSessionResult(struct WifiBattleMatchNetCtx *obj);
void WIFIBATTLEMATCH_NET_GetDateTime(unsigned char *dest);
void WIFIBATTLEMATCH_NET_AddMatchKey(struct WifiBattleMatchNetCtx *obj, int i, int value);
int WIFIBATTLEMATCH_NET_GetMatchKeyInt(int index, void *param);
int WIFIBATTLEMATCH_NET_GetMatchKeyDefault(int index, void *param);
int WIFIBATTLEMATCH_NET_GetMatchKeyValue(int index, void *param);
void WIFIBATTLEMATCH_NET_SetupMatchReport(struct WifiBattleMatchNetCtx *obj, int mode, int kind, u32 teamArg, u32 *rec, u32 slot);
int WIFIBATTLEMATCH_NET_ScProcess(struct WifiBattleMatchNetCtx *ctx, u32 *out);
u32 WIFIBATTLEMATCH_NET_GetReportState(struct WifiBattleMatchNetCtx *ctx);
void WIFIBATTLEMATCH_NET_OnReportResultA(int result, void *userArg);
void WIFIBATTLEMATCH_NET_OnReportResultB(int result, void *userArg);
void WIFIBATTLEMATCH_NET_OnReportResultC(int result, void *userArg);
void WIFIBATTLEMATCH_NET_ShutdownReport(struct WifiBattleMatchNetCtx *obj);
int WIFIBATTLEMATCH_NET_SubmitReport(struct WifiBattleMatchReportPlayer *ctx, struct WifiBattleMatchReportPlayer *other, struct WifiBattleMatchTeam *peer, u32 isAuthoritative, RoundFn cb, int flag, int have, int twoway);
int WIFIBATTLEMATCH_NET_ReportAddRecord(struct WifiBattleMatchReportPlayer *ctx,const u32 *record,int invert);
int WIFIBATTLEMATCH_NET_ReportAddTeam(struct WifiBattleMatchReportPlayer *ctx, const u32 *input, int invert);
int WIFIBATTLEMATCH_NET_ReportAddWin(struct WifiBattleMatchReportPlayer *ctx);
int WIFIBATTLEMATCH_NET_ReportAddLoss(struct WifiBattleMatchReportPlayer *ctx);
int WIFIBATTLEMATCH_NET_ReportAddDisconnectWin(struct WifiBattleMatchReportPlayer *ctx);
int WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss(struct WifiBattleMatchReportPlayer *ctx);
void WIFIBATTLEMATCH_NET_OnRecvPlayerData(int index,int unused,const void *src,struct WifiBattleMatchNetCtx *ctx,int owner);
void WIFIBATTLEMATCH_NET_OnRecvStatus(int index, int unused, void *dest, struct WifiBattleMatchNetCtx *ctx, int owner);
int WIFIBATTLEMATCH_NET_GetPlayerBuffer(int a, char *b);
void WIFIBATTLEMATCH_NET_OnRecvFlagA(u32 a, u32 b, u32 c, struct WifiBattleMatchNetCtx *d, u32 e);
void WIFIBATTLEMATCH_NET_OnRecvFlagB(u32 a, u32 b, u32 c, struct WifiBattleMatchNetCtx *d, u32 e);
void WIFIBATTLEMATCH_NET_OnRecvFlagC(u32 a, u32 b, u32 c, struct WifiBattleMatchNetCtx *d, u32 e);
void WIFIBATTLEMATCH_NET_OnRecvValue(u32 a, u32 b, u32 *c, struct WifiBattleMatchNetCtx *d, u32 e);
void WIFIBATTLEMATCH_NET_GdbRequest(struct WifiBattleMatchNetCtx *obj, u32 target, int kind, void *arg);
int WIFIBATTLEMATCH_NET_GdbGetMyRecords(struct WifiBattleMatchNetCtx *obj);
void WIFIBATTLEMATCH_NET_GdbShutdown(struct WifiBattleMatchNetCtx *obj);
void WIFIBATTLEMATCH_NET_SetupGdbRecord(struct WifiBattleMatchNetCtx *ctx);
void WIFIBATTLEMATCH_NET_GdbSortByName(int count, SAKEField **recs, void *userArg);
void WIFIBATTLEMATCH_NET_GdbCopyFieldsA(int count, SAKEField **fields, void *arg, int n);
void WIFIBATTLEMATCH_NET_GdbCopyFieldsB(int count, SAKEField **fields, void *arg, int n);
void WIFIBATTLEMATCH_NET_GdbCopyFieldC(int count, SAKEField **recs, void *dst, int nfields);
void WIFIBATTLEMATCH_NET_GdbCopyFieldD(int count, SAKEField **recs, void *dst, int nfields);
void WIFIBATTLEMATCH_NET_GdbCopyFieldE(int count, SAKEField **recs, void *dst, int nfields);
void WIFIBATTLEMATCH_NET_SetupGdbUpload(struct WifiBattleMatchNetCtx *ctx,u32 mode,struct WifibattlematchNetRecord *src);
int WIFIBATTLEMATCH_NET_GdbUpdateRecord(struct WifiBattleMatchNetCtx *ctx);
void WIFIBATTLEMATCH_NET_GdbClearRecord(struct WifiBattleMatchNetCtx *ctx);
int WIFIBATTLEMATCH_NET_GdbCreateRecord(struct WifiBattleMatchNetCtx *ctx);
u32 WIFIBATTLEMATCH_NET_GetNetId(struct WifiBattleMatchNetCtx *obj);
u32 WIFIBATTLEMATCH_NET_SendRegData(struct WifiBattleMatchNetCtx *obj, const void *data);
u32 WIFIBATTLEMATCH_NET_TakeRegData(struct WifiBattleMatchNetCtx *obj, char **out);
u32 WIFIBATTLEMATCH_NET_SendRegDataAlt(struct WifiBattleMatchNetCtx *ctx,const void *data);
u32 WIFIBATTLEMATCH_NET_TakeRegBuffer(struct WifiBattleMatchNetCtx *obj, void *arg);
int WIFIBATTLEMATCH_NET_SendRegFlag(struct WifiBattleMatchNetCtx *obj, const void *data);
u32 WIFIBATTLEMATCH_NET_TakeRegFlag(struct WifiBattleMatchNetCtx *obj, void *arg);
int WIFIBATTLEMATCH_NET_SendRegValue(struct WifiBattleMatchNetCtx *ignored, const void *ctx);
u32 WIFIBATTLEMATCH_NET_TakeRegValue(struct WifiBattleMatchNetCtx *obj, u32 *out);
void WIFIBATTLEMATCH_NET_SetupDownload(struct WifiBattleMatchNetCtx *ctx,unsigned a);
int WIFIBATTLEMATCH_NET_DownloadProcess(struct WifiBattleMatchNetCtx *ctx);
int WIFIBATTLEMATCH_NET_IsBufferZero(const u32 *buffer,u32 bytes);
void WIFIBATTLEMATCH_NET_CleanupDownload(void *arg, u32 errorCode, u32 kind, int dwcError);
int WIFIBATTLEMATCH_NET_GetDownloadSize(void *arg, u32 errorCode, u32 kind, int dwcError);
int WIFIBATTLEMATCH_NET_DownloadError(unsigned int a);
void WIFIBATTLEMATCH_NET_GetRegCardName(struct WifiBattleMatchNetCtx *ctx,void *out);
void WIFIBATTLEMATCH_NET_NdSetState(struct WifiBattleMatchNetCtx *ctx,int state);
void WIFIBATTLEMATCH_NET_NdCleanupState(struct WifiBattleMatchNetCtx *ctx,int state);
void WIFIBATTLEMATCH_NET_NdCancelState(struct WifiBattleMatchNetCtx *ctx,int state);
void WIFIBATTLEMATCH_NET_NdSetError(int reason,int kind,int serverError);
void WIFIBATTLEMATCH_NET_CreateHttpRap(struct WifiBattleMatchNetCtx *ctx,u16 heap);
int WIFIBATTLEMATCH_NET_HttpRapProcess(struct WifiBattleMatchNetCtx *ctx);
void WIFIBATTLEMATCH_NET_GetRapPair(const struct WifiBattleMatchNetCtx *ctx,WifibattlematchNetPair *out);
void WIFIBATTLEMATCH_NET_SetupHttpRap(struct WifiBattleMatchNetCtx *ctx, const W *src, u16 x);
int WIFIBATTLEMATCH_NET_HttpRapSend(struct WifiBattleMatchNetCtx *ctx);
void WIFIBATTLEMATCH_NET_StartProfanityCheck(struct WifiBattleMatchNetCtx *obj, void *win, u16 tag);
int WIFIBATTLEMATCH_NET_ProfanityProcess(struct WifiBattleMatchNetCtx *obj, int *out);
void WIFIBATTLEMATCH_NET_SetupPostData(struct WifiBattleMatchNetCtx *ctx,void *party,int mode);
int WIFIBATTLEMATCH_NET_HttpRapPost(struct WifiBattleMatchNetCtx *ctx,u8 *out);
void WIFIBATTLEMATCH_NET_SetErrorA(struct NetErrRecord *ctx, u32 v, int line);
void WIFIBATTLEMATCH_NET_SetErrorB(struct NetErrRecord *ctx, int v, int unused);
void WIFIBATTLEMATCH_NET_SetResultA(struct NetErrRecord *ctx, u32 v, int line);
void WIFIBATTLEMATCH_NET_SetResultB(struct NetErrRecord *ctx, u32 v, int line);
void WIFIBATTLEMATCH_NET_SetResultC(struct NetErrRecord *ctx, u32 v, int line);
void WIFIBATTLEMATCH_NET_SetResultD(struct NetErrRecord *ctx, u32 v, u32 unused);
u32 WIFIBATTLEMATCH_NET_GetErrorMsg(int a);
u32 WIFIBATTLEMATCH_NET_GetErrorCode(int a, int b, int c);
u32 WIFIBATTLEMATCH_NET_MapErrorCode(u32 v);
void WIFIBATTLEMATCH_NET_ClearStruct(void *ctx);
void WIFIBATTLEMATCH_NET_RestartNet(struct WifiBattleMatchNetCtx *ctx, int flag);
u32 WIFIBATTLEMATCH_NET_GetGsProfileId(struct WifiBattleMatchNetCtx *obj);
char *WIFIBATTLEMATCH_NET_GetRegNameA(void);
u32 WIFIBATTLEMATCH_NET_GetRegKindA(void);
char *WIFIBATTLEMATCH_NET_GetRegNameB(void);
u32 WIFIBATTLEMATCH_NET_GetRegKindB(void);
const char *WIFIBATTLEMATCH_NET_LookupFieldEntry(int a);
/* END mkheaders: generated region */

#endif
