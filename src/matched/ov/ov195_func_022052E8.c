/*
 * function: func_022052E8
 * address: 0x022052E8
 * packet: pkt_ov195_022052E8
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028604 0x02028604 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02031140 0x02031140 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj02240.h"
extern int func_02028604(int);
struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
struct Rec;
extern void func_02045C04(struct Rec *rec);
extern void func_0203FB44(unsigned, unsigned short, unsigned short);
extern void func_020452E8(struct Descriptor *d);
void func_022052E8(int task, char *p)
{
    func_02028604(((struct Obj02240 *)p)->f84);
    if (((struct Obj02240 *)p)->f64) func_0201CE48((struct Rec3 *)(((struct Obj02240 *)p)->f64));
    func_02031140((struct S02031140 *)(((struct Obj02240 *)p)->f68));
    if (((struct Obj02240 *)p)->f80) func_02045808((struct U16Vec *)(((struct Obj02240 *)p)->f80));
    func_02045C04(((struct Obj02240 *)p)->f78);
    func_02045C04(((struct Obj02240 *)p)->f7C);
    func_0203FB44(1, ((struct Obj02240 *)p)->f74, ((struct Obj02240 *)p)->f74 >> 16);
    func_020452E8((struct Descriptor *)(((struct Obj02240 *)p)->f6C));
    func_020452E8((struct Descriptor *)(((struct Obj02240 *)p)->f70));
}
