/*
 * function: func_021DD1E8
 * address:  0x021DD1E8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ED904  0x021ED904  thumb  ov170
 *   func_021ED9B4  0x021ED9B4  thumb  ov170
 *   func_021EDF5C  0x021EDF5C  thumb  ov170
 *   func_021EB85C  0x021EB85C  thumb  ov170
 *   func_021EF738  0x021EF738  thumb  ov170
 *
 * Five-step reset: fold the delta, rebuild the queue object,
 *   re-run the frame update, clear the flag and re-stage channel 9.
 */
#include "../include/Obj00000.h"


struct WinMgr;
extern void func_021ED904(unsigned char *p);
extern void func_021ED9B4(int);
extern void func_021EDF5C(unsigned char *p);
extern void func_021EB85C(unsigned char *p, int i);
extern void func_021EF738(struct WinMgr *mgr);
void func_021DD1E8(char *p)
{
    func_021ED904((unsigned char *)p);
    func_021ED9B4(*(int *)&((struct Obj00000 *)p)->f2C);
    func_021EDF5C((unsigned char *)p);
    func_021EB85C((unsigned char *)p, 0);
    func_021EF738(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
}
