/*
 * function: func_0207E184
 * address:  0x0207E184
 * packet:   pkt_0207E184
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   CCERR
 *
 * symbols:
 *   G2S_GetBG3ScrPtr  0x0207E184  arm
 *
 * TwlSDK libgx gx_bgcnt.o. Sub-engine BG3 screen pointer.
 */

typedef unsigned short u16;
typedef unsigned int u32;

void *func_0207E184(void)
{
    u32 bgMode = (*(volatile u32 *)0x04001000 & 0x00000007);
    u16 bg = *(volatile u16 *)0x0400100e;
    u32 baseBlock = ((u32)bg & 0x1f00) >> 8;

    switch (bgMode)
    {
    case 0:
    case 1:
    case 2:
        return (void *)(0x06200000 + (baseBlock << 11));
    case 3:
    case 4:
    case 5:
        if (bg & 0x80)
        {
            return (void *)(0x06200000 + (baseBlock << 14));
        }
        else
        {
            return (void *)(0x06200000 + (baseBlock << 11));
        }
    case 6:
        return NULL;
    default:
        return NULL;
    }
}
