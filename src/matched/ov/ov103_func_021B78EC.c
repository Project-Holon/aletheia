/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ExitScene
 * address: 0x021B78EC
 * packet: pkt_ov103_021B78EC
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   IRC_COMPATIBLE_TOUCH_TEST_ExitMarkers 0x021B8C40 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_Exit3D 0x021B7D08 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds 0x021B7AE8 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_ExitSprites 0x021B7C08 thumb ov103
 */
#include "../include/Obj22177.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void IRC_COMPATIBLE_TOUCH_TEST_ExitMarkers(void *);
extern void IRC_COMPATIBLE_TOUCH_TEST_Exit3D(u8 *p);
extern void IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds(u32 *);
extern void IRC_COMPATIBLE_TOUCH_TEST_ExitSprites(u8 *);
void IRC_COMPATIBLE_TOUCH_TEST_ExitScene(u8 *p) { func_02030EAC(((struct Obj22177 *)p)->f170); IRC_COMPATIBLE_TOUCH_TEST_ExitMarkers(p+352); IRC_COMPATIBLE_TOUCH_TEST_Exit3D(p+4); IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds((u32 *)p); IRC_COMPATIBLE_TOUCH_TEST_ExitSprites(p+204); }
