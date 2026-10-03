/*
 * function: func_02168BBC
 * address: 0x02168BBC
 * packet: pkt_ov010_02168BBC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_02168B20 0x02168B20 thumb ov010
 */
typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, int, unsigned int);
extern void func_02168B20(void);
void *func_02168BBC(void *a, void *b)
{
    void *h;
    void **p;
    func_020120F4(a);
    h = func_020122C0(a, 0, func_02168B20, 0xc);
    p = func_020124E8(h);
    func_02082BCC(p, 0, 0xc);
    p[2] = a;
    p[1] = b;
    return h;
}
