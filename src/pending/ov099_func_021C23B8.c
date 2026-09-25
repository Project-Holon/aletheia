/*
 * function: func_021C23B8
 * address:  0x021C23B8
 * packet:   pkt_ov099_021C23B8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0004 ABS32 func_02156860          -> unresolved: 02156860 (arm, from name) has no witness outside 021C23B8..021C23C0; 2 overlays overlap this address (ov009, ov010), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_02156860(void);
void func_021C23B8(void) { func_02156860(); }
