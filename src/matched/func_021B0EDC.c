/*
 * function: func_021B0EDC
 * address:  0x021B0EDC
 * packet:   pkt_021B0EDC
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_021B0A88() and returns 0x1.
 *
 * symbols:
 *   func_021B0A88  0x021B0A88  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void func_021B0A88();

u32 func_021B0EDC(void)
{
    func_021B0A88();

    return 0x1;
}

