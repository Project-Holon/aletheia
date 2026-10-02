/*
 * function: func_021D6E24
 * address: 0x021D6E24
 * packet: pkt_ov093_021D6E24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0202142C 0x0202142C thumb
 *   func_02017E40 0x02017E40 thumb
 * prototype: reads r0 after func_0202142C, so returns the live wrapper result.
 */
typedef unsigned int u32;
extern u32 func_0202142C(int);
extern void func_02017E40(void *, u32, u32);
void func_021D6E24(void **p, int value)
{
    u32 n;
    n = func_0202142C(value);
    if (n == 0) n = 4;
    func_02017E40(*p, 0x98, n);
}
