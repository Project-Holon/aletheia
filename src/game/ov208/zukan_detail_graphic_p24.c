/*
 * file:     zukan_detail_graphic_p24.c
 * unit:     yes
 * function: func_021C0C14, func_021C0C50, func_021C0C8C
 * address:  0x021C0C14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02166C7C  0x02166C7C  thumb
 *   func_021BBB48  0x021BBB48  thumb  ov072
 *   func_021BBB3C  0x021BBB3C  thumb  ov072
 *   func_0204B404  0x0204B404  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../../matched/include/Obj25500.h"
#include "../../matched/include/Obj10903.h"
#include "../../matched/include/Obj10904.h"

struct SaveBlock;
struct Rec44;
struct Obj;
struct Vec2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            s32;

extern int  ov208_func_021BC3A4(int key);
extern void *func_020127A4(struct SaveBlock *p);
extern u16  func_02012AC8(const struct Rec44 *a);
extern u32  func_02166C7C(int a, u32 b);
extern int func_021BBB48(int a0, int a1);
extern unsigned short func_021BBB3C(char *p, int a, int b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *obj, u32 on);
u8 ov208_func_021C0C14(u16 *heap, u8 *p, int key);
void ov208_func_021C0C50(u16 *heap, u8 *p, int key);
void ov208_func_021C0C8C(u16 *heap, u8 *p, int key, int on);


u8 ov208_func_021C0C14(u16 *heap, u8 *p, int key)
{
    int a;
    u32 m;
    int v;
    u8 r;

    a = ov208_func_021BC3A4(key);
    m = func_02012AC8((const struct Rec44 *)func_020127A4((struct SaveBlock *)a));
    r = 0xff;
    v = func_021BBB48(((struct Obj25500 *)p)->f3C8, func_02166C7C(a, m));
    if (v != 0xffff)
        r = v;
    return r;
}


void ov208_func_021C0C50(u16 *heap, u8 *p, int key)
{
    u8 idx;
    u16 pos[2];

    idx = ov208_func_021C0C14(heap, p, key);
    if (idx != 0xff) {
        pos[0] = func_021BBB3C((char *)(((struct Obj10903 *)p)->f3C8), idx, 2);
        pos[1] = func_021BBB3C((char *)(((struct Obj10903 *)p)->f3C8), idx, 3);
        func_0204B404((struct Obj *)(((struct Obj10903 *)p)->fD4), (const struct Vec2 *)pos, 0);
    }
}


void ov208_func_021C0C8C(u16 *heap, u8 *p, int key, int on)
{
    if (on) {
        if (ov208_func_021C0C14(heap, p, key) != 0xff) {
            func_0204B878((struct Obj *)(((struct Obj10904 *)p)->fD4), 6);
            func_0204B3DC((struct Obj *)((struct Obj10904 *)p)->fD4, 1);
        }
    } else {
        func_0204B3DC((struct Obj *)((struct Obj10904 *)p)->fD4, 0);
    }
}
