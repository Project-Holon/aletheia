/*
 * function: func_021F201C
 * address:  0x021F201C
 * packet:   pkt_ov032_021F201C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F201C 0x021F201C thumb
 *   func_021F20A8 0x021F20A8 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045770 0x02045770 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj06135.h"
#include "../include/Obj07634.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct CharBuf;
struct Descriptor;
extern void func_021F20A8(char *p, char *q, int *r);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
struct Descriptor;
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_020409B4(u32 index);

void func_021F201C(char *p, char *q, void *text, u16 x, u8 y, u8 a5, u16 col, u32 a7)
{
    u32 w;
    u32 v;

    func_02043B5C((struct CharBuf *)(((struct Obj06135 *)q)->f4), a5);
    if (((struct Obj07634 *)p)->f7A != 0) {
        func_0201C7D0(((struct Obj06135 *)q)->f4, x, y, text, ((struct Obj07634 *)p)->fB0, col);
        w = ((struct Obj06135 *)q)->f0;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        return;
    }
    v = ((struct Obj07634 *)p)->fB4;
    func_0201C724((void *)v, (u32)func_02045770((struct Descriptor *)((struct Obj06135 *)q)->f8), x, y, (u32)text,
                  ((struct Obj07634 *)p)->fB0, col);
    ((struct Obj06135 *)q)->fC = 1;
    func_021F20A8(p, q, (int *)a7);
}
