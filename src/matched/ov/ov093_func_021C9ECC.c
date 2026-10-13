/*
 * function: func_021C9ECC
 * address:  0x021C9ECC
 * packet:   pkt_ov093_021C9ECC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_SERVER_FLOW_PushPokeCmd42  0x021C60D4  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   BTL_SERVER_FLOW_SetHeldItem  0x021C2250  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
};

extern u8 *func_021B9934(char *p, int i);
extern void BTL_SERVER_FLOW_PushPokeCmd42(u8 *p, u8 *a);
struct Msg;
extern int func_021C99A0(void *w, const struct Msg *m);
extern void BTL_SERVER_FLOW_SetHeldItem(u8 *p, u8 *a, u16 b, u32 c);

int func_021C9ECC(u8 *w, struct Cmd *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)c->id);
    if (c->w4 == 0) {
        BTL_SERVER_FLOW_PushPokeCmd42(w, r);
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
    }
    BTL_SERVER_FLOW_SetHeldItem(w, r, 0, 1);
    return 1;
}
