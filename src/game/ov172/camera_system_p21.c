/*
 * function: func_021B6868
 * address:  0x021B6868
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears counts at +0x10/+0x1c and calls the release veneer when the guard still reads 1.
 *
 * symbols:
 *   func_02085D3C  0x02085D3C  arm
 *   func_021B6884  0x021B6884  arm  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../../matched/include/Obj02504.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int  func_02085D3C(void *p, int b);
extern void func_021B6884(void);

void func_021B6868(char *p)
{
    if (((struct Obj02504 *)p)->f10 == 1) {
        ((struct Obj02504 *)p)->f10 = 0;
        ((struct Obj02504 *)p)->f1C = 0;
        if (func_02085D3C(p, 0) == 1) {
            func_021B6884();
        }
    }
}
