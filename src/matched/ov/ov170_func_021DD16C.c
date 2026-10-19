/*
 * function: BOX2_MAIN_StepToAdjacentBox
 * address:  0x021DD16C
 * packet:   pkt_ov170_021DD16C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_MAIN_GetBoxWallpaper 0x021DEDCC thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 */
#include "../include/Obj00000.h"

extern void BOX2_SEQ_SetActorAnimSeq(char *p, int i, int v);
extern void BOX2_SEQ_LoadMonIcon(char **p, int box);
extern int BOX2_MAIN_GetBoxWallpaper(char *p, int box);
extern void BOX2_MAIN_SetBoxScroll(char *p, void *a, int dir);

void BOX2_MAIN_StepToAdjacentBox(unsigned char *p, int dir)
{
    if (dir == 0) {
        p[0x14] = p[0x14] == 0 ? p[0x15] - 1 : p[0x14] - 1;
        BOX2_SEQ_SetActorAnimSeq(*(char * *)&((struct Obj00000 *)p)->f2C, 0, 2);
    } else {
        p[0x14] = p[0x14] == p[0x15] - 1 ? 0 : p[0x14] + 1;
        BOX2_SEQ_SetActorAnimSeq(*(char * *)&((struct Obj00000 *)p)->f2C, 1, 4);
    }
    BOX2_SEQ_LoadMonIcon((char **)p, p[0x14]);
    BOX2_MAIN_SetBoxScroll((char *)p, (void *)BOX2_MAIN_GetBoxWallpaper((char *)p, p[0x14]), dir);
}
