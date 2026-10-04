/*
 * function: func_021EA114
 * address:  0x021EA114
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC768  0x021EC768  thumb  ov170
 *   func_021ED594  0x021ED594  thumb  ov170
 *   func_021EE038  0x021EE038  thumb  ov170
 *   func_021E8FC0  0x021E8FC0  thumb  ov170
 *
 * Arm the flag, store the state byte, zero the 0x24 queue entry,
 *   re-stage it, publish (2,1,0) and set selector 0x021E0779.
 */
#include "../include/Obj00000.h"


extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021ED594(char *p, unsigned i);
extern void func_021EE038(char *, int, int, int);
extern int func_021E8FC0(char *p, int a, int b);
void func_021EA114(char *p, int a)
{
    ((struct Obj00000 *)p)->f18 = 1;
    ((struct Obj00000 *)p)->f16 = a;
    func_021EC768((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x24, 0);
    func_021ED594(p, 0x24);
    func_021EE038(p, 2, 1, 0);
    func_021E8FC0(p, 0x021E0779, 0x15);
}
