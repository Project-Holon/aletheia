/*
 * function: func_068995B0
 * address:  0x068995B0
 * packet:   pkt_ov095_068995B0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_06898DE0  0x06898DE0  thumb
 *   func_06899638  0x06899638  thumb
 *   func_06899648  0x06899648  thumb
 *   func_06899658  0x06899658  thumb
 *   func_06899668  0x06899668  thumb
 *   func_06899678  0x06899678  thumb
 *   func_06899688  0x06899688  thumb
 *   func_06899698  0x06899698  thumb
 *   func_068996A8  0x068996A8  thumb
 *   func_068996B8  0x068996B8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_06898DE0(int a, int b);
extern int func_06899638(int a);
extern int func_06899648(int a);
extern int func_06899658(int a, int b);
extern u8 *func_06899668(int p, int n, int m);
extern int func_06899678(int a, int b);
extern int func_06899688(int a, int b);
extern void func_06899698(u8 *p, int n, int c);
extern void func_068996A8(u8 *p, int v);
extern void func_068996B8(int p, u8 *q);

void func_068995B0(int a, int p, int x)
{
    u8 v;
    int n;
    int w;
    u8 *t;

    v = func_06899638(2);
    if (x == func_06899648(v) && func_06899658(p, v) == 0) {
        switch (func_06898DE0(a, x)) {
        default:
        case 1:
            n = 8;
            break;
        case 2:
            n = 6;
            break;
        case 3:
            n = 4;
            break;
        }
        t = func_06899668(p, 7, 0x1f);
        w = func_06899678(p, v);
        t[6] = v;
        *(u16 *)(t + 4) = func_06899688(w, n);
        func_06899698(t + 0xc, 2, 0x353);
        func_068996A8(t + 0xc, v);
        func_068996B8(p, t);
    }
}
