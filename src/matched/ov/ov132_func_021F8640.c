/*
 * function: func_021F8640
 * address: 0x021F8640
 * packet: pkt_ov132_021F8640
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware display register 0x04000000 read at 0x021F868C.
 * symbols:
 *   func_02005D28 0x02005D28 thumb
 *   func_02006504 0x02006504 thumb
 *   func_02006518 0x02006518 thumb
 *   func_0207D534 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021F9D08 0x021F9D08 thumb ov132
 *   func_021FAB58 0x021FAB58 thumb ov132
 *   func_02045808 0x02045808 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_021FA64C 0x021FA64C thumb ov132
 *   func_021FA04C 0x021FA04C thumb ov132
 *   func_021F6F4C 0x021F6F4C thumb ov112
 *   func_021F6C7C 0x021F6C7C thumb ov112
 *   func_021F9E94 0x021F9E94 thumb ov132
 *   func_021F6A24 0x021F6A24 thumb ov112
 *   func_021F7120 0x021F7120 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204ED24 0x0204ED24 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00675.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_02005D28(void);
extern void func_02006504(void);
extern void func_02006518(void);
extern void func_0207D534(volatile u16 *,int);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021F9D08(char *);
extern void func_021FAB58(char *);
typedef unsigned char  u8;
struct Descriptor;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void func_021FA64C(char *);
extern void func_021FA04C(u8 *p);
extern void func_021F6F4C(u8 *p);
extern void func_021F6C7C(char *p);
extern void func_021F9E94(u8 *p);
extern void func_021F6A24(char *p);
extern void func_021F7120(char *p);
extern void func_021F51B0(int a);
extern void func_021F4948(u8 *p);
extern void func_0204A5AC(void);
extern void func_0204ED24(void *);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_020403F4(u32);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02030EAC(struct Node *n);
extern void func_02049238(void *);
extern u32 func_020307B0(void *p);
void func_021F8640(char *p)
{
    if(((struct Obj00675 *)p)->f2C==1)func_02005D28();
    if(((struct Obj00675 *)p)->f28==1)func_02006504();
    if(((struct Obj00675 *)p)->f24==1)func_02006518();
    func_0207D534((volatile u16 *)0x0400006c,-16);
    func_0207D534((volatile u16 *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    func_021F9D08(p);
    func_021FAB58(((struct Obj00675 *)p)->fB0);
    if(((struct Obj00675 *)p)->fE0!=0)func_02045808(((struct Obj00675 *)p)->fE0);
    func_0201C6EC(((struct Obj00675 *)p)->fE8);
    func_0201C4C0(((struct Obj00675 *)p)->fE8);
    func_02045C04(((struct Obj00675 *)p)->fDC);
    func_020452E8(((struct Obj00675 *)p)->fD0);
    func_0201D83C(((struct Obj00675 *)p)->fD4);
    func_02031140(((struct Obj00675 *)p)->fCC);
    func_021FA64C(*(char * *)&((struct Obj00675 *)p)->fA4);
    func_021FA04C(((struct Obj00675 *)p)->fB8);
    func_021F6F4C(((struct Obj00675 *)p)->f3C);
    func_021F6C7C(((struct Obj00675 *)p)->f90);
    func_021F9E94(((struct Obj00675 *)p)->f6C);
    func_021F6A24(((struct Obj00675 *)p)->f54);
    func_021F7120(((struct Obj00675 *)p)->f40);
    func_021F51B0((int)(((struct Obj00675 *)p)->f34));
    func_021F4948(((struct Obj00675 *)p)->f38);
    func_0204A5AC();
    func_0204ED24(((struct Obj00675 *)p)->fAC);
    func_02048AC4(((struct Obj00675 *)p)->fA8);
    func_02046788();
    func_020403F4(0);
    func_020403F4(1);
    func_020403F4(2);
    func_020403F4(3);
    func_020403F4(5);
    func_020403F4(7);
    func_020450C8();
    func_0203F9B4();
    func_02030EAC(((struct Obj00675 *)p)->f20);
    func_02049238(((struct Obj00675 *)p)->f18);
    func_020307B0(p);
}
