/*
 * function: SOC_InetNtoP
 * address:  0x0215fb28
 * packet:   pkt_ov009_0215FB28
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_InetNtoP (soc.o)
 *
 * symbols:
 *   MI_CpuCopy8      0x02082d44 arm
 *   SOC_U32to4U8     0x0215fbac arm
 *   OS_SNPrintf      0x02084f80 arm
 *   g_021A1D2C       0x021a1d2c data
 */

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern char g_021A1D2C[];

char *SOC_InetNtoP(int af, void *src, char *dst, unsigned int len)
{
    unsigned long addr32;
    unsigned char addr[4];

    if (af != 2)
        return 0;
    if (len < 0x10)
        return 0;
    MI_CpuCopy8(src, &addr32, 4);
    SOC_U32to4U8(addr32, addr);
    OS_SNPrintf(dst, 16, g_021A1D2C, addr[3], addr[2], addr[1], addr[0]);
    return dst;
}
