/*
 * function: func_0220D98C
 * address:  0x0220D98C
 * packet:   pkt_0220D98C
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0220B000  0x0220B000  thumb  ov197
 * blocker: +000A THM_CALL func_0202616C       -> unresolved: 0202616C (arm, from name) has no witness outside 0220D98C..0220D9A6
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0202616C(u32);
extern void func_0220B000(u32, u32);

void func_0220D98C(u8 *p)
{
    u32 t = func_0202616C(*(u32 *)(p + 0x144));

    func_0220B000(*(u32 *)(p + 0x148), t);
}

