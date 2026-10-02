/*
 * function: func_021BA1B4
 * address: 0x021BA1B4
 * packet: pkt_ov093_021BA1B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two bytes are alignment padding at 0x021BA1CA.
 * interface: r1 is untouched from entry and forwarded as the counter index.
 * symbols:
 *   sub_02008DF0 0x02008DF0 thumb
 */
typedef unsigned int u32;
struct Sub02008C20Obj;
extern u32 sub_02008DF0(struct Sub02008C20Obj *, int);
void func_021BA1B4(char **p, int i)
{
    if (*(unsigned char *)(*p + 0x23) == 0)
        sub_02008DF0(*(struct Sub02008C20Obj **)(*p + 0x6c), i);
}
