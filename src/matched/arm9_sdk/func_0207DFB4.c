/*
 * function: func_0207DFB4
 * address:  0x0207DFB4
 * packet:   pkt_0207DFB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G2_GetBG1ScrPtr  0x0207DFB4  arm
 *
 * TwlSDK libgx gx_bgcnt.o. Main-engine BG1 screen pointer.
 */

typedef unsigned short u16;
typedef unsigned int u32;

void *func_0207DFB4(void)
{
    u32 baseBlock = (u32)((*(volatile u16 *)0x0400000a & 0x1f00) >> 8);

    return (void *)(0x06000000 + (((*(volatile u32 *)0x04000000 & 0x38000000) >> 27) << 16) +
                    (baseBlock << 11));
}
