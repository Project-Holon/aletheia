/*
 * function: func_02005440
 * address:  0x02005440
 * packet:   pkt_02005438
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02005454
 * symbols:
 *   g_020A9E80      0x020A9E80  data
 *   func_02005454   0x02005454  arm
 */

extern int g_020A9E80;
extern void func_02005454(int v);
void func_02005440(void)
{
    func_02005454(0);
    g_020A9E80 = 1;
}
