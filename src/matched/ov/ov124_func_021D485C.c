/*
 * function: func_021D485C
 * address: 0x021D485C
 * packet: pkt_ov124_021D485C
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201DD68 0x0201DD68 thumb
 */
#include "../include/Obj00991.h"
typedef unsigned char  u8;
struct Descriptor;
struct PrintSys;
struct Rec;
struct TaskMenuState;
extern void func_02028148(u8 *p);
extern unsigned int func_02027FD8(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern unsigned int func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern void func_0201DD68(void *);
void func_021D485C(char *p)
{
    if (((struct Obj00991 *)p)->f3C) func_02028148(((struct Obj00991 *)p)->f3C);
    if (((struct Obj00991 *)p)->f38) func_02028148(((struct Obj00991 *)p)->f38);
    func_02028148(((struct Obj00991 *)p)->f40);
    func_02027FD8(((struct Obj00991 *)p)->f34);
    func_0201C4C0(((struct Obj00991 *)p)->f30);
    func_020452E8(((struct Obj00991 *)p)->f20);
    func_020452E8(((struct Obj00991 *)p)->f24);
    func_02045C04(((struct Obj00991 *)p)->f2C);
    func_0201DD68((void *)func_0201D83C(((struct Obj00991 *)p)->f28));
}
