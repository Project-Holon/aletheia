/*
 * function: func_021F38BC
 * address: 0x021F38BC
 * packet: pkt_ov065_021F38BC
 * region: ov065
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_021F38D0 0x021F38D0 thumb ov065
 */
typedef unsigned int   u32;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F38D0(void *p);

void *func_021F38BC(void *p)
{
    return func_020122C0(p, 0, (void *)func_021F38D0, 0);
}
