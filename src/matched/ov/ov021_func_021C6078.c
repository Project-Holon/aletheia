/*
 * function: func_021C6078
 * address:  0x021C6078
 * packet:   pkt_ov021_021C6078
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_021C60B8  0x021C60B8  thumb  ov021
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_02188CB4(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_021C60B8(void);

void *func_021C6078(void *a, void *b, int c)
{
    void *task;
    u8 *w;

    task = func_020122C0(a, 0, func_021C60B8, 0x14);
    w = func_020124E8(task);
    func_02082BCC(w, 0, 0x14);
    w[0] = c;
    *(void **)(w + 4) = a;
    *(void **)(w + 0xC) = b;
    *(void **)(w + 0x10) = func_02188CB4(b);
    *(void **)(w + 8) = func_020120F4(a);
    return task;
}
