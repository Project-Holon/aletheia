/*
 * function: func_021D5A9C
 * address: 0x021D5A9C
 * packet: pkt_ov115_021D5A9C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5FA0 0x021D5FA0 thumb ov115
 *   func_021D5FC4 0x021D5FC4 thumb ov115
 *   func_0203FB44 0x0203FB44 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02031140 0x02031140 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00724.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void func_0202F038(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_021D5D3C(u8 *p);
extern u32 func_021D5FA0(u32);
extern u32 func_021D5FC4(u32);
extern void func_0203FB44(u32,u16,u16);
extern void func_0201DD68(void);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_020307B0(void *);
void func_021D5A9C(u8 *p) {
    u32 n;
    if (((struct Obj00724 *)p)->f80) { func_0202F038(((struct Obj00724 *)p)->f80); ((struct Obj00724 *)p)->f80=0; }
    if (((struct Obj00724 *)p)->f38) { func_0201CE48(((struct Obj00724 *)p)->f38); ((struct Obj00724 *)p)->f38=0; }
    func_021D5D3C(p);
    n=((struct Obj00724 *)p)->f0;
    func_0203FB44(func_021D5FA0(((struct Obj00724 *)p)->f50),n,n>>16);
    n=((struct Obj00724 *)p)->f4;
    func_0203FB44(func_021D5FC4(((struct Obj00724 *)p)->f50),n,n>>16);
    func_0201DD68();
    func_0201ED04(((struct Obj00724 *)p)->f20);
    func_02045C04(((struct Obj00724 *)p)->f1C);
    func_0201D83C(((struct Obj00724 *)p)->f24);
    func_02045808(((struct Obj00724 *)p)->f28);
    func_02027FD8(((struct Obj00724 *)p)->f70);
    func_02031140(((struct Obj00724 *)p)->f44);
    func_0201C6EC(((struct Obj00724 *)p)->f48);
    func_0201C4C0(((struct Obj00724 *)p)->f48);
    if (((struct Obj00724 *)p)->f2C) { func_020452E8(((struct Obj00724 *)p)->f2C); ((struct Obj00724 *)p)->f2C=0; }
    if (((struct Obj00724 *)p)->f30) { func_020452E8(((struct Obj00724 *)p)->f30); ((struct Obj00724 *)p)->f30=0; }
    func_020450C8();
    func_020307B0(p);
}
