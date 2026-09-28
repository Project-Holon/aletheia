/*
 * function: func_0207E2A0
 * address:  0x0207E2A0
 * packet:   pkt_0207E2A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   CCERR
 *
 * symbols:
 *   G2_GetBG2CharPtr  0x0207E2A0  arm
 *
 * TwlSDK libgx gx_bgcnt.o. Main-engine BG2 character pointer.
 */

typedef unsigned short u16;
typedef unsigned int u32;

void *func_0207E2A0(void)
{
    u32 bgMode = (*(volatile u32 *)0x04000000 & 0x00000007);
    u16 bg = *(volatile u16 *)0x0400000c;

    if (bgMode >= 5 && (bg & 0x80))
    {
        return NULL;
    }

    return (void *)(0x06000000 + (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) +
                    ((((u32)bg & 0x3c) >> 2) << 14));
}
