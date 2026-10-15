/*
 * function: BOX2_UI_SetCloseButtonPos
 * address:  0x021ED9B4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_AddActorSurfacePos  0x021EC08C  thumb  ov170
 *
 * One range call with fixed arguments.
 */



extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
void BOX2_UI_SetCloseButtonPos(int a)
{
    BOX2_SEQ_AddActorSurfacePos((char *)a, 2, 0x4b * 4, 0x22, 0);
}
