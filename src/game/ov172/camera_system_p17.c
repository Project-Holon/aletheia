/*
 * file:     camera_system_p17.c
 * unit:     yes
 * function: func_021B6744, func_021B674C, func_021B67BC
 * address:  0x021B6744
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B6938 0x021B6938 thumb ov172
 *   func_021B6944 0x021B6944 thumb ov172
 *   func_02030734 0x02030734 arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   d_021C71C0 0x021C71C0 data a4
 *   func_02085D3C 0x02085D3C arm
 *   func_021B680C 0x021B680C arm ov172
 *   func_0203D7FC 0x0203D7FC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj14293.h"
#include "../../matched/include/Obj01264.h"
#include "../../matched/include/Obj02504.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern u16 func_021B6938(void *);
extern u16 func_021B6944(void *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0203D7C8(unsigned int, unsigned int, const char *, unsigned short);
extern int func_02085D3C(void);
extern int func_021B680C(void);
extern void func_0203D7FC(void *);
extern u32 func_020307B0(void *p);
void func_021B6744(void *p, u32 a, u32 b);
void func_021B674C(char *p, int count, u16 heap);
void func_021B67BC(char *p);
extern const char d_021C71C0[];



void func_021B6744(void *p, u32 a, u32 b)
{
    ((struct Obj14293 *)p)->f3C = a;
    ((struct Obj14293 *)p)->f40 = b;
}


void func_021B674C(char *p, int count, u16 heap)
{
    u32 width = func_021B6938(p);
    u32 height = func_021B6944(p);
    u8 i;
    if (*(u32 *)&((struct Obj01264 *)p)->f4 == 0) {
        ((struct Obj01264 *)p)->f4 = func_02030734(((struct Obj01264 *)p)->f0, count * 4, 0, d_021C71C0, 0x1D7);
        ((struct Obj01264 *)p)->f8 = count;
        for (i = 0; i < count; i++)
            (*(void ***)(p + 4))[i] = func_0203D7C8(heap, height * (width * 2), d_021C71C0, 0x1DC);
        ((struct Obj01264 *)p)->fC = 1;
    }
}

void func_021B67BC(char *p)
{
    u8 i;
    if (((struct Obj02504 *)p)->f10 != 0) return;
    if ((func_02085D3C() == 1 ? func_021B680C() : 0) != 0) return;
    if (((struct Obj02504 *)p)->fC == 1) {
        for (i = 0; i < ((struct Obj02504 *)p)->f8; i++)
            func_0203D7FC((void *)(*(u32 **)(p + 4))[i]);
    }
    func_020307B0(((struct Obj02504 *)p)->f4);
    ((struct Obj02504 *)p)->f8 = 0;
    *(u32 *)&((struct Obj02504 *)p)->f4 = 0;
}
