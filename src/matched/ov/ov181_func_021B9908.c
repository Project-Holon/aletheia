/*
 * function: func_021B9908
 * address: 0x021B9908
 * packet: pkt_ov181_021B9908
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02051E74 0x02051E74 arm
 *   sub_02040860 0x02040860 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021BAC74 0x021BAC74 data a4
 *   d_021BACC4 0x021BACC4 data a4
 *   d_021BAC84 0x021BAC84 data a4
 *   d_021BACA4 0x021BACA4 data a4
 */
typedef struct { unsigned words[4]; } Small;
typedef struct { unsigned words[8]; } Big;
extern const Small d_021BAC74;
extern const Big d_021BACC4, d_021BAC84, d_021BACA4;
extern void func_0203F8F4(unsigned short);
extern void func_0203FC28(Small *);
extern void func_0203FCA0(unsigned, const Big *, unsigned);
extern void func_02051E74(Small *, unsigned, const void *, const void *, unsigned char);
extern void sub_02040860(unsigned, unsigned, unsigned, unsigned);
extern void func_020434DC(unsigned, unsigned);
extern void func_02043598(unsigned, unsigned);
void func_021B9908(void)
{
    Small a;
    Big b, c;
    Small d;
    Big e;
    func_0203F8F4(0x8E);
    a = d_021BAC74;
    func_0203FC28(&a);
    b = d_021BACC4;
    func_0203FCA0(1, &b, 0);
    c = d_021BAC84;
    func_0203FCA0(3, &c, 2);
    func_02051E74(&d, 0, (const void *)0x9000, (const void *)0x9000, 0);
    sub_02040860(3, (unsigned)&d, 0x80, 0x60);
    e = d_021BACA4;
    func_0203FCA0(5, &e, 0);
    func_020434DC(2, 1);
    func_02043598(2, 1);
}
