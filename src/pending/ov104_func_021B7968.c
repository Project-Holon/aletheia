/*
 * function: func_021B7968
 * address:  0x021B7968
 * packet:   pkt_ov104_021B7968
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021B7D1C          -> unresolved: 021B7D1C (arm, from name) has no witness outside 021B7968..021B7974; 16 overlays overlap this address (ov016, ov021, ov067, ov070, ov071, ov091, ov093, ov102, ov103, ov104, ov105, ov106, ov133, ov172, ov173, ov180), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B7D1C(void *);
void func_021B7968(u8 *p) { func_021B7D1C(p + 4); }
