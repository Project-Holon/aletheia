/*
 * function: func_021D4940
 * address: 0x021D4940
 * packet: pkt_ov124_021D4940
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D49C6 before next labelled function.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj00068.h"
typedef short s16;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021D4940(char *p,int n)
{
    void *q;
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f24),1);
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f20),0);
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    func_0201C724(((struct Obj00068 *)p)->f30,(u32)func_02045770(((struct Obj00068 *)p)->f24),40,8,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    func_02045808(q);
    n += 12;
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    func_0201C724(((struct Obj00068 *)p)->f30,(u32)func_02045770(((struct Obj00068 *)p)->f20),0,0,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    func_02045808(q);
    ((struct Obj00068 *)p)->f1C = 1;
}
