/*
 * function: func_021F053C
 * address:  0x021F053C
 * packet:   pkt_ov035_021F053C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F053C 0x021F053C thumb
 *   func_020456F8 0x020456F8 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_021F0254 0x021F0254 thumb ov035
 *   func_020221A4 0x020221A4 thumb
 *   func_02035C60 0x02035C60 arm
 */
#include "../include/Obj02755.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void BMP_WIN_SetPosY(struct Descriptor *p, u8 v);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_021F0254(char *p, int a1, int a2);
extern u32 func_020221A4(void);
extern int func_02035C60(void);

int func_021F053C(char *p)
{
    switch (((struct Obj02755 *)p)->f4A) {
    case 0:
        func_020456F8((struct Descriptor *)(((struct Obj02755 *)p)->f18));
        func_020456F8((struct Descriptor *)(((struct Obj02755 *)p)->f1C));
        BMP_WIN_SetPosY((struct Descriptor *)(((struct Obj02755 *)p)->f1C), 6);
        func_02045334((struct Descriptor *)((struct Obj02755 *)p)->f1C);
        func_02045374((struct Cfg *)(((struct Obj02755 *)p)->f1C));
        func_021F0254(p, ((struct Obj02755 *)p)->f1C, 4);
        (((struct Obj02755 *)p)->f4A)++;
        break;
    case 1:
        if (func_020221A4() == 1)
            (((struct Obj02755 *)p)->f4A)++;
        break;
    case 2:
        if (func_02035C60() != 0)
            (((struct Obj02755 *)p)->f4A)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
