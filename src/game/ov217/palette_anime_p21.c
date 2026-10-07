/*
 * file:     palette_anime_p21.c
 * unit:     yes
 * function: func_021C2D9C, func_021C2DA0, func_021C2DC4, func_021C2DCC, func_021C2DE0
 * address:  0x021C2D9C
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02030734 0x02030734 arm
 *   d_021C408C 0x021C408C data ov217 a1
 */
#include "../../matched/include/Obj26037.h"
#include "../../matched/include/Obj14768.h"
#include "../../matched/include/Obj06721.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *, int, int);
u32 func_021C2D9C(u32 *p);
u32 func_021C2DA0(u32 a0);
u32 func_021C2DC4(void *a0);
void func_021C2DCC(char *p);
void func_021C2DE0(char *p, unsigned short *dst, unsigned short *src, int count);
extern char d_021C408C[];

u32 func_021C2D9C(u32 *p)
{
    return p[5];
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2DA0(u32 a0)
{
    u8 s[4];
    u32 p1 = (u32)func_02030734(a0, 32, 0, (const char *)0x21C408C, 667);
    ((struct Obj26037 *)((u8*)p1))->f0 = a0;
    return p1;
}


u32 func_021C2DC4(void *a0)
{
    return func_020307B0(a0);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C2DCC(char *p)
{
    u16 t = ((struct Obj14768 *)p)->f0;
    func_02082BCC(p, 0, 0x20);
    ((struct Obj14768 *)p)->f0 = t;
}

void func_021C2DE0(char *p, unsigned short *dst, unsigned short *src, int count)
{
    int i;
    ((struct Obj06721 *)p)->f4 = 1;
    *(unsigned short * *)&((struct Obj06721 *)p)->f8 = dst;
    ((struct Obj06721 *)p)->f10 = count;
    *(unsigned short * *)&((struct Obj06721 *)p)->fC = func_02030734(((struct Obj06721 *)p)->f0, count * 2, 0, d_021C408C, 728);
    for (i = 0; i < count; i++)
        (*(unsigned short **)(p + 12))[i] = src[i];
}
