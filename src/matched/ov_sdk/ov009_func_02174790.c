/*
 * function: DWCi_EvaluateServers
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
 *   ServerBrowserCount  0x0219F068  arm  ov009
 *   ServerBrowserGetServer  0x0219F058  arm  ov009
 *   SBServerGetIntValueA  0x0219E120  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID  0x021763AC  arm  ov009
 *   ServerBrowserRemoveServer  0x0219EFA8  arm  ov009
 *   DWCi_GetMathRand32  0x021685CC  arm  ov009
 *   func_0219E084  0x0219E084  arm  ov009
 *   ServerBrowserSortA  0x0219F078  arm  ov009
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
extern int ServerBrowserCount(void *sb);
extern void *ServerBrowserGetServer(void *sb, int index);
struct SBServer;
struct ServerBrowser;
extern int SBServerGetIntValueA(struct SBServer *server, char *key, int idefault);
extern char *DWCi_NodeInfoList_GetNodeInfoForProfileID(int pid);
extern void ServerBrowserRemoveServer(struct ServerBrowser *sb, struct SBServer *server);
extern unsigned long DWCi_GetMathRand32(unsigned long max);
extern void func_0219E084(void *server, char *keyname, int value);
extern void ServerBrowserSortA(struct ServerBrowser *sb, int ascending, char *sortkey, int comparemode);

static int DWCi_EvaluateServers(int sort)
{
    int eval;
    int deleteFlag = 0;
    int localDelete;
    int profileID;
    int i;
    void *server;

    for (i = 0; i < ServerBrowserCount(((DWCstMatchControl *)func_02175F3C())->sb); i++) {
        server = ServerBrowserGetServer(((DWCstMatchControl *)func_02175F3C())->sb, i);
        if (((DWCstMatchControl *)func_02175F3C())->qr2IsReserved == 0) {
            profileID = SBServerGetIntValueA(server, "dwc_pid", 0);
            localDelete = 0;
            if (DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID)) {
                ServerBrowserRemoveServer(((DWCstMatchControl *)func_02175F3C())->sb, server);
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
                func_0219E084(server, "dwc_eval", (eval << 8) | DWCi_GetMathRand32(0x100));
            } else {
                ServerBrowserRemoveServer(((DWCstMatchControl *)func_02175F3C())->sb, server);
                deleteFlag = 1;
                i--;
            }
        } else {
            func_0219E084(server, "dwc_eval", DWCi_GetMathRand32(0x80));
        }
    }
    if (sort && ServerBrowserCount(((DWCstMatchControl *)func_02175F3C())->sb))
        ServerBrowserSortA(((DWCstMatchControl *)func_02175F3C())->sb, 0, "dwc_eval", 0);
    if (deleteFlag && ServerBrowserCount(((DWCstMatchControl *)func_02175F3C())->sb) == 0)
        return 0;
    return 1;
}
