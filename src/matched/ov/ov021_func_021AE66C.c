/*
 * function: func_021AE66C
 * address:  0x021AE66C
 * packet:   pkt_ov021_021AE66C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 */

typedef struct Task {
    int state;              /* 0x00 */
    int f04;
    void *f08;              /* 0x08 */
    int f0C[4];
    int f1C;                /* 0x1C */
    int f20;
    int f24;                /* 0x24 */
    int f28[3];
    unsigned char *f34;     /* 0x34 */
} Task;

extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(void *x);
extern int func_0216D86C(void *x);
extern int func_021642B4(int a, int b, int c, int d);
extern int func_0216D5F8(void *x);
extern int func_0216D3CC(void *x);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *a, int b);

int func_021AE66C(Task *p)
{
    void *r4 = func_021A3074(p->f34);
    int r6 = func_0216D83C(r4);
    int r7 = func_0216D86C(r4);
    int t = func_0216D83C(p->f08);

    r6 = func_021642B4(r6, r7, t, func_0216D86C(p->f08));
    if (r6 != func_0216D5F8(r4) && (p->f24 == 0 || p->f1C == 2)) {
        if (func_0216D3CC(r4) == 1) {
            func_0216D410(r4, func_02197E7C(r6, 0));
            p->state = 0xf;
        }
    } else {
        p->state = 0x10;
    }
    return 0;
}
