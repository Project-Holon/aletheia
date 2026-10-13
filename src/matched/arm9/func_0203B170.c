/*
 * function: GFL_NET_STATE_StartBeaconScan
 * address:  0x0203B170
 * packet:   pkt_0203B170
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
 *
 * The same 0x200-byte channel-1 start as GFL_NET_STATE_StartConnectMac with no context
 * refresh, reporting at line 0x1AE (430).  0x1AE is not ARM-encodable, so the
 * constant is materialised off the 0x200 argument register as
 * `sub r3, r4, #0x52`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_StartBeaconScan.c \
 *       --func GFL_NET_STATE_StartBeaconScan --addr 0x0203B170 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u32 GFL_NET_SYSTEM_StartBeaconScan(u32 a0, u16 a1);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_StartBeaconScan(void)
{
    if (GFL_NET_SYSTEM_StartBeaconScan(1, 0x200) != 0)
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203B16C, 0, 0x1AE);
}
