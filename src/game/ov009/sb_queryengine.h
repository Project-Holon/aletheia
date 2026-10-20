#ifndef GAME_OV009_SB_QUERYENGINE_H
#define GAME_OV009_SB_QUERYENGINE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sb_queryengine.c, prototypes copied from their definitions. */

#include "../ov009/sb_server_types.h"
#include "../ov009/sb_server_types.h"

void FIFOAddRear(SBServerFIFO *fifo, SBServer *server);
void FIFOAddFront(SBServerFIFO *fifo, SBServer *server);
SBServer *FIFOGetFirst(SBServerFIFO *fifo);
int FIFORemove(SBServerFIFO *fifo, SBServer *server);
void FIFOClear(SBServerFIFO *fifo);
void SBQueryEngineInit(SBQueryEngine *engine, int maxupdates, int queryversion, int lanBrowse, SBEngineCB callback, void *instance);
void SBQueryEngineSetPublicIP(SBQueryEngine *engine, unsigned int publicip);
void SBEngineHaltUpdates(SBQueryEngine *engine);
void SBEngineCleanup(SBQueryEngine *engine);
void SBQueryEngineUpdateServer(SBQueryEngine *engine, SBServer *server, int addfront, unsigned int querytype, int usequerychallenge);
void ParseSingleQR2Reply(SBQueryEngine *engine, SBServer *server, char *data, int len);
int ParseSingleICMPReply(SBQueryEngine *engine, SBServer *server, char *data, int len);
void SBQueryEngineThink(SBQueryEngine *engine);
void SBQueryEngineAddQueryKey(SBQueryEngine *engine, unsigned char key);
void SBQueryEngineRemoveServerFromFIFOs(SBQueryEngine *engine, SBServer *server);
/* END mkheaders: generated region */

#endif
