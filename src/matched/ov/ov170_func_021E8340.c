/*
 * function: BOX2_SEQ_StateOpenZoom
 * address: 0x021E8340
 * packet: pkt_ov170_021E8340
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_GrowActor 0x021EC9D8 thumb ov170
 *   BOX2_SEQ_ResetActorTransform 0x021ECA38 thumb ov170
 *   BOX2_MAIN_DeleteScroll 0x021DE7B4 thumb ov170
 *   BOX2_SEQ_RefreshCursorSlot 0x021ED588 thumb ov170
 *   BOX2_SEQ_PrintMonName 0x021EBBC8 thumb ov170
 *   BOX2_SEQ_StateUseItemDone 0x021E912C thumb ov170
 */
#include "../include/Obj00000.h"
extern int BOX2_SEQ_GrowActor(char *p);
extern void BOX2_SEQ_ResetActorTransform(int *p);
extern void BOX2_MAIN_DeleteScroll(char *p);
extern void BOX2_SEQ_RefreshCursorSlot(char *p);
extern void BOX2_SEQ_PrintMonName(unsigned char *p, unsigned kind, int i);
extern int BOX2_SEQ_StateUseItemDone(unsigned char *p);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define SLOT(p) (*(char **)(WORK(p) + 0xA190))
int BOX2_SEQ_StateOpenZoom(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        if (BOX2_SEQ_GrowActor(SLOT(p)) != 0)
            break;
        BOX2_SEQ_ResetActorTransform((int *)SLOT(p));
        BOX2_MAIN_DeleteScroll((char *)p);
        BOX2_SEQ_RefreshCursorSlot((char *)p);
        BOX2_SEQ_PrintMonName(p, 4, 0x18);
        ((struct Obj00000 *)p)->f28 = 0x5C;
        STEP(p)++;
        return 6;
    case 1:
        BOX2_SEQ_PrintMonName(p, 5, 0x18);
        ((struct Obj00000 *)p)->f28 = 0x5C;
        STEP(p)++;
        return 6;
    case 2:
        STEP(p) = 0;
        return BOX2_SEQ_StateUseItemDone(p);
    }
    return 0x5C;
}
