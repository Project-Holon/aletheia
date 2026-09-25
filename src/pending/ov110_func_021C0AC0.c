/*
 * function: func_021C0AC0
 * address:  0x021C0AC0
 * packet:   pkt_ov110_021C0AC0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0004 ABS32 func_021B63D0          -> unresolved: 021B63D0 (arm, from name) has no witness outside 021C0AC0..021C0AC8; 16 overlays overlap this address (ov016, ov017, ov021, ov067, ov070, ov071, ov091, ov093, ov098, ov101, ov133, ov172, ov173, ov174, ov179, ov180), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B63D0(void);
void func_021C0AC0(void) { func_021B63D0(); }
