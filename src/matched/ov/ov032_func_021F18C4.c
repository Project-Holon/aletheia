/*
 * function: func_021F18C4
 * address: 0x021F18C4
 * packet: pkt_ov032_021F18C4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F0A98 0x021F0A98 thumb ov032
 *   func_021F18E0 0x021F18E0 thumb ov032
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F0A98(char *p, int b);
extern void func_021F18E0(char *p, u32 a, int *c);
void func_021F18C4(char *p, int b)
{
    func_021F0A98(p, b);
    func_021F18E0(p, *(u32 *)(p + 0x11c), (int *)(p + 0xa8));
}
