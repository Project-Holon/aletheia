/*
 * function: BOX2_MAIN_SceneMoveCursor
 * address:  0x021E072C
 * packet:   pkt_ov170_021E072C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *
 * Moves the window at 0x3DF6 to four pixels below window 4 and hides
 * sprite 0x24.
 */

extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_MAIN_SceneMoveCursor(unsigned char *p)
{
    short xy[2];
    BOX2_SEQ_SetCursorFrame((char *)p, 8);
    BOX2_SEQ_GetActorSurfacePos(WORK(p), 4, &xy[1], &xy[0], 0);
    BOX2_SEQ_AddActorSurfacePos(WORK(p), *(unsigned char *)(WORK(p) + 0x3DF6), (short)xy[1], (short)(xy[0] + 4), (short)0);
    BOX2_SEQ_SetSlotDrawPriority(WORK(p), 0x24, 0);
}
