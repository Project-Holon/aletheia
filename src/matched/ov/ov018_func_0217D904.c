/*
 * function: func_0217D904
 * address: 0x0217D904
 * packet: pkt_ov018_0217D904
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 0x0217D916.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
struct Descriptor;
extern void func_020452E8(struct Descriptor *);
void func_0217D904(char *p)
{
    func_020452E8(*(struct Descriptor **)(p + 0x44));
    func_020452E8(*(struct Descriptor **)(p + 0x4c));
}
