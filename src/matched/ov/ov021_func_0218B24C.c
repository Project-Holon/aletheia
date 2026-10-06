/*
 * function: func_0218B24C
 * address:  0x0218B24C
 * packet:   pkt_ov021_0218B24C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_021A2FA4  0x021A2FA4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021BB188  0x021BB188  thumb
 *   func_0219E418  0x0219E418  thumb
 *   func_021C46F8  0x021C46F8  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09449.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(u8 *p);
extern int func_021A2FA4(void *a, int b);
extern u16 func_021AB0F0(u32 attr);
extern int func_021BB188(u16 a);
extern int func_0219E418(u32 a, u32 b);
extern u32 func_021C46F8(u32 a, u32 b, u32 c);

int func_0218B24C(char *p, void *q, void *x)
{
    void *a = func_02188CB4(x);
    void *o = func_021A3074(a);
    int r = func_021A2FA4(a, ((struct Obj09449 *)p)->f2C);

    if (r == 1) {
        int t = ((struct Obj09449 *)p)->f1C;
        if (t == 0 || t == 3) {
            if (func_021BB188(func_021AB0F0(((struct Obj09449 *)p)->f38))) {
                if (func_0219E418((u32)o, r) & 3)
                    return func_021C46F8((u32)q, (u32)x, r);
            }
        }
    }
    return 0;
}
