/*
 * function: func_021C5BD0
 * address:  0x021C5BD0
 * packet:   pkt_ov021_021C5BD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns the func_021C5C08 task with a 0x14-byte work area.
 *
 * symbols:
 *   func_021C5C08  0x021C5C08  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;
    void *f4;
    u32 f8;
    u16 hC;
    u16 pad;
    u32 f10;
} W;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
void func_021C5C08(void);

void *func_021C5BD0(void *a, u16 b, u32 c)
{
    void *t = func_020122C0(a, 0, func_021C5C08, 0x14);
    W *w = func_020124E8(t);

    w->owner = a;
    w->f4 = func_0201210C(a);
    w->f10 = c;
    w->f8 = (u32)func_020120F4(a);
    w->hC = b;
    return t;
}
