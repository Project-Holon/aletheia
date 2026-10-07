/*
 * file:     wifi_2dchar_p06.c
 * unit:     yes
 * function: func_021C447C, func_021C4494, func_021C4514, func_021C4550, func_021C4564, func_021C4594, func_021C45AC, func_021C45E0, func_021C4604, func_021C4634, func_021C4680
 * address:  0x021C447C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_021C4790 0x021C4790 thumb ov127
 *   d_021C5FE4 0x021C5FE4 data a4
 *   func_0204B8A0 0x0204B8A0 arm
 *   func_0204B8D4 0x0204B8D4 arm
 */
#include "../../matched/include/Obj03277.h"
#include "../../matched/include/Obj05372.h"
#include "../../matched/include/Obj10466.h"
#include "../../matched/include/Obj14020.h"
#include "../../matched/include/Obj10467.h"
#include "../../matched/include/Obj14021.h"
#include "../../matched/include/Obj14022.h"
#include "../../matched/include/Obj14023.h"
#include "../../matched/include/Obj23024.h"
#include "../../matched/include/Obj10468.h"
#include "../../matched/include/Obj14024.h"
#include "../../matched/include/Obj14025.h"
#include "../../matched/include/Obj14026.h"
#include "../../matched/include/Obj14027.h"
#include "../../matched/include/Obj14028.h"
#include "../../matched/include/Obj23025.h"
#include "../../matched/include/Obj23026.h"

struct Obj;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

extern signed int func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern int func_021C4790(char *);
extern void func_0204B8A0(struct Obj *p, u16 v);
extern void func_0204B8D4(struct Obj *p, u32 arg);
int func_021C447C(char *p, int i);
void func_021C4494(u8 *p, u32 a, u32 heap);
void func_021C4514(char *p);
int func_021C4550(int *p);
void func_021C4564(u8 *p,u32 a,u32 b,u32 heap);
void func_021C4594(u8 *p);
void func_021C45AC(u8 *p,u32 heap);
void func_021C45E0(u8 *p);
void *func_021C4604(u8 *p);
void func_021C4634(u8 *p);
void func_021C464C(u8 *p, u32 i);
void func_021C465C(u8 *p, u32 i);
void func_021C466C(u8 *p, u32 i);
void func_021C4680(u8 *p, u32 i);
void func_021C4698(u8 *p, u32 i);
void func_021C46AC(u8 *p, u32 i);
void func_021C46C0(u8 *p, u32 i);
void func_021C46D4(u8 *p, u32 i);
void func_021C46E8(u8 *p, u32 i);
void func_021C46FC(u8 *p);
void func_021C470C(u8 *p);


int func_021C447C(char *p, int i)
{
    if (*(int *)(p + i * 0x14 + 0x14) == -1)
        return 0;
    return 1;
}

/*
 * extent: two zero alignment bytes at 0x021C4512 follow the return.
 */
void func_021C4494(u8 *p, u32 a, u32 heap)
{
    int i;
    i = 16;
    if (func_021C447C((char *)p, 16) == 1) {
        ((struct Obj03277 *)p)->f330 = i;
    } else {
        i = 17;
        if (func_021C447C((char *)p, 17) == 1)
        ((struct Obj03277 *)p)->f330 = i;
    }
    ((struct Obj03277 *)p)->f2E8 = (u32)func_0204AF28((void *)(((struct Obj03277 *)p)->f2F8), 9, 8, (u16)heap);
    ((struct Obj03277 *)p)->f2E0 = func_0204A6C8((void *)(((struct Obj03277 *)p)->f2F8), 11, 0, a, heap);
    ((struct Obj03277 *)p)->f2E4 = func_0204AC18((void *)(((struct Obj03277 *)p)->f2F8), 10, a, 320, 0, 1, heap);
}

/*
 * extent: trailing 2-byte alignment padding only.
 */
void func_021C4514(char *p) { if(func_021C4550((int *)(p+0x2e0))==1) { func_0204A8D4(((struct Obj05372 *)p)->f2E0); ((struct Obj05372 *)p)->f2E0=-1; func_0204ADA4(((struct Obj05372 *)p)->f2E4); ((struct Obj05372 *)p)->f2E4=-1; func_0204AFD8(((struct Obj05372 *)p)->f2E8); ((struct Obj05372 *)p)->f2E8=-1; } }


int func_021C4550(int *p)
{
    return *p != -1;
}

void func_021C4564(u8 *p,u32 a,u32 b,u32 heap) { ((struct Obj10466 *)p)->f2F4=func_0204AC18(((struct Obj10466 *)p)->f2FC,0,a,(u16)b,0,8,heap); }


/*
 * Addresses are Black-image addresses.
 */
void func_021C4594(u8 *p)
{
    func_0204ADA4((u32)(((struct Obj14020 *)p)->f2F4));
    *(u32 *)&((struct Obj14020 *)p)->f2F4 = (u32)-1;
}

/*
 * Extent remainder: 2-byte zero alignment padding.
 */
void func_021C45AC(u8 *p,u32 heap) { int i; for(i=0;i<16;i++) *(u32 *)(p+i*20+392)=func_0204AF28(((struct Obj10466 *)p)->f2FC,i*2+17,i*2+18,(u16)heap); }

void func_021C45E0(u8 *p) { int i; for(i=0;i<16;i++){func_0204AFD8(*(u32 *)(p+i*20+392));*(u32 *)(p+i*20+392)=-1;} }

void *func_021C4604(u8 *p) { u32 i; for(i=0;i<((struct Obj10467 *)p)->fC;i++) { if(func_021C4790(*(char * *)&((struct Obj10467 *)p)->f8+i*24)==1) return *(char * *)&((struct Obj10467 *)p)->f8+i*24; } return 0; }

extern void (*const d_021C5FE4[])(u8 *);

void func_021C4634(u8 *p)
{
    void (*f)(u8 *);
    f = d_021C5FE4[((struct Obj23024 *)p)->fC];
    if (f) f(p);
}

void func_021C464C(u8 *p, u32 i)
{
    ((struct Obj14021 *)p)->f10 = i;
    func_0204B8A0(((struct Obj14021 *)p)->f4, i);
}

void func_021C465C(u8 *p, u32 i)
{
    ((struct Obj14022 *)p)->f10 = i;
    func_0204B8A0(((struct Obj14022 *)p)->f4, 4);
}

void func_021C466C(u8 *p, u32 i)
{
    ((struct Obj14023 *)p)->f10 = i;
    func_0204B8A0(((struct Obj14023 *)p)->f4, i + 5);
}

void func_021C4680(u8 *p, u32 i)
{
    func_0204B8A0(((struct Obj10468 *)p)->f4, ((struct Obj10468 *)p)->f10 + 5);
    ((struct Obj10468 *)p)->f10 = i;
}

void func_021C4698(u8 *p, u32 i)
{
    ((struct Obj14024 *)p)->f10 = i;
    func_0204B8A0(((struct Obj14024 *)p)->f4, i + 9);
}

void func_021C46AC(u8 *p, u32 i)
{
    ((struct Obj14025 *)p)->f10 = i;
    func_0204B8A0(((struct Obj14025 *)p)->f4, i + 5);
}

void func_021C46C0(u8 *p, u32 i)
{
    ((struct Obj14026 *)p)->f10 = i;
    func_0204B8A0(((struct Obj14026 *)p)->f4, i + 5);
}

void func_021C46D4(u8 *p, u32 i)
{
    ((struct Obj14027 *)p)->f10 = i;
    func_0204B8A0(((struct Obj14027 *)p)->f4, i + 5);
}

void func_021C46E8(u8 *p, u32 i)
{
    ((struct Obj14028 *)p)->f10 = i;
    func_0204B8A0(((struct Obj14028 *)p)->f4, i + 5);
}

void func_021C46FC(u8 *p) { func_0204B8D4(((struct Obj23025 *)p)->f4, 8192); }

void func_021C470C(u8 *p) { func_0204B8D4(((struct Obj23026 *)p)->f4, 8192); }
