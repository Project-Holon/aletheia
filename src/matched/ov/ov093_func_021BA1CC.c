/*
 * function: BTL_MAIN_TrainerRecordAddDelta
 * address: 0x021BA1CC
 * packet: pkt_ov093_021BA1CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two bytes are alignment padding at 0x021BA1E2.
 * interface: r1/r2 remain live from entry as index and delta.
 * symbols:
 *   RECORD_AddCounter 0x02008DAC thumb
 */
#include "../include/Obj21001.h"
#include "../include/Obj21002.h"
typedef unsigned int u32;
struct Sub02008C20Obj;
extern u32 RECORD_AddCounter(struct Sub02008C20Obj *, int, u32);
void BTL_MAIN_TrainerRecordAddDelta(char **p, int i, u32 delta)
{
    if (((struct Obj21001 *)(*p))->f23 == 0)
        RECORD_AddCounter(*(struct Sub02008C20Obj * *)&((struct Obj21002 *)(*p))->f6C, i, delta);
}
