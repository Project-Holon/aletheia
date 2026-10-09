/*
 * file:     unit_021B7560_p01.c
 * unit:     yes
 * function: func_021B7560, func_021B7748, func_021B77B0, func_021B787C, func_021B78EC, func_021B7918, func_021B793C, func_021B7948, func_021B7954
 * address:  0x021B7560
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B8AF4 0x021B8AF4 thumb ov103
 *   func_021B7F7C 0x021B7F7C thumb ov103
 *   func_02012138 0x02012138 thumb
 *   func_021B800C 0x021B800C thumb ov103
 *   func_0201F73C 0x0201F73C thumb
 *   func_021B8074 0x021B8074 thumb ov103
 *   func_021B81A4 0x021B81A4 thumb ov103
 *   func_02041F6C 0x02041F6C arm
 *   func_02041FB0 0x02041FB0 arm
 *   func_021B91A8 0x021B91A8 thumb ov103
 *   func_021B9110 0x021B9110 thumb ov103
 *   func_021B7FFC 0x021B7FFC thumb ov103
 *   func_021B8000 0x021B8000 thumb ov103
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_021B63CC 0x021B63CC thumb ov101
 *   func_021B8338 0x021B8338 thumb ov103
 *   func_021B8364 0x021B8364 thumb ov103
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_021B9174 0x021B9174 thumb ov103
 *   func_021B80E4 0x021B80E4 thumb ov103
 *   func_021B7FC8 0x021B7FC8 thumb ov103
 *   func_021B8B1C 0x021B8B1C thumb ov103
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B7FF0 0x021B7FF0 thumb ov103
 *   func_021B8100 0x021B8100 thumb ov103
 *   func_021B63D0 0x021B63D0 thumb ov101
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_021B7B3C 0x021B7B3C thumb ov103
 *   func_021B7970 0x021B7970 thumb ov103
 *   func_021B7C68 0x021B7C68 thumb ov103
 *   func_021B8C14 0x021B8C14 thumb ov103
 *   func_020056A0 0x020056A0 thumb
 *   d_021B92D4 0x021B92D4 data ov103 a4
 *   func_021B795C 0x021B795C thumb ov103
 *   func_02030EAC 0x02030EAC arm
 *   func_021B8C40 0x021B8C40 thumb ov103
 *   func_021B7D08 0x021B7D08 thumb ov103
 *   func_021B7AE8 0x021B7AE8 thumb ov103
 *   func_021B7C08 0x021B7C08 thumb ov103
 *   func_021B7C4C 0x021B7C4C thumb ov103
 *   func_021B7D30 0x021B7D30 thumb ov103
 *   func_021B8C4C 0x021B8C4C thumb ov103
 *   func_021B7D44 0x021B7D44 thumb ov103
 *   func_021B7C5C  0x021B7C5C  thumb  ov103
 *   func_021B7C64  0x021B7C64  thumb  ov103
 */
#include "../../matched/include/Obj03740.h"
#include "../../matched/include/Obj22170.h"
#include "../../matched/include/Obj22173.h"
#include "../../matched/include/Obj22174.h"
#include "../../matched/include/Obj10240.h"
#include "../../matched/include/Obj22175.h"
#include "../../matched/include/Obj22176.h"
#include "../../matched/include/Obj22177.h"

#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))
struct Obj0203159C;
struct Ctx;
struct Rec;
struct S020315D4;
struct Obj;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern void func_021B8AF4(u8 *p, void *q);
extern void func_021B7F7C(u32 *p, int skip, u32 heap);
extern u32 func_02012138(const struct Ctx *p);
extern void func_021B800C(struct Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_021B8074(u8 *,int,int,u8,u8,u8,u8,u16,u8,u16);
extern void func_021B81A4(u8 *,void *,int);
extern void func_02041F6C(u32 which, u32 op, u32 value);
extern void func_02041FB0(u32,u32,u16);
extern void func_021B91A8(void *);
extern void func_021B9110(u8 *,void *,int,int,int,u8);
extern int func_021B7FFC(void *);
extern int func_021B8000(void *);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void func_021B63CC(int *,int);
extern void func_021B8338(u32 p, u32 a);
extern void func_021B8364(u8 *,u16 *);
extern void func_021B71C0(void *p);
extern void func_021B9174(void *p);
extern void func_021B80E4(u8 *);
extern void func_021B7FC8(u8 *);
extern void func_021B8B1C(u8 *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_0204E720(u32, int, int, int);
extern int func_0204E804(void);
extern u32 func_021B7FF0(u8 *);
extern int func_021B8100(u8 *p, u8 *q);
extern int func_021B63D0(struct Obj *p);
extern void func_021B71E4(int);
extern void func_0204335C(int);
extern void func_020433E0(void *);
extern int func_0204363C(int);
extern int func_0204361C(int);
extern void func_020434CC(int);
extern void func_021B7B3C(void *,void *,int);
extern void func_021B7970(void *,int);
extern void func_021B7C68(void *,int);
extern void func_021B8C14(void *,void *,int);
extern int func_020056A0(void *,void *,int);
extern void func_021B795C(void);
extern void func_02030EAC(struct Node *n);
extern void func_021B8C40(void *);
extern void func_021B7D08(u8 *p);
extern void func_021B7AE8(u32 *);
extern void func_021B7C08(u8 *);
extern void func_021B7C4C(void *);
extern void func_021B7D30(u8 *p);
extern void func_021B8C4C(u8 **);
extern void func_021B7D44(void *);
extern u32 func_021B7C5C(u8 *p, u32 i);
extern u32 func_021B7C64(u32 *p);
int func_021B7560(void *owner,int unused,void *arg);
int func_021B7748(int a, int b, int c, u8 *p);
int func_021B77B0(void *unused, u32 *state, int unused2, char *p);
void func_021B787C(u8 *p,int x);
void func_021B78EC(u8 *p);
void func_021B7918(u8 *p);
int func_021B793C(u8 *p, int i);
u32 func_021B7948(u8 *p);
u8 *func_021B7954(u8 *p);
extern u8 d_021B92D4[];



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



/*
 * volatile: 021B7750 reads display control register.
 */
int func_021B7748(int a, int b, int c, u8 *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    func_021B71C0((void *)(((struct Obj22174 *)p)->fA38));
    func_021B9174(p + 0x198);
    func_021B80E4(p + 0x748);
    func_021B80E4(p + 0x184);
    func_021B78EC(p);
    func_021B7FC8(p + 0x174);
    func_021B8B1C(p + 0x75c);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(55);
    return 1;
}



/*
 * prototype: 7FF0 tail-forwards to u32-returning 0201C4E4; caller tests live r0.
 */
int func_021B77B0(void *unused, u32 *state, int unused2, char *p)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        func_0204E720(3, 16, 0, 0);
        *state = 2;
        break;
    case 2:
        if (func_0204E804() == 0) *state = 3;
        break;
    case 3:
        (*(void (**)(char *, char *))(p + 0x728))(p, p + 0x72c);
        if (((struct Obj10240 *)p)->f730 != 0) *state = 4;
        break;
    case 4:
        func_0204E720(3, 0, 16, 0);
        *state = 5;
        break;
    case 5:
        if (func_0204E804() == 0) *state = 6;
        break;
    case 6:
        return 1;
    }
    if (func_021B7FF0((u8 *)(p + 0x174)) != 0) {
        func_021B8100((u8 *)(p + 0x184), (u8 *)(p + 0x174));
        func_021B8100((u8 *)(p + 0x748), (u8 *)(p + 0x174));
    }
    func_021B7918((u8 *)p);
    func_021B63D0(((struct Obj22175 *)(*(u8 * *)&((struct Obj10240 *)p)->fB0C))->f4);
    func_021B71E4(((struct Obj10240 *)p)->fA38);
    return 0;
}



/*
 * note: Verified against the ov103 Thumb image.
 */
void func_021B787C(u8 *p,int x) {func_02082BCC(p,0,0x174); func_0204335C(0); func_020433E0(d_021B92D4); func_020434CC(func_0204361C(func_0204363C(0))); func_021B7B3C(p+0xcc,d_021B92D4,x); func_021B7970(p,x); func_021B7C68(p+4,x); func_021B8C14(p+0x160,p+4,x); ((struct Obj22176 *)p)->f170=func_020056A0(func_021B795C,p,0); }


void func_021B78EC(u8 *p) { func_02030EAC(((struct Obj22177 *)p)->f170); func_021B8C40(p+352); func_021B7D08(p+4); func_021B7AE8((u32 *)p); func_021B7C08(p+204); }


void func_021B7918(u8 *p) { func_021B7C4C(p+204); func_021B7D30(p+4); func_021B8C4C((u8 **)(p+352)); func_021B7D44(p+4); }


/*
 * evidence: func_021B7C5C is ov103's own code ("lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x10]; bx lr" after pool_021B7C58), inside ov103's window, so
 * only ov103 can be resident there when this pool word is used.  Its start is
 * seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov103's own listing.  The old
 * hint ov016 named a different overlay's function mapped over the address.
 */
int func_021B793C(u8 *p, int i) { return func_021B7C5C(p + 0xcc, i); }


u32 func_021B7948(u8 *p) { return func_021B7C64((u32 *)(p + 0xcc)); }



u8 *func_021B7954(u8 *p) { return p + 0x160; }
