/*
 * function: func_021DE4DC
 * address: 0x021DE4DC
 * packet: pkt_ov121_021DE4DC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02082D44(void *dst, void *src, int n);
int func_021DE4DC(u8 *p, void *a, u32 b)
{
    int s = *(int *)(p + 0x17A4);
    if (s == 1) {
        func_02082D44(p + 0x7A4, a, b);
        return 1;
    }
    return s;
}
