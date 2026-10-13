/*
 * function: BTL_SERVER_FLOW_ExecCmdSetTurnFlag
 * address: 0x021C9728
 * packet: pkt_ov093_021C9728
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of trailing alignment padding.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct UtilWork;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *, u32);
int BTL_SERVER_FLOW_ExecCmdSetTurnFlag(u8 *p, u8 *q)
{
    u8 *a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!BTL_POKEPARAM_IsFainted(a)) {
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}
