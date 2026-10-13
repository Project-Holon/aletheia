/*
 * function: IRC_RANKING_DisplayVBlankTask
 * address: 0x021B80BC
 * packet: pkt_ov106_021B80BC
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_RANKING_DisplayBgVBlank 0x021B7F74 thumb ov106
 *   IRC_RANKING_ClactVBlank 0x021B7FEC thumb ov106
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
/* Both callback callees ignore entry arguments, but the original explicitly supplies them. */
extern void IRC_RANKING_DisplayBgVBlank(u8 *);
extern void IRC_RANKING_ClactVBlank(u8 *);
void IRC_RANKING_DisplayVBlankTask(void *a,u8 *p) { IRC_RANKING_DisplayBgVBlank(p); IRC_RANKING_ClactVBlank(p+16); }
