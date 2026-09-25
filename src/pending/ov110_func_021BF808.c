/*
 * function: func_021BF808
 * address:  0x021BF808
 * packet:   pkt_ov110_021BF808
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021BAFDC          -> unresolved: 021BAFDC (arm, from name) has no witness outside 021BF808..021BF814; 20 overlays overlap this address (ov016, ov021, ov068, ov070, ov072, ov088, ov091, ov093, ov099, ov100, ov110, ov114, ov172, ov206, ov213, ov214, ov217, ov218, ov223, ov225), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021BAFDC(u32);
void func_021BF808(u8 *p) { func_021BAFDC(*(u32 *)(p + 0x1c)); }
