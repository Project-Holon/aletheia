/*
 * unit:     no
 * function: BTL_SETUP_DeleteTrainerData
 * address:  0x02013270
 * packet:   pkt_02013220
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 */
#include "../include/Obj15644.h"

int BTL_SETUP_DeleteTrainerData(int a0){ int t0 = STRBUF_Delete((int)((struct Obj15644 *)((char *)((a0 + 0))))->f14); int t1 = func_020307B0((int)((a0 + 0) + 0)); return t1; }
