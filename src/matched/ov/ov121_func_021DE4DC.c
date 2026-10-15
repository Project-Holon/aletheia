/*
 * function: MYSTERY_NET_GetReceivedData
 * address: 0x021DE4DC
 * packet: pkt_ov121_021DE4DC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuCopy8(void *dst, void *src, int n);
int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b)
{
    int s = *(int *)(p + 0x17A4);
    if (s == 1) {
        MI_CpuCopy8(p + 0x7A4, a, b);
        return 1;
    }
    return s;
}
