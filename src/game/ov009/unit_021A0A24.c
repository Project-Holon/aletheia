/*
 * file:     unit_021A0A24.c
 * unit:     yes
 * function: func_021A0A24, func_021A0E30, func_021A0F0C, func_021A10D4, func_021A1254, func_021A12DC, func_021A13D0, func_021A153C, func_021A1620, func_021A174C, func_021A1804
 * address:  0x021A0A24
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
 *   func_021A0378  0x021A0378  arm  ov009
 *   func_0219D478  0x0219D478  arm  ov009
 *   func_0219F978  0x0219F978  arm  ov009
 *   func_021A0A1C  0x021A0A1C  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_02184200  0x02184200  arm  ov009
 *   func_0219F8B0  0x0219F8B0  arm  ov009
 *   func_02184234  0x02184234  arm  ov009
 *   func_021A08E8  0x021A08E8  arm  ov009
 *   func_02092364  0x02092364  arm
 *   g_021AEB00  0x021AEB00  data
 *   func_021A027C  0x021A027C  arm  ov009
 *   func_0219F6C8  0x0219F6C8  arm  ov009
 *   func_0219F7C4  0x0219F7C4  arm  ov009
 *   func_0219F768                  0x0219F768  arm ov009
 *   func_021A059C  0x021A059C  arm  ov009
 *   func_0219E900  0x0219E900  arm  ov009
 *   func_0219E9D8  0x0219E9D8  arm  ov009
 *   func_021A060C  0x021A060C  arm  ov009
 *   func_0219F638  0x0219F638  arm  ov009
 *   func_0217EC90  0x0217EC90  arm  ov009
 *   memmove        0x02092364  arm
 *   func_0219FAAC  0x0219FAAC  arm  ov009
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC4C  0x0217EC4C  arm  ov009
 *   func_0219FFD4  0x0219FFD4  arm  ov009
 *   func_0219FF30  0x0219FF30  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   func_0219E9AC  0x0219E9AC  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
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

typedef struct _KeyInfo {
    char *keyName;
    int keyType;
} KeyInfo;

struct KeyInfo { char *name; int type; };

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef void (*SBMapLoopCallback)(SBServerList *slist, void *server, long changeTime, int count, char **mapList, void *instance);

typedef struct {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

extern void func_021A0378(SBServerList *slist, char *key, int keylen);
extern void func_0219D478(void *state, unsigned char *bp, int len);
extern int func_0219F978(char *buf, int len);
extern void func_021A0A1C(SBServerList *slist, char *theError);
extern void *func_02184144(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern int func_02184200(void *array);
extern char *func_0219F8B0(SBServerList *slist, char *str);
extern void func_02184234(void *array, void *newElem);
extern int func_021A08E8(SBServerList *slist, char *buf, int len);
extern void *func_02092364(void *dst, const void *src, unsigned int n);
extern void func_021A027C(SBServerList *slist);
extern int func_0219F6C8(SBServerList *slist, u32 ip, u16 port);
extern void *func_0219F7C4(SBServerList *slist, int i);
extern void func_0219F768(SBServerList *slist, int index);
extern void func_021A059C(SBServerList *slist, unsigned char *buf, int len, unsigned int *ip, unsigned short *port);
extern SBServer *func_0219E900(int unused, unsigned int publicip, unsigned short publicport);
extern int func_0219E9D8(int v);
extern int func_021A060C(SBServerList *slist, void *server, char *buf, int len, int usepopularlist);
extern void func_0219F638(SBServerList *slist, SBServer *server);
extern int func_0217EC90(int sock, char *buffer, int bufferLen, int flags);
extern void *memmove(void *dst, const void *src, unsigned long n);
extern void func_0219FAAC(SBServerList *slist);
extern int func_0217EF50(int sock);
extern int func_0217EC4C(int sock, char *buf, int len, int flags);
extern int func_0219FFD4(SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers);
extern int func_0219FF30(SBServerList *slist, char *data, int len);
extern int func_0217EC60(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
extern void func_0219E9AC(unsigned char *p, unsigned char v);
extern unsigned int func_0217F264(void);
extern int func_0217EB2C(int sock);
SBError func_021A0A24(SBServerList *slist);
int func_021A0E30(SBServerList *slist, char *buf, int len);
int func_021A0F0C(SBServerList *slist, char *buf, int len);
int func_021A10D4(SBServerList *slist, char *buf, int len);
SBError func_021A1254(SBServerList *slist, char *buf, int len);
int func_021A12DC(SBServerList *slist, char *buf, int len);
int func_021A13D0(SBServerList *slist);
int func_021A153C(SBServerList *slist);
int func_021A1620(SBServerList *slist, unsigned int ip, unsigned short port, char *data, int len);
int func_021A174C(void *slist, unsigned int ip, unsigned short port, int cookie);
int func_021A1804(SBServerList *slist);
extern SBServer *g_021AEB00;




#define NULL ((void *)0)



#define NTOHS(x) ((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00))



/*
 * sdk:      ProcessMainListData (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * The object is stamped 4.0.0.1025; built with dsi/1.1p1.
 */
SBError func_021A0A24(SBServerList *slist)
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
        func_021A0378(slist, inbuf + keyoffset, keylen);
        slist->pstate = 1;
        memcpy(&slist->backendgameflags, inbuf + 1, 2);
        slist->backendgameflags = NTOHS(slist->backendgameflags);
        inbuf += reqlen;
        inlen -= reqlen;
        func_0219D478(slist->cryptkey, (unsigned char *)inbuf, inlen);
    case 1:
        if (inlen < 6)
            break;
        memcpy(&slist->mypublicip, inbuf, 4);
        slist->ListCallback(slist, 6, g_021AEB00, slist->instance);
        memcpy(&slist->defaultport, inbuf + 4, 2);
        if (slist->defaultport == 0xFFFF) {
            int keylen = func_0219F978(inbuf + 6, inlen - 6);
            if (keylen == -1)
                break;
            func_021A0A1C(slist, inbuf + 6);
            slist->ListCallback(slist, 5, g_021AEB00, slist->instance);
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
            slist->keylist = func_02184144(sizeof(KeyInfo), slist->expectedelements, NULL);
            if (slist->keylist == NULL)
                return sbe_allocerror;
            inbuf++;
            inlen--;
        }
        while (slist->expectedelements > func_02184200(slist->keylist)) {
            int keylen;
            if (inlen < 2)
                break;
            keylen = func_0219F978(inbuf + 1, inlen - 1);
            if (keylen == -1)
                break;
            ki.keyType = (unsigned char)*inbuf;
            ki.keyName = func_0219F8B0(slist, inbuf + 1);
            func_02184234(slist->keylist, &ki);
            inbuf += keylen + 1;
            inlen -= keylen + 1;
        }
        if (slist->expectedelements > func_02184200(slist->keylist))
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
            int keylen = func_0219F978(inbuf, inlen);
            if (keylen == -1)
                break;
            slist->popularvalues[slist->numpopularvalues++] = func_0219F8B0(slist, inbuf);
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
            keylen = func_021A08E8(slist, inbuf, inlen);
            if (keylen == -2)
                return sbe_allocerror;
            if (keylen == -1) {
                slist->state = 2;
                slist->pstate = 5;
                inlen -= 5;
                inbuf += 5;
                slist->ListCallback(slist, 3, g_021AEB00, slist->instance);
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
        func_02092364(slist->inbuffer, inbuf, inlen);
    slist->inbufferlen = inlen;
    return sbe_noerror;
}




/*
 * sdk:      ProcessPushKeyList (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_021A0E30(SBServerList *slist, char *buf, int len)
{
	int i;
	int numkeys;
	int keylen;
	struct KeyInfo ki;
	numkeys = (unsigned char)*buf++;
	len--;
	if (slist->keylist != 0)
		func_021A027C(slist);
	slist->keylist = func_02184144(8, numkeys, 0);
	if (slist->keylist == 0)
		return 5;
	for (i = 0; i < numkeys; i++) {
		if (len < 2)
			return 4;
		keylen = func_0219F978(buf + 1, len - 1);
		if (keylen == -1)
			return 4;
		ki.type = (unsigned char)buf[0];
		ki.name = func_0219F8B0(slist, buf + 1);
		func_02184234(slist->keylist, &ki);
		buf += keylen + 1;
		len -= keylen + 1;
	}
	return 0;
}




#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))




/*
 * sdk:      ProcessPlayerSearch (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_021A0F0C(SBServerList *slist, char *buf, int len)
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
        slen = func_0219F978(buf, len);
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
        slen = func_0219F978(buf, len);
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
int func_021A10D4(SBServerList *slist, char *buf, int len)
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
    i = func_0219F6C8(slist, ip, port);
    if (i == -1)
        return 0;
    server = func_0219F7C4(slist, i);
    memcpy(&changeTime, &buf[6], 4);
    changeTime = (((u32)changeTime >> 24) & 0xFF) | (((u32)changeTime >> 8) & 0xFF00) | (((u32)changeTime << 8) & 0xFF0000) | (((u32)changeTime << 24) & 0xFF000000);
    mapCount = buf[10];
    buf += 11;
    len -= 11;
    for (i = 0; i < mapCount && i < 16; i++) {
        if (len < 1)
            break;
        maplen = func_0219F978(buf, len);
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
SBError func_021A1254(SBServerList *slist, char *buf, int len)
{
    int i;
    unsigned short port;
    unsigned int ip;

    if (len < 6)
        return sbe_dataerror;
    memcpy(&ip, buf, 4);
    memcpy(&port, buf + 4, 2);
    i = func_0219F6C8(slist, ip, port);
    if (i == -1)
        return sbe_noerror;
    func_0219F768(slist, i);
    return sbe_noerror;
}





/*
 * sdk:      ProcessPushServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_021A12DC(SBServerList *slist, char *buf, int len)
{
	void *server;
	unsigned int ip;
	unsigned short port;
	int foundexisting;
	int i;
	if (len < 5)
		return 4;
	func_021A059C(slist, (unsigned char *)buf, len, &ip, &port);
	foundexisting = func_0219F6C8(slist, ip, port);
	if (foundexisting == -1) {
		server = func_0219E900((int)slist, ip, port);
		if (func_0219E9D8((int)server))
			return 5;
	} else {
		server = func_0219F7C4(slist, foundexisting);
	}
	if (func_021A060C(slist, server, buf, len, 0) < 0)
		return 4;
	if (foundexisting == -1)
		func_0219F638((SBServerList *)slist, server);
	slist->ListCallback(slist, 1, server, slist->instance);
	return 0;
}






/*
 * sdk:      ProcessAdHocData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_021A13D0(SBServerList *slist)
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
            ret = func_021A0E30((SBServerList *)slist, (char *)(slist->inbuffer + 3), msglen - 3);
            break;
        case 2:
            ret = func_021A12DC((SBServerList *)slist, (char *)(slist->inbuffer + 3), msglen - 3);
            break;
        case 3:
            if (func_0217EC90(slist->slsocket, (char *)slist->inbuffer, msglen, 0) <= 0)
                return 3;
            break;
        case 4:
            ret = func_021A1254((SBServerList *)slist, (char *)(slist->inbuffer + 3), msglen - 3);
            break;
        case 5:
            ret = func_021A10D4(slist, (char *)(slist->inbuffer + 3), msglen - 3);
            break;
        case 6:
            ret = func_021A0F0C(slist, (char *)(slist->inbuffer + 3), msglen - 3);
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
        func_0219FAAC((SBServerList *)slist);
    return ret;
}





int func_021A153C(SBServerList *slist)
{
	int err;
	int len;
	int oldlen;
	if (!func_0217EF50(slist->slsocket))
		return 0;
	oldlen = slist->inbufferlen;
	err = 0;
	len = func_0217EC4C(slist->slsocket, (char *)(slist->inbuffer + oldlen), 0x1000 - oldlen, 0);
	if (len == -1 || len == 0) {
		func_0219FAAC(slist);
		return 3;
	}
	slist->inbufferlen += len;
	if (slist->state == 2 || slist->pstate > 0)
		func_0219D478((struct GOACryptState *)slist->cryptkey, (unsigned char *)(slist->inbuffer + oldlen), slist->inbufferlen - oldlen);
	if (slist->state == 3)
		err = func_021A0A24((SBServerList *)slist);
	if (err != 0)
		return err;
	if (slist->state == 2 && slist->inbufferlen > 0)
		return func_021A13D0(slist);
	return 0;
}





#define HTONS(x) ((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00))





/*
 * sdk:      SBSendMessageToServer (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
int func_021A1620(SBServerList *slist, unsigned int ip, unsigned short port, char *data, int len)
{
    int i;
    int ret;
    unsigned short tmp;
    char requestBuffer[16];

    if (slist->state == 1)
        func_0219FFD4(slist, 0, 0, 2, 0);
    if (slist->state == 1)
        return 3;
    tmp = HTONS((unsigned short)(len + 9));
    memcpy(&requestBuffer[0], &tmp, 2);
    requestBuffer[2] = 2;
    memcpy(&requestBuffer[3], &ip, 4);
    memcpy(&requestBuffer[7], &port, 2);
    i = func_0219FF30(slist, requestBuffer, 9);
    if (i != 0)
        return i;
    ret = 0;
    i = func_0217EC90(slist->slsocket, data, len, 0);
    if (i < 0)
        ret = 3;
    return ret;
}





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





/*
 * SBSendNatNegotiateCookieToServer: fills a 10-byte natneg cookie packet
 * (6 magic bytes + the big-endian cookie) and hands it to SBSendMessageToServer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_021A174C.c \
 *       --func func_021A174C --addr 0x021A174C --region ov009 --arm --cc 1.1p1 --lang c99 --diff
 */
int func_021A174C(void *slist, unsigned int ip, unsigned short port, int cookie)
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
	return func_021A1620(slist, ip, port, (char *)negotiateBuffer, NATNEG_MAGIC_LEN + 4);
}



/*
 * sdk:      ProcessLanData (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 */
int func_021A1804(SBServerList *slist)
{
    char indata[1500];
    SOCSockAddrIn saddr;
    int saddrlen;
    int error;
    int foundexisting;
    SBServer *server;

    saddrlen = 8;
    while (func_0217EF50(slist->slsocket)) {
        error = func_0217EC60(slist->slsocket, indata, 1499, 0, &saddr, &saddrlen);
        if (error == -1)
            continue;
        foundexisting = func_0219F6C8((SBServerList *)slist, saddr.addr, saddr.port);
        if (foundexisting != -1)
            continue;
        server = func_0219E900((int)slist, saddr.addr, saddr.port);
        if (func_0219E9D8((int)server))
            return 5;
        func_0219E9AC((unsigned char *)server, 0x11);
        func_0219F638(slist, server);
    }
    if (func_0217F264() - slist->lanstarttime > 2000) {
        func_0217EB2C(slist->slsocket);
        slist->slsocket = -1;
        slist->state = 1;
        slist->ListCallback(slist, 3, g_021AEB00, slist->instance);
    }
    return 0;
}
