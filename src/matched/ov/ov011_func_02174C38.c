/*
 * function: func_02174C38
 * address: 0x02174C38
 * packet: pkt_ov011_02174C38
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * func_02026478 returns the argument consumed by func_020127C4.
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_020127C4 0x020127C4 thumb
 *   func_02174734 0x02174734 thumb ov011
 *   func_02162024 0x02162024 thumb ov010
 *   func_021747A8 0x021747A8 thumb ov011
 *   func_02162038 0x02162038 thumb ov010
 *   func_0216202C 0x0216202C thumb ov010
 *   func_021747F4 0x021747F4 thumb ov011
 *   func_02162040 0x02162040 thumb ov010
 */
int func_02026478(int a);
int func_020127C4(int h);
int func_02174734(void *p, int b, int c);
int func_02162024(void *p, int i, void *o);
int func_021747A8(void *a, int b);
void func_02162038(void *p, int i);
int func_0216202C(void *p, void *o, unsigned char *i);
int func_021747F4(void *a, int b);
void func_02162040(void *p);
void func_02174C38(unsigned char *p)
{
    int b1[2];
    int b2[2];
    unsigned char i;
    int h;
    h = func_02026478(*(int *)(p + 4));
    if (p[0x908] != 0) {
        if (func_02174734(p, p[0x908], func_020127C4(h)) == 1) {
            p[0x908] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if (func_02162024(p + 0x35C, i, b1) == 1) {
            if (func_021747A8(b1, i) == 1) {
                func_02162038(p + 0x35C, i);
            }
        }
    }
    if (func_0216202C(p + 0x35C, b2, &i) == 1) {
        if (func_021747F4(b2, i) == 1) {
            func_02162040(p + 0x35C);
        }
    }
}
