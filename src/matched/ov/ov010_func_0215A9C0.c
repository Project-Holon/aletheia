/*
 * function: SCRCMD_WORK_MenuCursorCallback
 * address:  0x0215A9C0
 * packet:   pkt_ov010_0215A9C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENULIST_GetUserData  0x02020D0C  thumb
 *   BMP_MENULIST_GetListIndex  0x020202EC  thumb
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   SCRCMD_WORK_GetMsgWindow  0x0215A61C  thumb  ov010
 *   FIELD_MSGBG_ClearInfoSysWin  0x02191164  thumb  ov021
 *   FIELD_MSGBG_InfoSysWinPrintStrNow  0x02191184  thumb  ov021
 */
#include "../include/Obj00005.h"

typedef struct {
    char pad[0x20];
    int k[8];
} Q;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
struct P;
struct Q;
extern u32 BMP_MENULIST_GetUserData(u8 *p);
extern void BMP_MENULIST_GetListIndex(struct Obj *obj, u16 *out);
extern int SCRIPT_WORK_CheckFlag(int);
extern int SCRCMD_WORK_GetMsgWindow(int);
extern void FIELD_MSGBG_ClearInfoSysWin(struct P *p);
extern void FIELD_MSGBG_InfoSysWinPrintStrNow(struct Q *q, u32 b, int c, u32 d);

void SCRCMD_WORK_MenuCursorCallback(int a)
{
    unsigned short h = 0;
    int r = BMP_MENULIST_GetUserData((u8 *)a);
    Q *q = (Q *)(*(char * *)&((struct Obj00005 *)r)->f20 + 0x34);

    BMP_MENULIST_GetListIndex((struct Obj *)a, &h);
    if (q->k[h] != 0) {
        if (SCRIPT_WORK_CheckFlag(1) != 0) {
            int t = SCRCMD_WORK_GetMsgWindow(r);
            FIELD_MSGBG_ClearInfoSysWin((struct P *)t);
            FIELD_MSGBG_InfoSysWinPrintStrNow((struct Q *)t, 0, 0, q->k[h]);
        } else if (SCRIPT_WORK_CheckFlag(2) == 0) {
            SCRIPT_WORK_CheckFlag(3);
        }
    }
}
