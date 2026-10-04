/*
 * function: func_021B98F0
 * address:  0x021B98F0
 * packet:   pkt_ov099_021B98F0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0004 ABS32 func_021B9FD0          -> unresolved: 021B9FD0 (arm, from name) has no witness outside 021B98F0..021B98F8; 27 overlays overlap this address (ov016, ov021, ov068, ov069, ov070, ov071, ov072, ov088, ov091, ov093, ov099, ov100, ov110, ov114, ov133, ov172, ov181, ov206, ov213, ov214, ov217, ov218, ov220, ov221, ov222, ov223, ov225), none resolvable without a region hint on the symbols: line
 
 * symbols:
 *   func_021B9FD0  0x021B9FD0  thumb  ov099
 *
 * UNBLOCKED: func_021B9FD0 is now an EXACT entry in layout/matched/ov099;
 * the call site resolves as matched, verdict promoted to EXACT.
*/

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B9FD0(void *p);
void func_021B98F0(void *p) { func_021B9FD0(p); }
