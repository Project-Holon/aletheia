/*
 * function: func_021C6980
 * address: 0x021C6980
 * packet: pkt_ov128_021C6980
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 */
#include "../include/Obj00725.h"
typedef unsigned char u8;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct WordSet;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
void func_021C6980(u8 *p)
{
    func_0201C6EC(((struct Obj00725 *)p)->f34);
    func_0201C4C0(((struct Obj00725 *)p)->f34);
    ((struct Obj00725 *)p)->f34=0;
    if (((struct Obj00725 *)p)->f2C) {
        func_0201CE48(((struct Obj00725 *)p)->f2C);
        ((struct Obj00725 *)p)->f2C=0;
    }
    func_02031140(((struct Obj00725 *)p)->f28);
    ((struct Obj00725 *)p)->f28=0;
    func_0201D83C(((struct Obj00725 *)p)->f17C);
    func_02045C04(((struct Obj00725 *)p)->f4);
    func_0201ED04(((struct Obj00725 *)p)->f0);
}
