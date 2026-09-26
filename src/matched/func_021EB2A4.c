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
typedef unsigned char u8;

extern void func_021EADB4(void *q, int a, int i);
extern void func_021EAE20(void *q, int a, int i);
extern void func_021EAE74(void *q, int a, int i);
extern void func_021EAF20(void *q, int a, int i);
extern void func_021EAFBC(void *p, int a, int i);
extern void func_021EB098(void *q, int a, int i);
extern void func_021EB114(void *q, int a, int i);
extern void func_021EB190(void *q, int a, int i);
extern void func_021EB208(void *q, int a, int i);
extern void func_021EABA0(void *q);

void func_021EB2A4(u8 *p, int a)
{
    func_021EADB4(*(void **)(p + 0x2c), a, 1);
    func_021EAE20(*(void **)(p + 0x2c), a, 2);
    func_021EAE74(*(void **)(p + 0x2c), a, 3);
    func_021EAF20(*(void **)(p + 0x2c), a, 4);
    func_021EAFBC(p, a, 5);
    func_021EB098(*(void **)(p + 0x2c), a, 6);
    func_021EB114(*(void **)(p + 0x2c), a, 7);
    func_021EB190(*(void **)(p + 0x2c), a, 8);
    func_021EB208(*(void **)(p + 0x2c), a, 9);
    func_021EABA0((u8 *)*(void **)(p + 0x2c) + 0xe4);
    func_021EABA0((u8 *)*(void **)(p + 0x2c) + 0xec);
    func_021EABA0((u8 *)*(void **)(p + 0x2c) + 0xf4);
    func_021EABA0((u8 *)*(void **)(p + 0x2c) + 0xfc);
}
