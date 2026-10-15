/*
 * function: BOX2_SEQ_HidePartialSlots
 * address:  0x021EC5A0
 * packet:   pkt_ov170_021EC5A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   d_021EFD4C 0x021EFD4C data a2
 */

typedef struct { short x; short y; } Pos;
extern unsigned POKEPARTY_GetCount(void *party);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern const Pos d_021EFD4C[];

void BOX2_SEQ_HidePartialSlots(char **p, int flag)
{
    unsigned n = POKEPARTY_GetCount(((void **)p[0])[2]);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int k = *(unsigned char *)(p[11] + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(p[11], k, d_021EFD4C[i].x, d_021EFD4C[i].y, 0);
        BOX2_SEQ_SetSlotDrawPriority(p[11], i + 0x1E, 1);
        if (i < n && (flag == 0 || ((unsigned char *)p)[0x16] != i + 0x1E))
            BOX2_SEQ_SetActorDrawEnable(p[11], k, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(p[11], k, 0);
    }
}
