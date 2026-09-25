/*
 * function: func_02211A24
 * address:  0x02211A24
 * packet:   pkt_02211A24
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0220B000  0x0220B000  thumb  ov198
 * blocker: +0008 THM_CALL func_0202616C       -> unresolved: 0202616C (arm, from name) has no witness outside 02211A24..02211A40
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0202616C(u32);
extern void func_0220B000(u32, u32);

void func_02211A24(u8 *p)
{
    u32 t = func_0202616C(*(u32 *)(p + 0x2184));

    func_0220B000(*(u32 *)(p + 0x2188), t);
}

