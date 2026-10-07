/*
 * file:     research_top_p09.c
 * unit:     yes
 * function: func_021BB940, func_021BB948, func_021BB94C, func_021BB974, func_021BB978, func_021BB98C, func_021BB990, func_021BB998, func_021BB9A0, func_021BB9D0, func_021BBA00, func_021BBA30, func_021BBAA4, func_021BBAD0, func_021BBADC, func_021BBB60, func_021BBBE4, func_021BBC50, func_021BBCB0, func_021BBCFC, func_021BBD14, func_021BBD18, func_021BBD28, func_021BBD38, func_021BBD40, func_021BBD68, func_021BBDAC, func_021BBDF0, func_021BBE7C
 * address:  0x021BB940
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *   func_021BC580  0x021BC580  thumb  ov217
 *   func_021BC3D4 0x021BC3D4 thumb ov217
 *   func_021BC3E0 0x021BC3E0 thumb ov217
 *   func_021BC3F8 0x021BC3F8 thumb ov217
 *   func_021BC400 0x021BC400 thumb ov217
 *   func_021BC3EC 0x021BC3EC thumb ov217
 *   func_021BC574  0x021BC574  thumb  ov217
 *   func_021BC2CC 0x021BC2CC thumb ov217
 *   func_021BC41C 0x021BC41C thumb ov217
 *   func_021BC40C 0x021BC40C thumb ov217
 *   func_021BBF1C 0x021BBF1C thumb ov217
 *   func_021BC628 0x021BC628 thumb ov217
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200E394 0x0200E394 thumb
 *   func_0200E44C 0x0200E44C thumb
 *   d_021C308A 0x021C308A data a1
 *   d_021C3080 0x021C3080 data a1
 *   d_021C30A8 0x021C30A8 data a1
 *   func_021BC6E4 0x021BC6E4 thumb ov217
 *   func_0200E440 0x0200E440 thumb
 *   func_021BC740  0x021BC740  thumb  ov217
 *   func_02025A54  0x02025A54  thumb
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021BC6DC 0x021BC6DC thumb ov217
 *   func_021BBF04 0x021BBF04 thumb ov217
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204162C 0x0204162C arm
 */
#include "../../matched/include/Obj25847.h"
#include "../../matched/include/Obj25848.h"
#include "../../matched/include/Obj00025.h"
#include "../../matched/include/Obj25849.h"
#include "../../matched/include/Obj14731.h"
#include "../../matched/include/Obj25850.h"
#include "../../matched/include/Obj25852.h"
#include "../../matched/include/Obj02928.h"
#include "../../matched/include/Obj01084.h"
#include "../../matched/include/Obj25853.h"
#include "../../matched/include/Obj25854.h"

struct Ring;
struct Big;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16;

typedef enum { INDEX_ZERO=0 } Index;

extern u32 func_021C0E54(struct Ring *r);
extern u32 func_021C0E64();
extern void func_020061E4(u32 a);
extern u32 func_021BC580();
extern unsigned int func_021BC3D4(void);
extern unsigned func_021BC3E0(void);
extern unsigned func_021BC3F8(unsigned);
extern unsigned func_021BC400(unsigned);
extern int func_021BC3EC(unsigned);
extern void func_021BC574(u8 **p, u32 i);
extern void func_021BC2CC(void *, unsigned, unsigned, unsigned);
extern unsigned func_021BC41C(void *);
extern int func_021BC40C(void *p);
extern unsigned func_021BBF1C(unsigned, unsigned);
extern unsigned func_021BC628(u8 *);
extern void *func_02012EBC(struct Big *);
extern void *func_0200E394(void *a0);
extern int func_0200E44C(int p0, int p1);
extern u32 func_021BC6E4(void *p);
extern void func_0200E440(u8 *p, int value, int index);
extern int func_021BC740(char *p, int i);
extern void func_02025A54(u8 *g, u32 a);
extern int _s32_div_f(int, int);
extern u32 func_021BC6DC(void *p);
extern u32 func_021BBF04(u32 p,u32 slot);
extern void func_020413B0(u32 layer,u32 x,u32 y,u8 width,u8 height,u8 pal);
extern void func_02041B6C(u32 layer);
extern u32 func_0204162C(int channel);
void func_021BB940(void *p, u32 v);
u32 func_021BB948(u8 *a0);
void func_021BB94C(u32 a0);
u32 func_021BB974(void *p);
int func_021BB978(char *p, int a1);
u32 func_021BB98C(void *p);
void func_021BB990(void *p);
void *func_021BB998(void *p);
u32 func_021BB9A0(u32 a0);
u32 func_021BB9D0(u32 a0);
u32 func_021BBA00(u32 a0, u32 a1);
void func_021BBA30(u8 *p);
u32 func_021BBAA4(u32 a0, u8 a1);
void func_021BBAD0(u32 a0);
void func_021BBADC(u8 *p);
void func_021BBB60(u8 *p);
void func_021BBBE4(u8 *p);
u8 func_021BBC50(u8 *p);
void func_021BBCB0(u8 *p);
void func_021BBCFC(void *p, s32 v);
void func_021BBD14(void *p, u32 v);
void func_021BBD18(int a, int b);
void func_021BBD28(int a, int b);
void func_021BBD38(void *p, u8 v);
void func_021BBD40(u8 *p, int a);
void func_021BBD68(u8 *p);
void func_021BBDAC(u8 *p);
void func_021BBDF0(u32 object,u32 slot);
void func_021BBE7C(u32 object,u32 slot);
extern const u8 d_021C308A[], d_021C3080[], d_021C30A8[];
extern const u8 d_021C30A8[],d_021C3080[],d_021C308A[];


/*
 * Field setter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB940(void *p, u32 v)
{
    ((struct Obj25847 *)p)->f168 = v;
}



u32 func_021BB948(u8 *a0)
{
    return ((struct Obj25848 *)(((u8*)a0)))->f28;
}

/*
 * Same guard shape as 021BA158 on the +0x158 word, handing the +0x18
 * handle to func_021BB978.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB94C(u32 a0)
{
    if (((struct Obj00025 *)(((u8*)a0)))->f158 != 0) {
    if (func_021C0E64(((struct Obj00025 *)(((u8*)a0)))->f18) == 0) {
    func_021BB978((char *)a0, func_021C0E54((struct Ring *)(((struct Obj00025 *)(((u8*)a0)))->f18)));
    }
    }
}


u32 func_021BB974(void *p)
{
    return ((struct Obj25849 *)p)->f1C;
}


int func_021BB978(char *p, int a1)
{
    int off = 0x56;
    ((struct Obj14731 *)p)->f1C = a1;
    ((struct Obj14731 *)p)->f24 = 0;
    *(int *)(p + (off << 2)) = 0;
    return (int)func_021BB998(p);
}


u32 func_021BB98C(void *p)
{
    return ((struct Obj25850 *)p)->f20;
}


void func_021BB990(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x20);
    *c += 1;
}


/*
 * Unlabelled Thumb leaf in a .word run:
 *   movs r1,#0; str r1,[r0,#0x20]; bx lr
 * Clears the word at p+0x20.
 */
void *func_021BB998(void *p)
{
    ((struct Obj25852 *)p)->f20 = 0;
    return p;
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BB9A0(u32 a0)
{
    func_021BBD28(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    func_021BBCFC((void *)a0, -1);
    func_021BBD18(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    func_020061E4(1352);
    return func_021BC580(a0, 4);
}

u32 func_021BB9D0(u32 a0)
{
    func_021BBD28(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    func_021BBCFC((void *)a0, 1);
    func_021BBD18(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    func_020061E4(1352);
    return func_021BC580(a0, 4);
}

u32 func_021BBA00(u32 a0, u32 a1)
{
    func_021BBD28(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    func_021BBD14((void *)a0, a1);
    func_021BBD18(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    func_020061E4(1352);
    return func_021BC580(a0, 4);
}

/*
 * arity: BC400 forwards entry r0 into BC3F8, so retain supplied argument despite legacy void. BC3EC overwrites r1 with 24 and tail-calls signed division; legacy trailing a1 neither read nor forwarded.
 */
void func_021BBA30(u8 *p)
{
    int low, high, left, right;
    u8 index;
    low = func_021BC3D4();
    high = func_021BC3E0();
    left = func_021BC3F8(p[0x32]);
    right = func_021BC400(p[0x32]);
    if (right <= low) {
        index = func_021BC3EC(right + 1);
        if (((struct Obj00025 *)p)->f160) func_021BBAA4((unsigned)p, index);
        else func_021BBD38(p, index);
    }
    if (high <= left) {
        index = func_021BC3EC(left - 1);
        if (((struct Obj00025 *)p)->f160) func_021BBAA4((unsigned)p, index);
        else func_021BBD38(p, index);
    }
}

u32 func_021BBAA4(u32 a0, u8 a1)
{
    func_021BBDAC((u8 *)a0);
    func_021BBD38((void *)a0, a1);
    func_021BBD68((u8 *)a0);
    func_020061E4(1352);
    return func_021BC580(a0, 1);
}

/*
 * Reconstructed from the listing.
 *
 * evidence: func_021BC574 is ov217's own code ("ldr r0, [r0]; ldr r3,
 * =func_021C09D8; bx r3" after the pop at 0x021BC570), inside ov217's window,
 * so only ov217 can be resident there when this pool word is used.  Its start
 * is seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov217's own listing.  The old
 * hint ov209 named a different overlay's function mapped over the address.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBAD0(u32 a0)
{
    func_021BC574((u8 **)a0, 0);
}

void func_021BBADC(u8 *p)
{
    int start, end, low, high, step, low2, high2;
    start = ((struct Obj01084 *)p)->f34;
    if (p[0x32] < p[0x33]) end = func_021BC400(p[0x33]) + 1;
    else end = func_021BC3F8(p[0x33]);
    low = func_021BC3D4();
    high = func_021BC3E0();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 4;
    low2 = func_021BC3D4();
    high2 = func_021BC3E0();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 0;
    func_021BC2CC(p, start, end, step);
}

void func_021BBB60(u8 *p)
{
    int start, end, step, low, high, low2, high2;
    start = ((struct Obj01084 *)p)->f34;
    end = start;
    if ((int)func_021BC41C(p) < start) end = func_021BC40C(p) + 24;
    else if (start < 0) end = 144;
    low = func_021BC3D4();
    high = func_021BC3E0();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 3;
    low2 = func_021BC3D4();
    high2 = func_021BC3E0();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 1;
    func_021BC2CC(p, start, end, step);
}

void func_021BBBE4(u8 *p)
{
    int center, target, start, end;
    center = (int)(func_021BC3D4() + func_021BC3E0()) / 2;
    target = func_021BBF1C((unsigned)p, p[0x32]) * 8;
    if (center < target) {
        start = func_021BC3E0();
        end = (target - center) + func_021BC3E0();
    } else {
        start = func_021BC3D4();
        end = func_021BC3D4() - (center - target);
    }
    func_021BC2CC(p, start, end, ((start >= end ? start : end) - (start <= end ? start : end)) / 3);
}

u8 func_021BBC50(u8 *p)
{
    u8 values[3];
    int i;
    void *data;
    u8 a, b, c, index;
    data = func_0200E394(func_02012EBC((struct Big *)func_021BC628(p)));
    for (i = 0; i < 3; i++) values[i] = func_0200E44C((int)data, i);
    a = values[0];
    b = values[1];
    c = values[2];
    for (index = 0; index < 10; index++)
        if (a == d_021C30A8[index] && b == d_021C3080[index] && c == d_021C308A[index]) return index;
    return 0;
}

/*
 * blocker C: typedef unsigned char u8; void func_0200E440(u8 *p,int value,int index) { (p+index)[640]=value; }
 * arity: BC628 returns C09B4's +8 pointer; E394 returns 071CC's pointer, both used live despite legacy void declarations.
 */
void func_021BBCB0(u8 *p)
{
    u32 index;
    int data;
    index=func_021BC6E4(p);
    data=(int)func_0200E394((void *)((int)func_02012EBC((struct Big *)func_021BC628(p))));
    func_0200E440((u8 *)data,d_021C30A8[index],0);
    func_0200E440((u8 *)data,d_021C3080[index],1);
    func_0200E440((u8 *)data,d_021C308A[index],2);
}


/*
 * Advance the u32 at +0x2c by the argument plus two, reduced modulo two.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBCFC(void *p, s32 v)
{
    *(s32 *)&((struct Obj02928 *)p)->f2C = (*(s32 *)&((struct Obj02928 *)p)->f2C + v + 2) % 2;
}


/*
 * Field setter, u32 at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBD14(void *p, u32 v)
{
    ((struct Obj25853 *)p)->f2C = v;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BBD18(int a, int b)
{
    func_02025A54((u8 *)func_021BC740((char *)a, b), 0);
}


void func_021BBD28(int a, int b)
{
    func_02025A54((u8 *)func_021BC740((char *)a, b), 1);
}


/*
 * Field setter, u8 at +0x32.
 *
 * Addresses are Black-image addresses.
 */
void func_021BBD38(void *p, u8 v)
{
    ((struct Obj25854 *)p)->f32 = v;
}


void func_021BBD40(u8 *p, int a)
{
    int base = p[0x32];
    int x = (int)func_021BC6DC(p);
    int s = base + a;
    p[0x33] = (u8)((s + x) % (int)func_021BC6DC(p));
}

void func_021BBD68(u8 *p)
{
    u8 slot;
    u32 x;
    u32 y;
    slot=p[0x32];
    x=func_021BBF04((u32)p,slot);
    y=func_021BBF1C((u32)p,slot);
    func_020413B0(2,x,y,28,3,10);
    func_02041B6C(2);
    ((struct Obj00025 *)p)->f160=1;
}

void func_021BBDAC(u8 *p)
{
    u8 slot;
    u32 x;
    u32 y;
    slot=p[0x32];
    x=func_021BBF04((u32)p,slot);
    y=func_021BBF1C((u32)p,slot);
    func_020413B0(2,x,y,28,3,9);
    func_02041B6C(2);
    ((struct Obj00025 *)p)->f160=0;
}

void func_021BBDF0(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)func_0204162C(2);
    second=(u16 *)func_0204162C(3);
    for(row=0;row<3;row++) {
        for(column=0;column<28;column++) {
            base=func_021BBF1C(object,slot);
            index=column+2+(base+row)*32;
            destination=index-1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=func_021BBF1C(object,slot);
    first[base*32+29]=first[0];
    second[base*32+29]=second[0];
    first[(base+1)*32+29]=first[0];
    second[(base+1)*32+29]=second[0];
    first[(base+2)*32+29]=first[0];
    second[(base+2)*32+29]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}

void func_021BBE7C(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)func_0204162C(2);
    second=(u16 *)func_0204162C(3);
    for(row=2;row>=0;row--) {
        for(column=27;column>=0;column--) {
            base=func_021BBF1C(object,slot);
            index=column+1+(base+row)*32;
            destination=index+1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=func_021BBF1C(object,slot);
    first[base*32+1]=first[0];
    second[base*32+1]=second[0];
    first[(base+1)*32+1]=first[0];
    second[(base+1)*32+1]=second[0];
    first[(base+2)*32+1]=first[0];
    second[(base+2)*32+1]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}
