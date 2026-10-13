/*
 * function: func_021D2320
 * address:  0x021D2320
 * packet:   pkt_ov093_021D2320
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021EA40C  0x021EA40C  thumb  ov093
 *   func_021EA428  0x021EA428  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_ResetAllEffects  0x021D646C  thumb  ov093
 */
#include "../include/Obj06240.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021EA40C(char *ctx, int a);
extern int func_021EA428(u32 *p);
extern u8 *func_021B9934(char *p, int i);
extern void BTL_POKEPARAM_ResetAllEffects(void *p);

int func_021D2320(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA40C(((struct Obj06240 *)p)->f54, func_021B8D8C(((struct Obj06240 *)p)->f0, ((struct Obj06240 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA428(((struct Obj06240 *)p)->f54)) {
            BTL_POKEPARAM_ResetAllEffects(func_021B9934(((struct Obj06240 *)p)->f4, (u8)(*c)));
            return 1;
        }
        break;
    }
    return 0;
}
