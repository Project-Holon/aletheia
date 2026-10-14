/*
 * function: MB_SEQ_ShowCursorActor
 * address:  0x021C6884
 * packet:   pkt_ov136_021C6884
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MB_SEQ_SetActorAnim 0x021C66A0 thumb
 *   MB_SEQ_SetActorPosition 0x021C66CC thumb
 */

typedef unsigned char u8;
extern void MB_SEQ_SetActorPosition(u8 *, int, int, int);
typedef unsigned int   u32;
extern void MB_SEQ_SetActorAnim(u8 *p, int i, u32 v);
void MB_SEQ_ShowCursorActor(u8 *p)
{
    MB_SEQ_SetActorPosition(p, 2, 0xE0, 0xB0);
    MB_SEQ_SetActorAnim(p, 2, 4);
}
