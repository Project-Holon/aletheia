/*
 * function: func_021B9D08
 * address:  0x021B9D08
 * packet:   pkt_ov069_021B9D08
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02045770  0x02045770  arm
 */
#include "../include/Obj01133.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

struct GfFont;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern void func_0201C724(u32 print, u32 bmp, s16 x, s16 y, u32 str, u32 font, u16 color);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);

void func_021B9D08(u8 *p)
{
    int i;
    u32 h;

    ((struct Obj01133 *)p)->fC = func_0201D7EC(0x17, 0, 0, 0, 0x80);
    ((struct Obj01133 *)p)->fE8 = (void *)func_0201C440((void *)0x80);
    for (i = 0; i < 18; i++) {
        *(int *)(p + i * 8 + 0x58) = *(int *)(p + i * 4 + 0x10);
        p[i * 8 + 0x5C] = 0;
    }
    h = *(u32 *)&((struct Obj01133 *)p)->fE8;
    func_0201C724(h, (int)func_02045770((struct Descriptor *)((struct Obj01133 *)p)->fA8), 0, 0,
                  ((struct Obj01133 *)p)->f100, *(u32 *)&((struct Obj01133 *)p)->fC, 0x3DC0);
    p[0xAC] = 1;
    h = *(u32 *)&((struct Obj01133 *)p)->fE8;
    func_0201C724(h, (int)func_02045770((struct Descriptor *)((struct Obj01133 *)p)->fC8), 0, 0,
                  ((struct Obj01133 *)p)->f10C, *(u32 *)&((struct Obj01133 *)p)->fC, 0x3DC0);
    p[0xCC] = 1;
    h = *(u32 *)&((struct Obj01133 *)p)->fE8;
    func_0201C724(h, (int)func_02045770((struct Descriptor *)((struct Obj01133 *)p)->fD8), 0, 0,
                  ((struct Obj01133 *)p)->f118, *(u32 *)&((struct Obj01133 *)p)->fC, 0x3DC0);
    p[0xDC] = 1;
}
