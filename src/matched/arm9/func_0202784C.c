/*
 * unit:     no
 * function: APP_TASKMENU_OpenMenuFastDecide
 * address:  0x0202784C
 * packet:   pkt_02027778
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 */
#include "../include/Obj00059.h"

int APP_TASKMENU_OpenMenuFastDecide(int a0, int a1){ int t0; t0 = APP_TASKMENU_OpenMenu(a0, a1); *(int *)&((struct Obj00059 *)((char *)(t0)))->f14 = (int)2; return t0; }
