/*
 * function: func_021BE920
 * address:  0x021BE920
 * packet:   pkt_021BE920
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021BE7A8  0x021BE7A8  thumb  ov203
 * blocker: codegen near miss (DIFF)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021BE7A8(u32);

typedef struct {
    u16 lo : 15;
    u16 hi : 1;
} bf_021BE920;

u32 func_021BE920(u32 a)
{
    bf_021BE920 *p = (bf_021BE920 *)(func_021BE7A8(a) + 6);

    return 0x1000 >> p->hi;
}

