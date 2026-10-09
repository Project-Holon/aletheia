/*
 * function: func_021E9858
 * address:  0x021E9858
 * packet:   pkt_ov093_021E9858
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9874  0x021E9874  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E9884  0x021E9884  thumb  ov093
 */
#include "../../matched/include/Obj21554.h"
typedef unsigned int u32;

extern void func_021E9874(void *p);
struct QU;
extern void func_021E9728(struct QU *p, u32 v);
extern int func_021E9884(void *p);

void func_021E9858(char *p)
{
    func_021E9874(((struct Obj21554 *)p)->f180);
    func_021E9728((struct QU *)p, (u32)func_021E9884);
}
