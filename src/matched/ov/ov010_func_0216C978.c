/*
 * function: func_0216C978
 * address:  0x0216C978
 * packet:   pkt_ov010_0216C978
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_02172548     0x02172548  data  ov010  a4
 */

extern int func_020120F4(int);
extern void func_020120B4(int, int, char *, int *);
extern int func_020120F0(int);
extern char d_02172548[];

int func_0216C978(int a, int *st, int *o)
{
    int x = o[0];
    int *t;
    switch (*st) {
    case 0:
        t = o + 3;
        o[3] = func_020120F4(x);
        t[1] = o[1];
        t[2] = o[2];
        func_020120B4(x, ~0, d_02172548, t);
        (*st)++;
        break;
    case 1:
        if (func_020120F0(x) == 0)
            return 1;
        break;
    }
    return 0;
}
