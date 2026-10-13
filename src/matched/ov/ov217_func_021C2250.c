/*
 * function: func_021C2250
 * address:  0x021C2250
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021C2250  0x021C2250  thumb  ov217
 *   CLACT_StopActorAnim  0x0204B974  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Actor;
extern void CLACT_StopActorAnim(struct Actor *a);
void func_021C2250(u32 a0, u32 a1)
{
    CLACT_StopActorAnim((struct Actor *)(*(u32*)(((u8*)a0 + a1 * 24) + 60)));
}

