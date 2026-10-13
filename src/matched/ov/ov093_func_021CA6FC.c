/*
 * function: func_021CA6FC
 * address: 0x021CA6FC
 * packet: pkt_ov093_021CA6FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_PushEffectAnim 0x021C70E4 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_PushEffectAnim(u8 *, int, int, int, int, u32);
struct Msg;
extern int func_021C99A0(void *, const struct Msg *);
int func_021CA6FC(u8 *p, const u8 *q)
{
    if (q[11]) BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 86, 0);
    BTL_SERVER_FLOW_PushEffectAnim(p, *(const u16 *)(q + 4), q[6], q[7], q[10], *(const u16 *)(q + 8));
    func_021C99A0(p, (const struct Msg *)(q + 12));
    return 1;
}
