/*
 * file:     sb_serverlist.c
 * unit:     yes
 * function: prevKeyCompare, IntKeyCompare, FloatKeyCompare, StrCaseKeyCompare, StrNoCaseKeyCompare, SBServerListSort, SBServerListAppendServer, SBServerListFindServer, SBServerListFindServerByIP, AddServerToDeadlist, SBServerListRemoveAt, SBServerListCount, SBServerListNth, SBFreeDeadList, SBServerListClear, SBAllocateServerList, SBRefStr, SBReleaseStr, NTSLengthSB, SBServerListInit, ErrorDisconnect, StringHash, ServerListConnect, BufferAddNTS, BufferAddByte, BufferAddInt, BufferAddIntLE, BufferAddData, SetupListChallenge, SendWithRetry, SBServerListConnectAndQuery, FreePopularValues, FreeKeyList, SBServerListDisconnect, SBServerListCleanup, InitCryptKey, ServerSizeForFlags, FullRulesPresent, AllKeysPresent, ParseServerIPPort, ParseServer, IncomingListParseServer, SBServerListSetLastError, ProcessMainListData, ProcessPushKeyList, ProcessPlayerSearch, ProcessMaploop, ProcessDeleteServer, ProcessPushServer, ProcessAdHocData, ProcessIncomingData, SBSendMessageToServer, SBSendNatNegotiateCookieToServer, ProcessLanData, SBListThink
 * address:  0x0219F0E0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      StringHash (sb_server.o)
 * Byte-identical to the StringHash entry at 0x0219E848 (same object) and the
 * same source.  `match.py one` leaves the two relocation fields wildcarded
 * (static, no exported symbol); `match.py tu` resolves both and is EXACT.
 * Sets the last error text of a server list.
 * SDK SBListThink (libdwcgsserverbrowsing.TWL.HYB.a, sb_serverlist.o, 76
 * bytes); all three callees are SDK members of the same object, so the
 * dependency tree is empty of game code and the SDK labels are overruled.
 * The listing extent runs long (5060 bytes) because the follower at
 * 0x021A1974 is unlabelled data, not a function; hence EXACT*.
 *
 * symbols:
 *   SBServerGetIntValueA  0x0219E120  arm  ov009
 *   SBServerGetFloatValueA  0x0219E1B8  arm  ov009
 *   SBServerGetStringValueA  0x0219E0C0  arm  ov009
 *   strcmp  0x020948E0  arm
 *   strcmp_nocase  0x0209ABF8  arm
 *   _dsub  0x0209AF34  arm
 *   _d2f  0x0209B64C  arm
 *   _fgr  0x0209BBB0  arm
 *   _fls  0x0209BC74  arm
 *   gSBSortContext  0x021AEB04  data
 *   gSBEmptyString  0x021A8230  data
 *   strlen  0x0209477C  arm
 *   strcmp  0x020948E0  arm
 *   ArraySort  0x021843C8  arm  ov009
 *   ArrayAppend  0x02184234  arm  ov009
 *   ArrayLength  0x02184200  arm  ov009
 *   ArrayNth  0x02184208  arm  ov009
 *   SBServerGetPublicInetAddress  0x0219E1EC  arm  ov009
 *   SBServerGetPublicQueryPortNBO  0x0219E218  arm  ov009
 *   SBServerSetNext  0x0219E264  arm  ov009
 *   ArrayDeleteAt  0x0218437C  arm  ov009
 *   SBServerGetNext  0x0219E26C  arm  ov009
 *   SBServerFree  0x0219DFF8  arm  ov009
 *   ArrayClear  0x0218452C  arm  ov009
 *   ArrayNew  0x02184144  arm  ov009
 *   SBRefStrHash  0x0219DF64  arm  ov009
 *   TableLookup  0x0218482C  arm  ov009
 *   goastrdup  0x0217F1E0  arm  ov009
 *   TableEnter  0x0218474C  arm  ov009
 *   TableRemove  0x021847BC  arm  ov009
 *   gsiSafeStrcpyA  0x021803BC  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   srand  0x020946C8  arm
 *   SocketStartUp  0x0217F25C  arm  ov009
 *   gGsAvailabilityState  0x021ACEF8  data
 *   strlen  0x0209477C  arm
 *   strncmp  0x020949F4  arm
 *   gSBMasterHostname  0x021A821C  data
 *   gSBNullServer  0x021AEB00  data
 *   _u32_div_f     0x0209C2B0  arm
 *   __lower_mapC   0x020A60DC  data
 *   OS_SPrintf  0x02084F40  arm
 *   inet_addr  0x0217ED38  arm  ov009
 *   SOC_GetHostByName  0x0215F650  arm  ov009
 *   socket  0x0217EB18  arm  ov009
 *   connect  0x0217EC08  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   gSBMasterHostFormat     0x021A8234  data
 *   memcpy  0x02092344  arm
 *   unit_02092344  0x02092344  arm
 *   rand  0x02094694  arm  ov009
 *   send  0x0217EC90  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   ArrayFree  0x021841B0  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   SBRefStrHashCleanup  0x0219DFC0  arm  ov009
 *   GOACryptInit  0x0219D2F0  arm  ov009
 *   SBServerSetFlags  0x0219E9AC  arm  ov009
 *   SBServerSetPrivateAddr  0x0219E9B4  arm  ov009
 *   SBServerSetICMPIP  0x0219E9C0  arm  ov009
 *   SBServerAddIntKeyValue  0x0219E084  arm  ov009
 *   SBServerAddKeyValue  0x0219E01C  arm  ov009
 *   SBServerGetState  0x0219E9D0  arm  ov009
 *   SBServerSetState  0x0219E9C8  arm  ov009
 *   memcmp  0x020923F0  arm
 *   SBAllocServer  0x0219E900  arm  ov009
 *   SBIsNullServer  0x0219E9D8  arm  ov009
 *   gSBNatNegMagic  0x021A8250  data
 *   GOADecrypt  0x0219D478  arm  ov009
 *   memmove  0x02092364  arm
 *   memmove        0x02092364  arm
 *   CanReceiveOnSocket  0x0217EF50  arm  ov009
 *   recv  0x0217EC4C  arm  ov009
 *   recvfrom  0x0217EC60  arm  ov009
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "sb_server_types.h"

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
#define LIST_CHALLENGE_LEN 8
#define CALCULATEODDMODE(buffer, i, oddmode) ((buffer[i-1] & 1) ^ (i & 1) ^ oddmode ^ (buffer[0] & 1) ^ ((buffer[0] < 79) ? 1 : 0) ^ ((buffer[i-1] < buffer[0]) ? 1 : 0))
#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
#define ADVANCE(b, l) { int n = strlen(b) + 1; b += n; l -= n; }
#define NULL ((void *)0)
#define NTOHS(x) ((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00))
#define HTONS(x) ((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00))
#define NATNEG_MAGIC_LEN 6
#define NN_MAGIC_0 0xfd
#define NN_MAGIC_1 0xfc
#define NN_MAGIC_2 0x1e
#define NN_MAGIC_3 0x66
#define NN_MAGIC_4 0x6a
#define NN_MAGIC_5 0xb2
#define SOC_HtoNl(hostlong) \
	( \
		(unsigned int) \
			( \
				(((unsigned int)(hostlong) >> 24) & 0x000000ff) | (((unsigned int)(hostlong) >> 8) & 0x0000ff00) | \
					(((unsigned int)(hostlong) << 8) & 0x00ff0000) | (((unsigned int)(hostlong) << 24) & 0xff000000) \
			) \
	)
struct GOACryptState;
struct SBServerList;
struct SBSortContext {
    char *masterHostname;
    SBServerList *slist;
};

struct Ref { char *str; int refcount; };

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct SOCSockAddrIn {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

typedef struct {
    char *name;
    char **aliases;
    short addrType;
    short length;
    u8 **addrList;
} SOCHostEnt;

typedef enum {
    sbe_noerror,
    sbe_socketerror,
    sbe_dnserror,
    sbe_connecterror,
    sbe_dataerror,
    sbe_allocerror,
    sbe_paramerror,
    sbe_duplicateupdateerror
} SBError;

typedef signed char s8;

struct KeyEnt { char *keyName; int keyType; };

typedef struct { unsigned char b[4]; } B4;

typedef struct { unsigned char b[2]; } B2;

typedef struct KeyInfo {
    char *keyName;
    int keyType;
} KeyInfo;

typedef void (*SBMapLoopCallback)(SBServerList *slist, void *server, long changeTime, int count, char **mapList, void *instance);

extern int SBServerGetIntValueA(SBServer *server, char *key, int idefault);
extern double SBServerGetFloatValueA(SBServer *server, char *key, double fdefault);
extern char *SBServerGetStringValueA(SBServer *server, char *keyname, char *def);
extern int strcmp_nocase(const char *a, const char *b);
extern void ArraySort(int *p, int b);
extern void ArrayAppend(void *array, void *newElem);
extern int ArrayLength(const void *array);
extern void *ArrayNth(void *a, int n);
extern int SBServerGetPublicInetAddress(const int *p);
extern unsigned short SBServerGetPublicQueryPortNBO(const unsigned short *p);
extern void SBServerSetNext(int *p, int v);
extern void ArrayDeleteAt(int a, int b);
extern int SBServerGetNext(const int *p);
extern void SBServerFree(void *elem);
extern void ArrayClear(void *a);
extern void *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void *SBRefStrHash(void *l);
extern struct Ref *TableLookup(void *t, void *k);
extern char *goastrdup(char *s);
extern void TableEnter(void *t, void *e);
extern int TableRemove(void *t, void *k);
extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
extern unsigned int current_time(void);
extern void srand(unsigned int seed);
extern void SocketStartUp(void);
extern unsigned int _u32_div_f(unsigned int a, unsigned int b);
static int StringHash(char *s, int numbuckets);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern u32 inet_addr(char *name);
extern SOCHostEnt *SOC_GetHostByName(char *name);
extern int socket(int pf, int type, int protocol);
extern int connect(int sock, void *addr, int len);
extern int closesocket(int sock);
extern void *unit_02092344(void *dst, const void *src, unsigned long n);
extern int rand(void);
extern int send(int sock, char *buf, int len, int flags);
extern void *gsimalloc(unsigned long size);
extern void ArrayFree(void *a);
extern void gsifree(void *p);
extern void SBRefStrHashCleanup(SBServerList *slist);
extern void GOACryptInit(struct GOACryptState *state, unsigned char *key, unsigned char keysize);
extern void SBServerSetFlags(SBServer *server, unsigned char flags);
extern void SBServerSetPrivateAddr(SBServer *server, unsigned int ip, unsigned short port);
extern void SBServerSetICMPIP(SBServer *server, unsigned int ip);
extern void SBServerAddIntKeyValue(SBServer *server, char *keyname, int value);
extern void SBServerAddKeyValue(SBServer *server, char *keyname, char *value);
extern unsigned char SBServerGetState(SBServer *server);
extern void SBServerSetState(SBServer *server, unsigned char state);
extern SBServer *SBAllocServer(int unused, unsigned int publicip, unsigned short publicport);
extern int SBIsNullServer(int v);
extern void GOADecrypt(void *state, unsigned char *bp, int len);
extern int CanReceiveOnSocket(int sock);
extern int recv(int sock, char *buf, int len, int flags);
extern int recvfrom(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
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
void SBServerListCount(void *list);
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
int SBListThink(int *slist);
extern struct SBSortContext gSBSortContext;
extern char gSBEmptyString[];
extern int gGsAvailabilityState;
extern char *gSBMasterHostname;
extern SBServer *gSBNullServer;
extern unsigned char __lower_mapC[];
extern char gSBMasterHostFormat[];
extern char gSBNatNegMagic[];








extern int strncmp(const u8 *s1, const u8 *s2, u32 n);
extern int strcmp(const char *a, const char *b);
extern void *memmove(void *dst, const void *src, unsigned int n);
/*
 * sdk:      prevKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in
 * src/matched/arm9/d2f.c, so its call sites are attested.
 */
int prevKeyCompare(SBServer *server1, SBServer *server2)
{
    char *prevsortkey;
    int diff;
    double f;

    prevsortkey = gSBSortContext.slist->prevsortinfo.sortkey;
    switch (gSBSortContext.slist->prevsortinfo.comparemode) {
    case 0:
        diff = SBServerGetIntValueA(server1, prevsortkey, 0) - SBServerGetIntValueA(server2, prevsortkey, 0);
        break;
    case 1:
        f = SBServerGetFloatValueA(server1, prevsortkey, 0) - SBServerGetFloatValueA(server2, prevsortkey, 0);
        if (!gSBSortContext.slist->sortascending)
            f = 0 - f;
        if ((float)f > 0)
            return 1;
        if ((float)f < 0)
            return -1;
        return 0;
    case 2:
        diff = strcmp(SBServerGetStringValueA((SBServer *)server1, prevsortkey, (char *)gSBEmptyString), SBServerGetStringValueA((SBServer *)server2, prevsortkey, (char *)gSBEmptyString));
        break;
    case 3:
        diff = strcmp_nocase(SBServerGetStringValueA((SBServer *)server1, prevsortkey, (char *)gSBEmptyString), SBServerGetStringValueA((SBServer *)server2, prevsortkey, (char *)gSBEmptyString));
        break;
    default:
        return 0;
    }
    if (!gSBSortContext.slist->sortascending)
        diff = -diff;
    return diff;
}







/*
 * sdk:      IntKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int IntKeyCompare(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = gSBSortContext.slist->currsortinfo.sortkey;
	diff = SBServerGetIntValueA(server1, currsortkey, 0) - SBServerGetIntValueA(server2, currsortkey, 0);
	if (diff == 0)
		return prevKeyCompare(server1, server2);
	if (gSBSortContext.slist->sortascending == 0)
		diff = -diff;
	return diff;
}








/*
 * sdk:      FloatKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * _d2f (0x0209B64C) is a recorded MSL runtime row (layout/runtime_arm9.txt), matched in
 * src/matched/arm9/d2f.c, so its call sites are attested.
 */
int FloatKeyCompare(void *entry1, void *entry2)
{
    SBServer *server1 = *(SBServer **)entry1;
    SBServer *server2 = *(SBServer **)entry2;
    double f;
    char *currsortkey = gSBSortContext.slist->currsortinfo.sortkey;

    f = SBServerGetFloatValueA(server1, currsortkey, 0) - SBServerGetFloatValueA(server2, currsortkey, 0);
    if (!((float)f > 0 || (float)f < 0))
        return prevKeyCompare(server1, server2);
    if (!gSBSortContext.slist->sortascending)
        f = 0 - f;
    if ((float)f > 0)
        return 1;
    if ((float)f < 0)
        return -1;
    return 0;
}







/*
 * sdk:      StrCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int StrCaseKeyCompare(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = gSBSortContext.slist->currsortinfo.sortkey;
	diff = strcmp(SBServerGetStringValueA(server1, currsortkey, (char *)gSBEmptyString), SBServerGetStringValueA(server2, currsortkey, (char *)gSBEmptyString));
	if (diff == 0)
		return prevKeyCompare(server1, server2);
	if (gSBSortContext.slist->sortascending == 0)
		diff = -diff;
	return diff;
}







/*
 * sdk:      StrNoCaseKeyCompare (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int StrNoCaseKeyCompare(void *entry1, void *entry2)
{
	char *currsortkey;
	int diff;
	void *server1;
	void *server2;
	server1 = *(void **)entry1;
	server2 = *(void **)entry2;
	currsortkey = gSBSortContext.slist->currsortinfo.sortkey;
	diff = strcmp_nocase(SBServerGetStringValueA(server1, currsortkey, (char *)gSBEmptyString), SBServerGetStringValueA(server2, currsortkey, (char *)gSBEmptyString));
	if (diff == 0)
		return prevKeyCompare(server1, server2);
	if (gSBSortContext.slist->sortascending == 0)
		diff = -diff;
	return diff;
}








/*
 * sdk:      SBServerListSort (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
void SBServerListSort(SBServerList *slist, int ascending, SBSortInfo sortinfo)
{
    int (*comparator)(void *, void *);

    switch (sortinfo.comparemode) {
    case 0:
        comparator = IntKeyCompare;
        break;
    case 1:
        comparator = FloatKeyCompare;
        break;
    case 2:
        comparator = StrCaseKeyCompare;
        break;
    case 3:
        comparator = StrNoCaseKeyCompare;
        break;
    default:
        comparator = StrNoCaseKeyCompare;
        break;
    }
    if (strlen(slist->prevsortinfo.sortkey) == 0) {
        slist->prevsortinfo = sortinfo;
    } else if (strcmp(sortinfo.sortkey, slist->currsortinfo.sortkey) != 0) {
        slist->prevsortinfo = slist->currsortinfo;
    }
    slist->currsortinfo = sortinfo;
    slist->sortascending = ascending;
    gSBSortContext.slist = slist;
    ArraySort(slist->servers, (int)comparator);
}








/*
 * sdk:      SBServerListAppendServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void SBServerListAppendServer(SBServerList *slist, SBServer *server)
{
    ArrayAppend(slist->servers, &server);
    slist->ListCallback(slist, 0, server, slist->instance);
}







/*
 * sdk:      SBServerListFindServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int SBServerListFindServer(SBServerList *slist, void *findserver)
{
	int numservers, i;
	numservers = ArrayLength(slist->servers);
	for (i = 0; i < numservers; i++)
		if (findserver == *(void **)ArrayNth(slist->servers, i))
			return i;
	return -1;
}







/*
 * sdk:      SBServerListFindServerByIP (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int SBServerListFindServerByIP(SBServerList *slist, unsigned int ip, unsigned short port)
{
	int numservers;
	void *server;
	int i;
	numservers = ArrayLength(slist->servers);
	for (i = 0; i < numservers; i++) {
		server = *(void **)ArrayNth(slist->servers, i);
		if (ip == SBServerGetPublicInetAddress(server) && port == SBServerGetPublicQueryPortNBO(server))
			return i;
	}
	return -1;
}








/*
 * sdk:      AddServerToDeadlist (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void AddServerToDeadlist(SBServerList *slist, SBServer *server)
{
    if (slist->deadlist == 0)
        SBServerSetNext((int *)server, 0);
    else
        SBServerSetNext((int *)server, (int)slist->deadlist);
    slist->deadlist = server;
}






/*
 * sdk:      SBServerListRemoveAt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void SBServerListRemoveAt(SBServerList *slist, int index)
{
	SBServer *server;
	server = *(SBServer **)ArrayNth(slist->servers, index);
	slist->ListCallback(slist, 2, server, slist->instance);
	ArrayDeleteAt((int)slist->servers, index);
	AddServerToDeadlist((SBServerList *)slist, (SBServer *)server);
}







void SBServerListCount(void *list)
{
    ArrayLength(*(void **)((char *)list + 4));
}






/*
 * Returns the server at the given index of the list.
 */
SBServer *SBServerListNth(SBServerList *slist, int index)
{
    return *(SBServer **)ArrayNth(slist->servers, index);
}





/*
 * sdk:      SBFreeDeadList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void SBFreeDeadList(SBServerList *slist)
{
	void *next;
	void *server;
	next = slist->deadlist;
	if (next == 0)
		return;
	for (server = next; server != 0; server = next) {
		next = (void *)SBServerGetNext(server);
		SBServerFree(&server);
	}
	slist->deadlist = 0;
}





/*
 * sdk:      SBServerListClear (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void SBServerListClear(SBServerList *slist)
{
	int i;
	int nservers;
	nservers = ArrayLength(slist->servers);
	for (i = 0; i < nservers; i++)
		AddServerToDeadlist((SBServerList *)slist, *(void **)ArrayNth(slist->servers, i));
	ArrayClear(slist->servers);
	SBFreeDeadList(slist);
}






/*
 * sdk:      SBAllocateServerList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void SBAllocateServerList(SBServerList *slist)
{
    slist->servers = ArrayNew(4, 100, 0);
    slist->deadlist = 0;
}





/*
 * sdk:      SBRefStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
char *SBRefStr(void *slist, char *str)
{
	struct Ref ref;
	struct Ref *val;
	ref.str = str;
	val = TableLookup(SBRefStrHash(slist), &ref);
	if (val != 0) {
		val->refcount++;
		return val->str;
	}
	ref.str = goastrdup(str);
	ref.refcount = 1;
	TableEnter(SBRefStrHash(slist), &ref);
	return ref.str;
}





/*
 * sdk:      SBReleaseStr (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void SBReleaseStr(void *slist, char *str)
{
	struct Ref ref;
	struct Ref *val;
	ref.str = str;
	val = TableLookup(SBRefStrHash(slist), &ref);
	if (val == 0)
		return;
	if (--val->refcount == 0)
		TableRemove(SBRefStrHash(slist), &ref);
}





/*
 * sdk:      NTSLengthSB (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int NTSLengthSB(const char *buf, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        if (buf[i] == 0)
            return i + 1;
    }
    return -1;
}






/*
 * sdk:      SBServerListInit (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
void SBServerListInit(SBServerList *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                   int queryFromVersion, int lanBrowse, SBListCB callback,
                   void *instance)
{
    if (!lanBrowse && gGsAvailabilityState != 1)
        return;
    slist->state = 1;
    SBAllocateServerList(slist);
    SBRefStrHash(slist);
    gsiSafeStrcpyA(slist->queryforgamename, queryForGamename, 36);
    gsiSafeStrcpyA(slist->queryfromgamename, queryFromGamename, 36);
    gsiSafeStrcpyA(slist->queryfromkey, queryFromKey, 32);
    slist->ListCallback = callback;
    slist->MaploopCallback = 0;
    slist->mypublicip = 0;
    slist->inbuffer = 0;
    slist->inbufferlen = 0;
    slist->keylist = 0;
    slist->numpopularvalues = 0;
    slist->srcip = 0;
    slist->instance = instance;
    slist->slsocket = -1;
    slist->expectedelements = -1;
    slist->fromgamever = queryFromVersion;
    slist->currsortinfo.sortkey[0] = *(volatile unsigned char *)gSBEmptyString;
    slist->prevsortinfo.sortkey[0] = *(volatile unsigned char *)gSBEmptyString;
    SBServerListSetLastError(slist, gSBEmptyString);
    slist->mLanAdapterOverride = 0;
    slist->backendgameflags = 0x80;
    srand(current_time());
    SocketStartUp();
}





/*
 * sdk:      ErrorDisconnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void ErrorDisconnect(SBServerList *slist)
{
	int len = slist->inbufferlen;
	char *q;
	if (len > 0 && len > (unsigned int)strlen((const char *)(q = gSBMasterHostname))) {
		char *e = gSBMasterHostname;
		char *s = (char *)slist->inbuffer;
		if (strncmp((const u8 *)s, (const u8 *)e, (unsigned int)strlen((const char *)e)) == 0) {
			SBServerListSetLastError(slist, s + strlen((const char *)q));
			slist->ListCallback(slist, 5, gSBNullServer, slist->instance);
		}
	}
	slist->ListCallback(slist, 4, gSBNullServer, slist->instance);
	SBServerListDisconnect(slist);
}



static int StringHash(char *s, int numbuckets)
{
    unsigned int hashcode = 0;
    char *p = s;
    int c;

    while ((c = *p) != 0)
    {
        if (c >= 0 && c < 0x80)
            c = __lower_mapC[c];
        hashcode = hashcode * 0x9CCF9319 + c;
        p++;
    }
    return hashcode % numbuckets;
}







/*
 * sdk:      ServerListConnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int ServerListConnect(SBServerList *slist)
{
    SOCSockAddrIn saddr;
    SOCHostEnt *hent;
    char masterHostname[128];
    int masterIndex;

    masterIndex = StringHash(slist->queryforgamename, 20);
    if ((*(char * *)&gSBSortContext))
        gsiSafeStrcpyA(masterHostname, (*(char * *)&gSBSortContext), 128);
    else
        OS_SPrintf(masterHostname, gSBMasterHostFormat, slist->queryforgamename, masterIndex);
    saddr.family = 2;
    saddr.port = 0xEE70;
    saddr.addr = inet_addr(masterHostname);
    if (saddr.addr == (u32)-1) {
        hent = SOC_GetHostByName(masterHostname);
        if (!hent)
            return 2;
        memcpy(&saddr.addr, hent->addrList[0], 4);
    }
    if (slist->slsocket == -1) {
        slist->slsocket = socket(2, 1, 0);
        if (slist->slsocket == -1)
            return 1;
    }
    if (connect(slist->slsocket, &saddr, 8) == 0)
        return 0;
    closesocket(slist->slsocket);
    slist->slsocket = -1;
    return 3;
}







/*
 * sdk:      BufferAddNTS (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void BufferAddNTS(char **buffer, char *str, int *len)
{
	int slen;
	if (!str)
		str = gSBEmptyString;
	slen = strlen((const char *)str) + 1;
	memcpy(*buffer, str, slen);
	*len += slen;
	*buffer += slen;
}







/*
 * Stores a byte through the pointer in *p, then advances the pointer and the counter.
 */
void BufferAddByte(char **buffer, unsigned char value, int *len)
{
    **buffer = value;
    (*len)++;
    (*buffer)++;
}







/*
 * sdk:      BufferAddInt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void BufferAddInt(char **buffer, int ival, int *len)
{
	char *d = *buffer;
	unsigned char *src = (unsigned char *)&ival;
	d[0] = src[0]; d[1] = src[1]; d[2] = src[2]; d[3] = src[3];
	*len += 4;
	*buffer += 4;
}







/*
 * sdk:      BufferAddIntLE (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void BufferAddIntLE(char **buffer, int ival, int *len)
{
	unsigned int ivalNBO;
	unsigned int ivalBE = 0;
	ivalNBO = SWAP32((unsigned int)ival);
	ivalBE |= ivalNBO << 24;
	ivalBE |= (ivalNBO & 0xff00) << 8;
	ivalBE |= (ivalNBO & 0xff0000) >> 8;
	ivalBE |= (ivalNBO & 0xff000000) >> 24;
	BufferAddInt(buffer, ivalBE, len);
}







/*
 * sdk:      BufferAddData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void BufferAddData(char **buffer, char *data, int dlen, int *len)
{
    unit_02092344(*buffer, data, dlen);
    *len += dlen;
    *buffer += dlen;
}







/*
 * sdk:      SetupListChallenge (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void SetupListChallenge(SBServerList *slist)
{
	int i;
	int oddmode;

	slist->mychallenge[0] = (char)(33 + rand() % 93);	/* chars in the range 33 - 125 */
	oddmode = 0;
	for (i = 1; i < LIST_CHALLENGE_LEN; i++)
	{
		oddmode = CALCULATEODDMODE(slist->mychallenge, i, oddmode);
		slist->mychallenge[i] = (char)(33 + rand() % 93);
		/* if oddmode make sure the char is odd, otherwise make sure it's even */
		if ((oddmode && (slist->mychallenge[i] & 1) == 0) || (!oddmode && ((slist->mychallenge[i] & 1) == 1)))
			slist->mychallenge[i]++;
	}
}




/*
 * sdk:      SendWithRetry (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int SendWithRetry(SBServerList *slist, char *data, int len)
{
	int err;
	int ret;
	int retryCount;
	retryCount = 1;
	do {
		retryCount--;
		ret = send(slist->slsocket, data, len, 0);
		if (ret > 0 || retryCount < 0 || slist->inbufferlen > 0)
			break;
		SBServerListDisconnect(slist);
		err = SBServerListConnectAndQuery((SBServerList *)slist, 0, 0, 2, 0);
		if (err != 0) {
			ErrorDisconnect(slist);
			return err;
		}
	} while (retryCount >= 0);
	{
		int r = 3;
		if (ret > 0)
			r = 0;
		return r;
	}
}








SBError SBServerListConnectAndQuery(SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers)
{
    SBError err;
    int ret;
    int requestLen;
    unsigned short netLen;
    char *requestBuf;
    char outgoingRequest[1023];

    if (fieldList == 0)
        fieldList = gSBEmptyString;
    if (serverFilter == 0)
        serverFilter = gSBEmptyString;
    if (strlen(fieldList) > 256)
        return sbe_paramerror;
    if (strlen(serverFilter) > 511)
        return sbe_paramerror;
    err = ServerListConnect(slist);
    if (err != sbe_noerror)
        return err;
    slist->queryoptions = options;
    SetupListChallenge(slist);
    requestLen = 2;
    requestBuf = outgoingRequest + 2;
    BufferAddByte(&requestBuf, 0, &requestLen);
    BufferAddByte(&requestBuf, 1, &requestLen);
    BufferAddByte(&requestBuf, 3, &requestLen);
    BufferAddIntLE(&requestBuf, slist->fromgamever, &requestLen);
    BufferAddNTS(&requestBuf, slist->queryforgamename, &requestLen);
    BufferAddNTS(&requestBuf, slist->queryfromgamename, &requestLen);
    BufferAddData(&requestBuf, slist->mychallenge, 8, &requestLen);
    BufferAddNTS(&requestBuf, serverFilter, &requestLen);
    BufferAddNTS(&requestBuf, fieldList, &requestLen);
    BufferAddInt(&requestBuf, SWAP32((unsigned int)options), &requestLen);
    if (slist->queryoptions & 8)
        BufferAddInt(&requestBuf, slist->srcip, &requestLen);
    if (slist->queryoptions & 0x80)
        BufferAddIntLE(&requestBuf, maxServers, &requestLen);
    netLen = SWAP16((unsigned short)requestLen);
    memcpy(outgoingRequest, &netLen, 2);
    ret = send(slist->slsocket, outgoingRequest, requestLen, 0);
    if (ret <= 0) {
        SBServerListDisconnect(slist);
        return sbe_connecterror;
    }
    slist->state = 3;
    slist->pstate = 0;
    if (slist->inbuffer == 0) {
        slist->inbuffer = gsimalloc(0x1000);
        if (slist->inbuffer == 0)
            return sbe_allocerror;
        slist->inbufferlen = 0;
    }
    return sbe_noerror;
}








/*
 * sdk:      FreePopularValues (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void FreePopularValues(char *list)
{
	int i;
	for (i = 0; i < *(int *)(list + 0x480); i++)
		SBReleaseStr(list, *(char **)(list + 0x84 + i * 4));
	*(int *)(list + 0x480) = 0;
}







/*
 * sdk:      FreeKeyList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void FreeKeyList(SBServerList *slist)
{
	int i;
	if (slist->keylist == 0)
		return;
	for (i = 0; i < ArrayLength(slist->keylist); i++)
		SBReleaseStr(slist, *(char **)ArrayNth(slist->keylist, i));
	ArrayFree(slist->keylist);
	slist->keylist = 0;
}






/*
 * sdk:      SBServerListDisconnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void SBServerListDisconnect(SBServerList *slist)
{
	if (slist->inbuffer != 0)
		gsifree(slist->inbuffer);
	slist->inbuffer = 0;
	slist->inbufferlen = 0;
	if (slist->slsocket != -1)
		closesocket(slist->slsocket);
	slist->slsocket = -1;
	slist->state = 1;
	FreeKeyList(slist);
	slist->expectedelements = -1;
	FreePopularValues((char *)slist);
}







/*
 * sdk:      SBServerListCleanup (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void SBServerListCleanup(SBServerList *slist)
{
    SBServerListDisconnect((SBServerList *)slist);
    SBServerListClear((SBServerList *)slist);
    SBRefStrHashCleanup(slist);
    if (slist->servers != 0)
        ArrayFree(slist->servers);
    slist->servers = 0;
}






/*
 * sdk:      InitCryptKey (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void InitCryptKey(SBServerList *slist, char *key, int keylen)
{
	int i;
	int seckeylen;
	char *seckey;
	seckeylen = strlen((const char *)slist->queryfromkey);
	seckey = slist->queryfromkey;
	for (i = 0; i < keylen; i++)
		slist->mychallenge[(i * seckey[i % seckeylen]) % 8] ^= slist->mychallenge[i % 8] ^ key[i];
	GOACryptInit((struct GOACryptState *)slist->cryptkey, (unsigned char *)slist->mychallenge, 8);
}






/*
 * Maps the flag bits 2, 8, 0x10 and 0x20 to a size code starting at 5.
 */
int ServerSizeForFlags(int flags)
{
    int n = 5;

    if (flags & 2) n += 4;
    if (flags & 8) n += 4;
    if (flags & 0x10) n += 2;
    if (flags & 0x20) n += 2;
    return n;
}







/*
 * Walk a length-bounded string, two decode steps per turn: NTSLengthSB
 * reports how many bytes one unit occupies and a negative answer is a hard
 * failure (0).  Each successful step consumes that many bytes from the
 * pointer and the remaining count, in the order the image shows (the count
 * first on the first step, the pointer first on the second).  Leaving with
 * the count exhausted answers 0, leaving on a terminator answers 1.
 */
int FullRulesPresent(const char *buf, int len)
{
    int consumed;

    while (len > 0 && *buf != 0) {
        consumed = NTSLengthSB(buf, len);
        if (consumed < 0)
            return 0;
        len -= consumed;
        buf += consumed;
        consumed = NTSLengthSB(buf, len);
        if (consumed < 0)
            return 0;
        buf += consumed;
        len -= consumed;
    }
    if (len == 0)
        return 0;
    return *buf == 0;
}







/*
 * sdk:      AllKeysPresent (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int AllKeysPresent(SBServerList *slist, char *buf, int len)
{
	int numkeys;
	int i;
	int strindex;
	numkeys = ArrayLength(slist->keylist);
	for (i = 0; i < numkeys; i++) {
		switch (((struct KeyEnt *)ArrayNth(slist->keylist, i))->keyType) {
		case 1:
			buf += 1;
			len -= 1;
			break;
		case 2:
			buf += 2;
			len -= 2;
			break;
		case 0:
			if (len < 1)
				return 0;
			if (*(unsigned char *)buf++ == 0xff) {
				len--;
				strindex = NTSLengthSB(buf, len);
				if (strindex == -1)
					return 0;
				buf += strindex;
				len -= strindex;
			} else
				len--;
			break;
		default:
			return 0;
		}
		if (len < 0)
			return 0;
	}
	return 1;
}






/*
 * sdk:      ParseServerIPPort (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void ParseServerIPPort(SBServerList *slist, unsigned char *buf, int len, unsigned int *ip, unsigned short *port)
{
	unsigned char flags;
	if (len < 5)
		return;
	flags = *buf++;
	*(B4 *)ip = *(B4 *)buf;
	buf += 4;
	len -= 5;
	if (flags & 0x10) {
		if (len < 2)
			return;
		*(B2 *)port = *(B2 *)buf;
	} else {
		*port = slist->defaultport;
	}
}







/*
 * sdk:      ParseServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * The object calls strlen once per string skip and applies the result to buf and
 * len; ADVANCE spells that with a block-scoped temporary.
 */
int ParseServer(SBServerList *slist, SBServer *server, char *buf, int len, int usepopularlist)
{
    int numkeys;
    int i;
    short sval;
    int strindex;
    int holdlen;
    unsigned int ip;
    unsigned short port;
    unsigned char flags;
    KeyInfo *ki;
    char *k;
    unsigned char state;

    holdlen = len;
    flags = *buf++;
    SBServerSetFlags(server, flags);
    buf += 4;
    len -= 5;
    if (flags & 0x10) {
        buf += 2;
        len -= 2;
    }
    if (flags & 2) {
        memcpy(&ip, buf, 4);
        buf += 4;
        len -= 4;
    } else
        ip = 0;
    if (flags & 0x20) {
        memcpy(&port, buf, 2);
        buf += 2;
        len -= 2;
    } else
        port = slist->defaultport;
    SBServerSetPrivateAddr(server, ip, port);
    if (flags & 8) {
        memcpy(&ip, buf, 4);
        buf += 4;
        len -= 4;
        SBServerSetICMPIP(server, ip);
    }
    if (flags & 0x40) {
        numkeys = ArrayLength(slist->keylist);
        for (i = 0; i < numkeys; i++) {
            ki = (KeyInfo *)ArrayNth(slist->keylist, i);
            switch (ki->keyType) {
            case 1:
                SBServerAddIntKeyValue(server, ki->keyName, (unsigned char)*buf++);
                len--;
                break;
            case 2:
                memcpy(&sval, buf, 2);
                SBServerAddIntKeyValue(server, ki->keyName, SWAP16((unsigned short)sval));
                buf += 2;
                len -= 2;
                break;
            case 0:
                if (usepopularlist) {
                    strindex = (unsigned char)*buf++;
                    len--;
                } else
                    strindex = 0xff;
                if (strindex == 0xff) {
                    SBServerAddKeyValue(server, ki->keyName, buf);
                    ADVANCE(buf, len);
                } else
                    SBServerAddKeyValue(server, ki->keyName, slist->popularvalues[strindex]);
                break;
            }
        }
        SBServerSetState(server, SBServerGetState(server) | 1);
    }
    if (flags & 0x80) {
        while (*buf && len > 0) {
            k = buf;
            ADVANCE(buf, len);
            SBServerAddKeyValue(server, k, buf);
            ADVANCE(buf, len);
        }
        len--;
        SBServerSetState(server, SBServerGetState(server) | 2);
    }
    state = SBServerGetState(server);
    if (!(flags & 0xc0) && ((state & 1) || (state & 2)))
        SBServerSetState(server, state & 0xfc);
    return holdlen - len;
}






/*
 * sdk:      IncomingListParseServer (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
int IncomingListParseServer(SBServerList *slist, char *buf, int len)
{
    SBServer *server;
    unsigned short port;
    unsigned int ip;
    int i;
    int ret;
    unsigned char flags;

    if (len < 1)
        return 0;
    flags = buf[0];
    i = ServerSizeForFlags(flags);
    if (len < i)
        return 0;
    if (flags & 0x40) {
        if (!AllKeysPresent((SBServerList *)slist, buf + i, len - i))
            return 0;
    }
    if (flags & 0x80) {
        if (!FullRulesPresent(buf + i, len - i))
            return 0;
    }
    if (!memcmp(buf + 1, gSBNatNegMagic, 4))
        return -1;
    ParseServerIPPort((SBServerList *)slist, (unsigned char *)buf, len, &ip, &port);
    server = SBAllocServer((int)slist, ip, port);
    if (SBIsNullServer((int)server))
        return -2;
    ret = ParseServer(slist, server, buf, len, 1);
    SBServerListAppendServer(slist, server);
    return ret;
}



void SBServerListSetLastError(SBServerList *slist, char *lastError)
{
    slist->lasterror = lastError;
}





/*
 * sdk:      ProcessMainListData (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * The object is stamped 4.0.0.1025; built with dsi/1.1p1.
 */
SBError ProcessMainListData(SBServerList *slist)
{
    int reqlen;
    int keyoffset;
    int keylen;
    char *inbuf = (char *)slist->inbuffer;
    int inlen = slist->inbufferlen;
    KeyInfo ki;

    switch (slist->pstate) {
    case 0:
        if (inlen < 1)
            break;
        keyoffset = ((unsigned char)inbuf[0] ^ 0xEC) + 2;
        if (inlen < keyoffset)
            break;
        keylen = (unsigned char)inbuf[keyoffset - 1] ^ 0xEA;
        reqlen = keyoffset + keylen;
        if (inlen < reqlen)
            break;
        InitCryptKey(slist, inbuf + keyoffset, keylen);
        slist->pstate = 1;
        memcpy(&slist->backendgameflags, inbuf + 1, 2);
        slist->backendgameflags = NTOHS(slist->backendgameflags);
        inbuf += reqlen;
        inlen -= reqlen;
        GOADecrypt(slist->cryptkey, (unsigned char *)inbuf, inlen);
    case 1:
        if (inlen < 6)
            break;
        memcpy(&slist->mypublicip, inbuf, 4);
        slist->ListCallback(slist, 6, gSBNullServer, slist->instance);
        memcpy(&slist->defaultport, inbuf + 4, 2);
        if (slist->defaultport == 0xFFFF) {
            int keylen = NTSLengthSB(inbuf + 6, inlen - 6);
            if (keylen == -1)
                break;
            SBServerListSetLastError(slist, inbuf + 6);
            slist->ListCallback(slist, 5, gSBNullServer, slist->instance);
            if (slist->inbuffer == NULL)
                break;
        }
        inbuf += 6;
        inlen -= 6;
        if ((slist->queryoptions & 2) || slist->defaultport == 0xFFFF) {
            slist->pstate = 5;
            slist->state = 2;
            break;
        }
        slist->pstate = 2;
        slist->expectedelements = -1;
    case 2:
        if (slist->expectedelements == -1) {
            if (inlen < 1)
                break;
            slist->expectedelements = (unsigned char)*inbuf;
            slist->keylist = ArrayNew(sizeof(KeyInfo), slist->expectedelements, NULL);
            if (slist->keylist == NULL)
                return sbe_allocerror;
            inbuf++;
            inlen--;
        }
        while (slist->expectedelements > ArrayLength(slist->keylist)) {
            int keylen;
            if (inlen < 2)
                break;
            keylen = NTSLengthSB(inbuf + 1, inlen - 1);
            if (keylen == -1)
                break;
            ki.keyType = (unsigned char)*inbuf;
            ki.keyName = SBRefStr(slist, inbuf + 1);
            ArrayAppend(slist->keylist, &ki);
            inbuf += keylen + 1;
            inlen -= keylen + 1;
        }
        if (slist->expectedelements > ArrayLength(slist->keylist))
            break;
        slist->pstate = 3;
        slist->expectedelements = -1;
    case 3:
        if (slist->expectedelements == -1) {
            if (inlen < 1)
                break;
            slist->expectedelements = (unsigned char)*inbuf;
            inbuf++;
            inlen--;
            slist->numpopularvalues = 0;
        }
        while (slist->expectedelements > slist->numpopularvalues) {
            int keylen = NTSLengthSB(inbuf, inlen);
            if (keylen == -1)
                break;
            slist->popularvalues[slist->numpopularvalues++] = SBRefStr(slist, inbuf);
            inbuf += keylen;
            inlen -= keylen;
        }
        if (slist->expectedelements > slist->numpopularvalues)
            break;
        slist->pstate = 4;
    case 4:
        if (inlen < 5)
            break;
        do {
            keylen = IncomingListParseServer(slist, inbuf, inlen);
            if (keylen == -2)
                return sbe_allocerror;
            if (keylen == -1) {
                slist->state = 2;
                slist->pstate = 5;
                inlen -= 5;
                inbuf += 5;
                slist->ListCallback(slist, 3, gSBNullServer, slist->instance);
                break;
            }
            inbuf += keylen;
            inlen -= keylen;
            if (slist->inbuffer == NULL)
                keylen = 0;
        } while (keylen != 0);
        break;
    }

    if (slist->inbuffer == NULL)
        return sbe_noerror;
    if (inlen != 0)
        memmove(slist->inbuffer, inbuf, inlen);
    slist->inbufferlen = inlen;
    return sbe_noerror;
}






/*
 * sdk:      ProcessPushKeyList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int ProcessPushKeyList(SBServerList *slist, char *buf, int len)
{
	int i;
	int numkeys;
	int keylen;
	KeyInfo ki;
	numkeys = (unsigned char)*buf++;
	len--;
	if (slist->keylist != 0)
		FreeKeyList(slist);
	slist->keylist = ArrayNew(8, numkeys, 0);
	if (slist->keylist == 0)
		return 5;
	for (i = 0; i < numkeys; i++) {
		if (len < 2)
			return 4;
		keylen = NTSLengthSB(buf + 1, len - 1);
		if (keylen == -1)
			return 4;
		ki.keyType = (unsigned char)buf[0];
		ki.keyName = SBRefStr(slist, buf + 1);
		ArrayAppend(slist->keylist, &ki);
		buf += keylen + 1;
		len -= keylen + 1;
	}
	return 0;
}






/*
 * sdk:      ProcessPlayerSearch (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int ProcessPlayerSearch(SBServerList *slist, char *buf, int len)
{
    unsigned char isFinal;
    unsigned char resultCount;
    unsigned int ip;
    unsigned short port;
    char *nick;
    long lastSeen;
    int i;
    int slen;

    if (len < 2)
        return 4;
    isFinal = buf[0];
    resultCount = buf[1];
    buf += 2;
    len -= 2;
    for (i = 0; i < resultCount; i++) {
        nick = buf;
        slen = NTSLengthSB(buf, len);
        if (slen == -1)
            return 4;
        buf += slen;
        len -= slen;
        if (len < 11)
            return 4;
        memcpy(&ip, buf, 4);
        memcpy(&port, buf + 4, 2);
        memcpy(&lastSeen, buf + 6, 4);
        lastSeen = SWAP32((unsigned int)lastSeen);
        buf += 10;
        len -= 10;
        slen = NTSLengthSB(buf, len);
        if (slen == -1)
            return 4;
        slist->PlayerSearchCallback(slist, nick, ip, port, lastSeen, buf, slist->instance);
        buf += slen;
        len -= slen;
    }
    if (isFinal)
        slist->PlayerSearchCallback(slist, 0, 0, 0, 0, 0, slist->instance);
    return 0;
}






/*
 * sdk:      ProcessMaploop (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int ProcessMaploop(SBServerList *slist, char *buf, int len)
{
    long changeTime;
    u32 ip;
    u16 port;
    void *server;
    u8 mapCount;
    int i;
    char *mapList[16];
    int maplen;

    if (len < 11)
        return 4;
    memcpy(&ip, buf, 4);
    memcpy(&port, &buf[4], 2);
    i = SBServerListFindServerByIP(slist, ip, port);
    if (i == -1)
        return 0;
    server = SBServerListNth(slist, i);
    memcpy(&changeTime, &buf[6], 4);
    changeTime = (((u32)changeTime >> 24) & 0xFF) | (((u32)changeTime >> 8) & 0xFF00) | (((u32)changeTime << 8) & 0xFF0000) | (((u32)changeTime << 24) & 0xFF000000);
    mapCount = buf[10];
    buf += 11;
    len -= 11;
    for (i = 0; i < mapCount && i < 16; i++) {
        if (len < 1)
            break;
        maplen = NTSLengthSB(buf, len);
        if (maplen == -1)
            return 4;
        mapList[i] = buf;
        buf += maplen;
        len -= maplen;
    }
    if (slist->MaploopCallback == 0)
        return 0;
    slist->MaploopCallback(slist, server, changeTime, i, mapList, slist->instance);
    return 0;
}







/*
 * sdk:      ProcessDeleteServer (sb_serverlist.o)
 *
 * Closed (w5_nm): both field copies are string.h memcpy, ip first then port;
 * mwccarm schedules the inline byte loads in the object's order (port bytes
 * first) and gives the object's registers.  Byte-pointer copies landed the
 * pointer and value temps in swapped registers.
 */
SBError ProcessDeleteServer(SBServerList *slist, char *buf, int len)
{
    int i;
    unsigned short port;
    unsigned int ip;

    if (len < 6)
        return sbe_dataerror;
    memcpy(&ip, buf, 4);
    memcpy(&port, buf + 4, 2);
    i = SBServerListFindServerByIP(slist, ip, port);
    if (i == -1)
        return sbe_noerror;
    SBServerListRemoveAt(slist, i);
    return sbe_noerror;
}







/*
 * sdk:      ProcessPushServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int ProcessPushServer(SBServerList *slist, char *buf, int len)
{
	void *server;
	unsigned int ip;
	unsigned short port;
	int foundexisting;
	int i;
	if (len < 5)
		return 4;
	ParseServerIPPort(slist, (unsigned char *)buf, len, &ip, &port);
	foundexisting = SBServerListFindServerByIP(slist, ip, port);
	if (foundexisting == -1) {
		server = SBAllocServer((int)slist, ip, port);
		if (SBIsNullServer((int)server))
			return 5;
	} else {
		server = SBServerListNth(slist, foundexisting);
	}
	if (ParseServer(slist, server, buf, len, 0) < 0)
		return 4;
	if (foundexisting == -1)
		SBServerListAppendServer((SBServerList *)slist, server);
	slist->ListCallback(slist, 1, server, slist->instance);
	return 0;
}








/*
 * sdk:      ProcessAdHocData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int ProcessAdHocData(SBServerList *slist)
{
    int ret = 0;
    int i;
    u16 msglen;

    while (slist->inbufferlen >= 3) {
        u8 *dst = (u8 *)&msglen;
        dst[0] = slist->inbuffer[0];
        dst[1] = slist->inbuffer[1];
        msglen = ((msglen >> 8) & 0xFF) | ((msglen << 8) & 0xFF00);
        if (msglen > 0x1000) {
            ret = 4;
            break;
        }
        if (slist->inbufferlen < msglen)
            return 0;
        switch ((char)slist->inbuffer[2]) {
        case 0:
            break;
        case 1:
            ret = ProcessPushKeyList((SBServerList *)slist, (char *)(slist->inbuffer + 3), msglen - 3);
            break;
        case 2:
            ret = ProcessPushServer((SBServerList *)slist, (char *)(slist->inbuffer + 3), msglen - 3);
            break;
        case 3:
            if (send(slist->slsocket, (char *)slist->inbuffer, msglen, 0) <= 0)
                return 3;
            break;
        case 4:
            ret = ProcessDeleteServer((SBServerList *)slist, (char *)(slist->inbuffer + 3), msglen - 3);
            break;
        case 5:
            ret = ProcessMaploop(slist, (char *)(slist->inbuffer + 3), msglen - 3);
            break;
        case 6:
            ret = ProcessPlayerSearch(slist, (char *)(slist->inbuffer + 3), msglen - 3);
            break;
        default:
            break;
        }
        slist->inbufferlen -= msglen;
        if (slist->inbufferlen != 0 && slist->inbuffer != 0)
            memmove(slist->inbuffer, slist->inbuffer + msglen, slist->inbufferlen);
        if (ret != 0)
            break;
    }
    if (ret != 0)
        ErrorDisconnect((SBServerList *)slist);
    return ret;
}







int ProcessIncomingData(SBServerList *slist)
{
	int err;
	int len;
	int oldlen;
	if (!CanReceiveOnSocket(slist->slsocket))
		return 0;
	oldlen = slist->inbufferlen;
	err = 0;
	len = recv(slist->slsocket, (char *)(slist->inbuffer + oldlen), 0x1000 - oldlen, 0);
	if (len == -1 || len == 0) {
		ErrorDisconnect(slist);
		return 3;
	}
	slist->inbufferlen += len;
	if (slist->state == 2 || slist->pstate > 0)
		GOADecrypt((struct GOACryptState *)slist->cryptkey, (unsigned char *)(slist->inbuffer + oldlen), slist->inbufferlen - oldlen);
	if (slist->state == 3)
		err = ProcessMainListData((SBServerList *)slist);
	if (err != 0)
		return err;
	if (slist->state == 2 && slist->inbufferlen > 0)
		return ProcessAdHocData(slist);
	return 0;
}







/*
 * sdk:      SBSendMessageToServer (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
int SBSendMessageToServer(SBServerList *slist, unsigned int ip, unsigned short port, char *data, int len)
{
    int i;
    int ret;
    unsigned short tmp;
    char requestBuffer[16];

    if (slist->state == 1)
        SBServerListConnectAndQuery(slist, 0, 0, 2, 0);
    if (slist->state == 1)
        return 3;
    tmp = HTONS((unsigned short)(len + 9));
    memcpy(&requestBuffer[0], &tmp, 2);
    requestBuffer[2] = 2;
    memcpy(&requestBuffer[3], &ip, 4);
    memcpy(&requestBuffer[7], &port, 2);
    i = SendWithRetry(slist, requestBuffer, 9);
    if (i != 0)
        return i;
    ret = 0;
    i = send(slist->slsocket, data, len, 0);
    if (i < 0)
        ret = 3;
    return ret;
}







/*
 * SBSendNatNegotiateCookieToServer: fills a 10-byte natneg cookie packet
 * (6 magic bytes + the big-endian cookie) and hands it to SBSendMessageToServer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/SBSendNatNegotiateCookieToServer.c \
 *       --func SBSendNatNegotiateCookieToServer --addr 0x021A174C --region ov009 --arm --cc 1.1p1 --lang c99 --diff
 */
int SBSendNatNegotiateCookieToServer(void *slist, unsigned int ip, unsigned short port, int cookie)
{
	unsigned char negotiateBuffer[NATNEG_MAGIC_LEN + 4];

	negotiateBuffer[0] = NN_MAGIC_0;
	negotiateBuffer[1] = NN_MAGIC_1;
	negotiateBuffer[2] = NN_MAGIC_2;
	negotiateBuffer[3] = NN_MAGIC_3;
	negotiateBuffer[4] = NN_MAGIC_4;
	negotiateBuffer[5] = NN_MAGIC_5;
	cookie = (int)SOC_HtoNl((unsigned int)cookie);
	memcpy(negotiateBuffer + NATNEG_MAGIC_LEN, &cookie, 4);
	return SBSendMessageToServer(slist, ip, port, (char *)negotiateBuffer, NATNEG_MAGIC_LEN + 4);
}





/*
 * sdk:      ProcessLanData (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
int ProcessLanData(SBServerList *slist)
{
    char indata[1500];
    SOCSockAddrIn saddr;
    int saddrlen;
    int error;
    int foundexisting;
    SBServer *server;

    saddrlen = 8;
    while (CanReceiveOnSocket(slist->slsocket)) {
        error = recvfrom(slist->slsocket, indata, 1499, 0, &saddr, &saddrlen);
        if (error == -1)
            continue;
        foundexisting = SBServerListFindServerByIP((SBServerList *)slist, saddr.addr, saddr.port);
        if (foundexisting != -1)
            continue;
        server = SBAllocServer((int)slist, saddr.addr, saddr.port);
        if (SBIsNullServer((int)server))
            return 5;
        SBServerSetFlags(server, 0x11);
        SBServerListAppendServer(slist, server);
    }
    if (current_time() - slist->lanstarttime > 2000) {
        closesocket(slist->slsocket);
        slist->slsocket = -1;
        slist->state = 1;
        slist->ListCallback(slist, 3, gSBNullServer, slist->instance);
    }
    return 0;
}


int SBListThink(int *slist)
{
    SBFreeDeadList((SBServerList *)slist);
    switch (slist[0]) {
    case 2:
    case 3:
        return ProcessIncomingData((SBServerList *)slist);
    case 0:
        return ProcessLanData((SBServerList *)slist);
    case 1:
    default:
        return 0;
    }
}
