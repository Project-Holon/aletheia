/*
 * function: BOX2_SEQ_ShiftSlotIcons
 * address:  0x021EC804
 * packet:   pkt_ov170_021EC804
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_SetSlotIconPal 0x021EC428 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_SetActorMode1 0x021ECB74 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 */
#include "../include/Obj24013.h"
#include "../include/Obj24014.h"
#include "../include/Obj24015.h"

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_SetSlotIconPal(char *p, int a, int i, int b);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern void BOX2_SEQ_SetActorMode1(char *a, int b);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);

void BOX2_SEQ_ShiftSlotIcons(char **p, short dx)
{
    short t[2];
    short reset;
    short lim;
    unsigned short i;
    unsigned char k;
    if (dx >= 0) {
        lim = 0xB0;
        reset = -8;
    } else {
        lim = -8;
        reset = 0xB0;
    }
    for (i = 0; i < 0x1E; i++) {
        k = *(unsigned char *)(p[11] + i + 0x3DD2);
        BOX2_SEQ_GetActorSurfacePos(p[11], k, &t[1], &t[0], 0);
        t[1] += dx;
        if (t[1] == lim) {
            t[1] = reset;
            BOX2_SEQ_SetSlotIconPal(p[11], (int)(p[11] + 0x1B4 + i * 0x200), k, *(unsigned char *)(p[11] + i + 0x3DB4));
            BOX2_SEQ_SetActorDrawEnable(p[11], k, *(int *)(p[11] + i * 4 + 0x3DF8));
            if (((struct Obj24013 *)(p[11]))->fA17A == 0 && (((struct Obj24014 *)(p[0]))->f24 == 3 || ((struct Obj24015 *)(p[0]))->f24 == 5))
                BOX2_SEQ_SetActorMode1((char *)p, i);
        }
        BOX2_SEQ_AddActorSurfacePos(p[11], k, t[1], t[0], 0);
    }
}
