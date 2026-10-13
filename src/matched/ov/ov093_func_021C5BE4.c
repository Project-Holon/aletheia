/*
 * function: BTL_SERVER_FLOW_KillPoke
 * address: 0x021C5BE4
 * packet: pkt_ov093_021C5BE4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_ZeroHp 0x021D5FB8 thumb ov093
 */
#include "../include/Obj13336.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int func_021D59B4(u8 *p, int k);
extern void BTL_POKEPARAM_ZeroHp(u8 *);
void BTL_SERVER_FLOW_KillPoke(u8 *p, u8 *a, int c)
{
    int n;
    func_021D59B4(a, 13);
    n = BTL_POKEPARAM_GetPokeId(a);
    BTL_POKEPARAM_ZeroHp(a);
    BTL_SERVER_CMD_Push(((struct Obj13336 *)p)->fC, 3, n);
    BTL_SERVER_CMD_Push(((struct Obj13336 *)p)->fC, 0x43, n, c);
}
