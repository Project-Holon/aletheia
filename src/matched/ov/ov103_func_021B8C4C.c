/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers
 * address: 0x021B8C4C
 * packet: pkt_ov103_021B8C4C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_DrawModel 0x021B7F04 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive 0x021B7F78 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped 0x021B7F4C thumb ov103
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
typedef unsigned char u8;
extern void IRC_COMPATIBLE_TOUCH_TEST_DrawModel(u8 *);
extern unsigned int IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive(u8 *);
extern unsigned int IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped(u8 *);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers(u8 **p) {
 int i;
 for(i=0;i<2;i++)IRC_COMPATIBLE_TOUCH_TEST_DrawModel(p[i]);
 if(IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive(p[0]) && IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped(p[0]))GFL_USE_PlaySeDefaultVolume(0x651);
 if(IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive(p[1]) && IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped(p[1]))GFL_USE_PlaySeDefaultVolume(0x656);
}
