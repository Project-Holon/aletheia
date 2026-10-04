/*
 * function: func_021F86A4
 * address:  0x021F86A4
 * packet:   pkt_021F86A4
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: every concrete byte reproduces; 0x021FFE90 lies outside ov185's
 *   region and the only branch to it is inside this range.
 *
 * symbols:
 *   func_021F8AA8   0x021F8AA8  thumb
 *   func_021F8658   0x021F8658  thumb
 *   func_021FFC9C   0x021FFC9C  thumb
 *   func_021FFE90   0x021FFE90  thumb
 *   func_021FD73C   0x021FD73C  thumb
 *
 * Poll the handle; on the two-result branch latch the returned halfword
 *   and chain to 0x21F8AA8, otherwise chain to 0x21F8658.
 */
#include "../include/Obj10771.h"


extern void func_021F8AA8(int *sys, int *state, char *p);
extern void func_021F8658(int a, int *state, char *p);
extern void func_021FFC9C(int);
extern int func_021FFE90(int, unsigned short *);
extern void func_021FD73C(int, void *);

void func_021F86A4(int a, int b, char *p)
{
    unsigned short buf;
    int r;
    func_021FFC9C(((struct Obj10771 *)p)->f0);
    r = func_021FFE90(((struct Obj10771 *)p)->f0, &buf);
    if (r == 0)
        return;
    if (r == 2) {
        ((struct Obj10771 *)p)->f8 = buf;
        func_021FD73C(a, func_021F8AA8);
    } else {
        func_021FD73C(a, func_021F8658);
    }
}
