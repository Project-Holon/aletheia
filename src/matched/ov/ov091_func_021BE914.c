/*
 * function: func_021BE914
 * address: 0x021BE914
 * packet: pkt_ov091_021BE914
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E40 0x02017E40 thumb
 */
typedef unsigned int u32;
extern void func_02017E40(void *, u32, u32);
void func_021BE914(void *p, u32 v, u32 limit, u32 step)
{
    if (limit == 1) step = 1;
    else if (step == 0xff) step = limit;
    else if (step == 0xfe) step = limit >> 1;
    else if (step == 0xfd) step = limit >> 2;
    v += step;
    if (v > limit) v = limit;
    func_02017E40(p, 0xa0, v);
}
