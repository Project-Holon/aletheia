/*
 * function: BTL_SERVER_FLOW_SetTurnFlag
 * address: 0x021C6134
 * packet: pkt_ov093_021C6134
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
struct UtilWork;
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *, unsigned int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
typedef unsigned int   u32;
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
void BTL_SERVER_FLOW_SetTurnFlag(u8 *p, u8 *a, unsigned int n)
{
    BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, n);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x1b, BTL_POKEPARAM_GetPokeId(a), n);
}
