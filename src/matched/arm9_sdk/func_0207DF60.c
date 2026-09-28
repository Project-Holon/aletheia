/*
 * function: func_0207DF60
 * address:  0x0207DF60
 * packet:   pkt_0207DF60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G2_GetBG0ScrPtr  0x0207DF60  arm
 *
 * TwlSDK libgx gx_bgcnt.o. Main-engine BG0 screen pointer from DISPCNT's
 * screen base and BG0CNT's screen base block.
 */

typedef unsigned short u16;
typedef unsigned int u32;

void *func_0207DF60(void)
{
    u32 baseBlock = (u32)((*(volatile u16 *)0x04000008 & 0x1f00) >> 8);

    return (void *)(0x06000000 + (((*(volatile u32 *)0x04000000 & 0x38000000) >> 27) << 16) +
                    (baseBlock << 11));
}
