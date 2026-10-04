/*
 * function: func_021D61CC
 * address:  0x021D61CC
 * packet:   pkt_021D61CC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocker: the call to 0x021E8AA8 has no func_ label in any overlay listing
 * (it is an unlabelled leaf in the overlapping window: ov093/ov170/ov177 hold
 * code or a pool word at that address but none traces a function start), so
 * no evidence class attests it.  Every concrete byte matches; --suggest-split
 * cannot help because the site is a direct `bl` with no second caller.
 *
 * symbols:
 *   func_021D9EA0  0x021D9EA0  thumb  ov175
 *   func_021E8AA8  0x021E8AA8  thumb
 */
typedef unsigned int u32;

typedef unsigned char  u8;
extern void func_021D9EA0(u8 *p);
extern void func_021E8AA8(void *a);

void func_021D61CC(void *a, u32 **pp, char *p)
{
    if (*pp != 0)
        return;
    if (*(u32 *)(p + 0x30) != 0) {
        func_021D9EA0((u8 *)(*(u32 *)(p + 0x30)));
        *(u32 *)(p + 0x30) = 0;
    }
    func_021E8AA8(a);
}
