/*
 * function: func_021C846C
 * address: 0x021C846C
 * packet: pkt_ov093_021C846C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow the 38-byte function.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021BFEAC 0x021BFEAC thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern u8 *func_021B9934(char *p, int i);
extern int func_021BFEAC(u8 *, u8 *, u8 *, int *);
int func_021C846C(u8 *p, int a, int b, int *out)
{
    u8 *x = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, a);
    u8 *y = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, b);
    return func_021BFEAC(p, x, y, out);
}
