/*
 * function: func_021EB2A4
 * address:  0x021EB2A4
 * packet:   pkt_021EB2A4
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EADB4  0x021EADB4  thumb  ov170
 *   func_021EAE20  0x021EAE20  thumb  ov170
 *   func_021EAE74  0x021EAE74  thumb  ov170
 *   func_021EAF20  0x021EAF20  thumb  ov170
 *   func_021EAFBC  0x021EAFBC  thumb  ov170
 *   func_021EB098  0x021EB098  thumb  ov170
 *   func_021EB114  0x021EB114  thumb  ov170
 *   func_021EB190  0x021EB190  thumb  ov170
 *   func_021EB208  0x021EB208  thumb  ov170
 *   func_021EABA0  0x021EABA0  thumb  ov170
 */
#include "../include/Obj00000.h"
typedef unsigned char u8;

extern void func_021EADB4(void *q, int a, int i);
extern void func_021EAE20(char *p, void **q, int i);
extern void func_021EAE74(void *q, int a, int i);
extern void func_021EAF20(void *q, int a, int i);
extern void func_021EAFBC(void *p, int a, int i);
extern void func_021EB098(char *p, unsigned char *e, int i);
extern void func_021EB114(char *p, unsigned char *e, int i);
extern void func_021EB190(char *p, unsigned char *e, int i);
extern void func_021EB208(void *q, int a, int i);
extern void func_021EABA0(void **p);

void func_021EB2A4(u8 *p, int a)
{
    func_021EADB4(((struct Obj00000 *)p)->f2C, a, 1);
    func_021EAE20(((struct Obj00000 *)p)->f2C, (void **)a, 2);
    func_021EAE74(((struct Obj00000 *)p)->f2C, a, 3);
    func_021EAF20(((struct Obj00000 *)p)->f2C, a, 4);
    func_021EAFBC(p, a, 5);
    func_021EB098(((struct Obj00000 *)p)->f2C, (unsigned char *)a, 6);
    func_021EB114(((struct Obj00000 *)p)->f2C, (unsigned char *)a, 7);
    func_021EB190(((struct Obj00000 *)p)->f2C, (unsigned char *)a, 8);
    func_021EB208(((struct Obj00000 *)p)->f2C, a, 9);
    func_021EABA0((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xe4));
    func_021EABA0((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xec));
    func_021EABA0((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xf4));
    func_021EABA0((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xfc));
}
