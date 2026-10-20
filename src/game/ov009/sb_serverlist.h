#ifndef GAME_OV009_SB_SERVERLIST_H
#define GAME_OV009_SB_SERVERLIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sb_serverlist.c, prototypes copied from their definitions. */

#include "../ov009/sb_server_types.h"
#include "../ov009/sb_server_types.h"

int prevKeyCompare(SBServer *server1, SBServer *server2);
int IntKeyCompare(void *entry1, void *entry2);
int FloatKeyCompare(void *entry1, void *entry2);
int StrCaseKeyCompare(void *entry1, void *entry2);
int StrNoCaseKeyCompare(void *entry1, void *entry2);
void SBServerListSort(SBServerList *slist, int ascending, SBSortInfo sortinfo);
void SBServerListAppendServer(SBServerList *slist, SBServer *server);
int SBServerListFindServer(SBServerList *slist, void *findserver);
int SBServerListFindServerByIP(SBServerList *slist, unsigned int ip, unsigned short port);
void AddServerToDeadlist(SBServerList *slist, SBServer *server);
void SBServerListRemoveAt(SBServerList *slist, int index);
int SBServerListCount(void *list);
SBServer *SBServerListNth(SBServerList *slist, int index);
void SBFreeDeadList(SBServerList *slist);
void SBServerListClear(SBServerList *slist);
void SBAllocateServerList(SBServerList *slist);
char *SBRefStr(void *slist, char *str);
void SBReleaseStr(void *slist, char *str);
int NTSLengthSB(const char *buf, int len);
void SBServerListInit(SBServerList *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int lanBrowse, SBListCB callback, void *instance);
void ErrorDisconnect(SBServerList *slist);
int ServerListConnect(SBServerList *slist);
void BufferAddNTS(char **buffer, char *str, int *len);
void BufferAddByte(char **buffer, unsigned char value, int *len);
void BufferAddInt(char **buffer, int ival, int *len);
void BufferAddIntLE(char **buffer, int ival, int *len);
void BufferAddData(char **buffer, char *data, int dlen, int *len);
void SetupListChallenge(SBServerList *slist);
int SendWithRetry(SBServerList *slist, char *data, int len);
SBError SBServerListConnectAndQuery(SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers);
void FreePopularValues(char *list);
void FreeKeyList(SBServerList *slist);
void SBServerListDisconnect(SBServerList *slist);
void SBServerListCleanup(SBServerList *slist);
void InitCryptKey(SBServerList *slist, char *key, int keylen);
int ServerSizeForFlags(int flags);
int FullRulesPresent(const char *buf, int len);
int AllKeysPresent(SBServerList *slist, char *buf, int len);
void ParseServerIPPort(SBServerList *slist, unsigned char *buf, int len, unsigned int *ip, unsigned short *port);
int ParseServer(SBServerList *slist, SBServer *server, char *buf, int len, int usepopularlist);
int IncomingListParseServer(SBServerList *slist, char *buf, int len);
void SBServerListSetLastError(SBServerList *slist, char *lastError);
SBError ProcessMainListData(SBServerList *slist);
int ProcessPushKeyList(SBServerList *slist, char *buf, int len);
int ProcessPlayerSearch(SBServerList *slist, char *buf, int len);
int ProcessMaploop(SBServerList *slist, char *buf, int len);
SBError ProcessDeleteServer(SBServerList *slist, char *buf, int len);
int ProcessPushServer(SBServerList *slist, char *buf, int len);
int ProcessAdHocData(SBServerList *slist);
int ProcessIncomingData(SBServerList *slist);
int SBSendMessageToServer(SBServerList *slist, unsigned int ip, unsigned short port, char *data, int len);
int SBSendNatNegotiateCookieToServer(void *slist, unsigned int ip, unsigned short port, int cookie);
int ProcessLanData(SBServerList *slist);
int SBListThink(SBServerList *slist);
/* END mkheaders: generated region */

#endif
