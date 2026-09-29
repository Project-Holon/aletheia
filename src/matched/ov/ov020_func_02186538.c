/*
 * function: func_02186538
 * address:  0x02186538
 * packet:   pkt_ov020_02186538
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02186278  0x02186278  thumb  ov020
 *   func_02030734  0x02030734  arm
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_02186830  0x02186830  thumb  ov020
 *   func_02161ECC  0x02161ECC  thumb  ov010
 *   func_021867B0  0x021867B0  thumb  ov020
 *   func_02186818  0x02186818  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02186804  0x02186804  thumb  ov020
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DBC     0x02187DBC  data  ov020  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fA;
    int f0C[6];
} Tmpl;

extern const char d_02187EB4[];
extern const Tmpl d_02187DBC;

extern int func_02186278(u16 *p, int which);
extern Tmpl *func_02030734(int heap, int size, int clear, const char *file, int line);
extern int func_021867C4(int, int);
extern u8 *func_02186830(int h, int b, int heap);
extern int func_02161ECC(void *p);
extern int func_021867B0(void *p);
extern void func_02186818(int h, int v);
extern u16 *func_0218682C(int h);
extern void func_0216E618(Tmpl *, u16, u16, int);
extern void func_0218683C(u8 *t);
extern void func_02186804(int);

Tmpl *func_02186538(u16 *p, int which, int id)
{
    int k;
    Tmpl *buf;
    int h;
    u8 *t;
    int heap;
    int n;
    int i;
    int off;
    char *base;
    u16 *r;
    Tmpl *e;
    Tmpl tmp;

    heap = (u16)((id & 0x7FFF) | 0x8000);
    n = func_02186278(p, which);
    if (n == 0)
        return 0;
    if (which == 0)
        base = (char *)p + 8;
    else
        base = (char *)p + 0xf8;
    buf = func_02030734(heap, n * 0x24, 1, d_02187EB4, 0x2E3);
    k = 0;
    h = func_021867C4(0, heap);
    t = func_02186830(h, p[1], heap);
    i = 0;
    tmp = d_02187DBC;
    for (; i < 10; i++) {
        off = i * 0x18;
        if (func_02161ECC(base + off)) {
            e = &buf[k];
            *e = tmp;
            func_02186818(h, func_021867B0(base + off));
            r = func_0218682C(h);
            e->f0 = func_021867B0(base + off) + 0x80;
            e->f2 = r[0];
            e->f4 = 3;
            if (which == 0) {
                if (p[1] == 0)
                    e->fA = r[0xf];
                else
                    e->fA = r[0xe];
            } else {
                if (p[1] == 0)
                    e->fA = r[0x11];
                else
                    e->fA = r[0x10];
            }
            func_0216E618(e, t[i * 2], t[i * 2 + 1], 0);
            k++;
        }
    }
    func_0218683C(t);
    func_02186804(h);
    return buf;
}
