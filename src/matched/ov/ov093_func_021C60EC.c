/*
 * function: BTL_SERVER_FLOW_SetContFlag
 * address: 0x021C60EC
 * packet: pkt_ov093_021C60EC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_POKEPARAM_SetContFlag 0x021D5FE4 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_POKEPARAM_SetContFlag(u8 *p, unsigned int n);
void BTL_SERVER_FLOW_SetContFlag(u8 *p, u8 *a, u32 n)
{
    BTL_POKEPARAM_SetContFlag(a, n);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x19, BTL_POKEPARAM_GetPokeId(a), n);
}
