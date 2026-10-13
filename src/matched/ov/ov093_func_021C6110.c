/*
 * function: BTL_SERVER_FLOW_ClearContFlag
 * address: 0x021C6110
 * packet: pkt_ov093_021C6110
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_ClearContFlag 0x021D6008 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern void BTL_POKEPARAM_ClearContFlag(u8 *, unsigned int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
typedef unsigned int   u32;
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
void BTL_SERVER_FLOW_ClearContFlag(u8 *p, u8 *a, unsigned int n)
{
    BTL_POKEPARAM_ClearContFlag(a, n);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x1a, BTL_POKEPARAM_GetPokeId(a), n);
}
