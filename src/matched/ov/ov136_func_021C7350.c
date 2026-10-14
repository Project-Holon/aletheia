/*
 * function: MB_SEQ_LoadMailDetail
 * address:  0x021C7350
 * packet:   pkt_ov136_021C7350
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_LoadSelectedMailGraphics 0x021C5D68 thumb
 *   MB_SEQ_DrawMailDetail 0x021C6374 thumb
 */

typedef unsigned char u8;
extern void MB_SEQ_LoadSelectedMailGraphics(u8 *);
extern void MB_SEQ_DrawMailDetail(u8 *);
void MB_SEQ_LoadMailDetail(u8 *p)
{
    MB_SEQ_LoadSelectedMailGraphics(p);
    MB_SEQ_DrawMailDetail(p);
}
