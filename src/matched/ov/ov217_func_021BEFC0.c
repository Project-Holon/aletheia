/*
 * function: func_021BEFC0
 * address:  0x021BEFC0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 724)), 1 to PERCENTAGE_SetVisible.
 *
 * symbols:
 *   PERCENTAGE_SetVisible  0x021C2740  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void PERCENTAGE_SetVisible(u32, u32);

void func_021BEFC0(u8 *a0, u32 a1)
{
    PERCENTAGE_SetVisible((u32)(*(u32*)(a0 + (a1)*4 + 724)), 1);
}

