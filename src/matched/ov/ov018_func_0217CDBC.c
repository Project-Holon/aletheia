/*
 * function: func_0217CDBC
 * address: 0x0217CDBC
 * packet: pkt_ov018_0217CDBC
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_0217CDD0 0x0217CDD0 thumb ov018
 */
extern int func_0217CDD0(void *, int *);
typedef unsigned int   u32;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_0217CDBC(void *p)
{
    return func_020122C0(p, 0, func_0217CDD0, 0);
}
