/*
 * file:     gsync_state_p10.c
 * unit:     yes
 * function: func_021D65F4, func_021D6650, func_021D6678, func_021D66D0, func_021D6720, func_021D679C, func_021D67B4
 * address:  0x021D65F4
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
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_02005624 0x02005624 thumb
 *   func_021D6548 0x021D6548 thumb ov123
 *   func_02024230 0x02024230 thumb
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   _fflt 0x0209BDBC arm
 *   _f2d 0x0209BD38 arm
 *   _dmul 0x0209B2E8 arm
 *   _d2f 0x0209B64C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021D6C48 0x021D6C48 thumb ov123
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B570 0x0204B570 arm
 *   d_021DA730 0x021DA730 data a2
 *   d_021DA750 0x021DA750 data a4
 *   func_021D6C90 0x021D6C90 thumb ov123
 *   d_021DA734 0x021DA734 data a2
 *   d_021DA740 0x021DA740 data a4
 */
#include "../../matched/include/Obj08108.h"
#include "../../matched/include/Obj08109.h"
#include "../../matched/include/Obj03267.h"
#include "../../matched/include/Obj13978.h"
#include "../../matched/include/Obj13979.h"
#include "../../matched/include/Obj10441.h"
#include "../../matched/include/Obj13980.h"

struct Obj;
struct Vec2;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed int     s32;

struct Pos { short x,y; };

struct Pair { int a,b; };

extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_021D6548(void *, u8 *);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void func_02024230(s16 *out, u32 count, u16 step, s32 amp);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_021D6C48(char *p, int i, void *h);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_021D6C90(char *p, int i, void *h);
void func_021D65F4(u8 *p);
void func_021D6650(u8 *p,int flag);
void func_021D6678(u8 *p);
void func_021D66D0(u8 *p, int n);
void func_021D6720(u8 *p, int i);
void func_021D679C(u8 *p);
void func_021D67B4(u8 *p, int i);
extern const struct Pos d_021DA730;
extern const struct Pair d_021DA750;
extern const struct Pos d_021DA734;
extern const struct Pair d_021DA740;

void func_021D65F4(u8 *p)
{
    void *h;
    h = func_020490F4(143, ((struct Obj08108 *)p)->f43C4);
    func_02049990(h, 22, 3, 0, (u16)((struct Obj08108 *)p)->f4, 0, 0, ((struct Obj08108 *)p)->f43C4);
    func_02049238(h);
    ((struct Obj08108 *)p)->f14 = func_02005624((u32)func_021D6548, (u32)p, 0);
    func_02024230((s16 *)(p + 0x43c8), 192, 0x5b0, 0x1800);
}

void func_021D6650(u8 *p,int flag){if(flag){((struct Obj08109 *)p)->f4554=0;((struct Obj08109 *)p)->f4558=1;}else{((struct Obj08109 *)p)->f4554=65536;((struct Obj08109 *)p)->f4558=-1;}}

void func_021D6678(u8 *p)
{
    int v;
    if (((struct Obj03267 *)p)->f4558 != 0) {
        ((struct Obj03267 *)p)->f4554 += ((struct Obj03267 *)p)->f4558 << 10;
        v = ((struct Obj03267 *)p)->f4554 >> 12;
        func_02040588(3, 1);
        if (v > 10) { ((struct Obj03267 *)p)->f4558 = 0; return; }
        if (v < 0) { v = 0; func_02040588(3, 0); ((struct Obj03267 *)p)->f4558 = v; return; }
        func_0207D63C((void *)0x04000050, 8, 55, v, 8);
    }
}

void func_021D66D0(u8 *p, int n)
{
    float x = (float)(1.2 * (double)(float)n);
    int v;
    if (n > 100) v = 0;
    else v = (int)(120.0f - x);
    if (((struct Obj13978 *)p)->f455C > v) ((struct Obj13978 *)p)->f455C = v;
}

void func_021D6720(u8 *p, int i)
{
    struct Pos pos;
    struct Pair pair;
    void *h;
    func_021D6C48((char *)p,i,((struct Obj13979 *)p)->fB4);
    h = ((struct Obj13979 *)p)->fB4;
    pos = d_021DA730; pair = d_021DA750;
    func_0204B404(h,(const struct Vec2 *)(&pos),0); func_0204B5AC(h,&pair);
    func_0204B92C(h,0); func_0204B3DC(h,0);
    func_0204B688(h,1); func_0204B570(h,2);
    *(void **)(p+i*24+0x40f4) = h;
}

void func_021D679C(u8 *p){if(*(struct Obj * *)&((struct Obj10441 *)p)->f0)func_0204B3DC(*(struct Obj * *)&((struct Obj10441 *)p)->f0,0);((struct Obj10441 *)p)->f0=0;}

void func_021D67B4(u8 *p, int i)
{
    struct Pos pos;
    struct Pair pair;
    void *h;
    func_021D6C90((char *)p,i,((struct Obj13980 *)p)->fB8);
    h = ((struct Obj13980 *)p)->fB8;
    pos = d_021DA734; pair = d_021DA740;
    func_0204B404(h,(const struct Vec2 *)(&pos),0); func_0204B5AC(h,&pair);
    func_0204B92C(h,0); func_0204B3DC(h,0);
    func_0204B688(h,1); func_0204B570(h,2);
    *(void **)(p+i*24+0x40f4) = h;
}
