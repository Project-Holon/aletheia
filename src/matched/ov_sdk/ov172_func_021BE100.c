/*
 * function: func_021BE100
 * address:  0x021BE100
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 1 when 0x0202EB0C returns 1 and 0x0202EB14 returns 0.
 *
 * symbols:
 *   sub_0202EB0C  0x0202EB0C  thumb
 *   unit_0202EB14  0x0202EB14  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 sub_0202EB0C(void);
extern int unit_0202EB14(void);

int func_021BE100(void)
{
    if (sub_0202EB0C() == 1 && unit_0202EB14() == 0) {
        return 1;
    }
    return 0;
}
