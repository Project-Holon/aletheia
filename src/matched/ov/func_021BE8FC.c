/*
 * function: func_021BE8FC
 * address:  0x021BE8FC
 * packet:   pkt_021BE8FC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Tears down the handle at +0x24, the two word pair at +0x1C and the handles at +0x18 and +0x14.
 */
#include "../include/Obj05867.h"


struct Descriptor;
struct Obj020437AC;
struct Rec;
extern void func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_020452E8(struct Descriptor *d);

void func_021BE8FC(char *p)
{
    func_02045C04((struct Rec *)(((struct Obj05867 *)p)->f24));
    func_0203FB44(5, ((struct Obj05867 *)p)->f1C, ((struct Obj05867 *)p)->f20);
    func_020437AC((struct Obj020437AC *)(((struct Obj05867 *)p)->f18));
    func_020452E8((struct Descriptor *)(((struct Obj05867 *)p)->f14));
}

