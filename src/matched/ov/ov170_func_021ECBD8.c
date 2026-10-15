/*
 * function: BOX2_SEQ_SwapSlotActorsB
 * address:  0x021ECBD8
 * packet:   pkt_ov170_021ECBD8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 */

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);

void BOX2_SEQ_SwapSlotActorsB(unsigned char *p, int i)
{
    short xy[2];
    unsigned char t;
    BOX2_SEQ_GetActorSurfacePos((char *)p, p[0x3DF6], &xy[1], &xy[0], 0);
    t = (p + 0x3DD2)[i];
    (p + 0x3DD2)[i] = p[0x3DF6];
    p[0x3DF6] = t;
    BOX2_SEQ_AddActorSurfacePos((char *)p, p[0x3DF6], xy[1], xy[0], 0);
}
