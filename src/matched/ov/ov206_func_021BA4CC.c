/*
 * unit: yes
 * function: func_021BA4CC
 * address: 0x021BA4CC
 * packet: pkt_ov206_021BA4CC
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAF50 0x021BAF50 thumb ov206
 *   func_021BA934 0x021BA934 thumb ov206
 *   func_021BBBD8 0x021BBBD8 thumb ov206
 *   func_021BB92C 0x021BB92C thumb ov206
 */
#include "../include/Obj00173.h"
extern void func_021BAF50(char *p);
extern void func_021BA934(char *p);
struct S;
extern void func_021BBBD8(struct S *p, int i);
extern void func_021BB92C(char *p, int index);
void func_021BA4CC(char *p)
{
    func_021BAF50(p);
    func_021BA934(p);
    func_021BBBD8((struct S *)p,((struct Obj00173 *)p)->f190);
    func_021BB92C(p,((struct Obj00173 *)p)->fE0);
}
