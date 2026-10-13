/*
 * function: BTL_SERVER_FLOW_ProcHandExClearContFlag
 * address: 0x021CA6C4
 * packet: pkt_ov093_021CA6C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_FLOW_TryClearContFlag 0x021C5418 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgRecord 0x021C99A0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern int BTL_SERVER_FLOW_TryClearContFlag(u8 *, u8 *, int);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *, const struct Msg *);
int BTL_SERVER_FLOW_ProcHandExClearContFlag(u8 *p, const u8 *q)
{
    u8 *m = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    if (!BTL_POKEPARAM_IsFainted(m) && BTL_SERVER_FLOW_TryClearContFlag(p, m, *(const int *)(q + 8))) {
        BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)(q + 12));
        return 1;
    }
    return 0;
}
