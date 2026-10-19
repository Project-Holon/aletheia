/*
 * function: intrVBlank
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
 *   DWCi_TSKlAct  0x021D75D0  arm  ov016
 *   sInterruptTable     0x02FE0000  data
 */

extern void DWCi_TSKlAct(int kind);
extern int sInterruptTable;

void intrVBlank(void)
{
    DWCi_TSKlAct(1);
    *(volatile unsigned int *)((unsigned int)&sInterruptTable + 0x3FF8) |= 1;
}
