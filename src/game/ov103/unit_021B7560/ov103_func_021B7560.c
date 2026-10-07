/*
 * function: func_021B7560
 * address: 0x021B7560
 * packet: pkt_ov103_021B7560
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: write argument byte 17 through the stored p+0xb0c pointer; the direct argument store loses the scratch copy and shifts the remaining code by two bytes.
 * prototype: 3064C preserves explicitly loaded third input; 3159C leaves allocator return live at 020315C0-C8. 7948 tail-forwards to 7C64's full-word getter. 1F73C's third input is explicitly narrowed at 021B75EC-F0.
 * volatile: DISPCNT read/write 021B76D2-DE; WININ re-read 021B76E4/EE, WINOUT 021B76FC; window-position hardware writes 021B770C-1C.
 * symbols:
 * func_0203064C 0x0203064C arm
 * func_0203159C 0x0203159C arm
 * func_02082BCC 0x02082BCC arm
 * func_021B8AF4 0x021B8AF4 thumb ov103
 * func_021B787C 0x021B787C thumb ov103
 * func_021B7F7C 0x021B7F7C thumb ov103
 * func_02012138 0x02012138 thumb
 * func_021B800C 0x021B800C thumb ov103
 * func_0201F73C 0x0201F73C thumb
 * func_021B8074 0x021B8074 thumb ov103
 * func_021B81A4 0x021B81A4 thumb ov103
 * func_02041F6C 0x02041F6C arm
 * func_02041FB0 0x02041FB0 arm
 * func_021B91A8 0x021B91A8 thumb ov103
 * func_021B9110 0x021B9110 thumb ov103
 * func_021B7948 0x021B7948 thumb ov103
 * func_021B7FFC 0x021B7FFC thumb ov103
 * func_021B8000 0x021B8000 thumb ov103
 * func_021B70DC 0x021B70DC thumb ov101
 * func_021B63CC 0x021B63CC thumb ov101
 * func_021B8338 0x021B8338 thumb ov103
 * func_021B8364 0x021B8364 thumb ov103
 */
#include "../../../matched/include/Obj03740.h"
#include "../../../matched/include/Obj22170.h"
#include "../../../matched/include/Obj22173.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203064C(u32,u32,u32);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
struct Ctx;
extern void func_021B8AF4(u8 *p, void *q);
extern void func_021B787C(u8 *,int);
extern void func_021B7F7C(u32 *p, int skip, u32 heap);
extern u32 func_02012138(const struct Ctx *p);
struct Rec;
extern void func_021B800C(struct Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_021B8074(u8 *,int,int,u8,u8,u8,u8,u16,u8,u16);
extern void func_021B81A4(u8 *,void *,int);
extern void func_02041F6C(u32 which, u32 op, u32 value);
extern void func_02041FB0(u32,u32,u16);
extern void func_021B91A8(void *);
extern void func_021B9110(u8 *,void *,int,int,int,u8);
extern u32 func_021B7948(u8 *);
extern int func_021B7FFC(void *),func_021B8000(void *);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void func_021B63CC(int *,int);
extern void func_021B8338(u32 p, u32 a);
extern void func_021B8364(u8 *,u16 *);
#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))
int func_021B7560(void *owner,int unused,void *arg)
{
    u8 *p;
    u32 handle;
    int first,second;
    func_0203064C(1,55,0x25000);
    p=func_0203159C(owner,0xb10,55);
    func_02082BCC(p,0,0xb10);
    ((struct Obj03740 *)p)->fB0C=arg;
    (*(u8 **)(p+0xb0c))[17]=0;
    func_021B8AF4(p+0x75c,((struct Obj22170 *)(*(u8 * *)&((struct Obj03740 *)p)->fB0C))->f4);
    func_021B787C(p,55);
    func_021B7F7C((u32 *)(p+0x174),0,55);
    if(**(void ** *)&((struct Obj03740 *)p)->fB0C) func_02012138(**(void ** *)&((struct Obj03740 *)p)->fB0C);
    func_021B800C((struct Rec *)(p+0x184),5,1,18,30,5,8,55);
    func_0201F73C(((struct Obj03740 *)p)->f184,0,(u16)(((struct Obj03740 *)p)->f0),6);
    func_021B8074(p+0x748,7,6,3,20,5,8,1,1,55);
    func_021B81A4(p+0x748,p+0x174,16);
    func_02041F6C(7,3,0x1000);
    func_02041F6C(7,6,0x1000);
    func_02041FB0(7,9,128);
    func_02041FB0(7,12,40);
    func_021B91A8(p+0xa4c);
    func_021B91A8(p+0xaac);
    func_021B9110(p+0x198,p,0,1,0,1);
    handle=func_021B7948(p);
    first=func_021B7FFC(p+0x174);
    second=func_021B8000(p+0x174);
    ((struct Obj03740 *)p)->fA38=func_021B70DC(2,handle,1,13,13,2,first,second,55);
    func_021B63CC(*(int * *)&((struct Obj22173 *)(*(u8 * *)&((struct Obj03740 *)p)->fB0C))->f4,2);
    func_021B8338((u32)p,(u32)func_021B8364);
    REG32(0x04000000)=(REG32(0x04000000)&~0xe000)|0x6000;
    REG16(0x04000048)=(REG16(0x04000048)&~0x3f)|0x1e;
    REG16(0x04000048)=(REG16(0x04000048)&~0x3f00)|0x1e00;
    REG16(0x0400004a)=(REG16(0x0400004a)&~0x3f)|0x1f;
    REG16(0x04000040)=0xff2c;
    REG16(0x04000044)=0xa8c0;
    REG16(0x04000042)=0xff;
    REG16(0x04000046)=0xa8c0;
    return 1;
}
