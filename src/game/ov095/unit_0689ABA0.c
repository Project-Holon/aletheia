/*
 * file:     unit_0689ABA0.c
 * function: func_0689ABA0
 * address:  0x0689ABA0
 * packet:   pkt_ov095_0689ABA0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The byte and word out-parameters are one struct local: struct-member
 * loads are re-read after stores/calls (the reload of w for the (u8)
 * argument), and the compound `t.w &= ~0x8000` re-reads the member, which
 * is the second `ldr r1,[sp,#4]`.
 *
 * symbols:
 *   func_021B9AB0  0x021B9AB0  thumb
 *   func_021D54C0  0x021D54C0  thumb
 *   func_021D82D0  0x021D82D0  thumb
 *   func_021D8318  0x021D8318  thumb
 *   func_021D83FC  0x021D83FC  thumb
 *   func_021D8434  0x021D8434  thumb
 *   func_022030F0  0x022030F0  thumb
 */
#include "../../matched/include/Obj04407.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_022030F0(u32 h, u8 *b, u32 *w);
extern int func_021B9AB0(u32 b);
extern u32 func_021D54C0(u32 a, u32 b);
extern void func_021D83FC(u8 *p, u32 b);
extern void func_021D82D0();
extern void func_021D8318(u32 p);
extern void func_021D8434(u32 p);

typedef struct { u8 b; u32 w; } T;

int func_0689ABA0(int unused, u8 *s)
{
    T t;
    u32 flag;
    u32 w;
    u32 v;

    if (func_022030F0(((struct Obj04407 *)s)->fB0, &t.b, &t.w)) {
        flag = (t.w & 0x8000) != 0;
        t.w &= ~0x8000;
        w = t.w;
        if (w != 4) {
            if (t.b == 0)
                t.b = 1;
            if (w != 7)
                v = func_021D54C0(*(u32 *)(*(u32 *)&((struct Obj04407 *)s)->f7C + func_021B9AB0(t.b) * 8), (u8)t.w);
            else
                v = 0xa5;
            func_021D83FC(*(u8 * *)&((struct Obj04407 *)s)->f7C + 0x18, t.b);
            func_021D82D0(*(u8 * *)&((struct Obj04407 *)s)->f7C + 0x1c, v, 6);
            func_021D82D0(((struct Obj04407 *)s)->f70, v, 6);
            if (flag)
                func_021D8318(((struct Obj04407 *)s)->f70);
        } else if (w == 4) {
            func_021D8434(((struct Obj04407 *)s)->f70);
        }
        return 1;
    }
    return 0;
}
