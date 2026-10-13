/*
 * function: IRC_COMPATIBLE_MENU_GetSprite
 * address:  0x021B78EC
 * packet:   pkt_ov102_021B78EC
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching IRC_COMPATIBLE_MENU_SpriteSetGetActor in ov102 (pkt_ov102_021B7C14).
 *
 * symbols:
 *   IRC_COMPATIBLE_MENU_SpriteSetGetActor  0x021B7C14  thumb  ov102
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern u32 IRC_COMPATIBLE_MENU_SpriteSetGetActor(u8 *p, int i);
u32 IRC_COMPATIBLE_MENU_GetSprite(void *p, int i) { return IRC_COMPATIBLE_MENU_SpriteSetGetActor(p, i); }
