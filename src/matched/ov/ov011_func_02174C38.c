/*
 * function: INTRUDE_COMM_UpdateUnionInfoAndReturnSlots
 * address: 0x02174C38
 * packet: pkt_ov011_02174C38
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * GAME_COMM_GetGameData returns the argument consumed by GAME_DATA_GetSecondUnionInfo.
 * symbols:
 *   GAME_COMM_GetGameData 0x02026478 thumb
 *   GAME_DATA_GetSecondUnionInfo 0x020127C4 thumb
 *   INTRUDE_COMM_SendUnionInfo 0x02174734 thumb ov011
 *   EVENT_FIELD_PROCLINK_GetReturnResultSlot 0x02162024 thumb ov010
 *   INTRUDE_COMM_SendReturnResult 0x021747A8 thumb ov011
 *   EVENT_FIELD_PROCLINK_ClearReturnResultSlot 0x02162038 thumb ov010
 *   EVENT_FIELD_PROCLINK_GetReturnPendingSlot 0x0216202C thumb ov010
 *   INTRUDE_COMM_SendReturnPending 0x021747F4 thumb ov011
 *   EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk 0x02162040 thumb ov010
 */
#include "../include/Obj07329.h"
typedef unsigned int   u32;
u32 GAME_COMM_GetGameData(void *obj);
unsigned char *GAME_DATA_GetSecondUnionInfo(void *p);
typedef unsigned char  u8;
int INTRUDE_COMM_SendUnionInfo(char *p, int b, void *c);
int EVENT_FIELD_PROCLINK_GetReturnResultSlot(char *p, int index, void *out);
int INTRUDE_COMM_SendReturnResult(void *a, int b);
void EVENT_FIELD_PROCLINK_ClearReturnResultSlot(char *p, int index);
int EVENT_FIELD_PROCLINK_GetReturnPendingSlot(char *p, void *out, u8 *index);
int INTRUDE_COMM_SendReturnPending(int a, int b);
void EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk(char *p);
void INTRUDE_COMM_UpdateUnionInfoAndReturnSlots(unsigned char *p)
{
    int b1[2];
    int b2[2];
    unsigned char i;
    int h;
    h = GAME_COMM_GetGameData((void *)(((struct Obj07329 *)p)->f4));
    if (p[0x908] != 0) {
        if (INTRUDE_COMM_SendUnionInfo((char *)p, p[0x908], (void *)GAME_DATA_GetSecondUnionInfo((void *)h)) == 1) {
            p[0x908] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if (EVENT_FIELD_PROCLINK_GetReturnResultSlot((char *)(p + 0x35C), i, b1) == 1) {
            if (INTRUDE_COMM_SendReturnResult(b1, i) == 1) {
                EVENT_FIELD_PROCLINK_ClearReturnResultSlot((char *)(p + 0x35C), i);
            }
        }
    }
    if (EVENT_FIELD_PROCLINK_GetReturnPendingSlot((char *)(p + 0x35C), b2, &i) == 1) {
        if (INTRUDE_COMM_SendReturnPending((int)b2, i) == 1) {
            EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk((char *)(p + 0x35C));
        }
    }
}
