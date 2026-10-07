/*
 * file:     pmsiv_category_p04.c
 * unit:     yes
 * function: func_021BB61C, func_021BB658, func_021BB6A0, func_021BB76C, func_021BB784, func_021BB7A0, func_021BB7B8, func_021BB804, func_021BB814
 * address:  0x021BB61C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   d_021C38D0 0x021C38D0 data ov110 a2
 *   func_021BAC3C 0x021BAC3C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_0204B404 0x0204B404 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BC8FC 0x021BC8FC thumb ov110
 *   func_021BC93C 0x021BC93C thumb ov110
 *   func_021BC78C 0x021BC78C thumb ov110
 *   func_021BC7DC 0x021BC7DC thumb ov110
 *   func_02040618 0x02040618 arm
 */
#include "../../matched/include/Obj03240.h"
#include "../../matched/include/Obj04444.h"
#include "../../matched/include/Obj04445.h"
#include "../../matched/include/Obj22365.h"
#include "../../matched/include/Obj22366.h"
#include "../../matched/include/Obj22367.h"
#include "../../matched/include/Obj13779.h"

struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021BB61C;

typedef unsigned int u32;

typedef struct { int a,b,c; } Triple;

typedef signed short s16_021BB6A0;

typedef struct { s16_021BB6A0 x, y; } Vec2;

typedef short s16_021BB76C;

typedef short s16_021BB784;

typedef short s16_021BB7A0;

typedef short s16_021BB814;

extern void func_021BAC64(void *,Triple *,int,int);
extern struct Obj *func_021BAC78(char *p, u32 *r, short x, short y, u32 a, int mode);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u8 func_021BF6DC(u8 *);
extern unsigned func_021BAC3C(u8 *);
extern void func_021BCF7C(u8 *, int, int);
extern void func_021BB224(unsigned, int *, int *);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_021BC8FC(u8 *,int,int,int,int);
extern int func_021BC93C(u8 *);
extern void func_021BC78C(u8 *,int,int,int,int);
extern int func_021BC7DC(u8 *p);
extern void func_02040618(unsigned, unsigned, unsigned);
void func_021BB61C(u8 *p);
void func_021BB658(u8 *p, int enable);
void func_021BB6A0(u8 *p, unsigned index);
void func_021BB76C(u8 *p);
int func_021BB784(u8 *p);
void func_021BB7A0(u8 *p);
int func_021BB7B8(u8 *p);
void func_021BB804(u8 *a0);
void func_021BB814(u8 *p);
extern const Vec2 d_021C38D0;

void func_021BB61C(u8 *p) { Triple t; func_021BAC64(((struct Obj03240 *)p)->f0,&t,0,0); ((struct Obj03240 *)p)->f54=func_021BAC78(((struct Obj03240 *)p)->f0,(u32 *)(&t),48,64,3,1); func_0204B878(((struct Obj03240 *)p)->f54,4); func_0204B3DC(((struct Obj03240 *)p)->f54,0); }

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021BB658(u8 *p, int enable)
{
    if (enable) {
        if (**(int * *)&((struct Obj04444 *)p)->f5C == 0) {
            func_0204B3DC(((struct Obj04444 *)p)->f54, 1);
            if (func_021BF6DC(*(u8 * *)&((struct Obj04444 *)p)->f4) == 0) {
                func_0204B878(((struct Obj04444 *)p)->f54, 4);
            } else {
                func_0204B878(((struct Obj04444 *)p)->f54, 6);
            }
        } else {
            func_0204B3DC(((struct Obj04444 *)p)->f54, 0);
        }
    } else {
        func_0204B3DC(((struct Obj04444 *)p)->f54, 0);
    }
}

/*
 * lever: ordered if/else chain, not switch dispatch; template word is 0x012C0190.
 */
void func_021BB6A0(u8 *p, unsigned index)
{
    Vec2 pos;
    int x, y;
    int state;
    u8 *q;
    pos = d_021C38D0;
    if (func_021BF6DC(*(u8 * *)&((struct Obj04445 *)p)->f4) == 0 && index != 254) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        state = 4;
    } else {
        q = (u8 *)func_021BAC3C(*(u8 * *)&((struct Obj04445 *)p)->f0);
        state = 16;
        if (index == 252) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) func_021BCF7C(q, 0, 1);
            else func_021BCF7C(q, 0, 0);
        } else if (index == 253) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) func_021BCF7C(q, 1, 1);
            else func_021BCF7C(q, 0, 0);
        } else if (index == 254) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) func_021BCF7C(q, 2, 1);
            else func_021BCF7C(q, 0, 0);
        } else {
            func_021BCF7C(q, 0, 0);
            func_021BB224(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            state = 6;
        }
    }
    func_0204B404(((struct Obj04445 *)p)->f54, (const struct Vec2 *)(&pos), 0);
    func_0204B878(((struct Obj04445 *)p)->f54, state);
}

void func_021BB76C(u8 *p) { ((struct Obj22365 *)p)->f10=0; func_021BC8FC(p+24,2,-10,0,16); }

int func_021BB784(u8 *p) { if (((struct Obj22366 *)p)->f10==0 && func_021BC93C(p+24)!=0) return 1; return 0; }

/*
 * extent: two bytes of zero alignment padding after return.
 */
void func_021BB7A0(u8 *p) { ((struct Obj22367 *)p)->f10=0; func_021BC78C(p+56,1,1,0,6); }

/*
 * extent: includes the unlabelled tail-call stub at 0x021BB804.
 */
int func_021BB7B8(u8 *p)
{
    switch (((struct Obj13779 *)p)->f10) {
    case 0:
        if (func_021BC7DC(p + 0x38)) {
            func_021BC8FC(p + 0x18, 2, 0, -10, 16);
            ++((struct Obj13779 *)p)->f10;
        }
        break;
    case 1:
        return func_021BC93C(p + 0x18);
    }
    return 0;
}

void func_021BB804(u8 *a0)
{
    func_02040618(1, 3, 16);
}

/*
 * extent: two-byte alignment padding then existing ov110_func_021BB82C.c follower.
 */
void func_021BB814(u8 *p) { func_021BC8FC(p+24,2,0,-10,16); }
