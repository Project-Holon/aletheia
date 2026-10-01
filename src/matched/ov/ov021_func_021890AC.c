/*
 * function: func_021890AC
 * address:  0x021890AC
 * packet:   pkt_ov021_021890AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047970  0x02047970  arm
 *   d_021D35B4     0x021D35B4  data  a4
 */

typedef int (*Fn)(unsigned char *p);

extern Fn d_021D35B4[];
void func_02047970(int x);

void func_021890AC(unsigned char *p)
{
    func_02047970(d_021D35B4[*(int *)(p + 0x12C)](p));
}
