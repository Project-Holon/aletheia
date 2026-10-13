/*
 * function: BTL_SERVER_FLOW_ChangeStatStage
 * address: 0x021C5A8C
 * packet: pkt_ov093_021C5A8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_RaiseStatStage 0x021D5DC0 thumb ov093
 *   BTL_POKEPARAM_LowerStatStage 0x021D5E38 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 */
#include "../include/Obj04360.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 BTL_POKEPARAM_RaiseStatStage(s8 *p, int i, u8 n);
extern u8 BTL_POKEPARAM_LowerStatStage(s8 *p, int i, u8 n);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
void BTL_SERVER_FLOW_ChangeStatStage(u8 *p, u8 *a, int c, int d, u16 msg, int flag)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    if (d > 0) {
        int x = BTL_POKEPARAM_RaiseStatStage((s8 *)a, c, d);
        u8 t = x;
        BTL_SERVER_CMD_Push(((struct Obj04360 *)p)->fC, 9, n, (u8)c, t);
        BTL_SERVER_CMD_Push(((struct Obj04360 *)p)->fC, 0x37, n, (u8)c, t);
        if (flag) {
            if (msg == 0) BTL_SERVER_CMD_PushVariable(((struct Obj04360 *)p)->fC, 0x5b, 0x1b, n, c, x, 0xffff0000);
            else BTL_SERVER_CMD_PushVariable(((struct Obj04360 *)p)->fC, 0x5b, 0x3aa, n, msg, c, x, 0xffff0000);
        }
    } else {
        int x = BTL_POKEPARAM_LowerStatStage((s8 *)a, c, -d);
        u8 t = x;
        BTL_SERVER_CMD_Push(((struct Obj04360 *)p)->fC, 10, n, (u8)c, t);
        BTL_SERVER_CMD_Push(((struct Obj04360 *)p)->fC, 0x38, n, (u8)c, t);
        BTL_SERVER_CMD_PushVariable(((struct Obj04360 *)p)->fC, 0x5b, 0x5a, n, c, x, 0xffff0000);
    }
}
