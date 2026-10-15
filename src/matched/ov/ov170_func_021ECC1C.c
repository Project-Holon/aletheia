/*
 * function: BOX2_SEQ_RefreshHandSlot
 * address:  0x021ECC1C
 * packet:   pkt_ov170_021ECC1C
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
 *   BOX2_SEQ_LayoutHandSlots 0x021ED310 thumb
 *   BOX2_SEQ_RefreshCursorSlot 0x021ED588 thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 */
#include "../include/Obj00000.h"

typedef struct {
    int pad[9];
    int x24;
} Top;

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_LayoutHandSlots(char *w);
extern void BOX2_SEQ_RefreshCursorSlot(char *p);
extern void BOX2_SEQ_MoveCursorToSlot(char *w, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_RefreshHandSlot(unsigned char *p)
{
    short xy[2];
    int k;
    if (p[0x18] == 0)
        return;
    BOX2_SEQ_GetActorSurfacePos(WORK(p), 4, &xy[1], &xy[0], 0);
    if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 3) {
        k = 0xA;
        xy[0] += 8;
    } else {
        k = *(unsigned char *)(WORK(p) + 0x3DF6);
        xy[0] += 4;
    }
    BOX2_SEQ_AddActorSurfacePos(WORK(p), k, xy[1], xy[0], 0);
    if ((*(Top * *)&((struct Obj00000 *)p)->f0)->x24 == 3) {
        BOX2_SEQ_LayoutHandSlots(WORK(p));
        return;
    }
    if (*(void **)(WORK(p) + 0x9FD4) == 0)
        BOX2_SEQ_RefreshCursorSlot((char *)p);
    BOX2_SEQ_MoveCursorToSlot(WORK(p), 0x24);
}
