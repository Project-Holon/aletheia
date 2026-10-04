/*
 * function: func_021C5814
 * address:  0x021C5814
 * packet:   pkt_ov127_021C5814
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled: forwards a by-value {s16 x, y} pair to func_021C41DC with the
 * pointer at +4.  Blocker of ov099 func_021BA2D4 / func_021BA36C.
 *
 * symbols:
 *   func_021C41DC  0x021C41DC  thumb  ov127
 */
#include "../include/Obj23048.h"

typedef signed short s16;

typedef struct {
    s16 x;
    s16 y;
} P2;

typedef unsigned char  u8;
extern void func_021C41DC(u8 *p, int x, int y);

void func_021C5814(char *p, P2 v)
{
    func_021C41DC(((struct Obj23048 *)p)->f4, v.x, v.y);
}
