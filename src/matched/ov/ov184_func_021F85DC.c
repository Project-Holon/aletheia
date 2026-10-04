/*
 * function: func_021F85DC
 * address:  0x021F85DC
 * packet:   pkt_021F85DC
 * region:   ov184
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: every concrete byte reproduces; the call to 0x021FE7B0 is left
 *   wildcarded because that address lies outside ov184's own 0x5A0-byte
 *   region and no listing labels it -- the only branch image-wide is the
 *   one inside this range.
 *
 * symbols:
 *   func_021F8670   0x021F8670  thumb
 *   func_021FE784   0x021FE784  thumb
 *   func_021FE7B0   0x021FE7B0  thumb
 *   func_021FD73C   0x021FD73C  thumb
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   finish through 0x21FD73C on 2.
 */
#include "../include/Obj14447.h"


extern void func_021F8670(int a, int b, char *p);
extern int func_021FE784(int, int, int, int);
extern int func_021FE7B0(int);
extern void func_021FD73C(int, void *);

void func_021F85DC(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_021FE784(*(int *)(((struct Obj14447 *)p)->f30), 4, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int *)(((struct Obj14447 *)p)->f30)))
            *state = 2;
        break;
    case 2:
        func_021FD73C(a, func_021F8670);
        break;
    }
}
