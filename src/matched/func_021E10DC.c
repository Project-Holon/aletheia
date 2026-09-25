/*
 * function: func_021E10DC
 * address:  0x021E10DC
 * packet:   pkt_021E10DC
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 */

extern void func_020490F4(int, int);
extern void func_02049238(void);

void func_021E10DC(char *p)
{
    func_020490F4(0x17, *(unsigned short *)(p + 0x34c));
    func_02049238();
}
