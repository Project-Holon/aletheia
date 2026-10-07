/*
 * file:     worldtrade_adapter_p16.c
 * unit:     yes
 * function: func_021FE178, func_021FE1A4, func_021FE254, func_021FE264
 * address:  0x021FE178
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
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   g_022037D4  0x022037D4  data  ov135
 *   func_0202208C 0x0202208C thumb
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_021F7B9C 0x021F7B9C thumb ov135
 */
#include "../../matched/include/Obj08190.h"
#include "../../matched/include/Obj23413.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj23414.h"
#include "../../matched/include/Obj23415.h"

struct U16Vec;
struct Obj;
struct Personal;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed short s16;

extern u32 func_020307B0(void *p);
extern void func_02045808(struct U16Vec *);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_021FF318(u8 *p, u32 k, int b, int c, int d);
extern int func_0207D55C(volatile u16 *reg);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern int func_02035C08(const void *p);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern int func_021F7B9C(u8 *p, int event);
void func_021FE178(char *p);
int func_021FE1A4(unsigned char *p);
int func_021FE254(void);
void func_021FE264(u8 *p, int mode);
extern char g_022037D4[];

void func_021FE178(char *p) {func_020307B0(((struct Obj23413 *)(*(char * *)&((struct Obj08190 *)p)->fE00))->f14);func_020307B0(((struct Obj08190 *)p)->fE00);func_02045808(*(struct U16Vec * *)&((struct Obj08190 *)p)->fB88);func_02045808(*(struct U16Vec * *)&((struct Obj08190 *)p)->fB8C);}

int func_021FE1A4(unsigned char *p)
{
    if (func_020355C4() == 1)
        func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
    else
        func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
    if (((struct Obj00018 *)p)->f20 == 15) {
        if (((struct Obj00018 *)p)->fD0 != 0)
            func_021FF318(p, 38, 0, 0, 0xf0f);
        else
            func_021FF318(p, 8, 1, 0, 0xf0f);
        if (func_0207D55C((u16 *)0x0400006c) == -16) {
            func_0202208C(0, 1, 1, 0, 16, 1, 0x48);
            *(int *)&((struct Obj00018 *)p)->f28 = 33;
        } else {
            *(int *)&((struct Obj00018 *)p)->f28 = 1;
        }
    } else {
        func_021FF318(p, 8, 1, 0, 0xf0f);
        func_021F4E98(p, 23, 1);
    }
    func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fD38, 1);
    return 2;
}


int func_021FE254(void)
{
    return func_02035C08(g_022037D4);
}

void func_021FE264(u8 *p, int mode)
{
    u32 h,v;
    switch(mode) {
    case 0: ((struct Obj00018 *)p)->f28=4; break;
    case 1:
        if(((struct Obj00018 *)p)->fB56!=0) {
            h=(u32)func_0201ADE4((u16)((struct Obj00018 *)p)->fB56,0,0x48);
            v=func_0201AE1C((const struct Personal *)h,0x14);
            func_0201AE14((void *)h);
            ((struct Obj23414 *)(*(u8 * *)&((struct Obj00018 *)p)->fE00))->f20=v;
            if(func_021F7B9C(p+0xB56,((struct Obj23415 *)(*(u8 * *)&((struct Obj00018 *)p)->fE00))->f20)) break;
        }
        ((struct Obj00018 *)p)->f28=7;
        break;
    case 2: ((struct Obj00018 *)p)->f28=10; break;
    case 3: ((struct Obj00018 *)p)->f28=13; break;
    case 4:
        if(*(u32 *)&((struct Obj00018 *)p)->fD0) {
            ((struct Obj00018 *)p)->f28=32;
            func_0202208C(0,0,0,0,16,1,0x48);
        }
        break;
    case 5: ((struct Obj00018 *)p)->f28=16; break;
    case 6:
        func_021FF318(p,15,1,0,0xF0F);
        func_021F4E98(p,23,26);
        break;
    }
}
