/*
 * function: BTL_SERVER_FLOW_PushSickFailedMessage
 * address: 0x021C5C74
 * packet: pkt_ov093_021C5C74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 */
#include "../include/Obj01688.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
void BTL_SERVER_FLOW_PushSickFailedMessage(u8 *p, u8 *a, int kind, u32 v)
{
    u8 n = BTL_POKEPARAM_GetPokeId(a);
    switch (kind) {
    case 1:
        switch (v) {
        case 5: BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5b, 0xf9, n, 0xffff0000); break;
        case 4: BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5b, 0x10b, n, 0xffff0000); break;
        case 1: BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5b, 0x11a, n, 0xffff0000); break;
        case 2: BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5b, 0x13b, n, 0xffff0000); break;
        case 3: BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5b, 0x129, n, 0xffff0000); break;
        case 6: BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5b, 0x162, n, 0xffff0000); break;
        case 15: BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5b, 0x18, n, 0xffff0000); break;
        case 20: return;
        default: BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5a, 0x47, 0xffff0000); break;
        }
        p[0x78a] |= 0x10;
        break;
    case 2:
        BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5b, 0xd2, n, 0xffff0000);
        p[0x78a] |= 0x10;
        break;
    default:
        BTL_SERVER_CMD_PushVariable(((struct Obj01688 *)p)->fC, 0x5a, 0x47, 0xffff0000);
        p[0x78a] |= 0x10;
        break;
    }
}
