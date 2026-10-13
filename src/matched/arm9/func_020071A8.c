/*
 * unit:     no
 * function: SAVE_CONTROL_CancelSave
 * address:  0x020071A8
 * packet:   pkt_020070C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BACKUP_SYSTEM_CancelSave  0x02031C04  arm
 */
#include "../include/Obj08731.h"

int SAVE_CONTROL_CancelSave(int a0){ int t0, t1; t0 = BACKUP_SYSTEM_CancelSave((int)((struct Obj08731 *)((char *)((a0 + 0))))->f10); if ((unsigned int)(((struct Obj08731 *)((char *)((a0 + 0))))->f3) == (unsigned int)(1)) { t1 = func_02008764((int)((a0 + 0) + 0)); } else {  return ((struct Obj08731 *)((char *)((a0 + 0))))->f3; } }
