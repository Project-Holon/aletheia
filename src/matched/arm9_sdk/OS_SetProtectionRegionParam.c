/*
 * function: OS_SetProtectionRegionParam
 * address:  0x02086D14
 * packet:   pkt_02086D14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   g_020A86B4 0x020A86B4 data
 */

typedef unsigned long u32;

extern void (*g_020A86B4[8])(u32);

void OS_SetProtectionRegionParam(int regionNo, u32 param)
{
    g_020A86B4[regionNo](param);
}
