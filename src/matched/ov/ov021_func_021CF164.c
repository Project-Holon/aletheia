/*
 * function: func_021CF164
 * address:  0x021CF164
 * packet:   pkt_ov021_021CF164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Opens the ov021 resource 0x021DB4BC in heap 0x2700 with 8 entries.
 *
 * symbols:
 *   func_0203A574  0x0203A574  arm
 *   data_021DB4BC  0x021DB4BC  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0203A574(u32 heap, const void *res, int n, u32 a);
extern const u8 data_021DB4BC[];

void func_021CF164(u32 a)
{
    func_0203A574(0x2700, data_021DB4BC, 8, a);
}
