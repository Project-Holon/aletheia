/*
 * file:     dwc_match_5.c
 * unit:     yes
 * function: func_02174790, func_02174930, func_02174AA0
 * address:  0x02174790
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
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0219F068  0x0219F068  arm  ov009
 *   func_0219F058  0x0219F058  arm  ov009
 *   func_0219E120  0x0219E120  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 *   func_0219EFA8  0x0219EFA8  arm  ov009
 *   func_021685CC  0x021685CC  arm  ov009
 *   func_0219E084  0x0219E084  arm  ov009
 *   func_0219F078  0x0219F078  arm  ov009
 *   d_021A20A4     0x021A20A4  data
 *   _s32_div_f     0x0209C0A4 arm
 *   g_021A19C0     0x021A19C0 data
 *   g_021A21BC     0x021A21BC data
 *   func_0217603C  0x0217603C arm   ov009
 *   func_0219B628  0x0219B628 arm   ov009
 *   func_02175FB8  0x02175FB8 arm   ov009
 *   func_0219B660  0x0219B660 arm   ov009
 *   g_021AAA40     0x021AAA40 data
 *   g_021AAA41     0x021AAA41 data
 *   g_021AAA48     0x021AAA48 data
 */
struct SBServer;
struct ServerBrowser;
typedef unsigned char u8;

typedef struct DWCstMatchControl {
    char pad0[0x15];
    u8 qr2IsReserved;                           /* +0x015 */
    char pad16[0x5e0 - 0x16];
    void *sb;                                   /* +0x5e0 */
    char pad5e4[0x780 - 0x5e4];
    int (*evalCallback)(int index, void *param);/* +0x780 */
    void *evalParam;                            /* +0x784 */
} DWCstMatchControl;

struct DWCstMatchControl_02174930 {
    char pad0[0x5e0];
    void *sb;
};

struct DWCstMatchControl_02174AA0 {
    char pad0[0x15];
    unsigned char f15;
    unsigned char f16;
    unsigned char f17;
    char pad18[0x10];
    int f28;
    char pad2c[0x678 - 0x2c];
    int f678;
    char pad67c[0x790 - 0x67c];
    int f790;
};

struct gamekey_s {
    unsigned char keyID;
    unsigned char isStr;
    unsigned short pad;
    char *keyStr;
    void *value;
};

extern int func_02175F3C(void);
extern int func_0219F068(void *sb);
extern void *func_0219F058(void *sb, int index);
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern char *func_021763AC(int pid);
extern void func_0219EFA8(struct ServerBrowser *sb, struct SBServer *server);
extern unsigned long func_021685CC(unsigned long max);
extern void func_0219E084(void *server, char *keyname, int value);
extern void func_0219F078(struct ServerBrowser *sb, int ascending, char *sortkey, int comparemode);
extern int func_0217603C(void);
extern int func_0219B628(void *outbuf, int value);
extern unsigned char func_02175FB8(void);
extern int func_0219B660(void *outbuf, char *value);
void func_02174930(void);
void func_02174AA0(int keyid, void *outbuf);
extern int g_021A19C0[6];
extern char g_021A21BC[];
extern char d_021A20A4[];      /* dwc_pid: dwc_match_3.c uses it too (one dwc_match.o) */
extern struct gamekey_s g_021AAA40[154];


/*
 * sdk:      DWCi_EvaluateServers (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
static int func_02174790(int sort)
{
    int eval;
    int deleteFlag = 0;
    int localDelete;
    int profileID;
    int i;
    void *server;

    for (i = 0; i < func_0219F068(((DWCstMatchControl *)func_02175F3C())->sb); i++) {
        server = func_0219F058(((DWCstMatchControl *)func_02175F3C())->sb, i);
        if (((DWCstMatchControl *)func_02175F3C())->qr2IsReserved == 0) {
            profileID = func_0219E120(server, d_021A20A4, 0);
            localDelete = 0;
            if (func_021763AC(profileID)) {
                func_0219EFA8(((DWCstMatchControl *)func_02175F3C())->sb, server);
                i--;
                localDelete = 1;
            }
            if (localDelete)
                continue;
        }
        if (((DWCstMatchControl *)func_02175F3C())->evalCallback) {
            eval = ((DWCstMatchControl *)func_02175F3C())->evalCallback(i, ((DWCstMatchControl *)func_02175F3C())->evalParam);
            if (eval > 0) {
                if (eval > 0x7fffff)
                    eval = 0x7fffff;
                func_0219E084(server, g_021A21BC, (eval << 8) | func_021685CC(0x100));
            } else {
                func_0219EFA8(((DWCstMatchControl *)func_02175F3C())->sb, server);
                deleteFlag = 1;
                i--;
            }
        } else {
            func_0219E084(server, g_021A21BC, func_021685CC(0x80));
        }
    }
    if (sort && func_0219F068(((DWCstMatchControl *)func_02175F3C())->sb))
        func_0219F078(((DWCstMatchControl *)func_02175F3C())->sb, 0, g_021A21BC, 0);
    if (deleteFlag && func_0219F068(((DWCstMatchControl *)func_02175F3C())->sb) == 0)
        return 0;
    return 1;
}


/*
 * sdk:      DWCi_RandomizeServers (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void func_02174930(void)
{
    unsigned long rand;
    int tmpEval;
    int maxEval;
    int sum;
    int i;
    unsigned long eval[6];
    void *server;

    maxEval = 0;
    sum = 0;
    if (func_0219F068(((struct DWCstMatchControl_02174930 *)func_02175F3C())->sb) <= 1)
        return;
    for (i = 0; i < func_0219F068(((struct DWCstMatchControl_02174930 *)func_02175F3C())->sb); i++) {
        server = func_0219F058(((struct DWCstMatchControl_02174930 *)func_02175F3C())->sb, i);
        tmpEval = func_0219E120(server, g_021A21BC, -1);
        if (tmpEval > maxEval)
            maxEval = tmpEval;
        sum += g_021A19C0[i];
    }
    rand = func_021685CC(100);
    for (i = 0; i < func_0219F068(((struct DWCstMatchControl_02174930 *)func_02175F3C())->sb); i++) {
        unsigned long prev;
        if (i == func_0219F068(((struct DWCstMatchControl_02174930 *)func_02175F3C())->sb) - 1)
            break;
        prev = (i > 0) ? eval[i - 1] : 0;
        tmpEval = g_021A19C0[i] * 100 / sum;
        tmpEval += prev;
        eval[i] = tmpEval;
        if (rand < tmpEval)
            break;
    }
    if (maxEval < 0x7fffffff)
        maxEval++;
    server = func_0219F058(((struct DWCstMatchControl_02174930 *)func_02175F3C())->sb, i);
    func_0219E084(server, g_021A21BC, maxEval);
    func_0219F078(((struct DWCstMatchControl_02174930 *)func_02175F3C())->sb, 0, g_021A21BC, 0);
}


/*
 * sdk:      DWCi_QR2ServerKeyCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void func_02174AA0(int keyid, void *outbuf)
{
    int suspendMatch;
    int numPlayers;
    int index;

    switch (keyid) {
    case 8:
        numPlayers = func_0217603C() - 1;
        if (numPlayers < 0)
            numPlayers = 0;
        func_0219B628(outbuf, numPlayers);
        return;
    case 10:
        func_0219B628(outbuf, ((struct DWCstMatchControl_02174AA0 *)func_02175F3C())->f17);
        return;
    case 50:
        func_0219B628(outbuf, ((struct DWCstMatchControl_02174AA0 *)func_02175F3C())->f678);
        return;
    case 51:
        func_0219B628(outbuf, ((struct DWCstMatchControl_02174AA0 *)func_02175F3C())->f15);
        return;
    case 52:
        func_0219B628(outbuf, 90);
        return;
    case 53:
        func_0219B628(outbuf, 1);
        return;
    case 54:
        if (func_02175FB8() == 2)
            suspendMatch = ((struct DWCstMatchControl_02174AA0 *)func_02175F3C())->f790;
        else
            suspendMatch = 0;
        func_0219B628(outbuf, suspendMatch);
        return;
    case 55:
        func_0219B628(outbuf, ((struct DWCstMatchControl_02174AA0 *)func_02175F3C())->f16);
        return;
    case 56:
        func_0219B628(outbuf, ((struct DWCstMatchControl_02174AA0 *)func_02175F3C())->f28);
        return;
    }
    index = keyid - 100;
    if (index < 0 || index >= 154)
        return;
    if (g_021AAA40[index].keyID == 0)
        return;
    if (g_021AAA40[index].isStr != 0)
        func_0219B660(outbuf, (char *)g_021AAA40[index].value);
    else
        func_0219B628(outbuf, *(int *)g_021AAA40[index].value);
}
