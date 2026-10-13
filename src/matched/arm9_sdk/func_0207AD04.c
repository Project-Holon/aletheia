/*
 * function: FS_Init
 * address:  0x0207AD04
 * packet:   pkt_0207AD04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      FS_Init (fs_api.o)
 *
 * symbols:
 *   FSi_InitRomArchive               0x0207ab10 arm
 *   FSi_InitOverlay                  0x02078c40 arm
 *   is_init                          0x02150e04 data
 *   .bss                             0x02150e04 data
 */

extern void FSi_InitRomArchive(unsigned long default_dma_no);
extern void func_02078C40(void);

static int is_init = 0;

void FS_Init(unsigned long default_dma_no)
{
    if (is_init) {
        return;
    }
    is_init = 1;
    FSi_InitRomArchive(default_dma_no);
    func_02078C40();
}
