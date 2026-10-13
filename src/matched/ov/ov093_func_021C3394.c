/*
 * function: BTL_SERVER_FLOW_CheckHealBlocked
 * address:  0x021C3394
 * packet:   pkt_ov093_021C3394
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_CMD_PushVariable  0x021CD64C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);

int BTL_SERVER_FLOW_CheckHealBlocked(u8 *p, u8 *q, int r)
{
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)q, 15) != 0) {
        if (r != 0) {
            BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 887, BTL_POKEPARAM_GetPokeId(q), 0xffff0000);
            p[0x78A] |= 0x20;
        }
        return 1;
    }
    return 0;
}
