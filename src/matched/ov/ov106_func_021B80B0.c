/*
 * function: IRC_RANKING_GetClactUnit
 * address:  0x021B80B0
 * packet:   pkt_ov106_021B80B0
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked by matching IRC_RANKING_ClactGetUnit in ov106 (pkt_ov106_021B7FF4).
 *
 * symbols:
 *   IRC_RANKING_ClactGetUnit  0x021B7FF4  thumb  ov106
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void *IRC_RANKING_ClactGetUnit(void **p);
void *IRC_RANKING_GetClactUnit(u8 *p) { return IRC_RANKING_ClactGetUnit((void **)(p + 0x10)); }
