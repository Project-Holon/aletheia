/*
 * function: PMSIV_CATEGORY_StartFadeOut
 * address: 0x021BB814
 * packet: pkt_ov110_021BB814
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding then existing ov110_func_021BB82C.c follower.
 * symbols:
 *   PMSIV_FADE_StartBrightness 0x021BC8FC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void PMSIV_FADE_StartBrightness(u8 *,int,int,int,int);
void PMSIV_CATEGORY_StartFadeOut(u8 *p) { PMSIV_FADE_StartBrightness(p+24,2,0,-10,16); }
