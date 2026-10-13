/*
 * function: IRC_COMPATIBLE_HandleEntry
 * address: 0x021B6A4C
 * packet: pkt_ov101_021B6A4C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_SetHandler 0x021B6A3C thumb ov101
 *   IRC_COMPATIBLE_HandleMenu 0x021B6A7C thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_COMPATIBLE_SetHandler(u8 *,u32);
extern void IRC_COMPATIBLE_HandleMenu(u8 *,u16 *);
void IRC_COMPATIBLE_HandleEntry(u8 *p,u16 *state) { if(*state==0) IRC_COMPATIBLE_SetHandler(p,(u32)IRC_COMPATIBLE_HandleMenu); }
