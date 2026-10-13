/*
 * function: FIELD_MSGBG_SetupSubMsgWin
 * address:  0x021917C4
 * packet:   pkt_ov021_021917C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MSGBG_LoadMenuGraphicsUpper  0x02193170  thumb  ov021
 *   FIELD_MSGBG_SetBlend  0x02193044  thumb  ov021
 *   FIELD_MSGBG_KeyWaitGetCharWait  0x02193210  thumb  ov021
 *   TALKMSGWIN_SetupPlainWindow  0x021947E8  thumb  ov021
 *   TALKMSGWIN_Open  0x02194940  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03112.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_MSGBG_LoadMenuGraphicsUpper(u32);
extern void FIELD_MSGBG_SetBlend(u32);
extern u32 FIELD_MSGBG_KeyWaitGetCharWait(u8 *p);
extern void TALKMSGWIN_SetupPlainWindow(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n);
extern void TALKMSGWIN_Open(u8 *p, int i);

void FIELD_MSGBG_SetupSubMsgWin(u16 *a, u32 *b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u32 i)
{
    a[3] = 11;
    b[3] = ((struct Obj03112 *)a)->f15C;
    b[2] = d;
    b[1] = i;
    FIELD_MSGBG_LoadMenuGraphicsUpper(a[0]);
    FIELD_MSGBG_SetBlend(0);
    TALKMSGWIN_SetupPlainWindow((u8 *)b[3], b[2], c, e, f, g, h, 0xFF, 0, FIELD_MSGBG_KeyWaitGetCharWait((u8 *)((u32)a + 0x15C + 4)), 2, 0);
    TALKMSGWIN_Open((u8 *)b[3], b[2]);
}
