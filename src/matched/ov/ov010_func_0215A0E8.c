/*
 * function: func_0215A0E8
 * address:  0x0215A0E8
 * packet:   pkt_ov010_0215A0E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02030734  0x02030734  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A214  0x0215A214  thumb  ov010
 *   d_021728CC  0x021728CC  data
 */

typedef unsigned int u32;

struct Ctx;
struct Desc;
extern void *func_020120F4(const struct Ctx *p);
typedef unsigned short u16;
struct BigObj;
struct Ctx;
struct Obj;
extern void *func_02012934(const struct BigObj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_0215A214(void);
extern const char d_021728CC[];

void *func_0215A0E8(int a, int b, int c, int d, unsigned short e)
{
    void *h = func_02012934(func_020120F4((const struct Ctx *)a));
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x66);
    void *r;
    u32 *q;
    p[0] = (u32)h;
    p[0x34 / 4] = 0x18;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    *((unsigned char *)p + 0x5e) = d;
    *(unsigned short *)((unsigned char *)p + 0x46) = e;
    r = func_020122C0((void *)a, 0, func_0215A214, 0x18);
    q = func_020124E8(r);
    q[0] = a;
    q[1] = (u32)func_0201210C((void *)a);
    q[2] = (u32)p;
    q[3] = 0;
    q[4] = b;
    q[5] = c;
    return r;
}
