/*
 * function: func_021BC1E8
 * address:  0x021BC1E8
 * packet:   pkt_ov099_021BC1E8
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
 */
#include "../include/Obj10203.h"

typedef unsigned char u8;

extern void GF_FONT_SetDefaultTextColor(void);
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *p);

int func_021BC1E8(char *p, int r)
{
    int v;

    GF_FONT_SetDefaultTextColor();
    v = func_021BA858(p);
    if (v == -1)
        return r;
    if (v == 0)
        ((struct Obj10203 *)p)->f1353 = 0x44;
    else
        ((struct Obj10203 *)p)->f1353 = 0x4A;
    func_021BA8EC(p);
    ((struct Obj10203 *)p)->f1CC = 0x8A;
    return r;
}
