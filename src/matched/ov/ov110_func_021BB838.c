/*
 * function: PMSIV_CATEGORY_StartBlendOut
 * address: 0x021BB838
 * packet: pkt_ov110_021BB838
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_FADE_StartBlend 0x021BC868 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void PMSIV_FADE_StartBlend(u8 *p, int a, int b, int start, int end, int frames);
void PMSIV_CATEGORY_StartBlendOut(u8 *p) { PMSIV_FADE_StartBlend(p+24,2,63,124,0,12); }
