/*
 * function: GFL_NET_STATE_StartConnectMac
 * address:  0x0203B084
 * packet:   pkt_0203B084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_StartBeaconScan  0x02037928  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *
 * Starts a 0x200-byte transfer over channel 1 and reports at line 0x17C
 * (380) when it answers zero.  The report site names GFL_NET_STATE_ConnectMac, the
 * sibling entry that put the read in flight.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_StartConnectMac.c \
 *       --func GFL_NET_STATE_StartConnectMac --addr 0x0203B084 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *GFL_NET_GetInitParam(void);
typedef unsigned short u16;
extern u32 GFL_NET_SYSTEM_StartBeaconScan(u32 a0, u16 a1);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_StartConnectMac(void)
{
    GFL_NET_GetInitParam();
    if (GFL_NET_SYSTEM_StartBeaconScan(1, 0x200) != 0)
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203B038, 0, (int)0x17C);
}
