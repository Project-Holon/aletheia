/*
 * function: func_021766CC
 * address: 0x021766CC
 * packet: pkt_ov011_021766CC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_021766F0 0x021766F0 thumb ov011
 */
typedef unsigned int u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021766F0(void *p, void *q, void *r);
void *func_021766CC(void *p, void *q)
{
    void *desc;
    void **buf;
    desc = func_020122C0(p, 0, func_021766F0, 8);
    buf = func_020124E8(desc);
    buf[1] = q;
    buf[0] = p;
    return desc;
}
