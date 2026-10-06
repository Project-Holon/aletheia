/*
 * function: func_021B9AF8
 * address:  0x021B9AF8
 * packet:   pkt_ov070_021B9AF8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_020437AC  0x020437AC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 */
#include "../include/Obj01682.h"

struct Bank;
struct Descriptor;
struct Obj;
struct Obj020437AC;
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);

void func_021B9AF8(char *p)
{
    int i;
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f73C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f74C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f744));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f734));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f754));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f76C));
    func_020452E8((struct Descriptor *)(((struct Obj01682 *)p)->f774));
    func_0204B3B4((struct Obj *)(((struct Obj01682 *)p)->f6A8));
    if (((struct Obj01682 *)p)->f6A0 != 0) {
        func_0204B3B4((struct Obj *)(((struct Obj01682 *)p)->f6A0));
        func_0204A8D4(((struct Obj01682 *)p)->f54C);
        func_0204ADA4(((struct Obj01682 *)p)->f548);
    }
    func_0204AFD8(((struct Obj01682 *)p)->f550);
    for (i = 0; i < 8; i++) {
        func_020437AC((struct Obj020437AC *)(*(int *)(p + i * 4 + 0x614)));
    }
    func_0204B1CC((struct Bank *)(((struct Obj01682 *)p)->f69C));
    func_0204A5AC();
}
