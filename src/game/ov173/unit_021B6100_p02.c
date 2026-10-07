/*
 * file:     unit_021B6100_p02.c
 * unit:     yes
 * function: func_021B6B0C, func_021B6B54, func_021B6B6C, func_021B6BA0, func_021B6BCC, func_021B6BF8
 * address:  0x021B6B0C
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_02017E40 0x02017E40 thumb
 *   func_0201C158 0x0201C158 thumb
 *   func_021B7460  0x021B7460  thumb  ov173
 *   func_0202208C 0x0202208C thumb
 *   func_021B71C4 0x021B71C4 thumb ov173
 *   func_021B7968 0x021B7968 thumb ov173
 *   func_0201D304 0x0201D304 thumb
 *   func_02045738 0x02045738 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 */
#include "../../matched/include/Obj05450.h"
#include "../../matched/include/Obj24157.h"
#include "../../matched/include/Obj24158.h"
#include "../../matched/include/Obj24159.h"
#include "../../matched/include/Obj10668.h"

struct Descriptor;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern u16 func_021B7438(char **);
extern void func_02017E40(void *, u32, u32);
extern u8 func_0201C158(u16 move, u32 ppUp);
extern void func_021B7460(char *p, u32 kind);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021B71C4(char *,int);
extern void func_021B7968(char *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 func_02045738(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C7D0(void *, s16, s16, void *, u8, u16);
int func_021B6B0C(char **p);
int func_021B6B54(int *p);
int func_021B6B6C(char *p);
int func_021B6BA0(char *p);
void func_021B6BCC(char *p);
u32 func_021B6BF8(char *p, int index, u8 font, u16 w, int align, u8 y);

int func_021B6B0C(char **p)
{
    char *q;
    u32 zero;
    q = *p;
    func_02017E40(((struct Obj05450 *)q)->f0, ((struct Obj05450 *)q)->f1B + 0x36, func_021B7438(p));
    q = *p;
    zero = 0;
    func_02017E40(((struct Obj05450 *)q)->f0, ((struct Obj05450 *)q)->f1B + 0x3e, 0);
    q = *p;
    func_02017E40(((struct Obj05450 *)q)->f0, ((struct Obj05450 *)q)->f1B + 0x3a, func_0201C158(func_021B7438(p), 0));
    ((struct Obj24157 *)(*p))->f1A = zero;
    return 8;
}


int func_021B6B54(int *p)
{
    func_021B7460((char *)p, 6);
    ((struct Obj24158 *)p)->f1B0 = 5;
    return 2;
}

int func_021B6B6C(char *p)
{
    if (*(u8 *)(*(char **)p + 0x1b) < 4) {
        func_021B7460(p, 10);
        p[0x1ba] = 4;
    } else {
        func_021B7460(p, 7);
        p[0x1ba] = 3;
    }
    *(u32 *)(p + 0x1b0) = 3;
    return 2;
}

int func_021B6BA0(char *p) { func_0202208C(0,0,0,0,6,1,79); ((struct Obj24159 *)p)->f1B0=9; return 0; }

void func_021B6BCC(char *p) { int n; n=func_021B7438((char **)p); if(n!=65535) func_021B71C4(p,n); else func_021B71C4(p,-2); func_021B7968(p); }

/*
 * lever: separate u8 width result from u8 coordinate x; otherwise 16 bytes
 *   differ from index/font/x register rotation. Both cases preserve byte
 *   width narrowing and signed division by two before coordinate wrap.
 * domain: all nine direct ov173 calls use align 0..2; sites 021B6CE2=2,
 *   6D00=0,6D36=0,6D90=0,6E24=0,6F88=1,7242=1,728C=1,72B8=0.
 *   At 6DC4 r7 copies zero r4 and stays invariant; at 6F5E r4 becomes 1.
 *   No defined coordinate exists in the original outside this domain.
 * extent: 138 bytes code; +0x8A 00 00 alignment padding, next labelled
 *   function 021B6C84 at +0x8C. No follower or unit.
 */
u32 func_021B6BF8(char *p, int index, u8 font, u16 w, int align, u8 y)
{
    u8 x;
    u8 width;
    switch (align) {
    case 0: x = 0; break;
    case 1:
        width = (u8)func_0201D304(((struct Obj10668 *)p)->f4C, font, 0);
        x = (u8)((u8)(func_02045738(*(void **)(p + index * 4 + 4)) * 8) - width);
        break;
    case 2:
        width = (u8)func_0201D304(((struct Obj10668 *)p)->f4C, font, 0);
        x = (u8)(((int)(u8)(func_02045738(*(void **)(p + index * 4 + 4)) * 8) - width) / 2);
        break;
    }
    return func_0201C7D0(func_02045770(*(void **)(p + index * 4 + 4)), x, y, ((struct Obj10668 *)p)->f4C, font, w);
}
