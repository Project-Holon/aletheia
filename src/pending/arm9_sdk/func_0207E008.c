/*
 * function: func_0207E008
 * address:  0x0207E008
 * packet:   pkt_0207E008
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   CCERR
 *
 * symbols:
 *   G2_GetBG2ScrPtr  0x0207E008  arm
 *
 * TwlSDK libgx gx_bgcnt.o. Main-engine BG2 screen pointer; the addressing mode
 * depends on the BG mode (text/affine 256x16/bitmap).
 */

typedef unsigned short u16;
typedef unsigned int u32;

void *func_0207E008(void)
{
    u32 bgMode = (*(volatile u32 *)0x04000000 & 0x00000007);
    u16 bg = *(volatile u16 *)0x0400000c;
    u32 base = (*(volatile u32 *)0x04000000 & 0x38000000) >> 27;
    u32 baseBlock = (u32)((bg & 0x1f00) >> 8);

    switch (bgMode)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return (void *)(0x06000000 + (base << 16) + (baseBlock << 11));
    case 5:
        if (bg & 0x80)
        {
            return (void *)(0x06000000 + (baseBlock << 14));
        }
        else
        {
            return (void *)(0x06000000 + (base << 16) + (baseBlock << 11));
        }
    case 6:
        return (void *)0x06000000;
    default:
        return NULL;
    }
}
