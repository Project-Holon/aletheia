/*
 * function: func_021B7968
 * address:  0x021B7968
 * packet:   pkt_ov104_021B7968
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7D1C  0x021B7D1C  thumb  ov104
 *
 * Target leaf func_021B7D1C filed EXACT in src/matched; this thunk now attests.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021B7D1C(void *);
void func_021B7968(u8 *p) { func_021B7D1C(p + 4); }
