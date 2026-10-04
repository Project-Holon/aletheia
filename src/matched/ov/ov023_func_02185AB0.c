/*
 * function: func_02185AB0
 * address:  0x02185AB0
 * packet:   pkt_ov023_02185AB0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021852F4  0x021852F4  thumb  ov023
 *   func_021857F4  0x021857F4  thumb  ov023
 *   func_021862F4  0x021862F4  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02186480  0x02186480  thumb  ov023
 *   func_02186860  0x02186860  thumb  ov023
 */
#include "../include/Obj00336.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_02039338(void);
struct Descriptor;
extern void func_02045334(struct Descriptor *a);
typedef unsigned char  u8;
struct Cfg;
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void func_021852F4(void *p, int flag);
extern void func_021857F4(char *p, int a, int b);
extern void func_021862F4(char *p);
extern void func_02186444(char *p, u32 v);
extern void func_02186480(char *p);
extern void func_02186860(char *p, int x, int y);

void func_02185AB0(char *p, int msg, int arg)
{
    u32 w;

    switch (msg) {
    case 1:
        if (((struct Obj00336 *)p)->f9288 == 1)
            return;
        if (((struct Obj00336 *)p)->f198 == 6 || ((struct Obj00336 *)p)->f198 == 0x10)
            func_02186480(p);
        func_021852F4((void *)(((struct Obj00336 *)p)->f100), 0);
        func_021857F4(p, 0, arg);
        ((struct Obj00336 *)p)->f1B4 = arg;
        ((struct Obj00336 *)p)->f9280 = 0;
        break;
    case 3:
        func_021862F4(p);
        break;
    case 0xb:
    case 0x12:
        break;
    case 0x18:
        if (((struct Obj00336 *)p)->f9288 == 1)
            return;
        func_021857F4(p, 0, arg);
        if (arg == func_02039338())
            return;
        if (func_02039338() == 0)
            ((struct Obj00336 *)p)->f9280 = ((struct Obj00336 *)p)->f9280 & (arg ^ 0xFFFF);
        if (((struct Obj00336 *)p)->f198 == 6 || ((struct Obj00336 *)p)->f198 == 0x10) {
            func_02186480(p);
            w = ((struct Obj00336 *)p)->f118;
            func_02045334((struct Descriptor *)w);
            func_02045374((struct Cfg *)w);
            func_020409B4(func_02045730((struct Descriptor *)w));
        }
        func_021852F4((void *)(((struct Obj00336 *)p)->f100), 0);
        break;
    case 9:
        func_02186860(p, 0x2907, func_02039338());
        break;
    default:
        return;
    }
    func_02186444(p, msg);
}
