/*
 * function: CircleGraph_ComputePercents
 * address: 0x021C1850
 * packet: pkt_ov217_021C1850
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declare base before total, preserve both base stores, guard do-loop.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base=p;` before `base=p+0x1c;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   CircleGraph_SumValues 0x021C1AD4 thumb ov217
 *   CircleGraph_SumPercents 0x021C1AFC thumb ov217
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj14759.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int CircleGraph_SumValues(u8 *p);
extern int CircleGraph_SumPercents(u8 *);
void CircleGraph_ComputePercents(u8 *p)
{
    u8 *base;
    u32 total=CircleGraph_SumValues(p);
    int count=p[0x1ac];
    int i=0;
    int remaining;
    if (count>0) {
        base=p+0x1c;
        do {
            u8 *record=base+i*20;
            record[8]=(((struct Obj14759 *)record)->f4*100)/total;
            i++;
        } while (i<count);
    }
    remaining=100-CircleGraph_SumPercents(p);
    i=0;
    while (remaining>0) {
        p[i*20+0x24]+=1;
        remaining--;
        i=(i+1)%count;
    }
}
