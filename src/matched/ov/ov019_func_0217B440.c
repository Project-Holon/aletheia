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

typedef unsigned int   u32;
struct Big;
struct BigObj;
struct L0200EDC4;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02188CE0(u8 *p);
extern void *func_0217AFB0(void **a, u8 *b, u8 *c);
extern int func_0217F894(void *p, char *q);
extern int func_0200EDC4(struct L0200EDC4 *l, u32 val);
extern void func_0217F948(char *p, u32 a, u32 b);

void func_0217B440(char *base, int x, int y)
{
    struct ent *q;
    int a;
    int b;
    int c;
    int r;
    int i;

    a = (int)func_0200ED48(func_02012EBC((struct Big *)x));
    b = func_0201283C((const struct BigObj *)x);
    c = func_02188CE0((u8 *)y);
    q = (struct ent *)(base + 0x2910);
    for (i = 0; i < 10; i++, q++) {
        if (q->on == 1 && q->p70 != 0) {
            r = (int)func_0217AFB0((void **)base, (u8 *)(*q->p70), (u8 *)q->p70);
            if (r != 0) {
                if (func_0217F894((void *)b, (char *)q) == 1) {
                    func_0217F948((char *)c, r, 0);
                } else if (func_0200EDC4((struct L0200EDC4 *)a, q->f5c) == 1) {
                    func_0217F948((char *)c, r, 1);
                }
            }
        }
    }
}
