/*
 * function: WIFICLUB_CopyZeroToDeviceAddr
 * address:  0x021C282C
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */
typedef unsigned char u8;

extern int MI_CpuCopy8(const void *a, const void *b, int n);

int WIFICLUB_CopyZeroToDeviceAddr(u8 *p)
{
    u8 z[6] = {0, 0, 0, 0, 0, 0};

    return MI_CpuCopy8(z, p + 8, 6);
}
