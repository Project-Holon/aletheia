/*
 * function: UNION_MSG_SetupTitleWindow
 * address:  0x0217F5E0
 * packet:   pkt_ov019_0217F5E0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreatePlainWin  0x02191558  thumb  ov021
 *   FIELD_MSGBG_PlainWinPrintMsg  0x0219161C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00033.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Fx;
struct R;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern struct R *FIELD_MSGBG_CreatePlainWin(struct Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
extern void FIELD_MSGBG_PlainWinPrintMsg(struct R *r, int b, int c, u32 d);

void UNION_MSG_SetupTitleWindow(char *p, u32 a1)
{
    if (*(u32 *)&((struct Obj00033 *)p)->f2818 == 0) {
        u32 x = (u32)FIELD_MSGBG_CreatePlainWin((struct Fx *)FIELDMAP_GetMsgBg((u8 *)a1), *(u32 *)&((struct Obj00033 *)p)->f2808, 0, 1, 1, 0x1e, 2);
        *(u32 *)&((struct Obj00033 *)p)->f2818 = x;
        FIELD_MSGBG_PlainWinPrintMsg((struct R *)x, 0, 0, 0x103);
    }
}
