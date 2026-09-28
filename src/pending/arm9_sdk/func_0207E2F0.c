/*
 * function: func_0207E2F0
 * address:  0x0207E2F0
 * packet:   pkt_0207E2F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   CCERR
 *
 * symbols:
 *   G2S_GetBG2CharPtr  0x0207E2F0  arm
 *
 * TwlSDK libgx gx_bgcnt.o. Sub-engine BG2 character pointer.
 */

typedef unsigned short u16;
typedef unsigned int u32;

void *func_0207E2F0(void)
{
    u32 bgMode = (*(volatile u32 *)0x04001000 & 0x00000007);
    u16 bg = *(volatile u16 *)0x0400100c;

    if (bgMode >= 5 && (bg & 0x80))
    {
        return NULL;
    }

    return (void *)(0x06200000 + ((((u32)bg & 0x3c) >> 2) << 14));
}
