/*
 * function: func_0217B440
 * address:  0x0217B440
 * packet:   pkt_ov019_0217B440
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC  thumb
 *   func_0200ED48 0x0200ED48  thumb
 *   func_0201283C 0x0201283C  thumb
 *   func_02188CE0 0x02188CE0  thumb  ov021
 *   func_0217AFB0 0x0217AFB0  thumb  ov019
 *   func_0217F894 0x0217F894  thumb  ov019
 *   func_0200EDC4 0x0200EDC4  thumb
 *   func_0217F948 0x0217F948  thumb  ov019
 */

typedef unsigned char u8;

struct ent {
    u8 pad0[7];
    u8 : 4;
    u8 on : 1;
    u8 : 3;
    u8 pad1[0x54];
    int f5c;
    u8 pad2[0x10];
    int *p70;
    u8 pad3[0x18];
};

extern void func_02012EBC(int);
extern int func_0200ED48(void);
extern int func_0201283C(int);
extern int func_02188CE0(int);
extern int func_0217AFB0(char *, int, int *);
extern int func_0217F894(int, struct ent *);
extern int func_0200EDC4(int, int);
extern void func_0217F948(int, int, int);

void func_0217B440(char *base, int x, int y)
{
    struct ent *q;
    int a;
    int b;
    int c;
    int r;
    int i;

    func_02012EBC(x);
    a = func_0200ED48();
    b = func_0201283C(x);
    c = func_02188CE0(y);
    q = (struct ent *)(base + 0x2910);
    for (i = 0; i < 10; i++, q++) {
        if (q->on == 1 && q->p70 != 0) {
            r = func_0217AFB0(base, *q->p70, q->p70);
            if (r != 0) {
                if (func_0217F894(b, q) == 1) {
                    func_0217F948(c, r, 0);
                } else if (func_0200EDC4(a, q->f5c) == 1) {
                    func_0217F948(c, r, 1);
                }
            }
        }
    }
}
