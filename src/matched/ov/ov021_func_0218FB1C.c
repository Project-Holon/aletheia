/*
 * function: func_0218FB1C
 * address:  0x0218FB1C
 * packet:   pkt_ov021_0218FB1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame callback armed by func_0218F9C4/func_0218FA40: steps the +0xf0
 * block's frame counter and interpolates each enabled channel from the
 * start snapshot (+0x34) toward the target (+0x64).
 *
 * symbols:
 *   func_0218FDF0  0x0218FDF0  thumb  ov021
 *   func_0218FD88  0x0218FD88  thumb  ov021
 *   func_0218FDD4  0x0218FDD4  thumb  ov021
 *   func_0218FE40  0x0218FE40  thumb  ov021
 *   func_02048B80  0x02048B80  arm
 *   func_02048B94  0x02048B94  arm
 *   d_020A1B38     0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00752.h"
#include "../include/Obj01491.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

extern u16 func_0218FDF0(u16 *a, u16 *b, s32 d, s32 n);
extern void func_0218FD88(s32 *a, s32 *b, s32 d, s32 n, s32 *out);
extern s32 func_0218FDD4(s32 *a, s32 *b, s32 d, s32 n);
extern void func_0218FE40(u8 *p);
struct Light;
extern void func_02048B80(struct Light *l, u32 v);
extern void func_02048B94(struct Light *l, u32 v);
extern s16 d_020A1B38[];

void func_0218FB1C(u8 *p)
{
    u8 *q;
    u8 *s;
    u8 *t;

    q = p + 0xf0;
    if (((struct Obj00752 *)q)->f9C == 0) {
        return;
    }
    (((struct Obj00752 *)q)->f96)++;
    s = q + 0x34;
    t = q + 0x64;
    if (((struct Obj00752 *)q)->fA4 != 0) {
        ((struct Obj01491 *)p)->f78 = func_0218FDF0((u16 *)(s + 0x24), (u16 *)(t + 0x24),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
    }
    if (((struct Obj00752 *)q)->fA8 != 0) {
        ((struct Obj01491 *)p)->f7A = func_0218FDF0((u16 *)(s + 0x26), (u16 *)(t + 0x26),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
    }
    if (((struct Obj00752 *)q)->fB4 != 0) {
        func_0218FD88((s32 *)(s + 0xc), (s32 *)(t + 0xc),
                      ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96, (s32 *)(p + 0x48));
    }
    if (((struct Obj00752 *)q)->fB0 != 0) {
        ((struct Obj01491 *)p)->f80 = func_0218FDF0((u16 *)(s + 0x2c), (u16 *)(t + 0x2c),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
        func_02048B80(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2]);
        func_02048B94(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (((struct Obj00752 *)q)->fAC != 0) {
        ((struct Obj01491 *)p)->f7C = func_0218FDD4((s32 *)(s + 0x28), (s32 *)(t + 0x28),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
    }
    if (((struct Obj00752 *)q)->fA0 != 0) {
        func_0218FD88((s32 *)(s + 0x18), (s32 *)(t + 0x18),
                      ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96, (s32 *)(p + 0x60));
    }
    if (((struct Obj00752 *)q)->f96 >= ((struct Obj00752 *)q)->f94) {
        ((struct Obj00752 *)q)->f9C = 0;
        func_0218FE40(p);
    }
}
