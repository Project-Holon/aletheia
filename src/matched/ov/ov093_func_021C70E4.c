/*
 * function: BTL_SERVER_FLOW_PushEffectAnim
 * address:  0x021C70E4
 * packet:   pkt_ov093_021C70E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_CMD_FillReserved  0x021CD568  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_SERVER_CMD_FillReserved(u8 *w, u16 v, u32 id, ...);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);

void BTL_SERVER_FLOW_PushEffectAnim(u8 *p, int a, int b, int c, int e, u32 f)
{
    int m;
    if (c != 6) {
        m = 2;
    } else {
        m = 1;
        if (b == 6) m = 0;
    }
    if (e) {
        switch (m) {
        case 0: BTL_SERVER_CMD_FillReserved(*(u8 * *)&((struct Obj00003 *)p)->fC, f, 0x4c, a); return;
        case 1: BTL_SERVER_CMD_FillReserved(*(u8 * *)&((struct Obj00003 *)p)->fC, f, 0x4d, b, a); return;
        case 2: BTL_SERVER_CMD_FillReserved(*(u8 * *)&((struct Obj00003 *)p)->fC, f, 0x4e, b, c, a); return;
        }
    } else {
        switch (m) {
        case 0: BTL_SERVER_CMD_Push(*(u8 * *)&((struct Obj00003 *)p)->fC, 0x4c, a); return;
        case 1: BTL_SERVER_CMD_Push(*(u8 * *)&((struct Obj00003 *)p)->fC, 0x4d, b, a); return;
        case 2: BTL_SERVER_CMD_Push(*(u8 * *)&((struct Obj00003 *)p)->fC, 0x4e, b, c, a); return;
        }
    }
}
