/*
 * function: OSi_DetectDeviceType
 * address:  0x02085D0C
 * packet:   pkt_02085D0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_GetBootType 0x02087B04 arm
 *   g_020A5CD4 0x020A5CD4 data
 */
typedef unsigned long u32;
extern int OS_GetBootType(void);
extern u32 g_020A5CD4[];

static u32 OSi_DetectDeviceType(void)
{
    return g_020A5CD4[OS_GetBootType()];
}
