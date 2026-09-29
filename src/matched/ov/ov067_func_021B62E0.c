/*
 * function: func_021B62E0
 * address:  0x021B62E0
 * packet:   pkt_ov067_021B62E0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates and clears a header plus f4 0x38-byte elements, initialises the
 * shared sub-object, then each element.  `flag = 0` goes after the
 * allocation call: assigned before it, the zero is stored to its spill slot
 * ahead of the heap spill and every register in the prologue shifts
 * (19 bytes of DIFF).  Loop invariants q1/q2 assigned inside the loop body,
 * flag/k in an if/else, and the q2, q1, flag declaration order fix the
 * stack slots.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B6608  0x021B6608  thumb  ov067
 *   func_021B67F8  0x021B67F8  thumb  ov067
 *   d_021B954C     0x021B954C  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 *f0;
    u32 f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    int f18;
    int f1c;
} A;

typedef struct {
    int f0;
    u32 f4;
    int f8;
    u8 sub[0x14];
    u8 elem[1];
} R;

extern const char d_021B954C[];

extern R *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_021B6608(void *a, u8 b, int c, int d, int e, u8 f, u8 g, int h, int i);
extern void func_021B67F8(void *a, int b, void *c, void *d, int e, int f);

R *func_021B62E0(A *a, int heap)
{
    u8 *q2;
    u8 *q1;
    int flag;
    R *p;
    int k;
    u32 size;
    u32 i;

    size = a->f4 * 0x38 + 0x20;
    p = func_02030734(heap, size, 0, d_021B954C, 0x123);
    flag = 0;
    func_02082BCC(p, 0, size);
    p->f4 = a->f4;
    p->f8 = flag;
    if (a->fC >= 4) {
        flag = 1;
        k = 4;
    } else {
        k = flag;
    }
    func_021B6608(p->sub, a->fC, flag, k, a->f18, a->f10, a->f14, a->f1c, heap);
    for (i = 0; i < p->f4; i++) {
        q1 = p->elem;
        q2 = p->sub;
        func_021B67F8(q1 + i * 0x38, a->f8, q2, a->f0 + i * 32, flag, heap);
    }
    return p;
}
