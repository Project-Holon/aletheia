/*
 * function: BTL_SERVER_FLOW_ExecCmdSetContFlag
 * address: 0x021C9778
 * packet: pkt_ov093_021C9778
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
 *   BTL_SERVER_FLOW_SetContFlag 0x021C60EC thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void BTL_SERVER_FLOW_SetContFlag(u8 *, u8 *, u32);
int BTL_SERVER_FLOW_ExecCmdSetContFlag(u8 *p, u8 *q)
{
    u8 *a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, q[8]);
    if (!BTL_POKEPARAM_IsFainted(a)) {
        BTL_SERVER_FLOW_SetContFlag(p, a, *(u32 *)(q + 4));
        return 1;
    }
    return 0;
}
