/*
 * function: func_021EA770
 * address:  0x021EA770
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF33C  0x021EF33C  thumb  ov170
 *   func_021EC6F4  0x021EC6F4  thumb  ov170
 *
 * Resume one 0x74 sub-object, then the plain resume.
 */
#include "../include/Obj18493.h"



struct WinMgr;
extern void func_021EF33C(struct WinMgr *mgr);
extern void func_021EC6F4(char *p);
void func_021EA770(int p)
{
    func_021EF33C(*(struct WinMgr **)(((struct Obj18493 *)p)->f2C + 0x74));
    func_021EC6F4((char *)p);
}
