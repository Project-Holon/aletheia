/*
 * function: BOX2_SEQ_OpenBoxLeft
 * address: 0x021E1A78
 * packet: pkt_ov170_021E1A78
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb ov170
 *   BOX2_UI_UpdateCurrentBoxMarker 0x021EDF5C thumb ov170
 *   BOX2_UI_AddSlotIcon 0x021EDD38 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23883.h"
typedef struct { unsigned char pad[0xE]; unsigned short fE; } Blk;
typedef unsigned char  u8;
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void BOX2_UI_SetMiniIconVisible(char *, int, int);
extern void BOX2_UI_UpdateCurrentBoxMarker(unsigned char *p);
extern void BOX2_UI_AddSlotIcon(char *, int);
int BOX2_SEQ_OpenBoxLeft(char *p)
{
    Blk *b = (Blk *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = CURSOR_MOVE_GetCurrent(((struct Obj23883 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
        if (r >= 1 && r <= 4)
            BOX2_UI_SetMiniIconVisible(p, r - 1, 1);
        else
            BOX2_UI_SetMiniIconVisible(p, 0, 0);
        BOX2_UI_UpdateCurrentBoxMarker((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    BOX2_UI_AddSlotIcon(p, (short)-b->fE);
    return 1;
}
