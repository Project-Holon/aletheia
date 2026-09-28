/*
 * function: func_021BD12C
 * address:  0x021BD12C
 * packet:   pkt_021BD12C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Calls 0x02047964 on p, then 0x02048AD0 on the word at [p], then 0x020479D8.
 */

extern void func_02047964(void *);
extern void func_02048AD0(int);
extern void func_020479D8(void);

void func_021BD12C(int *p)
{
    func_02047964(p);
    func_02048AD0(*p);
    func_020479D8();
}
