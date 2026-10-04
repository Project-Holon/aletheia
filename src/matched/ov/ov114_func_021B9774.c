/*
 * function: func_021B9774
 * address:  0x021B9774
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE698  0x021BE698  arm  ov114
 *   func_021BF184  0x021BF184  arm  ov114
 *
 *
 * Releases the record's +0x0c handle and re-arms the module.
 */
#include "../include/Obj03763.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BF184(int a);
extern void func_021BE698(void);

void func_021B9774(u8 *p)
{
    if (p == 0)
        return;
    if (((struct Obj03763 *)p)->fC == 0)
        return;
    func_021BF184(((struct Obj03763 *)p)->fC);
    ((struct Obj03763 *)p)->fC = 0;
    func_021BE698();
}
