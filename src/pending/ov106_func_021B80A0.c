/*
 * function: func_021B80A0
 * address:  0x021B80A0
 * packet:   pkt_ov106_021B80A0
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021B7FE4          -> unresolved: 021B7FE4 (arm, from name) has no witness outside 021B80A0..021B80AC; 16 overlays overlap this address (ov016, ov021, ov067, ov070, ov071, ov091, ov093, ov102, ov103, ov104, ov105, ov106, ov133, ov172, ov173, ov180), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B7FE4(void *);
void func_021B80A0(u8 *p) { func_021B7FE4(p + 0x10); }
