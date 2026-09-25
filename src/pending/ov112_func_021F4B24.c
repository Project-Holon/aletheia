/*
 * function: func_021F4B24
 * address:  0x021F4B24
 * packet:   pkt_ov112_021F4B24
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021F50D0          -> unresolved: 021F50D0 (arm, from name) has no witness outside 021F4B24..021F4B30; 5 overlays overlap this address (ov048, ov107, ov112, ov135, ov194), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021F50D0(u32);
void func_021F4B24(u8 *p) { func_021F50D0(*(u32 *)(p + 0x20)); }
