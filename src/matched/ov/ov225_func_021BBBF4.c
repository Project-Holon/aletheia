/*
 * function: func_021BBBF4
 * address: 0x021BBBF4
 * packet: pkt_ov225_021BBBF4
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020499D4 0x020499D4 arm
 */
typedef unsigned short u16;
extern void func_02049B68(unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern void func_02049658(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern unsigned func_020499D4(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
void func_021BBBF4(char *p)
{
    func_02049B68(*(unsigned *)(*(char **)(p + 4) + 0x24), 0, 4, 0, 64, *(u16 *)(*(char **)(p + 4) + 4));
    func_02049658(*(unsigned *)(*(char **)(p + 4) + 0x24), 2, 4, 0, 0, 0, *(u16 *)(*(char **)(p + 4) + 4));
    func_020499D4(*(unsigned *)(*(char **)(p + 4) + 0x24), 6, 4, 0, 0, 0, 0, *(u16 *)(*(char **)(p + 4) + 4));
}
