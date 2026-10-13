/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_End3DFrame
 * address:  0x021B7D44
 * packet:   pkt_ov103_021B7D44
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void G3D_SYSTEM_DrawEnd(void);
void IRC_COMPATIBLE_TOUCH_TEST_End3DFrame(void *a0) { G3D_SYSTEM_DrawEnd(); }
