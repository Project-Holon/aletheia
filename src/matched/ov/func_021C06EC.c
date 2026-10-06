/*
 * function: func_021C06EC
 * address:  0x021C06EC
 * packet:   pkt_021C06EC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)

 * Clears a word and releases two handles of each of four entries.
 */
#include "../include/Obj09204.h"


struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);

void func_021C06EC(void *unused, char *p, void *a2)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = p + i * 4;
        ((struct Obj09204 *)e)->f24 = 0;
        func_0201C6EC((struct PrintSys *)(((struct Obj09204 *)e)->f34));
        func_0201C4C0((struct PrintSys *)(((struct Obj09204 *)e)->f34));
    }
}

