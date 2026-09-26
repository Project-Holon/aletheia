/*
 * function: func_0218A2FC
 * address:  0x0218A2FC
 * packet:   pkt_ov096_0218A2FC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resolved by the func_021B98AC label in ov069 (thumb); cross-overlay target.
 *
 * symbols:
 *   func_021B98AC  0x021B98AC  thumb  ov069
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B98AC(u32);
void func_0218A2FC(u8 *p) { func_021B98AC(*(u32 *)(p + 0xb8)); }
