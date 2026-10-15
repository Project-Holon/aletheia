/*
 * function: BOX2_SEQ_OpenBoxUp
 * address:  0x021E19D4
 * packet:   pkt_ov170_021E19D4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb
 *   BOX2_UI_DeleteSlotIcon 0x021EDF5C thumb
 *   BOX2_UI_AddSlotIcon 0x021EDD38 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23881.h"

typedef struct {
    unsigned char pad[0xE];
    unsigned short fE;
} Blk;

typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void BOX2_UI_SetMiniIconVisible(char *p, int a, int b);
extern void BOX2_UI_DeleteSlotIcon(unsigned char *p);
extern void BOX2_UI_AddSlotIcon(char *p, int d);

int BOX2_SEQ_OpenBoxUp(char *p)
{
    Blk *b = (Blk *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23881 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
        if (r >= 0x22 && r <= 0x25)
            BOX2_UI_SetMiniIconVisible(p, r - 0x22, 1);
        else
            BOX2_UI_SetMiniIconVisible(p, 0, 0);
        BOX2_UI_DeleteSlotIcon((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    BOX2_UI_AddSlotIcon(p, (short)-b->fE);
    return 1;
}
