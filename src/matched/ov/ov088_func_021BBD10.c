/*
 * function: func_021BBD10
 * address:  0x021BBD10
 * packet:   pkt_ov088_021BBD10
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_021BBB84  0x021BBB84  thumb  ov088
 *   func_02041570  0x02041570  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_021BB9DC  0x021BB9DC  thumb  ov088
 */
#include "../include/Obj00263.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_021BBB84(u8 x, u8 y, u8 w, u8 h, u8 bg);
extern void func_02041570(int channel, u16 val);
extern void func_02041EE4(u32, u32, u32);
extern void func_021BB9DC(char *, int);

void func_021BBD10(char *p, int mode)
{
    func_020452E8(((struct Obj00263 *)p)->fF0);
    if (mode != 1) {
        func_021BBB84(0x20, 1, 0x20, 0x16, 2);
        func_02041570(0, 0);
        func_02041EE4(1, 0, 0);
        func_02041EE4(1, 3, ((struct Obj00263 *)p)->f130);
        func_02041EE4(2, 0, 0);
        func_02041EE4(2, 3, ((struct Obj00263 *)p)->f130);
        if (((struct Obj00263 *)p)->f120 == 0)
            func_021BB9DC(p, 1);
    }
}
