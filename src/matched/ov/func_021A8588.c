/*
 * function: FIELD_MENU_ShowBgLayers
 * address:  0x021A8588
 * packet:   pkt_021A8588
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   BG_SYS_PushTile  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02040588(u32, u32);
extern void BG_SYS_PushTile(u32 index);

int FIELD_MENU_ShowBgLayers(void)
{
BG_SYS_PushTile(6);
func_02040588(4, 1);
func_02040588(5, 1);
func_02040588(6, 1);
return func_02040588(7, 1);
}

