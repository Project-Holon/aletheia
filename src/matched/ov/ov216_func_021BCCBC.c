/*
 * function: BEACON_DETAIL_GRA_RefreshButtons
 * address: 0x021BCCBC
 * packet: pkt_ov216_021BCCBC
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GRA_UpdateButtons 0x021BCD60 thumb ov216
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BEACON_DETAIL_GRA_UpdateButtons(u8*);
void BEACON_DETAIL_GRA_RefreshButtons(u8*p){BEACON_DETAIL_GRA_UpdateButtons(p);}
