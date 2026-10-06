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

extern int func_02186278(char *p, int which);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct ArcFile;
extern int *func_021867C4(int a, int id);
extern void *func_02186830(struct ArcFile **p, int b, unsigned int heap);
extern int func_02161ECC(void *p);
extern int func_021867B0(u8 *p);
extern void func_02186818(u32 *p, u32 member);
extern char *func_0218682C(char *p);
extern void func_0216E618(Tmpl *, u16, u16, int);
extern void func_0218683C(void *p);
extern void func_02186804(void **p);

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
    n = func_02186278((char *)p, which);
    if (n == 0)
        return 0;
    if (which == 0)
        base = (char *)p + 8;
    else
        base = (char *)p + 0xf8;
    buf = func_02030734(heap, n * 0x24, 1, d_02187EB4, 0x2E3);
    k = 0;
    h = (int)func_021867C4(0, heap);
    t = func_02186830((struct ArcFile **)h, p[1], heap);
    i = 0;
    tmp = d_02187DBC;
    for (; i < 10; i++) {
        off = i * 0x18;
        if (func_02161ECC(base + off)) {
            e = &buf[k];
            *e = tmp;
            func_02186818((u32 *)h, func_021867B0((u8 *)(base + off)));
            r = (u16 *)func_0218682C((char *)h);
            e->f0 = func_021867B0((u8 *)(base + off)) + 0x80;
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
    func_02186804((void **)h);
    return buf;
}
