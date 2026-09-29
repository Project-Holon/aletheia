/*
 * function: func_02174CCC
 * address:  0x02174CCC
 * packet:   pkt_ov011_02174CCC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The guard's ldrb lands in r1 because func_02026478's result is live in r0:
 * it is func_020127C4's argument (the r0 at that call is never re-set).
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02174734  0x02174734  thumb ov011
 *   func_02174D5C  0x02174D5C  thumb ov011
 *   func_021748CC  0x021748CC  thumb ov011
 *   func_02174954  0x02174954  thumb ov011
 */

int func_02026478(int a);
int func_020127C4(int h);
int func_02174734(void *p, int b, int c);
void func_02174D5C(void *p, void *e);
int func_021748CC(void *p, int i);
int func_02174954(void *p);

void func_02174CCC(unsigned char *p)
{
    unsigned char i;
    unsigned char *e;
    unsigned char *q;
    int h;

    h = func_02026478(*(int *)(p + 4));
    if (p[0x908] != 0) {
        if (func_02174734(p, p[0x908], func_020127C4(h)) == 1) {
            p[0x908] = 0;
        }
    }
    e = p + 0x8D4;
    for (i = 0; i < 3; i++) {
        q = p + i * 4;
        if (q[0x8D5] == 1) {
            func_02174D5C(p, e + i * 4);
            if (func_021748CC(p, i) == 1) {
                q[0x8D5] = 0;
            }
        }
    }
    if (p[0x8E1] == 1) {
        if (func_02174954(p + 0x8E0) == 1) {
            p[0x8E1] = 0;
        }
    }
}
