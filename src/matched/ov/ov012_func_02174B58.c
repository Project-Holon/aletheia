/*
 * unit: yes
 * function: func_02174B58, func_02174B7C
 * address: 0x02174B58
 * packet: pkt_ov012_02174B58
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_0217562C 0x0217562C data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02034714(const char *,u32,const char *);
extern const char d_0217562C[];
u8 *func_02174B58(int a, u8 *b, int c)
{
    if (c > 0x800) func_02034714(d_0217562C, 0, d_0217562C);
    return b + 4 + (a << 11);
}

void func_02174B7C(void)
{
}
