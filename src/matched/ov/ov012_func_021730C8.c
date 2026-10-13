/*
 * function: UNION_COMM_UpdateBeaconScan
 * address: 0x021730C8
 * packet: pkt_ov012_021730C8
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: caller tests r0 after 0203CF3C; retains index r0 through ov014 thunk to 02177BAC.
 * symbols:
 *   func_0203CF10 0x0203CF10 arm
 *   GFL_NET_GetScanResultMac 0x0203CF3C arm
 *   UNION_COMM_StoreBeacon 0x021730F8 thumb ov012
 *   func_02177BF4 0x02177BF4 thumb ov014
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Entry { u8 b[0x64]; } Entry;
extern u32 func_0203CF10(u32 a);
extern void *GFL_NET_GetScanResultMac(u32 a);
extern int UNION_COMM_StoreBeacon(u8 *self, Entry *info, const u8 *mac);
extern void func_02177BF4(u32 idx);
void UNION_COMM_UpdateBeaconScan(u8 *self) { int i; Entry *p; const u8 *mac; for (i=0;i<10;i++) { p=(Entry *)func_0203CF10(i); if(p) { mac=(const u8 *)GFL_NET_GetScanResultMac(i); if(mac) UNION_COMM_StoreBeacon(self,p,mac); func_02177BF4(i); } } }
