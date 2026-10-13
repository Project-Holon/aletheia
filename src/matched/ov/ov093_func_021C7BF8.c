/*
 * function: func_021C7BF8
 * address: 0x021C7BF8
 * packet: pkt_ov093_021C7BF8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
extern void BTL_EVENT_PushVarFrame(int);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int);
void func_021C7BF8(u8 *p) { BTL_EVENT_PushVarFrame(13123); BTL_EVENT_DispatchEventChecked(p, 121); BTL_EVENT_PopVarFrame(13125); }
