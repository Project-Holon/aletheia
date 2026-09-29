/*
 * function: func_021868B8
 * address:  0x021868B8
 * packet:   pkt_ov020_021868B8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02186854  0x02186854  thumb  ov020
 *   func_02030734  0x02030734  arm
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_02186830  0x02186830  thumb  ov020
 *   func_021868A0  0x021868A0  thumb  ov020
 *   func_0218684C  0x0218684C  thumb  ov020
 *   func_02186898  0x02186898  thumb  ov020
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02186804  0x02186804  thumb  ov020
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DE0     0x02187DE0  data  ov020  a4
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
extern const Tmpl d_02187DE0;

extern int func_02186854(void *p);
extern Tmpl *func_02030734(int heap, int size, int clear, const char *file, int line);
extern int func_021867C4(int, int);
extern u8 *func_02186830(int h, int b, int heap);
extern int func_021868A0(void *p, int i);
extern u8 *func_0218684C(u8 *t, int i);
extern u16 func_02186898(void *p, int i);
extern void func_0216E618(Tmpl *, u16, u16, int);
extern void func_0218683C(u8 *t);
extern void func_02186804(int);

Tmpl *func_021868B8(void *p, int a1, int a2, int id)
{
    Tmpl *buf;
    int h;
    u8 *t;
    u8 *q;
    int heap;
    int n;
    int k;
    Tmpl *e;
    int i;
    Tmpl tmp;

    if (a1 != 0)
        return 0;
    if (a2 == 0)
        return 0;
    heap = (u16)((id & 0x7FFF) | 0x8000);
    n = func_02186854(p);
    k = 0;
    buf = func_02030734(heap, n * 0x24, 1, d_02187EB4, 0x561);
    h = func_021867C4(0, heap);
    t = func_02186830(h, a2, heap);
    i = 0;
    tmp = d_02187DE0;
    for (; i < 10; i++) {
        if (func_021868A0(p, i)) {
            q = func_0218684C(t, i);
            e = &buf[k];
            *e = tmp;
            e->f0 = i + 0xa0;
            e->fA = func_02186898(p, i);
            e->f8 = i + 0xaa0;
            func_0216E618(e, q[0], q[1], 0);
            k++;
        }
    }
    func_0218683C(t);
    func_02186804(h);
    return buf;
}
