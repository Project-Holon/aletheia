/*
 * function: BSUBWAY_RECORD_LIST_SetupVramBanks
 * address: 0x021B97D4
 * packet: pkt_ov069_021B97D4
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 0x021B97E0 reads and 0x021B97E4 writes hardware 0x04000304.
 * symbols:
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   sRecordListVramBanks 0x021BA620 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern const u32 sRecordListVramBanks[];
void BSUBWAY_RECORD_LIST_SetupVramBanks(void) { BG_SYS_SetVramBanks((const struct DispVram *)sRecordListVramBanks); *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000); }
