/*
 * function: func_021BF9CC
 * address:  0x021BF9CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021BF740  0x021BF740  thumb  ov217
 *   func_021BF7CC  0x021BF7CC  thumb  ov217
 *   func_0200E458  0x0200E458  thumb
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001C THM_CALL func_0200E458       -> unresolved: 0200E458 (arm, from name) has no witness outside 021BF9CC..021BF9EE
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Big;
extern void *func_0200E394(void *a0);
extern u16 func_0200E458(const u16 *, int);
extern void *func_02012EBC(struct Big *);
extern u32 func_021BF740(u8 *);
extern u32 func_021BF7CC(void *);
u16 func_021BF9CC(u32 a0)
{
    return func_0200E458((const u16 *)func_0200E394(func_02012EBC((struct Big *)func_021BF740((u8 *)a0))), func_021BF7CC((void *)a0));
}

