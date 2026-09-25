/*
 * function: func_02210408
 * address:  0x02210408
 * packet:   pkt_02210408
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 * blocker: +0008 THM_CALL func_02021ED8       -> unresolved: 02021ED8 (arm, from name) has no witness outside 02210408..02210420
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02021ED8(u32);

u32 func_02210408(u8 *p)
{
    if (func_02021ED8(*(u32 *)(p + 0x1d8)) == 0) {
        return 0x21;
    }
    return 0x20;
}

