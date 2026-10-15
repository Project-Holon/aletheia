/*
 * function: GFL_USE_RunMainTasks
 * address:  0x0200567C
 * packet:   pkt_0200567C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02050A70
 * symbols:
 *   _GflUse      0x020AA194  data
 *   FADE_Update  0x0204E638  arm
 *   TCB_Main  0x02030D28  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   DMA_UpdateChannels  0x02050A70  arm
 */

#include "../include/G_GflSys.h"

extern struct GflSys _GflUse;
extern int TCB_Main(int);
extern int BG_SYS_Update(int);
extern int DMA_UpdateChannels(int);
extern int FADE_Update(int);
void GFL_USE_RunMainTasks(void)
{
    FADE_Update(DMA_UpdateChannels(BG_SYS_Update(TCB_Main(*(int *)(((char *)_GflUse.heaps) + 0x20)))));
    _GflUse.unk0C++;
}
