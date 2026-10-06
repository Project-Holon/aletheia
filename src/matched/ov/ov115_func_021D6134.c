/*
 * function: func_021D6134
 * address:  0x021D6134
 * packet:   pkt_ov115_021D6134
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6130  0x021D6130  thumb  ov115
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0004 ABS32 func_021D6130          -> unresolved: 021D6130 (arm, from name) has no witness outside 021D6134..021D613C; 9 overlays overlap this address (ov016, ov021, ov093, ov115, ov118, ov120, ov123, ov131, ov175), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021D6130(int *p, int v);
void func_021D6134(void *a0, int a1, int a2) { func_021D6130(a0, a1); }
