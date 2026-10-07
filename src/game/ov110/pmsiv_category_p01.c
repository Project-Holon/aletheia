/*
 * file:     pmsiv_category_p01.c
 * unit:     yes
 * function: func_021BB280, func_021BB290, func_021BB2CC, func_021BB328
 * address:  0x021BB280
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
 *   d_021C37B1 0x021C37B1 data a1
 *   func_02030734 0x02030734 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   d_021C3C44 0x021C3C44 data a1
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049658 0x02049658 arm
 *   func_021BB3F4 0x021BB3F4 thumb ov110
 *   func_021BB4F4 0x021BB4F4 thumb ov110
 *   func_021BB5A0 0x021BB5A0 thumb ov110
 *   func_021BB5E0 0x021BB5E0 thumb ov110
 *   func_021BB61C 0x021BB61C thumb ov110
 *   func_02040618 0x02040618 arm
 *   func_0207D658 0x0207D658 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj03751.h"
#include "../../matched/include/Obj03752.h"

#define WININ (*(volatile u16 *)0x04000048)
#define WINOUT (*(volatile u16 *)0x0400004a)
struct Descriptor;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern u8 *func_021BF6D4(u8 *);
extern void func_0204B3B4(struct Obj *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u8 *func_021BB3F4(u8 *, u8 *);
extern u8 *func_021BB4F4(u8 *, u8 *);
extern u8 *func_021BB5A0(u8 *, u8 *);
extern void func_021BB5E0(u8 *);
extern void func_021BB61C(u8 *);
extern void func_02040618(u32, u32, u32);
extern void func_0207D658(u32, int, int);
extern void func_020409B4(u32);
u8 func_021BB280(u32 i);
u8 *func_021BB290(u32 a,u8 *b,u32 c);
void func_021BB2CC(u8 *p);
void func_021BB328(u8 *p, u32 data);
extern const u8 d_021C37B1[];
extern const char d_021C3C44[];

u8 func_021BB280(u32 i) { return *(const u8 *)(d_021C37B1+i*10); }

u8 *func_021BB290(u32 a,u8 *b,u32 c) { u8 *p; p=func_02030734(42,164,0,d_021C3C44,220); ((struct Obj03751 *)p)->f0=a; *(u8 * *)&((struct Obj03751 *)p)->f4=b; ((struct Obj03751 *)p)->f8=c; ((struct Obj03751 *)p)->fC=0; ((struct Obj03751 *)p)->f14=0; ((struct Obj03751 *)p)->f54=0; ((struct Obj03751 *)p)->f58=0; *(u8 * *)&((struct Obj03751 *)p)->f5C=func_021BF6D4(b); return p; }

/*
 * extent: trailing two-byte zero padding
 */
void func_021BB2CC(u8 *p) {
    u8 i;
    if(((struct Obj03752 *)p)->f54) func_0204B3B4(((struct Obj03752 *)p)->f54);
    for(i=0;i<12;i++) if(*(void **)(p+0x60+i*4)) func_020452E8(*(void **)(p+0x60+i*4));
    if(((struct Obj03752 *)p)->f90) func_020452E8(((struct Obj03752 *)p)->f90);
    if(((struct Obj03752 *)p)->f94) func_020452E8(((struct Obj03752 *)p)->f94);
    if(((struct Obj03752 *)p)->f98) func_020452E8(((struct Obj03752 *)p)->f98);
    func_020307B0(p);
}

static inline void inside(int wnd, int effect)
{
    u32 tmp;
    tmp = (WININ & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WININ = (u16)tmp;
}

static inline void outside(int wnd, int effect)
{
    u32 tmp;
    tmp = (WINOUT & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WINOUT = (u16)tmp;
}

void func_021BB328(u8 *p, u32 data)
{
    u32 bytes, q;
    func_020498F4((void *)data, 27, 1, 0, 0, 0, 42);
    bytes = func_02049658((void *)data, 15, 1, 0, 0, 0, 42);
    q = (u32)func_021BB3F4(p, (u8 *)(bytes / 32));
    q = (u32)func_021BB4F4(p, (u8 *)q);
    func_021BB5A0(p, (u8 *)q);
    func_021BB5E0(p);
    func_02040618(1, 0, -4);
    func_02040618(1, 3, 16);
    func_021BB61C(p);
    func_0207D658(0x04000050, 2, -10);
    inside(31, 1);
    outside(29, 1);
    *(volatile u16 *)0x04000040 = 255;
    *(volatile u16 *)0x04000044 = 168;
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0xe000) | 0x2000;
    func_020409B4(1);
}
