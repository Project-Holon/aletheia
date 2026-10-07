/*
 * function: func_0207AC64
 * address:  0x0207AC64
 * packet:   pkt_0207AC64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_SetDefaultDMA (libfs.TWL.HYB.a fs_proc_rom.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   FS_SuspendArchive  0x02078648  arm
 *   FS_ResumeArchive  0x020786D8  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   fsi_default_dma_no  0x02150DA0  data
 *   fsi_arc_rom  0x02150DA8  data
 */

#include "../include/G_FSiRomState.h"
#include "../include/G_fsi_arc_rom.h"

typedef unsigned long u32;
typedef int BOOL;

typedef struct FSArchive FSArchive;

extern struct FSiRomState fsi_default_dma_no;
extern struct G_fsi_arc_rom fsi_arc_rom;

extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern BOOL FS_SuspendArchive(FSArchive *p_arc);
extern BOOL FS_ResumeArchive(FSArchive *arc);

u32 func_0207AC64(u32 dma_no)
{
    u32 bak_psr = OS_DisableInterrupts();
    u32 bak_dma_no = (*(u32 *)&fsi_default_dma_no);
    BOOL bak_stat = FS_SuspendArchive(&(*(FSArchive *)&fsi_arc_rom));

    (*(u32 *)&fsi_default_dma_no) = dma_no;
    if (bak_stat)
    {
        (void)FS_ResumeArchive(&(*(FSArchive *)&fsi_arc_rom));
    }
    (void)OS_RestoreInterrupts(bak_psr);
    return bak_dma_no;
}
