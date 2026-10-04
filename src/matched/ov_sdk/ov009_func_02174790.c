/*
 * function: func_02174790
 * address:  0x02174790
 * packet:   pkt_ov009_02174790
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_EvaluateServers (libdwcmatch.TWL.HYB.a(dwc_match.o))
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
 *   @24222         0x021A20A4  data
 *   @26585         0x021A21BC  data
 */

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

extern int func_02175F3C(void);
extern int func_0219F068(void *sb);
extern void *func_0219F058(void *sb, int index);
struct SBServer;
struct ServerBrowser;
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern char *func_021763AC(int pid);
extern void func_0219EFA8(struct ServerBrowser *sb, struct SBServer *server);
extern unsigned long func_021685CC(unsigned long max);
extern void func_0219E084(void *server, char *keyname, int value);
extern void func_0219F078(struct ServerBrowser *sb, int ascending, char *sortkey, int comparemode);

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
            profileID = func_0219E120(server, "dwc_pid", 0);
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
                func_0219E084(server, "dwc_eval", (eval << 8) | func_021685CC(0x100));
            } else {
                func_0219EFA8(((DWCstMatchControl *)func_02175F3C())->sb, server);
                deleteFlag = 1;
                i--;
            }
        } else {
            func_0219E084(server, "dwc_eval", func_021685CC(0x80));
        }
    }
    if (sort && func_0219F068(((DWCstMatchControl *)func_02175F3C())->sb))
        func_0219F078(((DWCstMatchControl *)func_02175F3C())->sb, 0, "dwc_eval", 0);
    if (deleteFlag && func_0219F068(((DWCstMatchControl *)func_02175F3C())->sb) == 0)
        return 0;
    return 1;
}
