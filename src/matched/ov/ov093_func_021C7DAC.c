/*
 * function: func_021C7DAC
 * address:  0x021C7DAC
 * packet:   pkt_ov093_021C7DAC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   func_021B937C  0x021B937C  thumb  ov093
 *   BTL_SERVER_FLOW_GetMoveParam  0x021C64B4  thumb  ov093
 *   BTL_SERVER_FLOW_CalcTypeEffectiveness  0x021C6E3C  thumb  ov093
 */
#include "../include/Obj02135.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *func_021B9934(char *p, int i);
struct R4;
struct Out64B4;
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern u8 *func_021B937C(int a, char *b, u8 *c);
extern void BTL_SERVER_FLOW_GetMoveParam(u8 *p, int q, u8 *a, struct Out64B4 *out);
extern int BTL_SERVER_FLOW_CalcTypeEffectiveness(u8 *p, u8 *a, u8 *b, u8 *q, int flag);

int func_021C7DAC(u8 *p, int a, int b, int c)
{
    int buf[5];
    int r;
    u8 *x = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, a);
    u8 *y = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, b);
    ((struct Obj02135 *)p)->f774 += 1;
    if (BTL_POKEPARAM_IsIllusionActive((struct R4 *)y)) {
        y = func_021B937C(((struct Obj02135 *)p)->f4, *(char * *)&((struct Obj02135 *)p)->f8, y);
    }
    BTL_SERVER_FLOW_GetMoveParam(p, c, x, (struct Out64B4 *)buf);
    r = BTL_SERVER_FLOW_CalcTypeEffectiveness(p, x, y, (u8 *)buf, 0);
    ((struct Obj02135 *)p)->f774 -= 1;
    return r;
}
