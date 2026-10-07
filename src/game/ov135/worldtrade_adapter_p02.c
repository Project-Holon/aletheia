/*
 * file:     worldtrade_adapter_p02.c
 * unit:     yes
 * function: func_021FBA84, func_021FBBA0, func_021FBC1C, func_021FBC78
 * address:  0x021FBA84
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_021F8908 0x021F8908 thumb ov135
 *   func_021FB364 0x021FB364 thumb ov135
 *   func_021F9EEC 0x021F9EEC thumb ov135
 *   func_021FBF04 0x021FBF04 thumb ov135
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   tbl_02203324 0x02203324 data a4
 *   tbl_02203236 0x02203236 data a1
 *   func_0204B898 0x0204B898 arm
 *   func_021FA85C 0x021FA85C thumb ov135
 *   func_021F9660  0x021F9660  thumb  ov135
 *   g_022033FC  0x022033FC  data  ov135
 *   func_0204B98C 0x0204B98C arm
 */
#include "../../matched/include/Obj00437.h"
#include "../../matched/include/Obj23404.h"
#include "../../matched/include/Obj23405.h"
#include "../../matched/include/Obj02201.h"
#include "../../matched/include/Obj00098.h"

struct WinMgr;
struct Obj;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {u8 x,y;} Cell;

typedef signed char s8;

typedef signed int s32;

extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern u8 func_020355C4(void);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B92C(struct Obj *,u32);
extern void func_021F9260(void *,u32);
extern int func_021F8908(void **menu, void *msg, int id);
extern void func_021FB364(void *,int,int);
extern u32 func_021F9EEC(u8 *p, u32 n);
extern void func_021FBF04(void *,void *,void *,int,u32);
extern void func_021FBEB8(void *,void *,void *,u32,void *);
extern void func_021F4FF4(u32,u32,u32);
extern u16 func_0204B898(struct Obj *p);
extern int func_021FA85C(void *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021F9660(u8 *p, u32 k);
extern u32 func_0201F868(void *p);
int func_021FBA84(u8 *p);
int func_021FBBA0(u8 *p);
int func_021FBC1C(u8 *p);
int func_021FBC78(u8 *p);
extern const int tbl_02203324[];
extern const Cell tbl_02203236[];
extern u8 g_022033FC[];

int func_021FBA84(u8 *p)
{
    u8 pages;
    func_0202CAE4(((struct Obj00437 *)p)->f18,0,0x60,0x18,1);
    func_021F9260(p,3);
    ((struct Obj00437 *)p)->f58=func_021F8908((void **)(p+0x30),((struct Obj00437 *)p)->f28,((struct Obj00437 *)p)->f3A+tbl_02203324[((struct Obj00437 *)p)->f38]);
    func_021FB364(p,0,((struct Obj00437 *)p)->f58);
    ((struct Obj00437 *)p)->f56=0;
    pages=func_021F9EEC((u8 *)(((struct Obj00437 *)p)->f58),5);
    func_021FBF04(((struct Obj00437 *)p)->f18,((struct Obj00437 *)p)->f34,((struct Obj23404 *)(*(u8 * *)&((struct Obj00437 *)p)->f0))->f14,((struct Obj00437 *)p)->f56,pages);
    func_021FBEB8(((struct Obj00437 *)p)->f18,((struct Obj00437 *)p)->f20,((struct Obj23405 *)(*(u8 * *)&((struct Obj00437 *)p)->f0))->f38,0x4A,p+0x7C);
    func_0202CB4C(((struct Obj00437 *)p)->f18,0,1,0);
    ((struct Obj00437 *)p)->f44=0;
    func_021F4FF4(((struct Obj00437 *)p)->f8,tbl_02203236[*(int *)(p+0x44)].x,tbl_02203236[*(int *)(p+0x44)].y);
    func_021F4FF4(((struct Obj00437 *)p)->fC,0xB0,0x88);
    func_021F4FF4(((struct Obj00437 *)p)->f10,0x58,0x88);
    if(func_020355C4()==1)
        func_0204B3DC((struct Obj *)((struct Obj00437 *)p)->f8,0);
    else
        func_0204B3DC((struct Obj *)((struct Obj00437 *)p)->f8,1);
    if(pages==1) {
        func_0204B878((struct Obj *)(((struct Obj00437 *)p)->fC),0x3D);
        func_0204B878((struct Obj *)(((struct Obj00437 *)p)->f10),0x3E);
    } else {
        func_0204B878((struct Obj *)(((struct Obj00437 *)p)->fC),0x26);
        func_0204B878((struct Obj *)(((struct Obj00437 *)p)->f10),0x27);
    }
    func_0204B92C((struct Obj *)((struct Obj00437 *)p)->fC,0);
    func_0204B92C((struct Obj *)((struct Obj00437 *)p)->f10,0);
    func_0204B3DC((struct Obj *)((struct Obj00437 *)p)->fC,1);
    func_0204B3DC((struct Obj *)((struct Obj00437 *)p)->f10,1);
    ((struct Obj00437 *)p)->f48=27;
    return -1;
}

int func_021FBBA0(u8 *p)
{
    int r;
    r = func_021FA85C(p);
    switch (r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj02201 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02201 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02201 *)p)->f8)) + 9);
        func_0202CAE4(((struct Obj02201 *)p)->f18, 0, 0x60, 0x18, 1);
        ((struct Obj02201 *)p)->f48 = 5;
        ((struct Obj02201 *)p)->f4C = 28;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj02201 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02201 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02201 *)p)->f8)) + 9);
        ((struct Obj02201 *)p)->f48 = 3;
        ((struct Obj02201 *)p)->f4C = 29;
        ((struct Obj02201 *)p)->f3E = r;
        break;
    }
    return -1;
}


/*
 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0x19/0x15 code from the table.
 */
int func_021FBC1C(u8 *p)
{
    if (func_0204B98C((struct Actor *)(*(u32 *)&((struct Obj00098 *)p)->f8)) != 0) {
        return -1;
    }
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    func_021F9660(p, 0x3);
    func_0201F868((void *)(*(u32 *)&((struct Obj00098 *)p)->f30));
    *(u32 *)&((struct Obj00098 *)p)->f48 = (*(s32 *)(g_022033FC + ((struct Obj00098 *)p)->f38 * 8) != 1) ? 0x19 : 0x15;
    return -1;
}

int func_021FBC78(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8) != 0) return -1;
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    func_021F9660(p, 3);
    func_0201F868(((struct Obj00098 *)p)->f30);
    return ((struct Obj00098 *)p)->f3E;
}
