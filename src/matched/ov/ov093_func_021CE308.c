/*
 * function: func_021CE308
 * address:  0x021CE308
 * packet:   pkt_ov093_021CE308
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_BuildSlotChoices  0x021D0B10  thumb  ov093
 *   BTL_CLIENT_ClearSlotFlags  0x021CF41C  thumb  ov093
 *   BTL_CLIENT_ClearSlotLinkWords  0x021CF360  thumb  ov093
 *   BTL_CALC_ActionSetNone  0x021D8434  thumb  ov093
 *   func_021B990C  0x021B990C  thumb  ov093
 *   func_021CF470  0x021CF470  thumb  ov093
 *   BTL_CLIENT_SetSubFn  0x021CE150  thumb  ov093
 *   func_021CE4D0  0x021CE4D0  thumb  ov093
 */
#include "../include/Obj03688.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 a : 2; u8 f : 1; } Flags;

extern void BTL_CLIENT_BuildSlotChoices(u8 *p, u32 a, u32 b, void *q, void *out);
extern void BTL_CLIENT_ClearSlotFlags(u8 *p);
extern void BTL_CLIENT_ClearSlotLinkWords(u8 *p);
extern void BTL_CALC_ActionSetNone(u32 *p);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern u32 func_021CF470(u8 *p, void *q, u8 *o);
extern void BTL_CLIENT_SetSubFn(u8 *p, void *q);
extern int func_021CE4D0(u8 *p, u32 *st);

u32 func_021CE308(u8 *p)
{
    u32 i = 0;
    u32 w;
    p[0x11d] = 0;
    ((s8 *)p)[0x11e] = -1;
    p[0x11f] = 0;
    ((Flags *)(p + 0x1b2))->f = 0;
    BTL_CLIENT_BuildSlotChoices(p, 0, p[0x11c], p + 0x184, p + 0x190);
    BTL_CLIENT_ClearSlotFlags(p);
    BTL_CLIENT_ClearSlotLinkWords(p);
    for (i = 0; i < 3; i++) {
        BTL_CALC_ActionSetNone((u32 *)(p + 0x124 + i * 4));
    }
    for (i = 0; i < p[0x11c]; i++) {
        w = (u32)func_021B990C((char *)(((struct Obj03688 *)p)->f4), p[0x1a6], (u8)i);
        if (func_021CF470(p, (void *)w, 0) == 0) {
            p[0x11f] = i;
            break;
        }
    }
    BTL_CLIENT_SetSubFn(p, (void *)((u32)func_021CE4D0));
    return 0;
}
