/*
 * file:     unit_0219F0E0_p05.c
 * unit:     yes
 * function: func_0219F978, func_0219F9A8, func_0219FAAC
 * address:  0x0219F978
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
 *   func_0219F888  0x0219F888  arm  ov009
 *   func_0219DF64  0x0219DF64  arm  ov009
 *   func_021803BC  0x021803BC  arm  ov009
 *   func_021A0A1C  0x021A0A1C  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_020946C8  0x020946C8  arm
 *   func_0217F25C  0x0217F25C  arm  ov009
 *   g_021ACEF8  0x021ACEF8  data
 *   g_021A8230  0x021A8230  data
 *   func_0209477C  0x0209477C  arm
 *   func_020949F4  0x020949F4  arm
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   g_021A821C  0x021A821C  data
 *   g_021AEB00  0x021AEB00  data
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

struct SBL {
	char pad0[0x7c];
	char *errstr;
	int errlen;
	char pad1[0x488 - 0x84];
	void (*cb)(struct SBL *l, int type, void *s, void *ud);
	char pad2[0x494 - 0x48c];
	void *ud;
};

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_0219F888(SBServerList *slist);
extern void *func_0219DF64(SBServerList *slist);
extern int func_021803BC(char *dst, const char *src, unsigned int n);
extern void func_021A0A1C(int *p, int v);
extern unsigned int func_0217F264(void);
extern void func_020946C8(unsigned int seed);
extern void func_0217F25C(void);
extern int func_0209477C(const u8 *s);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void func_021A02E0(struct SBL *slist);
int func_0219F978(char *buf, int len);
void func_0219F9A8(SBServerList *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int lanBrowse, void (*callback)(SBServerList *, int, void *, void *), void *instance);
void func_0219FAAC(struct SBL *slist);
extern int g_021ACEF8;
extern volatile unsigned char g_021A8230[];
extern char *g_021A821C;
extern void *g_021AEB00;

/*
 * sdk:      NTSLengthSB (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
int func_0219F978(char *buf, int len)
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
void func_0219F9A8(SBServerList *slist, char *queryForGamename, char *queryFromGamename, char *queryFromKey,
                   int queryFromVersion, int lanBrowse, void (*callback)(SBServerList *, int, void *, void *),
                   void *instance)
{
    if (!lanBrowse && g_021ACEF8 != 1)
        return;
    slist->state = 1;
    func_0219F888(slist);
    func_0219DF64(slist);
    func_021803BC(slist->queryforgamename, queryForGamename, 36);
    func_021803BC(slist->queryfromgamename, queryFromGamename, 36);
    func_021803BC(slist->queryfromkey, queryFromKey, 32);
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
    slist->currsortinfo.sortkey[0] = g_021A8230[0];
    slist->prevsortinfo.sortkey[0] = g_021A8230[0];
    func_021A0A1C((int *)slist, (int)((char *)(unsigned char *)g_021A8230));
    slist->mLanAdapterOverride = 0;
    slist->backendgameflags = 0x80;
    func_020946C8(func_0217F264());
    func_0217F25C();
}

/*
 * sdk:      ErrorDisconnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_0219FAAC(struct SBL *slist)
{
	int len = slist->errlen;
	char *q;
	if (len > 0 && len > (unsigned int)func_0209477C((const u8 *)(q = g_021A821C))) {
		char *e = g_021A821C;
		char *s = slist->errstr;
		if (func_020949F4((const u8 *)s, (const u8 *)e, (unsigned int)func_0209477C((const u8 *)e)) == 0) {
			func_021A0A1C((int *)slist, (int)(s + (unsigned int)func_0209477C((const u8 *)q)));
			slist->cb(slist, 5, g_021AEB00, slist->ud);
		}
	}
	slist->cb(slist, 4, g_021AEB00, slist->ud);
	func_021A02E0(slist);
}
