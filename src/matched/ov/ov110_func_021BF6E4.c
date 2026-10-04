/*
 * function: func_021BF6E4
 * address:  0x021BF6E4
 * packet:   pkt_ov110_021BF6E4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202452C  0x0202452C  thumb
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_0202452C          -> unresolved: 0202452C (arm, from name) has no witness outside 021BF6E4..021BF6F0
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u16 func_0202452C(const u16 *p);
void func_021BF6E4(u8 *p) { func_0202452C((const u16 *)(p + 8)); }
