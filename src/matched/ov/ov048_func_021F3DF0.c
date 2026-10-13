/*
 * function: GIMMICK_OBJ_ELBOARD_FillSavedListMessages
 * address:  0x021F3DF0
 * packet:   pkt_021F3DF0
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_GetLineCount  0x021F47B8  thumb
 *   GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage  0x021F4058  thumb
 *   GIMMICK_OBJ_ELBOARD_AddDateMessage  0x021F3E6C  thumb
 *   GIMMICK_OBJ_ELBOARD_AddPlaceListMessage  0x021F3EE8  thumb
 *   GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage  0x021F4314  thumb
 *   GIMMICK_OBJ_ELBOARD_AddWeekdayMessage  0x021F4290  thumb
 */
#include "../include/Obj00270.h"
#include "../include/Obj20536.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int GIMMICK_OBJ_ELBOARD_GetLineCount(void *p);
extern void GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage(int *p);
extern void GIMMICK_OBJ_ELBOARD_AddDateMessage(int *p);
extern void GIMMICK_OBJ_ELBOARD_AddPlaceListMessage(int *p);
extern void GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage(int *p);
extern void GIMMICK_OBJ_ELBOARD_AddWeekdayMessage(int *p);

void GIMMICK_OBJ_ELBOARD_FillSavedListMessages(u8 *p)
{
    if (GIMMICK_OBJ_ELBOARD_GetLineCount((void *)(((struct Obj00270 *)p)->f14)) == 0) {
        u32 q = *(u32 *)&((struct Obj00270 *)p)->f1C;

        if (q != 0 && ((struct Obj20536 *)q)->f78 != 0) {
            GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage((int *)p);
            GIMMICK_OBJ_ELBOARD_AddDateMessage((int *)p);
            GIMMICK_OBJ_ELBOARD_AddPlaceListMessage((int *)p);
            GIMMICK_OBJ_ELBOARD_AddSavedIdsMessage((int *)p);
            GIMMICK_OBJ_ELBOARD_AddWeekdayMessage((int *)p);
        }
    }
}
