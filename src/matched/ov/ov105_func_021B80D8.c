/*
 * function: func_021B80D8
 * address: 0x021B80D8
 * packet: pkt_ov105_021B80D8
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: parent SDK/assignment/source/unit/shard audit cleared 16-byte stub.
 * Original overwrites r1 with callback80E8, tail-forwards r0 to80BC;
 * 80BC stores callback at18c and zeros halfword190, reads no other input.
 * symbols:
 *   func_021B80BC 0x021B80BC thumb ov105
 *   func_021B80E8 0x021B80E8 thumb ov105
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021B80BC(unsigned char *p, unsigned int v);
extern void func_021B80E8(u8 *,u16 *);
void func_021B80D8(u8 *p)
{
    func_021B80BC(p,(unsigned int)func_021B80E8);
}
