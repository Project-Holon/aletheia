/*
 * file:     fs_api.c
 * unit:     yes
 * function: FS_Init, FS_IsAvailable, MTX_Identity22_
 * address:  0x0207AD04
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FSi_InitRomArchive               0x0207ab10 arm
 *   FSi_InitOverlay                  0x02078c40 arm
 *   is_init                          0x02150e04 data
 *   .bss                             0x02150e04 data
 */
extern void FSi_InitRomArchive(unsigned long default_dma_no);
extern void FSi_InitOverlay(void);
void FS_Init(unsigned long default_dma_no);
int FS_IsAvailable(void);
asm void MTX_Identity22_(void);

static int is_init = 0;



/*
 * sdk:      FS_Init (fs_api.o)
 */
void FS_Init(unsigned long default_dma_no)
{
    if (is_init) {
        return;
    }
    is_init = 1;
    FSi_InitRomArchive(default_dma_no);
    FSi_InitOverlay();
}



/*
 * sdk:      FS_IsAvailable (libfs.TWL.HYB.a fs_api.o)
 */
int FS_IsAvailable(void)
{
    return is_init;
}

/*
 * sdk:      MTX_Identity22_ (libfx.TWL.HYB.a fx_mtx22.o)
 * asm:      fixed-register stm with writeback (stmia r0!, {r2, r3}); no C spelling.
 *
 * void MTX_Identity22_(MtxFx22 *pDst)
 */
asm void MTX_Identity22_(void)
{
    mov r1, #0
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r2}
    bx lr
}
