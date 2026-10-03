/*
 * function: func_021DDA50
 * address:  0x021DDA50
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8980  0x021D8980  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DD09C  0x021DD09C  thumb  ov119
 *   func_021DEBD4  0x021DEBD4  thumb  ov119
 *   func_021E1098  0x021E1098  thumb  ov119
 *   func_021E12F8  0x021E12F8  thumb  ov119
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_0202208C  0x0202208C  thumb
 */

typedef unsigned short u16;

extern void func_021D8980(char *p);
extern void func_021D8E84(void *p, int v);
extern void func_021DD09C(char *p);
extern void func_021DEBD4(void *p);
extern void func_021E1098(char *p);
extern void func_021E12F8(char *p);
extern int func_020279E8(int a);
extern int func_02027A04(int a);
extern void func_0202208C(int a, int b, int c, int d, int e, int f, int g);

void func_021DDA50(void *p)
{
    int v;

    if (func_020279E8(*(int *)((char *)p + 0x64c)) == 0)
        return;
    v = func_02027A04(*(int *)((char *)p + 0x64c));
    func_021E12F8(p);
    func_021E1098(p);
    *(int *)((char *)p + 0x64c) = 0;
    switch (v) {
    case 0:
        func_0202208C(3, 0, 0, 0, 6, 1, *(u16 *)((char *)p + 0x5f4));
        func_021D8E84(p, 0x021DE519);
        return;
    case 1:
        func_021D8980(p);
        func_021DEBD4(p);
        func_021DD09C(p);
        func_021D8E84(p, 0x021DEA25);
        return;
    }
}
