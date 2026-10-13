/*
 * function: IRC_RESULT_ScreenVBlankTask
 * address: 0x021B78E0
 * packet: pkt_ov105_021B78E0
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   IRC_RESULT_VBlankBackgrounds 0x021B7A80 thumb ov105
 *   IRC_RESULT_VBlankActorSystem 0x021B7C0C thumb ov105
 */
extern void IRC_RESULT_VBlankBackgrounds(void *); extern void IRC_RESULT_VBlankActorSystem(void *);
void IRC_RESULT_ScreenVBlankTask(int a, unsigned char *p) { IRC_RESULT_VBlankBackgrounds(p); IRC_RESULT_VBlankActorSystem(p+4); }
