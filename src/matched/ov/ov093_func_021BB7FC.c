/*
 * function: BTL_SERVER_ResetClientCommands
 * address: 0x021BB7FC
 * packet: pkt_ov093_021BB7FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_IsClientSlotUsed 0x021BB830 thumb ov093
 *   BTL_ADAPTER_ResetCommand 0x021EEAD0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_SERVER_IsClientSlotUsed(u8 *);
extern void BTL_ADAPTER_ResetCommand(u8 *p);
void BTL_SERVER_ResetClientCommands(const u8 *p) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (BTL_SERVER_IsClientSlotUsed((u8 *)(p+20+i*12))) BTL_ADAPTER_ResetCommand((u8 *)(*(const u32 *)((p+i*12)+20)));
    }
}
