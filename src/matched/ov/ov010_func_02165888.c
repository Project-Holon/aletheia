/*
 * function: func_02165888
 * address:  0x02165888
 * packet:   pkt_ov010_02165888
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02165888 0x02165888 thumb
 *   func_0203F4CC 0x0203F4CC arm
 *   func_02026CA0 0x02026CA0 thumb
 *   func_02026C1C 0x02026C1C thumb
 *   func_02165960 0x02165960 thumb ov010
 *   func_02026CE0 0x02026CE0 thumb
 */

extern void func_0203F4CC(int *);
extern int func_02026CA0(int *);
extern int func_02026C1C(void);
extern int func_02165960(int, int, int, int);
extern void func_02026CE0(int);

int func_02165888(int a0)
{
    int t[3];
    int cur;
    int n;
    int h;
    int k;
    int r;

    n = 0;
    cur = 0;
    func_0203F4CC(t);
    h = (unsigned short)((t[0] << 8) | t[1]);
    for (;;) {
        k = func_02026CA0(&cur);
        if (k == 0x1e) {
            break;
        }
        r = func_02165960(a0, func_02026C1C(), h, 0);
        if (r == 0x1e) {
            break;
        }
        func_02026CE0(k);
        n++;
    }
    return n;
}
