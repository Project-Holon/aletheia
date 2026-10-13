/*
 * function: func_021C7E14
 * address:  0x021C7E14
 * packet:   pkt_ov093_021C7E14
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   func_021B9934  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   func_021B937C  0x021B937C  thumb  ov093
 *   BTL_SERVER_FLOW_GetMoveParam  0x021C64B4  thumb  ov093
 *   func_021C7DAC  0x021C7DAC  thumb  ov093
 *   BTL_SERVER_FLOW_CalcMoveDamage  0x021C1E74  thumb  ov093
 */
#include "../include/Obj02135.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 WAZA_TOOL_IsDamaging(void *p);
extern u8 *func_021B9934(char *p, int i);
struct R4;
struct Out64B4;
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern u8 *func_021B937C(int a, char *b, u8 *c);
extern void BTL_SERVER_FLOW_GetMoveParam(u8 *p, int q, u8 *a, struct Out64B4 *out);
extern int func_021C7DAC(u8 *p, int a, int b, int c);
extern int BTL_SERVER_FLOW_CalcMoveDamage(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out);

u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1)
{
    int buf[5];
    u16 o;
    u8 *x;
    u8 *y;
    int z;
    if (c != 0 && WAZA_TOOL_IsDamaging((void *)c) != 0) {
        x = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, a);
        y = func_021B9934(*(char * *)&((struct Obj02135 *)p)->f8, b);
        ((struct Obj02135 *)p)->f774 += 1;
        if (BTL_POKEPARAM_IsIllusionActive((struct R4 *)y)) {
            y = func_021B937C(((struct Obj02135 *)p)->f4, *(char * *)&((struct Obj02135 *)p)->f8, y);
        }
        if (e0) {
            z = func_021C7DAC(p, a, b, c);
        } else {
            z = 3;
        }
        BTL_SERVER_FLOW_GetMoveParam(p, c, x, (struct Out64B4 *)buf);
        BTL_SERVER_FLOW_CalcMoveDamage(p, x, y, (u8 *)buf, z, 0x1000, 0, e1 == 0, &o);
        ((struct Obj02135 *)p)->f774 -= 1;
        return o;
    }
    return 0;
}
