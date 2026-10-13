/*
 * function: IRC_COMPATIBLE_HandleQuit
 * address: 0x021B6A60
 * packet: pkt_ov101_021B6A60
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   IRC_COMPATIBLE_SetFinished 0x021B6A44 thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_COMPATIBLE_SetFinished(u8 *);
void IRC_COMPATIBLE_HandleQuit(u8 *p,u16 *state) { switch(*state) { case 0: *state=1; break; case 1: IRC_COMPATIBLE_SetFinished(p); break; } }
