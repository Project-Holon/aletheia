/*
 * function: func_021EA750
 * address:  0x021EA750
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
 * Tail call func_020307B0 with the word at +0x2c/+0x60.
 */
#include "../include/Obj00000.h"
#include "../include/Obj18489.h"

extern void func_020307B0(void *);

void func_021EA750(char *p)
{
    func_020307B0(((struct Obj18489 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60);
}

