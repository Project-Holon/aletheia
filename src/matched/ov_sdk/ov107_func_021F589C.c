/*
 * function: MBi_GetBeaconPeriodDispersion
 * address:  0x021F589C
 * packet:   pkt_ov107_021F589C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o).
 * 0x02FFFC3C is a system word read as a cast constant (see
 * docs/idioms/volatile-reread-needs-two-locals.md): no relocation, address
 * stays in r1.
 *
 * symbols:
 *   OS_GetMacAddress                 0x02087c6c arm
 */
typedef unsigned char u8;
typedef unsigned long u32;

extern void OS_GetMacAddress(u8 *macAddress);

static u32 MBi_GetBeaconPeriodDispersion(void)
{
    u8 mac[6];
    long i;
    u32 ret;

    OS_GetMacAddress(mac);
    for (i = 0, ret = 0; i < 6; i++)
        ret += mac[i];
    ret = (ret + *(volatile u32 *)0x02FFFC3C) * 7 % 20;
    return ret;
}
