/*
 * function: func_021A2640
 * address:  0x021A2640
 * packet:   pkt_021A2640
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021A2C28  0x021A2C28  thumb  ov021
 *   func_0204B454  0x0204B454  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Actor;
struct PtS {
    s16 x;
    s16 y;
};
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern u32 func_021A2C28(u8 *);

void func_021A2640(u8 *a, struct PtS *b)
{
    func_0204B454((struct Actor *)func_021A2C28(a), b, 0);
}

