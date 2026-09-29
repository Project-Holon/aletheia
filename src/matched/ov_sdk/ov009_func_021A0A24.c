/*
 * function: func_021A0A24
 * address:  0x021A0A24
 * packet:   pkt_ov009_021A0A24
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessMainListData (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
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
 *
 * The object is stamped 4.0.0.1025; built with dsi/1.1p1.
 */

#define NULL ((void *)0)

#include "../arm9_sdk/libc/string.h"

typedef enum { sbe_noerror = 0, sbe_allocerror = 5 } SBError;

struct SBServer;

typedef struct _KeyInfo {
    char *keyName;
    int keyType;
} KeyInfo;

typedef struct _SBServerList {
    int state;                                  /* +0x000 */
    void *servers;                              /* +0x004 */
    void *keylist;                              /* +0x008 */
    char pad00C[0x7C - 0x0C];
    char *inbuffer;                             /* +0x07C */
    int inbufferlen;                            /* +0x080 */
    char *popularvalues[255];                   /* +0x084 */
    int numpopularvalues;                       /* +0x480 */
    int expectedelements;                       /* +0x484 */
    void (*ListCallback)(struct _SBServerList *, int, struct SBServer *, void *); /* +0x488 */
    void *MaploopCallback;                      /* +0x48C */
    void *PlayerSearchCallback;                 /* +0x490 */
    void *instance;                             /* +0x494 */
    char pad498[0x6A4 - 0x498];
    unsigned int mypublicip;                    /* +0x6A4 */
    unsigned int srcip;                         /* +0x6A8 */
    unsigned short defaultport;                 /* +0x6AC */
    char *lasterror;                            /* +0x6B0 */
    int slsocket;                               /* +0x6B4 */
    unsigned int lanstarttime;                  /* +0x6B8 */
    int fromgamever;                            /* +0x6BC */
    char cryptkey[0x7C8 - 0x6C0];               /* +0x6C0 */
    int queryoptions;                           /* +0x7C8 */
    int pstate;                                 /* +0x7CC */
    unsigned short backendgameflags;            /* +0x7D0 */
    char *mLanAdapterOverride;                  /* +0x7D4 */
    struct SBServer *deadlist;                  /* +0x7D8 */
} SBServerList;

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
extern struct SBServer *g_021AEB00;

#define NTOHS(x) ((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00))

SBError func_021A0A24(SBServerList *slist)
{
    int reqlen;
    int keyoffset;
    int keylen;
    char *inbuf = slist->inbuffer;
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
