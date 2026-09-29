/*
 * function: func_021C4C54
 * address:  0x021C4C54
 * packet:   pkt_ov021_021C4C54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216DBE8  0x0216DBE8  thumb  ov010
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_021C6844  0x021C6844  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_021C6828  0x021C6828  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */

typedef unsigned short u16;

extern int func_0216E1C4(int a, int *b);
extern void func_021AC154(int a);
extern int func_0216DBE8(int a);
extern int func_021ABE18(int a);
extern void func_021C6658(int a, int b);
extern int func_021C6844(int a, int b);
extern void func_021C66EC(int a, int b, int c);
extern void func_021C6828(int a, int b, int c);
extern void func_0216D88C(int a, int *out);
extern void func_021AC1CC(int a, int *v);

void func_021C4C54(int a, int *b)
{
    int v[3];
    int h;
    int r;

    if (func_0216E1C4(b[1], b + 2) == 0) {
        func_021AC154(a);
        return;
    }
    if (func_0216DBE8(b[1]) == 0) {
        func_021AC154(a);
        return;
    }
    h = *(u16 *)(b + 4);
    r = func_021ABE18(*(int *)b[0]);
    func_021C6658(r, h);
    if (func_021C6844(r, h) == 0) {
        func_021C66EC(r, h, 0x1000);
        func_021C6828(r, h, 1);
    }
    func_0216D88C(b[1], v);
    v[2] += 0x8000;
    func_021AC1CC(a, v);
}
