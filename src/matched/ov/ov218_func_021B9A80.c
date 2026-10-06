/*
 * function: func_021B9A80
 * address: 0x021B9A80
 * packet: pkt_ov218_021B9A80
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02264.h"
struct Rec3;
struct Descriptor;
struct U16Vec;
struct Rec;
struct PrintSys;
struct S02031140;
struct WordSet;
extern void func_0201CE48(struct Rec3 *);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *);
extern unsigned int func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *);
extern unsigned int func_0201ED04(struct WordSet *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021B9A80(char *p)
{
    if (*(struct Rec3 * *)&((struct Obj02264 *)p)->f20 != 0) {
        func_0201CE48(*(struct Rec3 * *)&((struct Obj02264 *)p)->f20);
        *(struct Rec3 * *)&((struct Obj02264 *)p)->f20 = 0;
    }
    func_020452E8(*(struct Descriptor * *)&((struct Obj02264 *)p)->f28);
    func_020452E8(*(struct Descriptor * *)&((struct Obj02264 *)p)->f24);
    func_02045808(*(struct U16Vec * *)&((struct Obj02264 *)p)->f18);
    func_02045808(*(struct U16Vec * *)&((struct Obj02264 *)p)->f1C);
    func_02045C04(*(struct Rec * *)&((struct Obj02264 *)p)->f8);
    func_0201C4C0(*(struct PrintSys * *)&((struct Obj02264 *)p)->f10);
    func_0201D83C(((struct Obj02264 *)p)->fC);
    func_02031140(*(struct S02031140 * *)&((struct Obj02264 *)p)->f4);
    func_0201ED04(*(struct WordSet * *)&((struct Obj02264 *)p)->f14);
    func_020307B0(p);
}
