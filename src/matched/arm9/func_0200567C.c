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
 */

#include "../include/G_GflSys.h"

extern struct GflSys _GflUse;
extern int func_02030D28(int);
extern int func_020419E4(int);
extern int func_02050A70(int);
extern int FADE_Update(int);
void GFL_USE_RunMainTasks(void)
{
    FADE_Update(func_02050A70(func_020419E4(func_02030D28(*(int *)(((char *)_GflUse.heaps) + 0x20)))));
    _GflUse.unk0C++;
}
