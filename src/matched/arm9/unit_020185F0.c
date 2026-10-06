/*
 * unit:     yes
 * address:  0x020185F0
 * packet:   pkt_0201854C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020185F0, func_020185F4, func_020185F8
 *
 * func_020185F0 and func_020185F4 are a bare `bx lr` padded to four bytes,
 * which is `void f(void) {}`: a hook that was never filled in.  Neither
 * carries a label in the generated listing.  func_020185F0 is reached from
 * func_02019B58, which is what attests the pair's addresses.
 *
 * symbols:
 *   func_02019C54  0x02019C54  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AF6C  0x0201AF6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Personal;
extern void *func_02019C54(u32 a, u32 b);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern u32  func_0201AF6C(u32 n);

void func_020185F0(void)
{
}

void *func_020185F4(void *p)
{
    return p;
}

u32 func_020185F8(int a, int b, int c)
{
    u32 r = 8;
    u8 n = (u8)func_0201AE1C(func_02019C54(a, b), 0x14);

    if (func_0201AF6C(n) != 1) {
        if (c == 0) {
            r = n;
        } else {
            r = n - 1;
            if (n == 0) {
                r = 0;
            }
        }
    }
    return r;
}
