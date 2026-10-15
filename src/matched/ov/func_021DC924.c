/*
 * function: BOX2_MAIN_Exit
 * address:  0x021DC924
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm  arm9
 *
 * Push the record's id and its 0x14 byte to channel 4, release
 *   d[1], then hand the frame over; 1 when done.
 */
#include "../include/Obj09220.h"


typedef unsigned int   u32;
extern void func_0200780C(void *save, u32 box);
struct S020314B8;
extern void func_0203133C(struct S020314B8 *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int BOX2_MAIN_Exit(int a, int b, int c, int *d)
{
    func_0200780C((void *)(*(int *)(*d + 4)), ((struct Obj09220 *)d)->f14);
    func_0203133C((struct S020314B8 *)d[1]);
    func_020315D4((struct S020315D4 *)a);
    GFL_HEAP_DeleteChecked(0x4b);
    return 1;
}
