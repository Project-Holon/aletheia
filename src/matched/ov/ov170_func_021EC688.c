/*
 * function: BOX2_SEQ_HideSlotsC688
 * address: 0x021EC688
 * packet: pkt_ov170_021EC688
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb ov170
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   d_021EFD4C 0x021EFD4C data a2
 */
#include "../include/Obj24009.h"
#include "../include/Obj24010.h"
typedef struct { short x, y; } Pos;
extern const Pos d_021EFD4C[];
extern unsigned POKEPARTY_GetCount(void *);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetSlotDrawPriority(char *, unsigned, int);
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
#define WORK(p) (*(char **)((p) + 0x2C))
void BOX2_SEQ_HideSlotsC688(char *p)
{
    unsigned n = POKEPARTY_GetCount(((struct Obj24010 *)(*(char * *)&((struct Obj24009 *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(WORK(p), win, (short)d_021EFD4C[i].x, (short)(d_021EFD4C[i].y - 0x90), (short)0);
        BOX2_SEQ_SetSlotDrawPriority(WORK(p), i + 0x1E, 1);
        if (i < n)
            BOX2_SEQ_SetActorDrawEnable(WORK(p), win, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(WORK(p), win, 0);
    }
}
