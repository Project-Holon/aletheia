/*
 * function: func_021B66D4
 * address:  0x021B66D4
 * packet:   pkt_021B66D4
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047E54  0x02047E54  arm
 *   func_02046788  0x02046788  arm
 */

extern void func_02047E54(int);
extern void func_02046788(void);

void func_021B66D4(int *p)
{
    func_02047E54(*(int *)((char *)p + 0x10));
    func_02046788();
}
