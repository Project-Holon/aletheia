/*
 * function: func_0218A308
 * address:  0x0218A308
 * packet:   pkt_ov096_0218A308
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resolved by the matched BTL_SLOT_GetPokeParam in ov093 (thumb); cross-overlay target.
 *
 * symbols:
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);
u8 *func_0218A308(void *p, u32 i) { return BTL_SLOT_GetPokeParam(p, i); }
