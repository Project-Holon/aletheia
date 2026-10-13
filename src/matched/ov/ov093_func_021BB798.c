/*
 * function: BTL_SERVER_AreRepliesReady
 * address: 0x021BB798
 * packet: pkt_ov093_021BB798
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_IsClientSlotUsed 0x021BB830 thumb ov093
 *   BTL_ADAPTER_Update 0x021EEB2C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_SERVER_IsClientSlotUsed(u8 *);
extern int BTL_ADAPTER_Update(u32);
int BTL_SERVER_AreRepliesReady(u8 *p) {
    int result;
    int i;
    u8 *q;
    result = 1; i = 0; q = p+20;
    for (; i < 4; i++) {
        if (BTL_SERVER_IsClientSlotUsed(q+i*12)) {
            if (!BTL_ADAPTER_Update(*(u32 *)((p+i*12)+20))) result = 0;
        }
    }
    return result;
}
