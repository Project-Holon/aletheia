/*
 * function: CROWD_OpenChatterSlot
 * address:  0x021F4530
 * packet:   pkt_ov055_021F4530
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   FIELD_MSGBG_AddSubMsgWinMsg  0x02191870  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020056EC(u32 v);
struct Fx;
extern void FIELD_MSGBG_AddSubMsgWinMsg(struct Fx *a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h);

void CROWD_OpenChatterSlot(u16 *p, u32 a, u32 b, u32 c, u32 d)
{
    u32 r = func_020056EC(0);

    p[0] = 1;
    p[3] = 0;
    FIELD_MSGBG_AddSubMsgWinMsg((struct Fx *)a, b, c + r % d, p[2], ((u8 *)p)[2], ((u8 *)p)[3], 8, 2);
}
