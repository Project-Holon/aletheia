/*
 * function: func_021F30B4
 * address: 0x021F30B4
 * packet: pkt_ov032_021F30B4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020452E8 0x020452E8 arm
 */
struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
void func_021F30B4(char *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_020452E8(*(struct Descriptor **)(p + i * 20 + 0x17c));
}
