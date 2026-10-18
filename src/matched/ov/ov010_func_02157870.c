/*
 * function: DELIVERY_BEACON_StepStartScan
 * address: 0x02157870
 * packet: pkt_ov010_02157870
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 28-byte lead followed by existing matched DELIVERY_BEACON_OnSessionStarted.c.
 * symbols:
 *   GFL_NET_BeaconScanStart 0x0203D010 arm
 *   DELIVERY_BEACON_SetStepAtLine 0x021576C4 thumb ov010
 *   DELIVERY_BEACON_StepCollectPieces 0x02157760 thumb ov010
 */
extern void GFL_NET_BeaconScanStart(void);
typedef unsigned char  u8;
extern void DELIVERY_BEACON_SetStepAtLine(char *p, int v, int line);
extern void DELIVERY_BEACON_StepCollectPieces(u8 *q);
void DELIVERY_BEACON_StepStartScan(void *p) { GFL_NET_BeaconScanStart(); DELIVERY_BEACON_SetStepAtLine(p, (int)DELIVERY_BEACON_StepCollectPieces, 0x1d7); }
