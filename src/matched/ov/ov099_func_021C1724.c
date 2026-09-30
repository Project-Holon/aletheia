/*
 * function: func_021C1724
 * address: 0x021C1724
 * packet: pkt_ov099_021C1724
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two bytes of zero alignment padding at 0x021C1766.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BA828 0x021BA828 thumb ov099
 */
extern int func_020399A8(void);
extern int func_02039CB4(unsigned, unsigned, unsigned);
extern void func_0203D7B0(int);
extern int func_0203D7BC(int);
extern int func_021BA928(char *);
extern void func_021BA828(char *);
int func_021C1724(char *p, int ret)
{
    if (func_02039CB4(func_020399A8(), 16, 10) == 0) return ret;
    func_0203D7B0(0);
    func_0203D7BC(1);
    if (func_021BA928(p) != 0) {
        func_021BA828(p);
        *(int *)(p + 0x1cc) = 54;
    }
    return ret;
}
