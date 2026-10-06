/*
 * function: func_021D0750
 * address:  0x021D0750
 * packet:   pkt_ov021_021D0750
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * func_02047888 (arm9 ARM leaf) is filed as src/matched/arm9/func_02047888.c
 * to give the witness.  EXACT*: the listing extent includes 2 pad bytes.
 *
 * symbols:
 *   func_021D07FC  0x021D07FC  thumb  ov021
 *   func_021D0824  0x021D0824  thumb  ov021
 *   func_021D08BC  0x021D08BC  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02047888  0x02047888  arm
 */

typedef unsigned char u8;
typedef signed char s8;

typedef struct S {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    u8 rows[6][0x14];
} S;

struct Row;
extern struct Row *func_021D07FC(struct S *s);
extern void func_021D0824(int *p, int a);
extern void func_021D08BC(struct Row *r, int v);
extern int func_0216D3CC(int p);
extern int func_02047888(int *a, int idx, int *out);

void func_021D0750(int unused, S *s)
{
    int v;
    int i;
    void *r;

    s->fA++;
    if (s->fA >= 0x78) {
        r = func_021D07FC(s);
        if (r) {
            func_021D0824(r, s->f4);
        }
        s->fA = 0;
    }
    if (s->f8 != func_0216D3CC(s->f4)) {
        s->f9++;
        if (s->f9 >= 5) {
            r = func_021D07FC(s);
            if (r) {
                func_021D0824(r, s->f4);
            }
            s->f9 = 0;
        }
        s->f8 = func_0216D3CC(s->f4);
    }
    func_02047888((int *)s->f0[7], 0, &v);
    for (i = 0; i < 6; i++) {
        func_021D08BC((struct Row *)s->rows[i], v);
    }
}
