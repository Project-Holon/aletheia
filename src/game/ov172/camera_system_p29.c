/*
 * function: func_021B699C
 * address:  0x021B699C
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Guard on func_02085D3C(p), then hands the +0x30 pointer to the veneer.
 *
 * symbols:
 *   func_02085D3C  0x02085D3C  arm
 *   func_021B69B4  0x021B69B4  arm  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../../matched/include/Obj24062.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_02085D3C(void *p);
extern int func_021B69B4(void *v);

int func_021B699C(void *p)
{
    void *v = ((struct Obj24062 *)p)->f30;
    if (func_02085D3C(p) == 1) {
        return func_021B69B4(v);
    }
    return 0;
}
