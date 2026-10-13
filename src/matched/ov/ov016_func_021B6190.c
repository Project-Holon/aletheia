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
 *   func_0200F234 0x0200F234 thumb
 *   func_02034A5C 0x02034A5C arm
 *   func_020306F0 0x020306F0 arm
 *   WIH_DWC_ResetFilterState 0x020107CC thumb
 *   ov107_id 0x0000006B data a1
 */
typedef unsigned int u32;
extern void func_0200F234(u32);
extern void func_02034A5C(int);
extern void func_020306F0(unsigned int);
extern void WIH_DWC_ResetFilterState(void);
extern char ov107_id[];
int DWC_RAPUTIL_Exit(void) { func_0200F234(1); func_02034A5C((int)ov107_id); func_020306F0(15); WIH_DWC_ResetFilterState(); return 1; }
