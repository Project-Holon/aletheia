/*
 * function: func_021C5898
 * address:  0x021C5898
 * packet:   pkt_ov127_021C5898
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled: forwards a by-value {s16 x, y} pair to func_021C428C with the
 * pointer at +4.  Blocker of ov099 func_021BA2D4 / func_021BA36C.
 *
 * symbols:
 *   func_021C428C  0x021C428C  thumb  ov127
 */
#include "../include/Obj23053.h"

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} P2;

extern void func_021C428C(char *p, int x, int y);

void func_021C5898(char *p, P2 v)
{
    func_021C428C(((struct Obj23053 *)p)->f4, v.x, v.y);
}
