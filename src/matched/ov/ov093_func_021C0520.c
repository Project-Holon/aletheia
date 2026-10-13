/*
 * function: BTL_SERVER_FLOW_PushMoveFailMessage
 * address: 0x021C0520
 * packet: pkt_ov093_021C0520
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a u8 local for the random result narrows in r0 before copying to r2.
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_PushPokeCmd59 0x021C5604 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u32 BTL_CALC_Random(u32 range);
extern void BTL_SERVER_FLOW_PushPokeCmd59(u8 *p, u8 *a, int b);
void BTL_SERVER_FLOW_PushMoveFailMessage(u8 *p, u8 *a, u16 b, u32 c)
{
    u32 id = BTL_POKEPARAM_GetPokeId(a);
    switch (c) {
    case 2: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x135, id, 0xffff0000); break;
    case 3: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x114, id, 0xffff0000); break;
    case 4: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x123, id, 0xffff0000); break;
    case 6: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x16b, id, 0xffff0000); break;
    case 7: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x16e, id, 0xffff0000); break;
    case 8: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x150, id, 0xffff0000); break;
    case 9: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x253, id, b, 0xffff0000); break;
    case 18: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x1bd, id, 0xffff0000); break;
    case 10: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x23b, id, b, 0xffff0000); break;
    case 11: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x244, id, b, 0xffff0000); break;
    case 12: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x24d, id, b, 0xffff0000); break;
    case 13: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x37a, id, b, 0xffff0000); break;
    case 14: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x37d, id, 0xffff0000); break;
    case 15:
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x57, id);
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x1c3, id, 0xffff0000);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x58, id);
        break;
    case 20: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 0x43e, id, b, 0xffff0000); break;
    case 22:
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 2) != 0) {
            BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 0xc2, id, 0xffff0000);
        } else {
            u8 rand = BTL_CALC_Random(4);
            BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, rand + 0xbc, id, 0xffff0000);
        }
        break;
    case 23: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 0xc1, id, 0xffff0000); break;
    case 1:
        BTL_SERVER_FLOW_PushPokeCmd59(p, a, b);
        BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 0x52, id, 0xffff0000);
        break;
    default: BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5a, 0x47, id, 0xffff0000); break;
    case 19:
    case 25:
        break;
    }
}
