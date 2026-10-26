#ifndef GAME_OV009_SB_SERVERBROWSING_H
#define GAME_OV009_SB_SERVERBROWSING_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sb_serverbrowsing.c, prototypes copied from their definitions. */

#include "../ov009/sb_server_types.h"

ServerBrowser *ServerBrowserNewA(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, SBBrowserCB callback, void *instance);
void EngineCallback(struct SBQueryEngine *unused, int reason, SBServer *server, void *inst);
void ServerBrowserFree(ServerBrowser *sb);
int ServerBrowserBeginUpdate2(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int updateOptions, int maxServers);
int ServerBrowserLimitUpdateA(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers);
int ServerBrowserSendMessageToServerA(ServerBrowser *sb, char *ip, unsigned short port, char *data, int len);
int ServerBrowserSendNatNegotiateCookieToServerA(ServerBrowser *sb, char *ip, unsigned short port, int cookie);
void ServerBrowserRemoveServer(ServerBrowser *sb, SBServer *server);
int ServerBrowserThink(ServerBrowser *sb);
void ServerBrowserHalt(ServerBrowser *sb);
void ServerBrowserClear(ServerBrowser *sb);
int ServerBrowserState(ServerBrowser *sb);
SBServer *ServerBrowserGetServer(ServerBrowser *sb, int index);
int ServerBrowserCount(ServerBrowser *sb);
void ServerBrowserSortA(ServerBrowser *sb, int ascending, char *sortkey, int comparemode);
unsigned int ServerBrowserGetMyPublicIPAddr(const ServerBrowser *browser);
/* END mkheaders: generated region */

#endif
