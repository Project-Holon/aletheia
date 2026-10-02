/*
 * function: func_021C5918
 * address:  0x021C5918
 * packet:   pkt_ov136_021C5918
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5918 0x021C5918 thumb
 *   func_0202CA0C 0x0202CA0C thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202CA0C(u32 v);
void func_021C5918(u8 *p)
{
    func_0202CA0C(**(u32 **)(p + 8));
}
