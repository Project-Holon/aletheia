/*
 * function: func_021E88F8
 * address:  0x021E88F8
 * packet:   pkt_ov093_021E88F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02034A5C  0x02034A5C  arm
 *   d_021F6380  0x021F6380  data
 *   ov140_id  0x0000008C  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void sub_02034A5C(u8 *handle);
extern u8 ov140_id[];
extern int d_021F6380;

void func_021E88F8(void)
{
    if (d_021F6380 != 0) {
        sub_02034A5C(ov140_id);
        d_021F6380 = 0;
    }
}
