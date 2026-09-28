/*
 * function: func_0207E1F8
 * address:  0x0207E1F8
 * packet:   pkt_0207E1F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G2_GetBG0CharPtr  0x0207E1F8  arm
 *
 * TwlSDK libgx gx_bgcnt.o. Main-engine BG0 character pointer.
 */

typedef unsigned short u16;
typedef unsigned int u32;

void *func_0207E1F8(void)
{
    u32 baseBlock = (u32)((*(volatile u16 *)0x04000008 & 0x3c) >> 2);

    return (void *)(0x06000000 + (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) +
                    (baseBlock << 14));
}
