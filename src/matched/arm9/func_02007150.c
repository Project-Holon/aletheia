/*
 * function: SAVE_CONTROL_StartSave
 * address:  0x02007150
 * packet:   pkt_020070C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BACKUP_SYSTEM_StartSave  0x02031B8C  arm
 */
#include "../include/Obj11223.h"

int SAVE_CONTROL_StartSave(int a0){ int t0, t1, t2; t0 = func_02008754(a0); ((struct Obj11223 *)((char *)((a0 + 0))))->f3 = (unsigned char)t0; t1 = func_02008774((int)((a0 + 0) + 0)); t2 = BACKUP_SYSTEM_StartSave((int)((struct Obj11223 *)((char *)((a0 + 0))))->f10); return t2; }
