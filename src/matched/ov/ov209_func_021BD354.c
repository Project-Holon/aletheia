/*
 * function: ZUKAN_LIST_ToggleSaveFlag15
 * address: 0x021BD354
 * packet: pkt_ov209_021BD354
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BD396 two-byte alignment padding before 021BD398.
 * symbols:
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 *   GAME_DATA_SetRecentId 0x02012BE0 thumb
 *   ZUKAN_LIST_StartActorAnim 0x021BD890 thumb ov209
 */
#include "../include/Obj10912.h"
extern int GAME_DATA_ContainsRecentId(int, int);
extern void GAME_DATA_SetRecentId(void *, unsigned, unsigned);
extern void ZUKAN_LIST_StartActorAnim(char *, int, int);
void ZUKAN_LIST_ToggleSaveFlag15(char *p)
{
    if (GAME_DATA_ContainsRecentId(**(int * *)&((struct Obj10912 *)p)->f0, 15) == 1) {
        GAME_DATA_SetRecentId(**(void ** *)&((struct Obj10912 *)p)->f0, 15, 0);
        ZUKAN_LIST_StartActorAnim(p, 5, 6);
    } else {
        GAME_DATA_SetRecentId(**(void ** *)&((struct Obj10912 *)p)->f0, 15, 1);
        ZUKAN_LIST_StartActorAnim(p, 5, 7);
    }
}
