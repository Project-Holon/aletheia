/*
 * function: func_02185730
 * address:  0x02185730
 * packet:   pkt_02185730
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02185354  0x02185354  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_021862B0  0x021862B0  thumb  ov023
 *   func_021865B4  0x021865B4  thumb  ov023
 */
#include "../include/Obj02742.h"

extern void func_02185354(char *p);
typedef unsigned int   u32;
extern void func_02186444(char *p, u32 v);
extern int  func_021862B0(char *p);
extern int func_021865B4(char *p);

int func_02185730(char *p, int a1)
{
    if (func_021862B0(p)) {
        if (((struct Obj02742 *)p)->f178 == 0)
            ((struct Obj02742 *)p)->f178 = (void *)func_021865B4(p);
        func_02186444(p, 0x10);
    }
    func_02185354(p);
    return a1;
}
