/*
 * function: BTLV_SCD_PollCounterTouch
 * address:  0x0689B790
 * packet:   pkt_0689B790
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tail-call forwarding thunk: passes *(p+0xb0) and the two pinned addresses
 * to func_02202DC4 (ov094).  The compiler emits the `ldr r3,pool; bx r3` form
 * because the call is the last statement.
 *
 * symbols:
 *   func_02202DC4   0x02202DC4  thumb  ov094
 *   gBtlvScdCounterRegionsA      0x0689D934  data   ov095
 *   gBtlvScdCounterRegionsB      0x0689DEBC  data   ov095
 */
#include "../include/Obj21901.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02202DC4(void *, void *, void *);
extern char gBtlvScdCounterRegionsA[];
extern char gBtlvScdCounterRegionsB[];

void BTLV_SCD_PollCounterTouch(void *p)
{
    func_02202DC4(((struct Obj21901 *)p)->fB0, gBtlvScdCounterRegionsA, gBtlvScdCounterRegionsB);
}
