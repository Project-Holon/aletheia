/*
 * function: func_021D533C
 * address: 0x021D533C
 * packet: pkt_ov093_021D533C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent tail: two zero alignment bytes at 021D5362; next code at 021D5364.
 * symbols:
 *   func_021D4EFC 0x021D4EFC thumb ov093
 *   func_021D5150 0x021D5150 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct S { void *f00; u8 pad04[0x17]; u8 lo : 5; u8 flag : 1; };
extern void func_021D4EFC(struct S *, void *, u32, u32);
extern void func_021D5150(struct S *);
void func_021D533C(struct S *p)
{
    if (p->flag != 0) {
        func_021D4EFC(p, p->f00, 0, 1);
        func_021D5150(p);
        p->flag = 0;
    }
}
