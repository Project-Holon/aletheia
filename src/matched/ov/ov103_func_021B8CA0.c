/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive
 * address: 0x021B8CA0
 * packet: pkt_ov103_021B8CA0
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_ModelSetActive 0x021B7F60 thumb ov103
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_COMPATIBLE_TOUCH_TEST_ModelSetActive(u8 *,int);
void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(u8 **p,int i,int v) { IRC_COMPATIBLE_TOUCH_TEST_ModelSetActive(p[i],v); }
