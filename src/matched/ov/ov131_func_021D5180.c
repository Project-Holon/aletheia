/*
 * function: func_021D5180
 * address: 0x021D5180
 * packet: pkt_ov131_021D5180
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D89FC 0x021D89FC thumb ov131
 *   func_021D9BD4 0x021D9BD4 thumb ov131
 *   func_021D694C 0x021D694C thumb ov131
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../include/Obj10504.h"
typedef unsigned char u8;
struct Obj;
extern void func_021D89FC(void *unused, unsigned char *s);
extern void func_021D9BD4(void *a, u8 *p);
extern void func_021D694C(void *a, unsigned char *p);
extern void func_0204B3B4(struct Obj *p);
void func_021D5180(char *p)
{
    u8 i;
    func_021D89FC(p,((struct Obj10504 *)p)->f94);
    func_021D9BD4(p,((struct Obj10504 *)p)->f90);
    func_021D694C(p,((struct Obj10504 *)p)->f88);
    for (i=0;i<8;i++) func_0204B3B4(*(void **)(p+i*4+0x178));
    for (i=0;i<2;i++) func_0204B3B4(*(void **)(p+i*4+0x198));
}
