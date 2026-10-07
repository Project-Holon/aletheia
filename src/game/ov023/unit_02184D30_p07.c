/*
 * file:     unit_02184D30_p07.c
 * unit:     yes
 * function: func_02185974, func_021859C4, func_02185A1C, func_02185AB0, func_02185BBC
 * address:  0x02185974
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02039338  0x02039338  arm
 *   func_021861C4  0x021861C4  thumb  ov023
 *   func_02186480  0x02186480  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02186304  0x02186304  thumb  ov023
 *   func_0218654C  0x0218654C  thumb  ov023
 *   func_02185354  0x02185354  thumb  ov023
 *   func_02186558  0x02186558  thumb  ov023
 *   func_021862B0  0x021862B0  thumb  ov023
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_021862F4  0x021862F4  thumb  ov023
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021852F4  0x021852F4  thumb  ov023
 *   func_021857F4  0x021857F4  thumb  ov023
 *   func_02186860  0x02186860  thumb  ov023
 *   func_020436FC  0x020436FC  arm
 *   func_02045770  0x02045770  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 */
#include "../../matched/include/Obj00336.h"
#include "../../matched/include/Obj06119.h"
#include "../../matched/include/Obj02104.h"

struct Descriptor;
struct Cfg;
struct Bmp;
struct Obj020437AC;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_020061E4(u32 a);
extern u16 func_02039338(void);
extern void func_021861C4(u8 *w, u32 msg, int mode);
extern void func_02186480(char *p);
extern void func_02186444(char *p, u32 v);
extern void func_02186304(char *p, int a);
extern int  func_0218654C(char *p);
extern void func_02185354(char *p);
extern int  func_02186558(char *p);
extern int  func_021862B0(char *p);
extern int  func_021841A4(unsigned char *p);
extern unsigned char func_021841A0(unsigned char *p);
extern void func_021862F4(char *p);
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void func_021852F4(void *p, int flag);
extern void func_021857F4(char *p, int a, int b);
extern void func_02186860(char *p, int x, int y);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void *func_02045770(struct Descriptor *a);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
int func_02185974(char *p, int a1);
int func_021859C4(char *p, int a1);
int func_02185A1C(char *p, int a1);
void func_02185AB0(char *p, int msg, int arg);
void func_02185BBC(int a0, int a1, int x, int y, int w, int h, int dx, int dy, int mx, int my);


int func_02185974(char *p, int a1)
{
    func_021861C4((u8 *)p, 2, 1);
    func_02186480(p);
    func_02186444(p, 0x19);
    func_020061E4(0x54c);
    if (func_02039338() == 0)
        func_02186304(p, 0);
    ((struct Obj00336 *)p)->f927C = func_0218654C(p);
    func_02185354(p);
    return a1;
}


int func_021859C4(char *p, int a1)
{
    if (!((((struct Obj06119 *)p)->f927C == 0 || ((struct Obj06119 *)p)->f927C == func_0218654C(p))
          && (func_02186558(p) & ((struct Obj06119 *)p)->f9280)))
        ((struct Obj06119 *)p)->f927C = 0;
    if (func_021862B0(p)) {
        func_02186444(p, 0x1a);
        ((struct Obj06119 *)p)->f1A4 = 0;
    }
    func_02185354(p);
    return a1;
}


int func_02185A1C(char *p, int a1)
{
    if (!((((struct Obj02104 *)p)->f927C == 0 || ((struct Obj02104 *)p)->f927C == func_0218654C(p))
          && (func_02186558(p) & ((struct Obj02104 *)p)->f9280)))
        ((struct Obj02104 *)p)->f927C = 0;
    ((struct Obj02104 *)p)->f1A4 += 1;
    if (((struct Obj02104 *)p)->f1A4 > 0x3c && ((struct Obj02104 *)p)->f927C == 0) {
        func_021862F4(p);
        func_02186444(p, 4);
        if (func_02039338() == 0) {
            ((struct Obj02104 *)p)->f9E6C = 1;
            func_02186304(p, 1);
        }
        ((struct Obj02104 *)p)->f1AC = func_021841A4(**(unsigned char ** *)&((struct Obj02104 *)p)->f4);
        ((struct Obj02104 *)p)->f1B0 = func_021841A0((unsigned char *)(**(u32 * *)&((struct Obj02104 *)p)->f4));
    }
    func_02185354(p);
    return a1;
}


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


/*
 * Clearing dx/dy before the w/h subtraction is what moves a1 into r0 at
 * entry (t in r1, the bound in r2); clearing it last keeps a1 in r1.
 */
void func_02185BBC(int a0, int a1, int x, int y, int w, int h, int dx, int dy,
                   int mx, int my)
{
    int s;
    int t;

    if (dx < 0) {
        t = -dx;
        if (t > mx)
            t = mx;
        x += t;
        dx = 0;
        w -= t;
    }
    if (dy < 0) {
        t = -dy;
        if (t > my)
            t = my;
        y += t;
        dy = 0;
        h -= t;
    }
    s = (int)func_020436FC((void *)a1, 8, 8, 0x20, 0x28);
    func_020439A0((struct Bmp *)s, (struct Bmp *)((int)func_02045770((struct Descriptor *)a0)), x, y, dx, dy, w, h, 0);
    func_020437AC((struct Obj020437AC *)s);
}
