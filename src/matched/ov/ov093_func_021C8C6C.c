/*
 * function: func_021C8C6C
 * address:  0x021C8C6C
 * packet:   pkt_ov093_021C8C6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8CAC  0x021C8CAC  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_SERVER_FLOW_PushPokeCmd42  0x021C60D4  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C8CAC(int a, u8 b);
extern u8 *func_021B9934(char *p, int i);
extern void BTL_SERVER_FLOW_PushPokeCmd42(u8 *p, u8 *a);

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent;

int func_021C8C6C(int a, Ent *e)
{
    if (func_021C8CAC(a + 0x1ab8, e->idx)) {
        BTL_SERVER_FLOW_PushPokeCmd42((u8 *)a, func_021B9934(*(char * *)&((struct Obj00003 *)a)->f8, (u8)e->idx));
        return 1;
    }
    return 0;
}
