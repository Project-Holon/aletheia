/*
 * function: IRC_RANKING_Draw
 * address:  0x021B80A0
 * packet:   pkt_ov106_021B80A0
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching IRC_RANKING_ClactDraw in ov106 (pkt_ov106_021B7FE4).
 *
 * symbols:
 *   IRC_RANKING_ClactDraw  0x021B7FE4  thumb  ov106
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void IRC_RANKING_ClactDraw(void *);
void IRC_RANKING_Draw(u8 *p) { IRC_RANKING_ClactDraw(p + 0x10); }
