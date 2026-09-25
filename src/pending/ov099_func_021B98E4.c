/*
 * function: func_021B98E4
 * address:  0x021B98E4
 * packet:   pkt_ov099_021B98E4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021C584C          -> unresolved: 021C584C (arm, from name) has no witness outside 021B98E4..021B98F0; 9 overlays overlap this address (ov016, ov021, ov093, ov111, ov114, ov127, ov136, ov172, ov208), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021C584C(u32, int);
void func_021B98E4(int a, u8 *b) { func_021C584C(*(u32 *)(b + 4), 1); }
