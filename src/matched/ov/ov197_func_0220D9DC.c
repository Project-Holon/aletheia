/*
 * function: func_0220D9DC
 * address:  0x0220D9DC
 * packet:   pkt_0220D9DC
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0220D98C  0x0220D98C  thumb  ov197
 *   func_0220D974  0x0220D974  thumb  ov197
 *   func_020260E4  0x020260E4  thumb
 */
#include "../include/Obj06649.h"

typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_0220D98C(char *p, int b);
extern void func_0220D974(char *p, int b);

void func_0220D9DC(char *p, int b)
{
    if ((unsigned int)(b - 7) <= 1) {
        func_020260E4((struct Sound *)(*(int *)&((struct Obj06649 *)p)->f144), 0);
        b = 0;
    }
    func_0220D98C(p, b);
    func_0220D974(p, 1);
}
