/*
 * function: func_021C0AB4
 * address:  0x021C0AB4
 * packet:   pkt_ov110_021C0AB4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021B639C          -> unresolved: 021B639C (arm, from name) has no witness outside 021C0AB4..021C0AC0; 16 overlays overlap this address (ov016, ov017, ov021, ov067, ov070, ov071, ov091, ov093, ov098, ov101, ov133, ov172, ov173, ov174, ov179, ov180), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B639C(u32);
void func_021C0AB4(u8 *p) { func_021B639C(*(u32 *)(p + 0x54)); }
