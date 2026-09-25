/*
 * function: func_021BEC24
 * address:  0x021BEC24
 * packet:   pkt_021BEC24
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 * blocker: codegen near miss (DIFF)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02006148(u32);
extern void func_020061F8(void);

void func_021BEC24(u32 a, u32 b, int *c)
{
    if (c[1] == -1) {
        func_02006148(c[0]);
    }
    func_020061F8();
}

