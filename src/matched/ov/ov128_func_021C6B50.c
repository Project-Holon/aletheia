/*
 * function: func_021C6B50
 * address: 0x021C6B50
 * packet: pkt_ov128_021C6B50
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 */
typedef unsigned long long u64;
extern void func_0201EFA4(void *,unsigned,unsigned,unsigned,unsigned,unsigned);
void func_021C6B50(void **p,u64 value)
{
    func_0201EFA4(*p,1,(unsigned)(value/100000000ULL),4,2,1);
    func_0201EFA4(*p,2,(unsigned)(value/10000ULL%10000ULL),4,2,1);
    func_0201EFA4(*p,3,(unsigned)(value%10000ULL),4,2,1);
}
