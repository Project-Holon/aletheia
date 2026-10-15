/*
 * function: BOX2_SEQ_SwapSlotActors
 * address:  0x021ECB84
 * packet:   pkt_ov170_021ECB84
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
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 */

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);

void BOX2_SEQ_SwapSlotActors(char *w, unsigned i)
{
    short xy[2];
    unsigned char *tbl = (unsigned char *)(w + 0x3DD2);
    unsigned char t;
    BOX2_SEQ_GetActorSurfacePos(w, tbl[i], &xy[1], &xy[0], 0);
    t = w[0x3DF6];
    w[0x3DF6] = tbl[i];
    tbl[i] = t;
    BOX2_SEQ_AddActorSurfacePos(w, tbl[i], xy[1], xy[0], 0);
    BOX2_SEQ_SetSlotDrawPriority(w, i, 1);
}
