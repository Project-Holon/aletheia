/*
 * function: func_021DD94C
 * address:  0x021DD94C
 * packet:   pkt_021DD94C
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

extern void func_02045374(int);
extern void func_02045730(int);
extern void func_02041B6C(void);

void func_021DD94C(int *p)
{
    func_02045374(*(int *)p);
    func_02045730(*(int *)p);
    func_02041B6C();
}
