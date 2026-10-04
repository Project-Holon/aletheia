/*
 * function: func_0217416C
 * address:  0x0217416C
 * packet:   pkt_ov012_0217416C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021734A8 is a 3-argument field setter (case 4 is strb r2): the table
 * key loads straight into r2 because it is the third argument.
 *
 * symbols:
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_02012374  0x02012374  thumb
 *   d_0217549C     0x0217549C  data   ov012  a1
 *   d_02175498     0x02175498  data   ov012  a4
 *   d_0217549D     0x0217549D  data   ov012  a1
 */

typedef unsigned char u8;

typedef struct { int f0; int f4; int f8; u8 fc; } R;
typedef int (*Fn)(int, u8 *, int, int, int, int *, u8 *);

typedef unsigned int   u32;
extern void func_0217F074(void *p);
extern void func_021734A8(u8 *self, u32 id, u32 v);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u8 d_0217549C[];
extern u8 d_0217549D[];
extern u8 d_02175498[];

int func_0217416C(int a, int *b, int *c)
{
    int first;
    u8 *base;
    R *r4;
    int loc;
    int k;

    first = c[0];
    base = (u8 *)c[2];
    r4 = (R *)(base + 0x3548);
    loc = 0;
    switch (*b) {
    case 0:
        func_0217F074(base);
        k = d_0217549C[r4->f4 * 8];
        if (k != 0x1b) {
            func_021734A8(base, 4, k);
        }
        (*b)++;
    case 1: {
        int r;
        r = (*(Fn *)(d_02175498 + r4->f4 * 8))(first, base, c[1], r4->f8, a, &loc, &r4->fc);
        if (loc != 0) {
            func_02012374((struct Evt *)a, (struct Evt **)loc);
        } else if (r == 1) {
            (*b)++;
        }
        break;
    }
    case 2:
        k = d_0217549D[r4->f4 * 8];
        if (k != 0x1b) {
            func_021734A8(base, 4, k);
        }
        r4->f4 = 0;
        r4->f8 = 0;
        r4->fc = 0;
        r4->f0 = 0;
        return 1;
    }
    return 0;
}
