/*
 * function: func_021A9B68
 * address:  0x021A9B68
 * packet:   pkt_ov021_021A9B68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_02019C90  0x02019C90  thumb
 *   func_021A9DC8  0x021A9DC8  thumb
 *   _u32_div_f  0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };

extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern u32 func_021A9DC8(void);

u8 func_021A9B68(u8 *u, struct Spec *specs, u32 type)
{
    u8 buf[12];
    int i;
    int n;
    u8 t1, t2;

    n = 0;
    for (i = 0; i < u[0x14]; i++) {
        if (specs[i].lvl != 0x1F) {
            t1 = func_02019C90(specs[i].id, specs[i].lvl, 6);
            t2 = func_02019C90(specs[i].id, specs[i].lvl, 7);
            if (t1 == type || t2 == type) {
                buf[n] = i;
                n++;
            }
        }
    }
    if (n == 0)
        return 0xFF;
    return buf[func_021A9DC8() % n];
}
