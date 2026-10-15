/*
 * function: SBServerListInit
 * address:  0x0219F9A8
 * packet:   pkt_ov009_0219F9A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListInit (libdwcgsserverbrowsing.TWL.HYB.a sb_serverlist.o)
 *
 * symbols:
 *   SBAllocateServerList  0x0219F888  arm  ov009
 *   func_0219DF64  0x0219DF64  arm  ov009
 *   gsiSafeStrcpyA  0x021803BC  arm  ov009
 *   SBServerListSetLastError  0x021A0A1C  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   srand  0x020946C8  arm
 *   SocketStartUp  0x0217F25C  arm  ov009
 *   gGsAvailabilityState  0x021ACEF8  data
 *   gSBEmptyString  0x021A8230  data
 */

typedef struct {
    unsigned char sortkey[256];
    int pad100;
} SBSortInfo;
typedef struct SBServerList {
    int state;
    void *servers;
    void *keylist;
    char queryforgamename[36];
    char queryfromgamename[36];
    char queryfromkey[32];
    char mychallenge[8];
    char *inbuffer;
    int inbufferlen;
    char *popularvalues[255];
    int numpopularvalues;
    int expectedelements;
    void (*ListCallback)(struct SBServerList *, int, void *, void *);
    void (*MaploopCallback)(void);
    void (*PlayerSearchCallback)(void);
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
    void *deadlist;
} SBServerList;

extern void SBAllocateServerList(SBServerList *slist);
extern void *func_0219DF64(SBServerList *slist);
extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
extern void SBServerListSetLastError(int *p, int v);
extern unsigned int current_time(void);
extern void srand(unsigned int seed);
extern void SocketStartUp(void);
extern int gGsAvailabilityState;
extern volatile unsigned char gSBEmptyString[];


void SBServerListInit(SBServerList *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                   int queryFromVersion, int lanBrowse, void (*callback)(SBServerList *, int, void *, void *),
                   void *instance)
{
    if (!lanBrowse && gGsAvailabilityState != 1)
        return;
    slist->state = 1;
    SBAllocateServerList(slist);
    func_0219DF64(slist);
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
    slist->currsortinfo.sortkey[0] = gSBEmptyString[0];
    slist->prevsortinfo.sortkey[0] = gSBEmptyString[0];
    SBServerListSetLastError((int *)slist, (int)((char *)(unsigned char *)gSBEmptyString));
    slist->mLanAdapterOverride = 0;
    slist->backendgameflags = 0x80;
    srand(current_time());
    SocketStartUp();
}
