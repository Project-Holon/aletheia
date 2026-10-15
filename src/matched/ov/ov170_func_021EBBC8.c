/*
 * function: BOX2_SEQ_PrintMonName
 * address: 0x021EBBC8
 * packet: pkt_ov170_021EBBC8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   WORDSET_SetSlotMonSpeciesAlt 0x0201EF14 thumb
 *   BOX2_SEQ_PrintMessageMsg 0x021EBA84 thumb ov170
 * The image leaves the message undefined for kinds above six.
 */
#include "../include/Obj00000.h"
#include "../include/Obj23992.h"
#include "../include/Obj23993.h"
#include "../include/Obj23994.h"
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
typedef unsigned int   u32;
struct WordSet;
extern void WORDSET_SetSlotMonSpeciesAlt(struct WordSet *p, u32 i, void *mon);
extern void BOX2_SEQ_PrintMessageMsg(unsigned char *, int, int);
void BOX2_SEQ_PrintMonName(unsigned char *p, unsigned kind, int i)
{
    int msg;
    switch (kind) {
    case 0: msg = 2; break;
    case 1: msg = 3;
        WORDSET_SetSlotMonSpeciesAlt(((struct Obj23992 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, (void *)BOX2_MAIN_GetMonAt((void ***)p, p[0x14], p[0x16]));
        break;
    case 2: msg = 4;
        WORDSET_SetSlotMonSpeciesAlt(((struct Obj23993 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, (void *)BOX2_MAIN_GetMonAt((void ***)p, p[0x14], p[0x16]));
        break;
    case 3: msg = 0x1c; break;
    case 4: msg = 0x1d;
        WORDSET_SetSlotMonSpeciesAlt(((struct Obj23994 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, (void *)BOX2_MAIN_GetMonAt((void ***)p, p[0x14], p[0x16]));
        break;
    case 5: msg = 0x1e; break;
    case 6: msg = 6; break;
    }
    BOX2_SEQ_PrintMessageMsg(p, msg, i);
}
