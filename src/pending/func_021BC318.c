/*
 * function: func_021BC318
 * address:  0x021BC318
 * packet:   pkt_021BC318
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021BC33C  0x021BC33C  thumb  ov210
 * blocker: +0014 ABS32 func_021BC33C          -> unresolved: 021BC33C (thumb, from header) has no witness outside 021BC318..021BC330; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02005624(void (*)(void), u8 *, u32);
extern void func_021BC33C(void);

void func_021BC318(u8 *p)
{
    *(u32 *)(p + 8) = func_02005624(func_021BC33C, p, 0);
}
