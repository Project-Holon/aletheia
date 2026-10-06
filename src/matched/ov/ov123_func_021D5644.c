/*
 * function: func_021D5644
 * address: 0x021D5644
 * packet: pkt_ov123_021D5644
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: low and high halves of packed words pass to u16 callee parameters; no explicit high-half cast.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D54E0 0x021D54E0 thumb ov123
 *   func_020452E8 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_020450C8 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01154.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D584C(char *);
typedef unsigned char  u8;
extern void func_021D54E0(u8 *p);
struct Descriptor;
struct PrintSys;
struct Rec;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern int func_02028604(int a0);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201DD68(void);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02031140(struct S02031140 *p);
extern void func_020450C8(void);
extern u32 func_020307B0(void *p);
void func_021D5644(char *p)
{
    int i;
    u32 a;
    func_021D584C(p);
    if (((struct Obj01154 *)p)->f44) func_020452E8(((struct Obj01154 *)p)->f44);
    if (((struct Obj01154 *)p)->f48) func_020452E8(((struct Obj01154 *)p)->f48);
    for(i=0;i<12;i++) {
        if (*(void **)(p+0x4c+i*4)) func_020452E8(*(void **)(p+0x4c+i*4));
    }
    a=((struct Obj01154 *)p)->f8>>16;
    func_0203FB44((int)5,(u16)(((struct Obj01154 *)p)->f8),(u16)a);
    a=((struct Obj01154 *)p)->f4>>16;
    func_0203FB44((int)6,(u16)(((struct Obj01154 *)p)->f4),(u16)a);
    func_021D54E0((u8 *)p);
    func_02028604((int)(((struct Obj01154 *)p)->f40));
    func_0201ED04(((struct Obj01154 *)p)->f24);
    func_0201DD68();
    func_02045C04(((struct Obj01154 *)p)->f20);
    func_0201D83C(((struct Obj01154 *)p)->f28);
    func_02045808(((struct Obj01154 *)p)->f2C);
    func_02045808(((struct Obj01154 *)p)->f30);
    func_02027FD8(((struct Obj01154 *)p)->fA4);
    func_0201C6EC(((struct Obj01154 *)p)->f88);
    func_0201C4C0(((struct Obj01154 *)p)->f88);
    func_02031140(((struct Obj01154 *)p)->f84);
    func_020450C8();
    func_020307B0(p);
}
