/*
 * file:     palette_anime_p02.c
 * unit:     yes
 * function: func_021C11A4, func_021C11C8, func_021C11D0, func_021C11DC, func_021C11E8, func_021C11F4, func_021C11FC, func_021C1224, func_021C124C
 * address:  0x021C11A4
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
 *   func_021C1194  0x021C1194  thumb  ov217
 *   func_021C1A84  0x021C1A84  thumb  ov217
 *   func_021C1AB4  0x021C1AB4  thumb  ov217
 *   func_021C1AC0  0x021C1AC0  thumb  ov217
 *   func_021C1D28  0x021C1D28  thumb  ov217
 *   func_021C1B74  0x021C1B74  thumb  ov217
 *   func_021C1F44  0x021C1F44  thumb  ov217
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../../matched/include/Obj14758.h"

typedef unsigned char u8;

typedef short s16_021C11A4;

struct Pos {
    s16_021C11A4 a;
    s16_021C11A4 b;
    s16_021C11A4 c;
};

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16_021C11D0;

typedef signed short   s16_021C11DC;

typedef signed short   s16_021C11E8;

typedef signed short   s16_021C11FC;

typedef signed short   s16_021C1224;

typedef signed short s16_021C124C;

typedef enum { GX_POLYGONMODE_MODULATE=0 } GXPolygonMode;

typedef enum { GX_CULL_NONE=3 } GXCull;

typedef enum { GX_BEGIN_TRIANGLES=0 } GXBegin;

extern void func_021C1194(u8 *p, struct Pos *v);
extern u8 func_021C1A84(u8 *p, u8 key);
extern void *func_021C1AB4(void *p, u32 n);
extern void *func_021C1AC0(u8 *p, u8 key);
extern int func_021C1D28(u8 *p);
extern void func_021C1B74(u8 *p, u8 *rec, s16_021C11FC *out);
extern void func_021C1F44(const s16_021C11FC *p, s32 *px, s32 *py);
void func_021C11A4(u8 *p, int a1);
u8 func_021C11C8(u8 *p, u8 key);
u8 func_021C11D0(u8 *p, u8 n);
u8 func_021C11DC(u8 *p, u8 key);
u8 func_021C11E8(u8 *p, u8 n);
int func_021C11F4(u8 *p);
void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py);
void func_021C1224(u8 *h, u8 n, s32 *px, s32 *py);
void func_021C124C(u8 *p);


void func_021C11A4(u8 *p, int a1)
{
    struct Pos v;
    s16_021C11A4 y = ((struct Obj14758 *)p)->f1B6;
    s16_021C11A4 x = ((struct Obj14758 *)p)->f1B4;
    v.a = x;
    v.b = y;
    v.c = a1;
    func_021C1194(p, &v);
}


/*
 * Tail-call veneer: branch to func_021C1A84.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021C11C8(u8 *p, u8 key)
{
    return func_021C1A84(p, key);
}


/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021C11D0(u8 *p, u8 n)
{
    return *(u8 *)func_021C1AB4(p, n);
}


u8 func_021C11DC(u8 *p, u8 key)
{
    return *((u8 *)func_021C1AC0(p, key) + 8);
}


u8 func_021C11E8(u8 *p, u8 n)
{
    return *((u8 *)func_021C1AB4(p, n) + 8);
}


/*
 * Tail-call veneer: branch to func_021C1D28.
 *
 * Addresses are Black-image addresses.
 */
int func_021C11F4(u8 *p)
{
    return func_021C1D28(p);
}


/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py)
{
    s16_021C11FC s[4];
    func_021C1B74(h, func_021C1AC0(h, key), s);
    func_021C1F44(s, px, py);
}


void func_021C1224(u8 *h, u8 n, s32 *px, s32 *py)
{
    s16_021C1224 s[4];
    func_021C1B74(h, func_021C1AB4(h, n), s);
    func_021C1F44(s, px, py);
}

static inline void G3_PolygonAttr(int light,GXPolygonMode mode,GXCull cull,int id,int alpha,int misc)
{
    *(volatile u32 *)0x040004a4=light|(mode<<4)|(cull<<6)|(id<<24)|(alpha<<16)|misc;
}

static inline void G3_Begin(GXBegin primitive) { *(volatile u32 *)0x04000500=primitive; }

static inline void G3_Color(u16 rgb) { *(volatile u32 *)0x04000480=rgb; }

static inline void G3_Vtx(s16_021C124C x,s16_021C124C y,s16_021C124C z)
{
    *(volatile u32 *)0x0400048c=(u32)(u16)x|((u32)(u16)y<<16);
    *(volatile u32 *)0x0400048c=(u32)(u16)z;
}

static inline void G3_End(void) { *(volatile u32 *)0x04000504=0; }

void func_021C124C(u8 *p)
{
    int n,i,index;
    u32 rest=(u32)p;
    switch(*(u32 *)(p+8)) {
    case 0: n=0; break;
    case 1: n=*(u32 *)(p+16)*100/120; rest=100-n; break;
    case 2: n=*(u32 *)(p+16)*100/30; rest=100-n; break;
    case 3: n=(20-*(u32 *)(p+16))*100/20; rest=100-n; break;
    case 4: n=100; rest=0; break;
    case 5: n=*(u32 *)(p+16)*100/60; rest=100-n; break;
    }
    index=rest*3;
    for(i=0;i<n;i++) {
        G3_PolygonAttr(0,GX_POLYGONMODE_MODULATE,GX_CULL_NONE,p[index*10+0x41a],31,0);
        G3_Begin(GX_BEGIN_TRIANGLES);
        G3_Color(*(u16 *)(p+index*10+0x418));
        G3_Vtx(*(s16_021C124C *)(p+index*10+0x412),*(s16_021C124C *)(p+index*10+0x414),*(s16_021C124C *)(p+index*10+0x416));
        index=(index+1)%300;
        G3_Color(*(u16 *)(p+index*10+0x418));
        G3_Vtx(*(s16_021C124C *)(p+index*10+0x412),*(s16_021C124C *)(p+index*10+0x414),*(s16_021C124C *)(p+index*10+0x416));
        index=(index+1)%300;
        G3_Color(*(u16 *)(p+index*10+0x418));
        G3_Vtx(*(s16_021C124C *)(p+index*10+0x412),*(s16_021C124C *)(p+index*10+0x414),*(s16_021C124C *)(p+index*10+0x416));
        index=(index+1)%300;
        G3_End();
    }
}
