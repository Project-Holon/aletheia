/*
 * function: INTRUDE_COMM_RefreshSelfRecord
 * address:  0x02174E3C
 * packet:   pkt_ov011_02174E3C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetSize  0x02008468  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   INTRUDE_COMM_UpdateSelfRecord  0x021752DC  thumb ov011
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   INTRUDE_COMM_SetIntrudeId  0x02175710  thumb ov011
 */
#include "../include/Obj09349.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ent {
    int w[7];
} Ent;

typedef struct F86 {
    u16 x : 3;
    u16 rest : 13;
} F86;

unsigned int GAME_COMM_GetGameData(void *obj);
u8 *GAME_DATA_GetMyStatus(void *p);
int MYSTATUS_GetSize(void);
void MI_CpuCopy8(int a, u8 *b, int c);
void *GAME_DATA_GetLastBattleRecSlot(void *p);
typedef unsigned int   u32;
int INTRUDE_COMM_UpdateSelfRecord(u8 *p);
u16 GFL_NET_SYSTEM_GetCurrentAid(void);
void INTRUDE_COMM_SetIntrudeId(u8 *o, u32 v);

void INTRUDE_COMM_RefreshSelfRecord(u8 *p)
{
    int v;

    v = GAME_COMM_GetGameData((void *)(((struct Obj09349 *)p)->f4));
    MI_CpuCopy8((int)GAME_DATA_GetMyStatus((void *)v), p + 0x160, MYSTATUS_GetSize());
    MI_CpuCopy8((int)GAME_DATA_GetLastBattleRecSlot((void *)v), p + 0x180, 0x10);
    INTRUDE_COMM_UpdateSelfRecord(p);
    if (((F86 *)(p + 0x86))->x == 0x80) {
        INTRUDE_COMM_SetIntrudeId(p, GFL_NET_SYSTEM_GetCurrentAid());
    }
    *(Ent *)(p + 0x190) = *(Ent *)(p + 0x70);
}
