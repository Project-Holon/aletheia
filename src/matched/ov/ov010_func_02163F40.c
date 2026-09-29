/*
 * function: func_02163F40
 * address:  0x02163F40
 * packet:   pkt_ov010_02163F40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb
 *   func_0216D86C  0x0216D86C  thumb
 *   func_0216D8AC  0x0216D8AC  thumb
 *   func_02164280  0x02164280  thumb
 *   func_02164208  0x02164208  thumb
 *   func_02163E34  0x02163E34  thumb
 */

extern int func_0216D83C(int a);
extern int func_0216D86C(int a);
extern int func_0216D8AC(int a);
extern void func_02164280(int x, int y, int *p);
extern void func_02164208(int dir, int *p, int amt);
extern void func_02163E34(int a, int *p, int *out);

int func_02163F40(int a, int dir)
{
    int buf[3];
    int v;

    v = -1;
    func_02164280(func_0216D83C(a), func_0216D86C(a), buf);
    buf[1] = func_0216D8AC(a);
    func_02164208(dir, buf, 0x10000);
    func_02163E34(a, buf, &v);
    return v;
}
