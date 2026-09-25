/*
 * function: func_0218A308
 * address:  0x0218A308
 * packet:   pkt_ov096_0218A308
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0004 ABS32 func_021B9C00          -> unresolved: 021B9C00 (arm, from name) has no witness outside 0218A308..0218A310; 30 overlays overlap this address (ov016, ov021, ov068, ov069, ov070, ov071, ov072, ov088, ov091, ov092, ov093, ov099, ov100, ov110, ov114, ov133, ov172, ov181, ov182, ov205, ov213, ov214, ov217, ov218, ov220, ov221, ov222, ov223, ov224, ov225), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B9C00(void);
void func_0218A308(void) { func_021B9C00(); }
