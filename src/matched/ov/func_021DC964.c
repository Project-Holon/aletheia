/*
 * function: func_021DC964
 * address:  0x021DC964
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm  arm9
 *
 * Tail call func_02030EAC with the word at +0x2c/+0x54.
 */
#include "../include/Obj00000.h"
#include "../include/Obj18437.h"

struct Node;
extern void func_02030EAC(struct Node *n);

void func_021DC964(char *p)
{
    func_02030EAC(((struct Obj18437 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f54);
}

