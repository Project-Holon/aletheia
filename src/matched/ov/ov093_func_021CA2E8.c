/*
 * function: BTL_SERVER_FLOW_ProcHandExSetWeight
 * address: 0x021CA2E8
 * packet: pkt_ov093_021CA2E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero bytes at 021CA316 are alignment padding.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_SetWeight 0x021D67D8 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgRecord 0x021C99A0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_SetWeight(u8 *, u32);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *, const struct Msg *);
int BTL_SERVER_FLOW_ProcHandExSetWeight(u8 *p, const u8 *q)
{
    BTL_POKEPARAM_SetWeight(BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, q[4]), *(const u16 *)(q + 6));
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 20, q[4], *(const u16 *)(q + 6));
    BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)(q + 8));
    return 1;
}
