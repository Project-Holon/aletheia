/*
 * function: func_021DE3E4
 * address: 0x021DE3E4
 * packet: pkt_ov183_021DE3E4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 */
#include "../include/Obj02519.h"
#include "../include/Obj14429.h"
typedef unsigned short u16;
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
void func_021DE3E4(char *p, char *q)
{
    ((struct Obj02519 *)p)->f8 = func_021FD12C(((struct Obj14429 *)q)->f8, (void *)(*(int *)&((struct Obj02519 *)p)->f4), ((struct Obj02519 *)p)->f6C);
    func_021FD170(((struct Obj02519 *)p)->f8, (char *)(((struct Obj14429 *)q)->f8), (void *)0x86);
}
