/*
 * function: GURU2_MAIN_IsAngleInRangeList
 * address: 0x021E1830
 * packet: pkt_ov137_021E1830
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_AddAngleWrapped 0x021E15DC thumb ov137
 *   gGuru2PlayerAngleRangeLists 0x021E1F04 data a4
 */
#include "../include/Obj02497.h"
typedef unsigned short u16;
struct Range { u16 lo, hi; };
struct Entry { unsigned count; struct Range *ranges; };
extern struct Entry gGuru2PlayerAngleRangeLists[];
extern void GURU2_MAIN_AddAngleWrapped(int *, int);
int GURU2_MAIN_IsAngleInRangeList(char *p, int angle, int index)
{
    int tmp;
    unsigned a;
    unsigned count;
    unsigned b;
    struct Range *r;
    struct Entry *e;
    GURU2_MAIN_AddAngleWrapped(&angle, -((struct Obj02497 *)p)->f11C);
    GURU2_MAIN_AddAngleWrapped(&angle, -((struct Obj02497 *)p)->f124);
    tmp = angle;
    GURU2_MAIN_AddAngleWrapped(&tmp, -0x4000);
    a = tmp / 0x1000;
    tmp = angle;
    GURU2_MAIN_AddAngleWrapped(&tmp, 0x5000);
    b = tmp / 0x1000;
    e = &gGuru2PlayerAngleRangeLists[index];
    count = e->count;
    r = e->ranges;
    while (count) {
        if ((a >= r->lo && a <= r->hi) || (b >= r->lo && b <= r->hi))
            return 1;
        r++;
        count--;
    }
    return 0;
}
