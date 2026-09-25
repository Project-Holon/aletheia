/*
 * function: func_021F535C
 * address:  0x021F535C
 * packet:   pkt_ov112_021F535C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021F624C          -> unresolved: 021F624C (arm, from name) has no witness outside 021F535C..021F5368; 4 overlays overlap this address (ov107, ov112, ov135, ov215), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021F624C(u32);
void func_021F535C(u8 *p) { func_021F624C(*(u32 *)(p + 8)); }
