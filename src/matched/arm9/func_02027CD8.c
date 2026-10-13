/*
 * unit:     no
 * function: APP_TASKMENU_SetDisableKey
 * address:  0x02027CD8
 * packet:   pkt_02027A24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   APP_TASKMENU_SetWinActive  0x02027B30  thumb
 */
#include "../include/Obj00059.h"

int APP_TASKMENU_SetDisableKey(int a0, int a1){ int t0, t1; *(int *)&((struct Obj00059 *)((char *)((a0 + 0))))->f10 = (int)a1; if ((unsigned int)(a1) == (unsigned int)(1)) { t0 = func_020355D8((int)1); t1 = APP_TASKMENU_SetWinActive((int)*(int *)(((char *)(*(int *)&((struct Obj00059 *)((char *)((a0 + 0))))->f18) + ((int)((*(unsigned char *)&((struct Obj00059 *)((char *)((a0 + 0))))->f0 << 2)) << 0))), (int)*(int *)&((struct Obj00059 *)((char *)((a0 + 0))))->f34, (int)0); } else {  return a0; } }
