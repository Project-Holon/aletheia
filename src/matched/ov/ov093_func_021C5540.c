/*
 * function: BTL_SERVER_FLOW_ApplyFixedDamageEffect
 * address: 0x021C5540
 * packet: pkt_ov093_021C5540
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_SERVER_FLOW_ChangeHp 0x021C5B74 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern void BTL_SERVER_FLOW_ChangeHp(u8 *, u8 *, int, int);
void BTL_SERVER_FLOW_ApplyFixedDamageEffect(u8 *p, u8 *a, int c)
{
    int n;
    n = BTL_POKEPARAM_GetPokeId(a);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x36, n);
    BTL_SERVER_FLOW_ChangeHp(p, a, (int)(0u - (u32)c), 1);
    BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 0x50, n, 0xffff0000);
}
