/*
 * file:     startmenu_p10.c
 * unit:     yes
 * function: func_021BB798, func_021BB810, func_021BB840, func_021BB858, func_021BB890
 * address:  0x021BB798
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020410D0  0x020410D0  arm
 *   func_0202CF84  0x0202CF84  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   d_021BD5EE     0x021BD5EE  data  ov088  a2
 *   func_020413B0  0x020413B0  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   _s32_div_f     0x0209C0A4  arm
 */
#include "../../matched/include/Obj20819.h"
#include "../../matched/include/Obj20820.h"
#include "../../matched/include/Obj00271.h"

#define ROWH(r) (*(u16 *)((char *)d_021BD5EE + (r) * 4))
struct WinMgr;
struct Actor;
struct PtS;
struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

typedef struct { s16 x; s16 y; } Pos;

extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_02041B6C(u32);
extern void func_020413B0(u32, u32, u8, u8, u8, u32);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BB798(char *p, u32 i, u32 arg);
void func_021BB810(void *p, u8 row, int y, int pal);
int func_021BB840(char *p, int y);
void func_021BB858(char *p, int d);
int func_021BB890(char *p, int d);
extern u16 d_021BD5EE[];


void func_021BB798(char *p, u32 i, u32 arg)
{
    u8 v = arg;
    u16 x = *(u16 *)((char *)d_021BD5EE + i * 4);
    u32 h;
    func_020410D0(2, 3, v, 0x1a, x, (u32)(*(void **)(p + i * 4 + 0xf8)), 0, 0, 0x1a, x);
    h = func_0202CF84(((struct Obj20819 *)p)->f118, i);
    func_020410D0(1, 3, v, 0x1a, x, (u32)((void *)h), 0, 0, 0x1a, x);
    func_02041B6C(1);
    func_02041B6C(2);
}


/*
 * Redraws menu row `row` (height from the row table d_021BD5EE) at tile
 * row y on bg layer 2 with palette pal, then commits the layer.
 */
void func_021BB810(void *p, u8 row, int y, int pal)
{
    func_020413B0(2, 3, y, 0x1a, *(u16 *)((char *)d_021BD5EE + row * 4), pal);
    func_02041B6C(2);
}


int func_021BB840(char *p, int y)
{
    return (s8)(y + ((struct Obj20820 *)p)->f130 / 8);
}

/*
 * Shifts the six sprites at +0x1c..+0x30 vertically by d.
 */
void func_021BB858(char *p, int d)
{
    u32 i;
    Pos pos;
    for (i = 0; i < 6; i++) {
        func_0204B454((struct Actor *)*(int *)((p + i * 4) + 0x1c), (struct PtS *)&pos, 0);
        pos.y += (s16)d;
        func_0204B404((struct Obj *)(*(int *)((p + i * 4) + 0x1c)), (const struct Vec2 *)(&pos), 0);
    }
}


int func_021BB890(char *p, int d)
{
    u8 old;
    u16 h;
    s8 y;
    u8 nv;
    s8 n;
    u8 cur;

    cur = p[0x128];
    old = (p + cur)[0x120];
    ((struct Obj00271 *)p)->f134 = 0;
    if (d < 0) {
        if (cur == 0)
            return 0;
        n = cur + d;
        h = ROWH((u8)(p + n)[0x120]);
        y = (s8)p[0x12f] - h;
        func_021BB810(p, old, func_021BB840(p, (s8)p[0x12f]), 1);
        if ((u8)p[0x120] == 0) {
            if (y < 2) {
                if (n == 0) {
                    ((struct Obj00271 *)p)->f138 = -(((h - ((s8)p[0x12f] - 2)) / 3) * 8);
                    p[0x12f] = 2;
                } else {
                    ((struct Obj00271 *)p)->f138 = -((h / 3) * 8);
                }
            } else {
                p[0x12f] = y;
            }
        } else {
            p[0x12f] = y;
        }
    } else {
        if (cur + d >= 8)
            return 0;
        if ((u8)(p + (cur + d))[0x120] == 8)
            return 0;
        nv = (p + (s8)(cur + d))[0x120];
        y = (s8)p[0x12f] + ROWH(old);
        func_021BB810(p, old, func_021BB840(p, (s8)p[0x12f]), 1);
        if ((u8)p[0x120] == 0) {
            if (y == 0x18) {
                ((struct Obj00271 *)p)->f138 = (ROWH(nv) / 3) * 8;
            } else if (y + ROWH(nv) > 0x18) {
                ((struct Obj00271 *)p)->f138 = (ROWH(nv) / 3) * 8;
            } else {
                p[0x12f] = y;
            }
        } else {
            p[0x12f] = y;
        }
    }
    ((struct Obj00271 *)p)->f128 += (u8)d;
    return 1;
}
