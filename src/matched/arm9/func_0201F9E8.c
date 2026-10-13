/*
 * function: BMP_MENU_Delete
 * address:  0x0201F9E8
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_CURSOR_Delete  0x02020D3C  thumb
 */
#include "../include/Obj02993.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Obj;

struct D;
extern void BMP_CURSOR_Delete(struct D *p);
extern u32 func_020307B0(void *p);

void BMP_MENU_Delete(struct Obj *o, u8 *out)
{
    if (out != 0) {
        *out = ((struct Obj02993 *)o)->f2D;
    }
    BMP_CURSOR_Delete((struct D *)(((struct Obj02993 *)o)->f24));
    func_020307B0(o);
}
