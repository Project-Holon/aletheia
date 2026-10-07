/*
 * file:     worldtrade_enter_p19.c
 * unit:     yes
 * function: func_021FB588, func_021FB5E4, func_021FB614, func_021FB674, func_021FB704, func_021FB7A0
 * address:  0x021FB588
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
 *   func_021F9660  0x021F9660  thumb  ov135
 *   g_022033FC  0x022033FC  data  ov135
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0201F868 0x0201F868 thumb
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021FA9C8 0x021FA9C8 thumb ov135
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   tbl_02203298 0x02203298 data a1
 *   func_021FA514 0x021FA514 thumb ov135
 *   tbl_022033FC 0x022033FC data a4
 */
#include "../../matched/include/Obj00098.h"
#include "../../matched/include/Obj02858.h"
#include "../../matched/include/Obj00195.h"
#include "../../matched/include/Obj02859.h"

struct Actor;
struct Obj;
struct WinMgr;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

typedef signed char s8;

extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *v, unsigned int k);
extern void func_021F9660(u8 *p, u32 k);
extern u32 func_0201F868(void *p);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021FA9C8(u8 *p, int mode, int pos);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern u8 func_020355C4(void);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern int func_021FA514(void *p, u8 *flags);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
int func_021FB588(u8 *p);
int func_021FB5E4(u8 *p);
int func_021FB614(u8 *p);
int func_021FB674(u8 *p);
int func_021FB704(u8 *p);
int func_021FB7A0(u8 *p);
extern u8 g_022033FC[];
extern const u8 tbl_02203298[][2];
extern const int tbl_022033FC[][2];


/*
 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0xd/0x9 code from the table.
 */
int func_021FB588(u8 *p)
{
    if (func_0204B98C((struct Actor *)(*(u32 *)&((struct Obj00098 *)p)->f8)) != 0) {
        return -1;
    }
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    func_021F9660(p, 0x0);
    func_0201F868((void *)(*(u32 *)&((struct Obj00098 *)p)->f30));
    *(u32 *)&((struct Obj00098 *)p)->f48 = (*(s32 *)(g_022033FC + ((struct Obj00098 *)p)->f38 * 8) != 1) ? 0xd : 0x9;
    return -1;
}

int func_021FB5E4(u8 *p) { if(func_0204B98C(((struct Obj00098 *)p)->f8))return -1;func_0204B3DC(((struct Obj00098 *)p)->f8,0);func_021F9660(p,0);func_0201F868(((struct Obj00098 *)p)->f30);return ((struct Obj00098 *)p)->f3C; }

int func_021FB614(u8 *p)
{
    func_021FA9C8(p, 6, 0x20);
    func_0204B878((struct Obj *)(((struct Obj02858 *)p)->f8), 18);
    func_0202CD64(((struct Obj02858 *)p)->f18, 0, -4, 0, 4);
    ((struct Obj02858 *)p)->f48 = 1;
    ((struct Obj02858 *)p)->f4C = 19;
    ((struct Obj02858 *)p)->f44 = 10;
    ((struct Obj02858 *)p)->f38 = -1;
    func_021F4FF4(((struct Obj02858 *)p)->f8, (tbl_02203298[((struct Obj02858 *)p)->f44][0] + 16) * 8, tbl_02203298[((struct Obj02858 *)p)->f44][1] * 8);
    func_0204B878((struct Obj *)(((struct Obj02858 *)p)->f8), 6);
    return -1;
}

int func_021FB674(u8 *p)
{
    int r;
    r = func_021FA514(p, p + 0x60);
    switch ((u32)r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00195 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00195 *)p)->f8)) + 9);
        ((struct Obj00195 *)p)->f48 = 3;
        ((struct Obj00195 *)p)->f4C = 20;
        ((struct Obj00195 *)p)->f38 = -1;
        break;
    case 10:
        func_0204B3DC((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00195 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00195 *)p)->f8)) + 9);
        ((struct Obj00195 *)p)->f48 = 3;
        ((struct Obj00195 *)p)->f4C = 20;
        ((struct Obj00195 *)p)->f38 = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00195 *)p)->f8), 19);
        ((struct Obj00195 *)p)->f38 = r;
        ((struct Obj00195 *)p)->f48 = 20;
        break;
    }
    return -1;
}

int func_021FB704(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8) != 0) return -1;
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_021F9660(p, 6);
    if (((struct Obj00098 *)p)->f38 < 0) {
        if (((struct Obj00098 *)p)->f38 == -1) return -2;
        else if (((struct Obj00098 *)p)->f38 == -2) return 0;
    } else {
        if (tbl_022033FC[((struct Obj00098 *)p)->f38][0] != 1) {
            ((struct Obj00098 *)p)->f48 = 22;
        } else {
            ((struct Obj00098 *)p)->f3A = 0;
            func_0202CD64(((struct Obj00098 *)p)->f18, 0, -4, 0, 3);
            if (((struct Obj00098 *)p)->f14 != 0) func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f14, 0);
            func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00098 *)p)->f8), 7);
            ((struct Obj00098 *)p)->f48 = 2;
            func_0202CAE4(((struct Obj00098 *)p)->f18, 0, 0x60, 0x18, 1);
            ((struct Obj00098 *)p)->f4C = 26;
        }
    }
    return -1;
}

int func_021FB7A0(u8 *p)
{
    func_021FA9C8(p, 6, 0x10);
    func_0204B878((struct Obj *)(((struct Obj02859 *)p)->f8), 18);
    func_0204B3DC((struct Obj *)((struct Obj02859 *)p)->f8, 1);
    ((struct Obj02859 *)p)->f44 = ((struct Obj02859 *)p)->f38;
    func_021F4FF4(((struct Obj02859 *)p)->f8, (tbl_02203298[((struct Obj02859 *)p)->f44][0] + 16) * 8, tbl_02203298[((struct Obj02859 *)p)->f44][1] * 8);
    if (func_020355C4() == 1) func_0204B3DC((struct Obj *)((struct Obj02859 *)p)->f8, 0);
    else func_0204B3DC((struct Obj *)((struct Obj02859 *)p)->f8, 1);
    ((struct Obj02859 *)p)->f48 = 19;
    return -1;
}
