/*
 * function: IRC_RANKING_DisplayBgVBlank
 * address:  0x021B7F74
 * packet:   pkt_ov106_021B7F74
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_Update  0x020419E4  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void BG_SYS_Update(void);
void IRC_RANKING_DisplayBgVBlank(u8 *a0) { BG_SYS_Update(); }
