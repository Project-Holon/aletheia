/*
 * function: func_0200E06C
 * address:  0x0200E06C
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00318.h"

extern void func_0203F37C(void *p, unsigned int size, unsigned int seed);
void func_0200E06C(char *p)
{
    func_0203F37C(p, 0x84c,
        ((struct Obj00318 *)p)->f84C + (((struct Obj00318 *)p)->f84E << 16));
    ((struct Obj00318 *)p)->f84E = 0;
}
