/*
 * function: func_02173A2C
 * address:  0x02173A2C
 * packet:   pkt_ov011_02173A2C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02082BCC  0x02082BCC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
void func_02082BCC(void *p, int v, int n);
struct Entry;
struct Entry *func_020399A8(void);
int func_0203D3F8(int a, int b, int c, int d, void *e, int f, int g, int h);

typedef struct T {
    int w[13];
} T;

typedef struct B {
    unsigned char a;
    unsigned char b;
    short pad;
    T t;
} B;

int func_02173A2C(unsigned char *p, int b, T *c, int d)
{
    B buf;
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    if (p[0x944] == 0) {
        p[0x944]++;
    }
    func_02082BCC(&buf, 0, 0x38);
    buf.a = d;
    buf.t = *c;
    buf.b = p[0x944];
    r = func_0203D3F8((int)func_020399A8(), (unsigned char)b, 0x207, 0x38, &buf, 0, 0, 0);
    if (r == 1) {
        p[0x158] = p[0x944];
        p[0x159] = p[0x944];
    }
    return r;
}
