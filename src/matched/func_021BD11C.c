/*
 * function: func_021BD11C
 * address:  0x021BD11C
 * packet:   pkt_021BD11C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 *
 * Loads the word at [p], then calls the ARM9 functions at 0x02048AC4 and 0x02046788.
 */

extern void func_02048AC4(int);
extern void func_02046788(void);

void func_021BD11C(int *p)
{
    func_02048AC4(*p);
    func_02046788();
}
