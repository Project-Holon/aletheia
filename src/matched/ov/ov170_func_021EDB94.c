/*
 * function: BOX2_UI_FindAndDrawSlot
 * address: 0x021EDB94
 * packet: pkt_ov170_021EDB94
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two trailing zero bytes at 0x021EDBE6 are alignment padding.
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb ov170
 *   BOX2_UI_UploadSlotChar 0x021EDB64 thumb ov170
 *   BOX2_SEQ_DrawMonName 0x021EB874 thumb ov170
 */
#include "../include/Obj00000.h"
extern void BOX2_SEQ_GetActorSurfacePos(char *, int, short *, short *, unsigned short);
extern void BOX2_UI_UploadSlotChar(char *, int, int);
extern void BOX2_SEQ_DrawMonName(char **, unsigned, int);
void BOX2_UI_FindAndDrawSlot(char *p, int a, int b)
{
    short t[2];
    int i = 0;
    b *= 0x22;
    for (; i < 6u; i++) {
        BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2d, &t[1], &t[0], 0);
        if (b == t[0]) {
            BOX2_UI_UploadSlotChar(p, a, i + 0x2d);
            BOX2_SEQ_DrawMonName((char **)p, a, i + 1);
            return;
        }
    }
}
