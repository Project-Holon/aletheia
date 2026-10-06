/*
 * function: func_0217AF9C
 * address:  0x0217AF9C
 * packet:   pkt_0217AF9C
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E8628  0x021E8628  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 */
#include "../include/Obj03869.h"
typedef unsigned int u32;

extern void func_021E8628(u32 a);
struct PrintSys;
struct Rec;
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);

void func_0217AF9C(int *p)
{
    func_021E8628(((struct Obj03869 *)p)->f8);
    func_0201C4C0((struct PrintSys *)(((struct Obj03869 *)p)->f14));
    func_02045C04((struct Rec *)(((struct Obj03869 *)p)->f10));
    func_0201D83C((void *)(((struct Obj03869 *)p)->fC));
}
