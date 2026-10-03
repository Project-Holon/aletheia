/*
 * function: func_021D30B8
 * address:  0x021D30B8
 * packet:   pkt_ov021_021D30B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02030734  0x02030734  arm
 *   func_021D310C  0x021D310C  thumb  ov021
 *   d_021DE698     0x021DE698  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct W {
    void *a;
    void *b;
    void **c;
    u16 *d;
} W;

struct Ctx;
struct Desc;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021D310C(u32 a, u32 *st, u32 *p);
extern char d_021DE698[];

void *func_021D30B8(void *a, u16 *b)
{
    void *r7;
    void *s4;
    void *s8;
    W *w;

    r7 = func_020120F4(a);
    s4 = func_0201210C(a);
    s8 = func_020122C0(a, 0, func_021D310C, 0x10);
    w = func_020124E8(s8);
    w->a = a;
    w->b = s4;
    w->d = b;
    w->c = func_02030734(4, 8, 0, d_021DE698, 0x4a);
    *w->c = r7;
    return s8;
}
