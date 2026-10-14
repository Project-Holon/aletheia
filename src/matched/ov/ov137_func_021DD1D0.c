/*
 * function: GURU2_RECEIPT_SetVramBanks
 * address: 0x021DD1D0
 * packet: pkt_ov137_021DD1D0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   gGuru2LobbyVramBanks 0x021E1B40 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern const u32 gGuru2LobbyVramBanks[];
void GURU2_RECEIPT_SetVramBanks(void) {BG_SYS_SetVramBanks((const struct DispVram *)gGuru2LobbyVramBanks);}
