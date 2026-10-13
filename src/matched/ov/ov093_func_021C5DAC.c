/*
 * function: BTL_SERVER_FLOW_PushMsgStd
 * address:  0x021C5DAC
 * packet:   pkt_ov093_021C5DAC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

void BTL_SERVER_FLOW_PushMsgStd(u8 *p, u32 a, int n, const int *v)
{
    switch (n) {
    default:
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, a, 0xffff0000);
        break;
    case 1:
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], 0xffff0000);
        break;
    case 2:
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], v[1], 0xffff0000);
        break;
    case 3:
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}
