/*
 * file:     unit_0219FBB8.c
 * unit:     yes
 * function: func_0219FBB8, func_0219FCF0, func_0219FD40, func_0219FD64, func_0219FDB8, func_0219FE10, func_0219FE44, func_0219FF30, func_0219FFD4, func_021A0238, func_021A027C, func_021A02E0, func_021A0340, func_021A0378, func_021A0414, func_021A0440, func_021A04C4, func_021A059C, func_021A060C, func_021A08E8
 * address:  0x0219FBB8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0219FB64  0x0219FB64  arm  ov009
 *   func_021803BC  0x021803BC  arm  ov009
 *   func_02084F40  0x02084F40  arm
 *   func_0217ED38  0x0217ED38  arm  ov009
 *   func_0215F650  0x0215F650  arm  ov009
 *   func_0217EB18  0x0217EB18  arm  ov009
 *   func_0217EC08  0x0217EC08  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   g_021AEB04     0x021AEB04  data
 *   g_021A8234     0x021A8234  data
 *   func_0209477C  0x0209477C  arm
 *   func_02092344  0x02092344  arm
 *   g_021A8230  0x021A8230  data
 *   unit_02092344  0x02092344  arm
 *   rand  0x02094694  arm  ov009
 *   func_0217EC90  0x0217EC90  arm  ov009
 *   func_0219FAAC  0x0219FAAC  arm  ov009
 *   strlen  0x0209477C  arm
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0219F920  0x0219F920  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_0219F830  0x0219F830  arm  ov009
 *   func_0219DFC0  0x0219DFC0  arm  ov009
 *   func_0219D2F0  0x0219D2F0  arm  ov009
 *   func_0219F978  0x0219F978  arm  ov009
 *   func_0219E9AC  0x0219E9AC  arm  ov009
 *   func_0219E9B4  0x0219E9B4  arm  ov009
 *   func_0219E9C0  0x0219E9C0  arm  ov009
 *   func_0219E084  0x0219E084  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   func_0219E9D0  0x0219E9D0  arm  ov009
 *   func_0219E9C8  0x0219E9C8  arm  ov009
 *   memcmp  0x020923F0  arm
 *   func_0219E900  0x0219E900  arm  ov009
 *   func_0219E9D8  0x0219E9D8  arm  ov009
 *   func_0219F638  0x0219F638  arm  ov009
 *   g_021A8250  0x021A8250  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

struct SBQueryEngine;
struct SBServerList;
struct ServerBrowser;
struct GOACryptState;
typedef struct SBServer {
    unsigned int publicip;
    unsigned short publicport;
    unsigned int privateip;
    unsigned short privateport;
    unsigned int icmpip;
    unsigned char state;
    unsigned char flags;
    void *keyvals;
    unsigned int updatetime;
    unsigned int querychallenge;
    struct SBServer *next;
    unsigned char splitResponseBitmap;
} SBServer;

typedef struct SBServerFIFO {
    SBServer *first;
    SBServer *last;
    int count;
} SBServerFIFO;

typedef void (*SBEngineCB)(struct SBQueryEngine *engine, int reason, SBServer *server, void *instance);

typedef void (*SBListCB)(struct SBServerList *, int, SBServer *, void *);

typedef void (*SBMaploopCB)(struct SBServerList *slist, void *server, long changeTime, int count, char **mapList, void *instance);

typedef void (*SBPlayerSearchCB)(struct SBServerList *, char *, unsigned int, unsigned short, long, char *, void *);

typedef void (*SBBrowserCB)(struct ServerBrowser *, int, SBServer *, void *);

typedef struct SBQueryEngine {
    int queryversion;
    int maxupdates;
    SBServerFIFO querylist;
    SBServerFIFO pendinglist;
    int querysock;
    int icmpsock;
    unsigned int mypublicip;
    unsigned char serverkeys[40];
    int numserverkeys;
    SBEngineCB ListCallback;
    void *instance;
} SBQueryEngine;

typedef struct SBSortInfo {
    char sortkey[256];
    int comparemode;
} SBSortInfo;

typedef struct SBServerList {
    int state;
    void *servers;
    void *keylist;
    char queryforgamename[36];
    char queryfromgamename[36];
    char queryfromkey[32];
    char mychallenge[8];
    unsigned char *inbuffer;
    int inbufferlen;
    char *popularvalues[255];
    int numpopularvalues;
    int expectedelements;
    SBListCB ListCallback;
    SBMaploopCB MaploopCallback;
    SBPlayerSearchCB PlayerSearchCallback;
    void *instance;
    SBSortInfo currsortinfo;
    SBSortInfo prevsortinfo;
    int sortascending;
    unsigned int mypublicip;
    unsigned int srcip;
    unsigned short defaultport;
    char *lasterror;
    int slsocket;
    unsigned int lanstarttime;
    int fromgamever;
    char cryptkey[0x108];
    int queryoptions;
    int pstate;
    unsigned short backendgameflags;
    char *mLanAdapterOverride;
    SBServer *deadlist;
} SBServerList;

typedef struct ServerBrowser {
    SBQueryEngine engine;
    SBServerList list;
    int disconnectFlag;
    int dontUpdateList;
    unsigned int triggerIP;
    unsigned short triggerPort;
    SBBrowserCB BrowserCallback;
    void *ConnectCallback;
    void *instance;
} ServerBrowser;

struct G_021AEB04 {
    int pad;
    SBServerList *slist;
};

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
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

struct KeyEnt { int a; int type; };

typedef struct { unsigned char b[4]; } B4;

typedef struct { unsigned char b[2]; } B2;

typedef struct {
    char *keyName;
    int keyType;
} KeyInfo;

extern int func_0219FB64(char *s, int numbuckets);
extern u32 func_021803BC(char *dst, char *src, u32 size);
extern int func_02084F40(char *dst, char *fmt, ...);
extern u32 func_0217ED38(char *name);
extern SOCHostEnt *func_0215F650(char *name);
extern int func_0217EB18(int pf, int type, int protocol);
extern int func_0217EC08(int sock, void *addr, int len);
extern int func_0217EB2C(int sock);
extern int func_0209477C(const u8 *s);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern void *unit_02092344(void *dst, const void *src, unsigned long n);
extern int func_02094694(void);
extern int func_0217EC90(int sock, char *buf, int len, int flags);
extern void func_0219FAAC(SBServerList *slist);
extern void *func_0217EAB0(unsigned long size);
extern void func_0219F920(void *s, char *str);
extern int func_02184200(const int *p);
extern void *func_02184208(void *a, int n);
extern void func_021841B0(void *a);
extern void func_0217EAE0(void *p);
extern void func_0219F830(SBServerList *slist);
extern void func_0219DFC0(SBServerList *slist);
extern void func_0219D2F0(struct GOACryptState *state, unsigned char *key, unsigned char keysize);
extern int func_0219F978(const char *buf, int len);
extern void func_0219E9AC(SBServer *server, unsigned char flags);
extern void func_0219E9B4(SBServer *server, unsigned int ip, unsigned short port);
extern void func_0219E9C0(SBServer *server, unsigned int ip);
extern void func_0219E084(SBServer *server, char *keyname, int value);
extern void func_0219E01C(SBServer *server, char *keyname, char *value);
extern unsigned char func_0219E9D0(SBServer *server);
extern void func_0219E9C8(SBServer *server, unsigned char state);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern SBServer *func_0219E900(int unused, unsigned int publicip, unsigned short publicport);
extern int func_0219E9D8(int v);
extern void func_0219F638(SBServerList *slist, SBServer *server);
int func_0219FBB8(SBServerList *slist);
void func_0219FCF0(char **buffer, char *str, int *len);
/* * Stores a byte through the pointer in *p, then advances the pointer and the counter. */ void func_0219FD40(char **p, unsigned char v, int *n);
/* * sdk: BufferAddInt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219FD64(char **buffer, int ival, int *len);
/* * sdk: BufferAddIntLE (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219FDB8(char **buffer, int ival, int *len);
/* * sdk: BufferAddData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219FE10(char **buffer, char *data, int dlen, int *len);
/* * sdk: SetupListChallenge (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_0219FE44(SBServerList *slist);
int func_0219FF30(SBServerList *slist, char *data, int len);
SBError func_0219FFD4(SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers);
void func_021A0238(char *slist);
void func_021A027C(SBServerList *slist);
void func_021A02E0(SBServerList *slist);
/* * sdk: SBServerListCleanup (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_021A0340(SBServerList *slist);
/* * sdk: InitCryptKey (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o)) */ void func_021A0378(SBServerList *slist, char *key, int keylen);
/* * Maps the flag bits 2, 8, 0x10 and 0x20 to a size code starting at 5. */ int func_021A0414(int f);
int func_021A0440(const char *p, int n);
int func_021A04C4(SBServerList *slist, char *buf, int len);
void func_021A059C(SBServerList *slist, unsigned char *buf, int len, unsigned int *ip, unsigned short *port);
int func_021A060C(SBServerList *slist, SBServer *server, char *buf, int len, int usepopularlist);
int func_021A08E8(SBServerList *slist, char *buf, int len);
extern struct G_021AEB04 g_021AEB04;
extern char g_021A8234[];
extern char g_021A8230[];
extern char g_021A8250[];





/*
 * sdk:      ServerListConnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219FBB8(SBServerList *slist)
{
    SOCSockAddrIn saddr;
    SOCHostEnt *hent;
    char masterHostname[128];
    int masterIndex;

    masterIndex = func_0219FB64(slist->queryforgamename, 20);
    if ((*(char * *)&g_021AEB04))
        func_021803BC(masterHostname, (*(char * *)&g_021AEB04), 128);
    else
        func_02084F40(masterHostname, g_021A8234, slist->queryforgamename, masterIndex);
    saddr.family = 2;
    saddr.port = 0xEE70;
    saddr.addr = func_0217ED38(masterHostname);
    if (saddr.addr == (u32)-1) {
        hent = func_0215F650(masterHostname);
        if (!hent)
            return 2;
        memcpy(&saddr.addr, hent->addrList[0], 4);
    }
    if (slist->slsocket == -1) {
        slist->slsocket = func_0217EB18(2, 1, 0);
        if (slist->slsocket == -1)
            return 1;
    }
    if (func_0217EC08(slist->slsocket, &saddr, 8) == 0)
        return 0;
    func_0217EB2C(slist->slsocket);
    slist->slsocket = -1;
    return 3;
}





/*
 * sdk:      BufferAddNTS (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219FCF0(char **buffer, char *str, int *len)
{
	int slen;
	if (!str)
		str = g_021A8230;
	slen = func_0209477C((const u8 *)str) + 1;
	func_02092344(*buffer, str, slen);
	*len += slen;
	*buffer += slen;
}




#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))





/*
 * Stores a byte through the pointer in *p, then advances the pointer and the counter.
 */
void func_0219FD40(char **p, unsigned char v, int *n)
{
    **p = v;
    (*n)++;
    (*p)++;
}





/*
 * sdk:      BufferAddInt (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219FD64(char **buffer, int ival, int *len)
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
void func_0219FDB8(char **buffer, int ival, int *len)
{
	unsigned int ivalNBO;
	unsigned int ivalBE = 0;
	ivalNBO = SWAP32((unsigned int)ival);
	ivalBE |= ivalNBO << 24;
	ivalBE |= (ivalNBO & 0xff00) << 8;
	ivalBE |= (ivalNBO & 0xff0000) >> 8;
	ivalBE |= (ivalNBO & 0xff000000) >> 24;
	func_0219FD64(buffer, ivalBE, len);
}




#define LIST_CHALLENGE_LEN 8



#define CALCULATEODDMODE(buffer, i, oddmode) ((buffer[i-1] & 1) ^ (i & 1) ^ oddmode ^ (buffer[0] & 1) ^ ((buffer[0] < 79) ? 1 : 0) ^ ((buffer[i-1] < buffer[0]) ? 1 : 0))





/*
 * sdk:      BufferAddData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219FE10(char **buffer, char *data, int dlen, int *len)
{
    unit_02092344(*buffer, data, dlen);
    *len += dlen;
    *buffer += dlen;
}





/*
 * sdk:      SetupListChallenge (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219FE44(SBServerList *slist)
{
	int i;
	int oddmode;

	slist->mychallenge[0] = (char)(33 + func_02094694() % 93);	/* chars in the range 33 - 125 */
	oddmode = 0;
	for (i = 1; i < LIST_CHALLENGE_LEN; i++)
	{
		oddmode = CALCULATEODDMODE(slist->mychallenge, i, oddmode);
		slist->mychallenge[i] = (char)(33 + func_02094694() % 93);
		/* if oddmode make sure the char is odd, otherwise make sure it's even */
		if ((oddmode && (slist->mychallenge[i] & 1) == 0) || (!oddmode && ((slist->mychallenge[i] & 1) == 1)))
			slist->mychallenge[i]++;
	}
}


/*
 * sdk:      SendWithRetry (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219FF30(SBServerList *slist, char *data, int len)
{
	int err;
	int ret;
	int retryCount;
	retryCount = 1;
	do {
		retryCount--;
		ret = func_0217EC90(slist->slsocket, data, len, 0);
		if (ret > 0 || retryCount < 0 || slist->inbufferlen > 0)
			break;
		func_021A02E0(slist);
		err = func_0219FFD4((SBServerList *)slist, 0, 0, 2, 0);
		if (err != 0) {
			func_0219FAAC(slist);
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






#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))






SBError func_0219FFD4(SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers)
{
    SBError err;
    int ret;
    int requestLen;
    unsigned short netLen;
    char *requestBuf;
    char outgoingRequest[1023];

    if (fieldList == 0)
        fieldList = g_021A8230;
    if (serverFilter == 0)
        serverFilter = g_021A8230;
    if (strlen(fieldList) > 256)
        return sbe_paramerror;
    if (strlen(serverFilter) > 511)
        return sbe_paramerror;
    err = func_0219FBB8(slist);
    if (err != sbe_noerror)
        return err;
    slist->queryoptions = options;
    func_0219FE44(slist);
    requestLen = 2;
    requestBuf = outgoingRequest + 2;
    func_0219FD40(&requestBuf, 0, &requestLen);
    func_0219FD40(&requestBuf, 1, &requestLen);
    func_0219FD40(&requestBuf, 3, &requestLen);
    func_0219FDB8(&requestBuf, slist->fromgamever, &requestLen);
    func_0219FCF0(&requestBuf, slist->queryforgamename, &requestLen);
    func_0219FCF0(&requestBuf, slist->queryfromgamename, &requestLen);
    func_0219FE10(&requestBuf, slist->mychallenge, 8, &requestLen);
    func_0219FCF0(&requestBuf, serverFilter, &requestLen);
    func_0219FCF0(&requestBuf, fieldList, &requestLen);
    func_0219FD64(&requestBuf, SWAP32((unsigned int)options), &requestLen);
    if (slist->queryoptions & 8)
        func_0219FD64(&requestBuf, slist->srcip, &requestLen);
    if (slist->queryoptions & 0x80)
        func_0219FDB8(&requestBuf, maxServers, &requestLen);
    netLen = SWAP16((unsigned short)requestLen);
    memcpy(outgoingRequest, &netLen, 2);
    ret = func_0217EC90(slist->slsocket, outgoingRequest, requestLen, 0);
    if (ret <= 0) {
        func_021A02E0(slist);
        return sbe_connecterror;
    }
    slist->state = 3;
    slist->pstate = 0;
    if (slist->inbuffer == 0) {
        slist->inbuffer = func_0217EAB0(0x1000);
        if (slist->inbuffer == 0)
            return sbe_allocerror;
        slist->inbufferlen = 0;
    }
    return sbe_noerror;
}






/*
 * sdk:      FreePopularValues (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_021A0238(char *slist)
{
	int i;
	for (i = 0; i < *(int *)(slist + 0x480); i++)
		func_0219F920(slist, *(char **)(slist + 0x84 + i * 4));
	*(int *)(slist + 0x480) = 0;
}





/*
 * sdk:      FreeKeyList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_021A027C(SBServerList *slist)
{
	int i;
	if (slist->keylist == 0)
		return;
	for (i = 0; i < func_02184200(slist->keylist); i++)
		func_0219F920(slist, *(char **)func_02184208(slist->keylist, i));
	func_021841B0(slist->keylist);
	slist->keylist = 0;
}




/*
 * sdk:      SBServerListDisconnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_021A02E0(SBServerList *slist)
{
	if (slist->inbuffer != 0)
		func_0217EAE0(slist->inbuffer);
	slist->inbuffer = 0;
	slist->inbufferlen = 0;
	if (slist->slsocket != -1)
		func_0217EB2C(slist->slsocket);
	slist->slsocket = -1;
	slist->state = 1;
	func_021A027C(slist);
	slist->expectedelements = -1;
	func_021A0238((char *)slist);
}





/*
 * sdk:      SBServerListCleanup (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_021A0340(SBServerList *slist)
{
    func_021A02E0((SBServerList *)slist);
    func_0219F830((SBServerList *)slist);
    func_0219DFC0(slist);
    if (slist->servers != 0)
        func_021841B0(slist->servers);
    slist->servers = 0;
}




/*
 * sdk:      InitCryptKey (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_021A0378(SBServerList *slist, char *key, int keylen)
{
	int i;
	int seckeylen;
	char *seckey;
	seckeylen = func_0209477C((const u8 *)slist->queryfromkey);
	seckey = slist->queryfromkey;
	for (i = 0; i < keylen; i++)
		slist->mychallenge[(i * seckey[i % seckeylen]) % 8] ^= slist->mychallenge[i % 8] ^ key[i];
	func_0219D2F0((struct GOACryptState *)slist->cryptkey, (unsigned char *)slist->mychallenge, 8);
}




/*
 * Maps the flag bits 2, 8, 0x10 and 0x20 to a size code starting at 5.
 */
int func_021A0414(int f)
{
    int n = 5;

    if (f & 2) n += 4;
    if (f & 8) n += 4;
    if (f & 0x10) n += 2;
    if (f & 0x20) n += 2;
    return n;
}





/*
 * Walk a length-bounded string, two decode steps per turn: func_0219F978
 * reports how many bytes one unit occupies and a negative answer is a hard
 * failure (0).  Each successful step consumes that many bytes from the
 * pointer and the remaining count, in the order the image shows (the count
 * first on the first step, the pointer first on the second).  Leaving with
 * the count exhausted answers 0, leaving on a terminator answers 1.
 */
int func_021A0440(const char *p, int n)
{
    int k;

    while (n > 0 && *p != 0) {
        k = func_0219F978(p, n);
        if (k < 0)
            return 0;
        n -= k;
        p += k;
        k = func_0219F978(p, n);
        if (k < 0)
            return 0;
        p += k;
        n -= k;
    }
    if (n == 0)
        return 0;
    return *p == 0;
}





/*
 * sdk:      AllKeysPresent (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_021A04C4(SBServerList *slist, char *buf, int len)
{
	int numkeys;
	int i;
	int strindex;
	numkeys = func_02184200(slist->keylist);
	for (i = 0; i < numkeys; i++) {
		switch (((struct KeyEnt *)func_02184208(slist->keylist, i))->type) {
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
				strindex = func_0219F978(buf, len);
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
void func_021A059C(SBServerList *slist, unsigned char *buf, int len, unsigned int *ip, unsigned short *port)
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





#define ADVANCE(b, l) { int n = strlen(b) + 1; b += n; l -= n; }





/*
 * sdk:      ParseServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * The object calls strlen once per string skip and applies the result to buf and
 * len; ADVANCE spells that with a block-scoped temporary.
 */
int func_021A060C(SBServerList *slist, SBServer *server, char *buf, int len, int usepopularlist)
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
    func_0219E9AC(server, flags);
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
    func_0219E9B4(server, ip, port);
    if (flags & 8) {
        memcpy(&ip, buf, 4);
        buf += 4;
        len -= 4;
        func_0219E9C0(server, ip);
    }
    if (flags & 0x40) {
        numkeys = func_02184200(slist->keylist);
        for (i = 0; i < numkeys; i++) {
            ki = (KeyInfo *)func_02184208(slist->keylist, i);
            switch (ki->keyType) {
            case 1:
                func_0219E084(server, ki->keyName, (unsigned char)*buf++);
                len--;
                break;
            case 2:
                memcpy(&sval, buf, 2);
                func_0219E084(server, ki->keyName, SWAP16((unsigned short)sval));
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
                    func_0219E01C(server, ki->keyName, buf);
                    ADVANCE(buf, len);
                } else
                    func_0219E01C(server, ki->keyName, slist->popularvalues[strindex]);
                break;
            }
        }
        func_0219E9C8(server, func_0219E9D0(server) | 1);
    }
    if (flags & 0x80) {
        while (*buf && len > 0) {
            k = buf;
            ADVANCE(buf, len);
            func_0219E01C(server, k, buf);
            ADVANCE(buf, len);
        }
        len--;
        func_0219E9C8(server, func_0219E9D0(server) | 2);
    }
    state = func_0219E9D0(server);
    if (!(flags & 0xc0) && ((state & 1) || (state & 2)))
        func_0219E9C8(server, state & 0xfc);
    return holdlen - len;
}




/*
 * sdk:      IncomingListParseServer (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
int func_021A08E8(SBServerList *slist, char *buf, int len)
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
    i = func_021A0414(flags);
    if (len < i)
        return 0;
    if (flags & 0x40) {
        if (!func_021A04C4((SBServerList *)slist, buf + i, len - i))
            return 0;
    }
    if (flags & 0x80) {
        if (!func_021A0440(buf + i, len - i))
            return 0;
    }
    if (!memcmp(buf + 1, g_021A8250, 4))
        return -1;
    func_021A059C((SBServerList *)slist, (unsigned char *)buf, len, &ip, &port);
    server = func_0219E900((int)slist, ip, port);
    if (func_0219E9D8((int)server))
        return -2;
    ret = func_021A060C(slist, server, buf, len, 1);
    func_0219F638(slist, server);
    return ret;
}
