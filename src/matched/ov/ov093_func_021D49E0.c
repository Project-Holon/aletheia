/*
 * unit: yes
 * function: func_021D49E0, func_021D4A04
 * address: 0x021D49E0
 * packet: pkt_ov093_021D49E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Extent follower 021D4A04 is a tail-call stub; function_start seed.
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_020307B0 0x020307B0 arm
 *   func_021D4A6C 0x021D4A6C thumb ov093
 */
typedef unsigned char u8;
extern u8 *d_021F3B88;
extern void func_020307B0(void *);
extern void func_021D4A6C(void);
void func_021D49E0(void)
{
    func_020307B0(*(void **)(d_021F3B88 + 0x3b14));
    *(void **)(d_021F3B88 + 0x3b14) = 0;
    *(void **)(d_021F3B88 + 0x3b18) = 0;
}
void func_021D4A04(void)
{
    func_021D4A6C();
}
