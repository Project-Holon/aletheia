/*
 * function: func_021BEF4C
 * address: 0x021BEF4C
 * packet: pkt_ov110_021BEF4C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: BAD14 retains r1 explicitly loaded at EF4C+68/+86 despite its unused input.
 * symbols:
 *   d_021C39A8 0x021C39A8 data a1
 *   d_021C3900 0x021C3900 data a1
 *   func_02035C08 0x02035C08 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02035D40 0x02035D40 arm
 *   func_021BACDC 0x021BACDC thumb ov110
 *   func_020061E4 0x020061E4 thumb
 *   func_021BAD14 0x021BAD14 thumb ov110
 *   func_021BF3A0 0x021BF3A0 thumb ov110
 *   func_021BF3D4 0x021BF3D4 thumb ov110
 */
#include "../include/Obj00493.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Box { u8 b[8]; };
struct Ctx;
extern const struct Box d_021C39A8;
extern const struct Box d_021C3900[];
extern int func_02035C08(const void *p);
extern u32 func_02035D20(u32 *, u32 *);
extern u32 func_02035D40(struct Ctx *, u32, u32);
extern int func_021BACDC(u8 *p, int unused, unsigned n);
extern void func_020061E4(u32);
extern void func_021BAD14(u8 *, u32);
extern int func_021BF3A0(u8 *, u8 *);
extern int func_021BF3D4(u8 *, u8 *);
int func_021BEF4C(u8 *p)
{
    u32 x, y;
    struct Box box = d_021C39A8;
    int outer, inner, stop;
    u16 index;
    if (func_02035C08(d_021C3900) == 0) {
        func_02035D20(&x, &y);
        switch (func_021BACDC(*(u8 * *)&((struct Obj00493 *)p)->f14, x, y)) {
        case 0:
            p[106] = 1;
            func_020061E4(1352);
            return 0;
        case 1:
            p[106] = 1;
            func_021BAD14(*(u8 * *)&((struct Obj00493 *)p)->f14, y);
            return func_021BF3A0(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84);
        case 2:
            p[106] = 1;
            func_021BAD14(*(u8 * *)&((struct Obj00493 *)p)->f14, y);
            return func_021BF3D4(*(u8 * *)&((struct Obj00493 *)p)->f14, p + 84);
        case 3:
            break;
        }
    }
    func_02035D20(&x, &y);
    index = ((struct Obj00493 *)p)->f54 * 2;
    stop = 0;
    for (outer = 0; outer < 6; outer++) {
        box.b[0] = 24 * outer + 13;
        box.b[1] = box.b[0] + 22;
        for (inner = 0; inner < 2; inner++) {
            box.b[2] = 112 * inner + 16;
            box.b[3] = box.b[2] + 102;
            if (func_02035D40((struct Ctx *)&box, x, y) != (u32)-1) {
                ((struct Obj00493 *)p)->f62 = index;
                p[90] = inner;
                p[91] = outer;
                return 5;
            }
            index++;
            if (index >= ((struct Obj00493 *)p)->f58 - 2) {
                stop = 1;
                break;
            }
        }
        if (stop) break;
    }
    return 0;
}
