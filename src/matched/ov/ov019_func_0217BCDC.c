/*
 * function: UNION_ONESELF_ErrorMain
 * address:  0x0217BCDC
 * packet:   pkt_ov019_0217BCDC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   UNION_ONESELF_SetFieldBusy  0x0217BAF0  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   UNION_MSG_CloseAllWindows  0x0217F074  thumb  ov019
 *   func_0200FB24  0x0200FB24  thumb
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   UNION_COMM_RequestShutdown  0x02172D38  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   UNION_COMM_ReleaseWorks  0x02173420  thumb  ov012
 *   UNION_COMM_InitConnectInfo  0x02173524  thumb  ov012
 *   UNION_COMM_RequestStart  0x02172D50  thumb  ov012
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 */

typedef unsigned char u8;

extern void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
extern unsigned int UNION_MSG_CheckTalkPrintEnd(u8 *p);
typedef unsigned int   u32;
extern void UNION_MSG_CloseAllWindows(void *p);
extern u32 func_0200FB24(void);
struct Ctx;
extern void GAMESYSTEM_SetFieldMapState(struct Ctx *p, u32 v);
extern void UNION_COMM_RequestShutdown(u8 *p);
extern int UNION_COMM_IsResetting(u8 *p);
extern void UNION_COMM_ReleaseWorks(int *a);
extern void UNION_COMM_InitConnectInfo(int *a, u8 *b);
extern void UNION_COMM_RequestStart(u8 *p);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);

int UNION_ONESELF_ErrorMain(int *a, u8 *b, int c, u8 *d)
{
    switch (*d) {
    case 0:
        UNION_ONESELF_SetFieldBusy((char *)a, c, 1);
        (*d)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd((u8 *)a) == 1) {
            UNION_MSG_CloseAllWindows(a);
            (*d)++;
        }
        break;
    case 2:
        if (func_0200FB24() != 0) {
            GAMESYSTEM_SetFieldMapState((struct Ctx *)(*(int *)(a[0] + 0xc)), 1);
            return 0;
        }
        UNION_COMM_RequestShutdown((u8 *)a);
        (*d)++;
        break;
    case 3:
        if (UNION_COMM_IsResetting((u8 *)a) == 0)
            (*d)++;
        break;
    case 4:
        UNION_COMM_ReleaseWorks(a);
        UNION_COMM_InitConnectInfo(a, b + 0x14);
        UNION_COMM_RequestStart((u8 *)a);
        (*d)++;
        break;
    case 5:
        if (UNION_COMM_IsResetting((u8 *)a) == 0)
            (*d)++;
        break;
    default:
        UNION_ONESELF_SetNextPlayCategory((char *)a, 0);
        return 1;
    }
    return 0;
}
