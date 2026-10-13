/*
 * unit:     no
 * function: APP_KEYCURSOR_Delete
 * address:  0x02028604
 * packet:   pkt_02028590
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_Delete  0x020437AC  arm
 */
#include "../include/Obj15795.h"

int APP_KEYCURSOR_Delete(int a0){ int t0 = BMP_Delete((int)((struct Obj15795 *)((char *)((a0 + 0))))->f0); int t1 = func_020307B0((int)((a0 + 0) + 0)); return t1; }
