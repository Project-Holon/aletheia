#ifndef GAME_OV009_SB_SERVER_H
#define GAME_OV009_SB_SERVER_H


/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sb_server.c, prototypes copied from their definitions. */

struct HashImplementation;
struct SBServerList;

#include "../ov009/sb_server_types.h"

int RefStringHash(void *elem, int numbuckets);
int RefStringCompare(void *entry1, void *entry2);
void RefStringFree(void *elem);
struct HashImplementation *SBRefStrHash(struct SBServerList *slist);
void SBRefStrHashCleanup(struct SBServerList *slist);
void SBServerFree(void *elem);
void SBServerAddKeyValue(SBServer *server, char *keyname, char *value);
void SBServerAddIntKeyValue(SBServer *server, char *keyname, int value);
char *SBServerGetStringValueA(SBServer *server, char *keyname, char *def);
int SBServerGetIntValueA(SBServer *server, char *key, int idefault);
double SBServerGetFloatValueA(SBServer *server, char *key, double fdefault);
unsigned int SBServerGetPublicInetAddress(const SBServer *server);
unsigned short SBServerGetPublicQueryPort(const unsigned short *p);
unsigned short SBServerGetPublicQueryPortNBO(const SBServer *server);
int SBServerHasPrivateAddress(const unsigned char *p);
unsigned int SBServerGetPrivateInetAddress(const SBServer *server);
unsigned short SBServerGetPrivateQueryPort(const unsigned short *p);
void SBServerSetNext(SBServer *server, SBServer *next);
SBServer *SBServerGetNext(const SBServer *server);
int CheckValidKey(char *key);
char *mytok(char *instr, char delim);
void SBServerParseKeyVals(SBServer *server, char *keyvals);
void SBServerParseQR2FullKeysSingle(SBServer *server, char *data, int len);
void SBServerParseQR2FullKeysSplit(SBServer *server, char *data, int len);
int KeyValHashKey(void *elem, int numbuckets);
int SBServerGetPing(const SBServer *server);
SBServer *SBAllocServer(struct SBServerList *unused, unsigned int publicip, unsigned short publicport);
void SBServerSetFlags(SBServer *server, unsigned char flags);
void SBServerSetPrivateAddr(char *p, int v, unsigned short w);
void SBServerSetICMPIP(SBServer *server, unsigned int icmpIp);
void SBServerSetState(SBServer *server, unsigned char state);
unsigned char SBServerGetState(const SBServer *server);
int SBIsNullServer(int v);
/* END mkheaders: generated region */

#endif
