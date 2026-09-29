/*
 * function: func_021D6D1C
 * address:  0x021D6D1C
 * packet:   pkt_ov016_021D6D1C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      intrVBlank (libdwcutil.TWL.HYB.a interrupt.o)
 *
 * symbols:
 *   func_021D75D0  0x021D75D0  arm  ov016
 *   g_02FE0000     0x02FE0000  data
 */

extern void func_021D75D0(int kind);
extern int g_02FE0000;

void func_021D6D1C(void)
{
    func_021D75D0(1);
    *(volatile unsigned int *)((unsigned int)&g_02FE0000 + 0x3FF8) |= 1;
}
