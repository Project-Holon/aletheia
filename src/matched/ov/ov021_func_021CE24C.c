/*
 * function: func_021CE24C
 * address:  0x021CE24C
 * packet:   pkt_ov021_021CE24C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_021CE3D8  0x021CE3D8  thumb  ov021
 *   func_021CEA84  0x021CEA84  thumb  ov021
 *   func_021CEAB0  0x021CEAB0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02098.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0203D1C0(u32 index);
extern void func_021CE3D8(u8 *p, u8 i);
extern void func_021CEA84(u8 *p, int n);
extern void func_021CEAB0(u8 *p);

void func_021CE24C(u8 *p)
{
    u8 i;
    int off;

    for (i = 0; i < 4; i++) {
        off = i * 0x2c;
        if (p[0x70 + off] && !func_0203D1C0(i)) {
            void (*cb)(u32, u8 *, u8 *) = *(void (**)(u32, u8 *, u8 *))(p + 0x490);

            if (cb) {
                cb(((struct Obj02098 *)p)->f488, p + 0x50 + off, p + 0x73 + off);
            }
            func_021CE3D8(p, i);
            func_021CEA84(p, i);
            func_021CEAB0(p);
        }
    }
}
