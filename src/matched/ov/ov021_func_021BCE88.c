/*
 * function: func_021BCE88
 * address:  0x021BCE88
 * packet:   pkt_ov021_021BCE88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_021BC92C  0x021BC92C  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */
#include "../include/Obj01123.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void func_021BCB9C(void *p, int keep);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021BC92C(char *p);

void func_021BCE88(char *p)
{
    if (((struct Obj01123 *)p)->f42 > 0x14) {
        func_021BCB9C(p, 0);
        func_02040588(3, 0);
        func_021BC92C(p);
    }
}
