/*
 * function: func_021DD8F8
 * address:  0x021DD8F8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm  arm9
 *
 * Tail call func_020307B0 with the word at +0x2c/+0x180.
 */
#include "../include/Obj00000.h"
#include "../include/Obj18452.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021DD8F8(char *p)
{
    func_020307B0(((struct Obj18452 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f180);
}

