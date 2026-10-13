/*
 * function: BTL_SERVER_FLOW_ProcOhkoEndured
 * address: 0x021C36E8
 * packet: pkt_ov093_021C36E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * The final 00 00 at 0x021C371E is alignment padding before 0x021C3720.
 * A separate call-result local keeps the halfword load before that call.
 * symbols:
 *   BTL_SERVER_FLOW_SubtractHp 0x021C604C thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_ProcDamageAftereffect 0x021C16F8 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_SERVER_FLOW_SubtractHp(u8 *, u8 *, int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_ProcDamageAftereffect(u8 *, u8 *, int);
void BTL_SERVER_FLOW_ProcOhkoEndured(u8 *p, u8 *q, u16 *r, int a, int b, u16 c)
{
    int n;
    int v;
    BTL_SERVER_FLOW_SubtractHp(p, q, c);
    n = *r;
    v = BTL_POKEPARAM_GetPokeId(q);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x32, v, (u8)a, n);
    BTL_SERVER_FLOW_ProcDamageAftereffect(p, q, b);
}
