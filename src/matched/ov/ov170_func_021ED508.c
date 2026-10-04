/*
 * function: func_021ED508
 * address:  0x021ED508
 * packet:   pkt_ov170_021ED508
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC000 0x021EC000 thumb
 *
 * Sets window 9's frame and mode; outside modes 2, 3 and 4 the mode is
 * cleared again.
 */
#include "../include/Obj00000.h"
#include "../include/Obj24021.h"

extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021ED508(unsigned char *p, int a, int b)
{
    int kind;
    func_021EBFA8(WORK(p), 9, a);
    func_021EC000(WORK(p), 9, b);
    kind = ((struct Obj24021 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24;
    if (kind != 2 && kind != 4 && kind != 3)
        func_021EC000(WORK(p), 9, 0);
}
