/*
 * function: func_021F31A8
 * address:  0x021F31A8
 * packet:   pkt_ov032_021F31A8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_020307B0 0x020307B0 arm
 */

extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

typedef struct {
    unsigned n0;
    unsigned *a0;
    unsigned n1;
    unsigned *a1;
    unsigned n2;
    unsigned *a2;
} T;

void func_021F31A8(void *unused, T *p)
{
    unsigned i;
    int j;
    for (i = 0; i < p->n2; i++)
        func_0204AFD8(p->a2[i]);
    for (i = 0; i < p->n1; i++)
        func_0204A8D4(p->a1[i]);
    for (i = 0; i < p->n0; i++)
        func_0204ADA4(p->a0[i]);
    for (j = 0; j < 3; j++) {
        if (((unsigned *)p)[j * 2 + 1] != 0)
            func_020307B0((void *)(((unsigned *)p)[j * 2 + 1]));
    }
}
