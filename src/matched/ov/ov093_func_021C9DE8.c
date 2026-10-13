/*
 * function: func_021C9DE8
 * address:  0x021C9DE8
 * packet:   pkt_ov093_021C9DE8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_SERVER_FLOW_ProcHeldItemActivate  0x021C2128  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 f0 : 1;
    u32 f1 : 1;
};

extern u8 *func_021B9934(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern int BTL_SERVER_FLOW_ProcHeldItemActivate(u8 *p, u8 *a);

int func_021C9DE8(u8 *w, struct Cmd *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)c->id);
    if (BTL_POKEPARAM_IsFainted(r) == 0 || c->f1) {
        if (c->f0 && BTL_POKEPARAM_IsHpFull(r) != 0) return 0;
        if (BTL_SERVER_FLOW_ProcHeldItemActivate(w, r) != 0) return 1;
    }
    return 0;
}
