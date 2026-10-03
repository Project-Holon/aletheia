/*
 * function: func_02208B10
 * address: 0x02208B10
 * packet: pkt_ov094_02208B10
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef signed short s16;
typedef struct E {
    void *f0, *f4, *f8, *fc, *f10, *f14;
    char p18[0x2c];
    int f44;
    char p48[0x28];
    unsigned int lo:16, count:4, hi:12;
    char p74[8];
    void *f7c;
} E;
extern void func_0204B454(void *, s16 *, int);
extern void func_0204B404(void *, s16 *, int);
struct Node;
extern void func_02030EAC(struct Node *n);
void func_02208B10(void *h, E *e)
{
    int step;
    s16 v[2];
    if (e->f44 != 0) step = 8;
    else step = -8;
    func_0204B454(e->f0, v, 0);
    v[0] += (s16)step;
    func_0204B404(e->f0, v, 0);
    func_0204B454(e->f8, v, 0);
    v[0] += (s16)step;
    func_0204B404(e->f8, v, 0);
    func_0204B454(e->f14, v, 0);
    v[0] += (s16)step;
    func_0204B404(e->f14, v, 0);
    if (e->f44 == 0) {
        func_0204B454(e->f4, v, 0);
        v[0] += (s16)step;
        func_0204B404(e->f4, v, 0);
    }
    if (e->f10 != 0) {
        func_0204B454(e->f10, v, 0);
        v[0] += (s16)step;
        func_0204B404(e->f10, v, 0);
    }
    e->count--;
    if (e->count == 0) {
        func_02030EAC(h);
        e->f7c = 0;
    }
}
