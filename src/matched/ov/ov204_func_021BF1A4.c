/*
 * function: func_021BF1A4
 * address: 0x021BF1A4
 * packet: pkt_ov204_021BF1A4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF580 0x021BF580 thumb ov204
 *   func_02028604 0x02028604 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01292.h"
struct U16Vec; struct Descriptor; struct S02031140;
typedef unsigned char  u8;
extern void func_021BF580(u8 *p);
extern int func_02028604(int);
extern void func_02045808(struct U16Vec *);
extern void func_0201D83C(void *);
struct Rec3;
extern void func_0201CE48(struct Rec3 *p);
extern void func_020452E8(struct Descriptor *);
extern void func_02031140(struct S02031140 *);
struct PrintSys;
struct Rec;
struct WordSet;
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201ED04(struct WordSet *p);
extern void func_020307B0(void *);
void func_021BF1A4(char *p)
{
    func_021BF580((u8 *)p);
    func_02028604(((struct Obj01292 *)p)->f20);
    func_02045808(*(struct U16Vec * *)&((struct Obj01292 *)p)->f3C);
    func_02045808(*(struct U16Vec * *)&((struct Obj01292 *)p)->f40);
    func_0201D83C(((struct Obj01292 *)p)->f10);
    if (((struct Obj01292 *)p)->f14 != 0)
        func_0201CE48((struct Rec3 *)(((struct Obj01292 *)p)->f14));
    func_020452E8(*(struct Descriptor * *)&((struct Obj01292 *)p)->f1C);
    if (((struct Obj01292 *)p)->f38)
        func_020452E8(*(struct Descriptor * *)&((struct Obj01292 *)p)->f38);
    func_02031140(*(struct S02031140 * *)&((struct Obj01292 *)p)->f18);
    func_0201C4C0(((struct Obj01292 *)p)->f4);
    if (((struct Obj01292 *)p)->fC)
        func_02045C04(((struct Obj01292 *)p)->fC);
    func_0201ED04(((struct Obj01292 *)p)->f8);
    func_020307B0(p);
}
