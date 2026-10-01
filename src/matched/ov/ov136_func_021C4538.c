/*
 * function: func_021C4538
 * address: 0x021C4538
 * packet: pkt_ov136_021C4538
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021C458E..021C4590 zero alignment padding.
 * symbols:
 *   func_02035C38 0x02035C38 arm
 *   func_0203630C 0x0203630C arm
 */
typedef unsigned char u8;
extern int func_02035C38(void);
extern int func_0203630C(void);
int func_021C4538(u8 *p)
{
    if (p[0xA] == 0) {
        if (func_02035C38()) return 0;
        if (func_0203630C()) {
            if (*(void (**)(void *))(p + 0x3C)) (*(void (**)(void *))(p + 0x3C))(p);
            p[0xA] = 1;
            return 1;
        }
    } else {
        if (func_0203630C()) return 0;
        if (func_02035C38()) {
            if (*(void (**)(void *))(p + 0x40)) (*(void (**)(void *))(p + 0x40))(p);
            p[0xA] = 0;
            return 0;
        }
    }
    return 0;
}
