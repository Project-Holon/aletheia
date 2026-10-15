/*
 * function: BOX2_SEQ_HideSlotsC61C
 * address:  0x021EC61C
 * packet:   pkt_ov170_021EC61C
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
 *   d_021EFD4C 0x021EFD4C data a1
 *
 * Lays out the six party-slot windows and shows the ones the party fills.
 * The window id is an int local: as unsigned char the load is scheduled after
 * the table address and 34 bytes move.
 */
#include "../include/Obj24007.h"
#include "../include/Obj24008.h"

typedef struct {
    short x;
    short y;
} Pos;

typedef unsigned int   u32;
extern u32 POKEPARTY_GetCount(void *p);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern const Pos d_021EFD4C[];

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_HideSlotsC61C(unsigned char *p)
{
    unsigned n = POKEPARTY_GetCount(((struct Obj24008 *)(*(char * *)&((struct Obj24007 *)p)->f0))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(WORK(p) + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(WORK(p), win, (short)(d_021EFD4C[i].x + 0x98), (short)d_021EFD4C[i].y, (short)0);
        BOX2_SEQ_SetSlotDrawPriority(WORK(p), i + 0x1E, 1);
        if (i < n)
            BOX2_SEQ_SetActorDrawEnable(WORK(p), win, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(WORK(p), win, 0);
    }
}
