/*
 * function: func_021C0C7C
 * address:  0x021C0C7C
 * packet:   pkt_ov099_021C0C7C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_02156BC4          -> unresolved: 02156BC4 (arm, from name) has no witness outside 021C0C7C..021C0C88; 2 overlays overlap this address (ov009, ov010), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_02156BC4(int);
void func_021C0C7C(void) { func_02156BC4(0); }
