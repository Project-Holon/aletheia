/*
 * function: func_021C9634
 * address: 0x021C9634
 * packet: pkt_ov114_021C9634
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021CA188 0x021CA188 arm ov114
 *   g_021D4084 0x021D4084 data a4
 */
extern void func_021CA188(void);
extern unsigned g_021D4084;
void func_021C9634(void)
{
    switch (g_021D4084) {
    case 2: func_021CA188(); g_021D4084 = 3; break;
    case 4: func_021CA188(); g_021D4084 = 5; break;
    case 6: func_021CA188(); g_021D4084 = 7; break;
    case 8: func_021CA188(); g_021D4084 = 9; break;
    case 10: func_021CA188(); g_021D4084 = 11; break;
    }
}
