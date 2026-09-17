/*
 * function: func_020370C8
 * address:  0x020370C8
 * packet:   pkt_020370C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  PC24 func_02036E80 at +0x18: no branch anywhere outside this range reaches 0x02036E80
 * symbols:
 *   g_021469C8      0x021469C8  data
 */

extern void func_02036FD8(void);
extern void func_02036E80(void);
extern int g_021469C8[];
void func_020370C8(void)
{
    func_02036FD8();
    if (g_021469C8[1] == 0)
        return;
    func_02036E80();
    g_021469C8[1] = 0;
}
