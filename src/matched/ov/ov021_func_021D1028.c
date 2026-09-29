/*
 * function: func_021D1028
 * address:  0x021D1028
 * packet:   pkt_ov021_021D1028
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020120F4(void);
extern u32 func_02012EBC(u32 a);
extern u8 *func_0200E8F8(u32 a);

int func_021D1028(void)
{
    u8 *p = func_0200E8F8(func_02012EBC(func_020120F4()));

    if (p[0] != 0) {
        if (p[0x14] != 0) {
            return 3;
        }
        return 1;
    }
    if (p[0x14] != 0) {
        return 2;
    }
    return 0;
}
