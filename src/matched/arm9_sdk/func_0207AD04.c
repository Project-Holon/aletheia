/*
 * function: func_0207AD04
 * address:  0x0207AD04
 * packet:   pkt_0207AD04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * SDK symbol: FS_Init (TwlSDK libfs.TWL.HYB.a fs_api.o)
 *
 * symbols:
 *   FSi_InitRomArchive   0x0207AB10  arm
 *   FSi_InitOverlay      0x02078C40  arm
 *   is_init              0x02150E04  data
 */

typedef unsigned long u32;

extern u32 is_init;
extern void FSi_InitRomArchive(u32 default_dma_no);
extern void FSi_InitOverlay(void);

void func_0207AD04(u32 default_dma_no)
{
    if (is_init == 0)
    {
        is_init = 1;
        FSi_InitRomArchive(default_dma_no);
        FSi_InitOverlay();
    }
}
