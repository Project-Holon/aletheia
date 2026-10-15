/*
 * function: DWC_RAPUTIL_Exit
 * address: 0x021B6190
 * packet: pkt_ov016_021B6190
 * region: ov016
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NET_DEVICE_TABLE_Reset 0x0200F234 thumb
 *   func_02034A5C 0x02034A5C arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   WIH_DWC_ResetFilterState 0x020107CC thumb
 *   ov107_id 0x0000006B data a1
 */
typedef unsigned int u32;
extern void NET_DEVICE_TABLE_Reset(u32);
extern void func_02034A5C(int);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern void WIH_DWC_ResetFilterState(void);
extern char ov107_id[];
int DWC_RAPUTIL_Exit(void) { NET_DEVICE_TABLE_Reset(1); func_02034A5C((int)ov107_id); GFL_HEAP_DeleteChecked(15); WIH_DWC_ResetFilterState(); return 1; }
