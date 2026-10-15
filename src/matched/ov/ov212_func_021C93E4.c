/*
 * function: ZUKAN_TickCounter
 * address: 0x021C93E4
 * packet: pkt_ov212_021C93E4
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   BG_SYS_ResetSlot  0x02041EE4  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_ResetSlot(u32,u32,u32);
void ZUKAN_TickCounter(u32 a, u32 b, u32 *counter) {
    ++*counter;
    if(*counter==4) { BG_SYS_ResetSlot(a,1,1); BG_SYS_ResetSlot(b,1,1); *counter=0; }
}
