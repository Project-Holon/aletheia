/*
 * function: func_021BC718
 * address:  0x021BC718
 * packet:   pkt_021BC6D8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC6C8 0x021BC6C8  thumb  ov208
 *   func_021BC7B4 0x021BC7B4  thumb  ov208

 * Runs the idle transition with 0x10 twice and marks state 1.
 */
#include "../include/Obj18189.h"


extern int func_021BC6C8(char *);
extern void func_021BC7B4(char *p, short b, unsigned char c, unsigned char d);

void func_021BC718(char *p)
{
    if (func_021BC6C8(p))
        return;
    func_021BC7B4(p, 0, 0x10, 0x10);
    ((struct Obj18189 *)p)->f10 = 1;
}

