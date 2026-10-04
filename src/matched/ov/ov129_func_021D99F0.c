/*
 * function: func_021D99F0
 * address: 0x021D99F0
 * packet: pkt_ov129_021D99F0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DA3D0 0x021DA3D0 thumb ov129
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 * Extent ends with two bytes of zero alignment padding.
 */
#include "../include/Obj06480.h"
#include "../include/Obj10500.h"

struct Bank;
struct Descriptor;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_021DA3D0(char *);
extern void func_020452E8(struct Descriptor *d);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021D99F0(char *p)  {
    int i;
    char *q;
    for(i=0;i<((struct Obj10500 *)p)->f23C;i++) func_0204B3B4((struct Obj *)(*(int *)(p+i*28+12)));
    for(i=0;i<2;i++)  {
        q=p+i*28;
        func_0204B3B4((struct Obj *)(((struct Obj06480 *)q)->f15C));
        func_0204B3B4((struct Obj *)(((struct Obj06480 *)q)->f1E8));
    }
    for(i=0;i<3;i++) func_0204B3B4((struct Obj *)(*(int *)(p+i*28+0x194)));
    func_021DA3D0(p);
    func_020452E8((struct Descriptor *)(((struct Obj10500 *)p)->f310));
    for(i=0;i<3;i++)  {
        q=p+i*4;
        func_0204ADA4(((struct Obj06480 *)q)->f260);
        func_0204A8D4(((struct Obj06480 *)q)->f26C);
        func_0204AFD8(((struct Obj06480 *)q)->f284);
    }
    func_0204B1CC((struct Bank *)(((struct Obj10500 *)p)->f25C));
    func_0204A5AC();
}
