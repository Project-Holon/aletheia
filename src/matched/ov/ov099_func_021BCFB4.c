/*
 * function: func_021BCFB4
 * address:  0x021BCFB4
 * packet:   pkt_ov099_021BCFB4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   func_021BA858  0x021BA858  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 */
#include "../include/Obj06356.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern void GF_FONT_SetDefaultTextColor(void);
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *p);
extern void func_021BAAB8(char *p, int a, int b);

int func_021BCFB4(char *p, int v)
{
    int r;

    GF_FONT_SetDefaultTextColor();
    r = func_021BA858(p);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        ((struct Obj06356 *)p)->f1CC = 0x62;
        func_021BA8EC(p);
    } else {
        if ((unsigned)(((struct Obj06356 *)p)->f135C - 1) <= 1) {
            ((struct Obj06356 *)p)->f1353 = 0x4A;
            func_021BAAB8(p, 0x4A, 0);
        } else {
            ((struct Obj06356 *)p)->f1353 = 0x90;
        }
        ((struct Obj06356 *)p)->f1CC = 0x8A;
    }
    return v;
}
