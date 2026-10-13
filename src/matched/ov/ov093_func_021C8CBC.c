/*
 * function: func_021C8CBC
 * address:  0x021C8CBC
 * packet:   pkt_ov093_021C8CBC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8CFC  0x021C8CFC  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupIn  0x021C5A1C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C8CFC(int a, u8 b);
extern u8 *func_021B9934(char *p, int i);
extern void BTL_SERVER_FLOW_PushAbilityPopupIn(u8 *p, u8 *a);

typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent;

int func_021C8CBC(int a, Ent *e)
{
    if (func_021C8CFC(a + 0x1ab8, e->idx)) {
        BTL_SERVER_FLOW_PushAbilityPopupIn((u8 *)a, func_021B9934(*(char * *)&((struct Obj00003 *)a)->f8, (u8)e->idx));
        return 1;
    }
    return 0;
}
