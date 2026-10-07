/*
 * file:     gsync_state_p08.c
 * unit:     yes
 * function: func_021D60F8, func_021D614C, func_021D62A8, func_021D62B4, func_021D62BC, func_021D62D0, func_021D62E0, func_021D62F8
 * address:  0x021D60F8
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A648 0x0204A648 arm
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049F78 0x02049F78 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021D6404 0x021D6404 thumb ov123
 *   func_021D634C 0x021D634C thumb ov123
 *   func_0204B878  0x0204B878  arm
 *   func_0204BA00  0x0204BA00  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../../matched/include/Obj06462.h"
#include "../../matched/include/Obj22948.h"
#include "../../matched/include/Obj00343.h"
#include "../../matched/include/Obj03266.h"

struct Obj;
struct Actor;
struct Cmd;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed short s16;

struct Point { s16 x, y; u16 f4; u8 f6, f7; };

extern void func_0204A648(void);
extern void func_0207E3D0(void *, unsigned int, unsigned int);
extern void func_0207E468(void *, unsigned int, unsigned int);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_021D6404(u8 *);
extern void func_021D634C(u8 *,unsigned int);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B3B4(struct Obj *p);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021D60F8(void *a, u8 *p);
void func_021D614C(u8 *p);
void func_021D62A8(u8 *p);
void func_021D62B4(u8 *p,unsigned int i);
void func_021D62BC(u8 *p, int i, u32 v);
void func_021D62D0(u8 *p, int i, int v);
void func_021D62E0(u8 *p, int i);
void func_021D62F8(u8 *p, int x, int y);

void func_021D60F8(void *a, u8 *p)
{
    int n;
    u8 *base;
    int off;
    func_0204A648();
    n = ((struct Obj06462 *)p)->f4564 + 1;
    ((struct Obj06462 *)p)->f4564 = n;
    if (n % 10 == 1) {
        base = *(u8 * *)&((struct Obj22948 *)(*(u8 * *)&((struct Obj06462 *)p)->f18))->fC;
        off = (n / 10 + 2) * 32;
        func_0207E3D0(base + off, 64, 32);
        func_0207E468(base + off, 64, 32);
    }
    if (((struct Obj06462 *)p)->f4564 >= 80) ((struct Obj06462 *)p)->f4564 = 0;
}

void func_021D614C(u8 *p)
{
    void *h;
    h=func_020490F4((u32)((void *)143),((struct Obj00343 *)p)->f43C4);
    func_02049B68(h,2,4,0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f0=func_02049740(h,8,4,0,0,((struct Obj00343 *)p)->f43C4);
    func_02049990(h,21,4,0,(u16)(((struct Obj00343 *)p)->f0),0,0,((struct Obj00343 *)p)->f43C4);
    func_02049990(h,24,7,0,(u16)(((struct Obj00343 *)p)->f4),0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f1C=func_02049F78(h,2,(u32)((void **)(p+0x18)),((struct Obj00343 *)p)->f43C4);
    func_02049B68(h,2,0,0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f4=func_02049740(h,8,0,0,0,((struct Obj00343 *)p)->f43C4);
    func_02049990(h,23,0,0,(u16)(((struct Obj00343 *)p)->f4),0,0,((struct Obj00343 *)p)->f43C4);
    func_02049990(h,24,1,0,(u16)(((struct Obj00343 *)p)->f4),0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f38=(void *)func_0204A6C8(h,9,0,2,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f20=(void *)func_0204AC18(h,3,2,96,0,4,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f54=(void *)func_0204AF28(h,12,25,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f3C=(void *)func_0204A6C8(h,10,0,2,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f24=(void *)func_0204AC18(h,4,2,224,0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f58=(void *)func_0204AF28(h,13,26,((struct Obj00343 *)p)->f43C4);
    func_021D6404(p); func_02049238(h);
}

void func_021D62A8(u8 *p){func_021D62F8(p,133,128);}

void func_021D62B4(u8 *p,unsigned int i){func_021D634C(p,i);}


/*
 * Addresses are Black-image addresses.
 */
void func_021D62BC(u8 *p, int i, u32 v)
{
    func_0204B878(*(void **)(p + i * 4 + 0x74), (u16)v);
}


void func_021D62D0(u8 *p, int i, int v)
{
    func_0204BA00(*(void **)(p + i * 4 + 0x74), (const struct Cmd *)v);
}


void func_021D62E0(u8 *p, int i)
{
    if (*(u32 *)(p + 0x74 + i * 4)) {
        func_0204B3B4(*(void **)(p + 0x74 + i * 4));
        *(u32 *)(p + 0x74 + i * 4) = 0;
    }
}

void func_021D62F8(u8 *p, int x, int y)
{
    struct Point pt;
    if (((struct Obj03266 *)p)->fAC == 0) {
        pt.x = x; pt.y = y; pt.f4 = 0; pt.f6 = 0; pt.f7 = 1;
        ((struct Obj03266 *)p)->fAC = func_0204B294((void *)((struct Obj03266 *)p)->fC, (u32)((struct Obj03266 *)p)->f3C, ((struct Obj03266 *)p)->f24, ((struct Obj03266 *)p)->f58, &pt, 1, ((struct Obj03266 *)p)->f43C4);
        func_0204B92C(((struct Obj03266 *)p)->fAC, 1);
        func_0204B3DC(((struct Obj03266 *)p)->fAC, 1);
    }
}
