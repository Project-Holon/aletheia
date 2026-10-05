/*
 * function: func_021CF59C
 * address:  0x021CF59C
 * packet:   pkt_ov021_021CF59C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail call through r3; the second argument is the ov075 overlay id
 * (a pool word, 0x4B).
 *
 * symbols:
 *   func_021CF564  0x021CF564  thumb ov021
 *   ov075_id       0x0000004B  data
 */

typedef unsigned int u32;
struct Res021CF;
extern void func_021CF564(struct Res021CF *r, u32 id);
extern unsigned char ov075_id[];

void func_021CF59C(struct Res021CF *r)
{
    func_021CF564(r, (u32)ov075_id);
}
