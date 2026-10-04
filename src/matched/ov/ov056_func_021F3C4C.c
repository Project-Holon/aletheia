/*
 * function: func_021F3C4C
 * address:  0x021F3C4C
 * packet:   pkt_021F3C4C
 * region:   ov056
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 */
#include "../include/Obj03652.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec;
struct Tagged;
extern void func_02047738(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);

void func_021F3C4C(u8 *p)
{
    func_02047738((struct Rec *)(((struct Obj03652 *)p)->f1C));
    func_0204762C((struct Rec *)(((struct Obj03652 *)p)->f14));
    func_0204762C((struct Rec *)(((struct Obj03652 *)p)->f18));
    func_02047504((struct Rec *)(((struct Obj03652 *)p)->f10));
    func_020470D0((u32 *)(((struct Obj03652 *)p)->f0));
    func_02046EFC((struct Tagged *)(((struct Obj03652 *)p)->f0));
    func_02046EFC((struct Tagged *)(((struct Obj03652 *)p)->f4));
    func_02046EFC((struct Tagged *)(((struct Obj03652 *)p)->f8));
}
