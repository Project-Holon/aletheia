/*
 * function: BEACON_VIEW_ShowRecordMessage
 * address: 0x021F1888
 * packet: pkt_ov032_021F1888
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_BEACON_ACCESSOR_RegisterRecordWords 0x02165FCC thumb ov010
 *   BEACON_VIEW_GetActionVariant 0x021F0DC0 thumb ov032
 *   BEACON_VIEW_SetupMessageText 0x021F0A98 thumb ov032
 *   BEACON_VIEW_StartFadeTask 0x021F18E0 thumb ov032
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Rec Rec;
extern void GAME_BEACON_ACCESSOR_RegisterRecordWords(Rec *r, void *win, u32 heap);
extern int BEACON_VIEW_GetActionVariant(void *p);
extern void BEACON_VIEW_SetupMessageText(char *p, unsigned a);
extern void BEACON_VIEW_StartFadeTask(char *p, u32 a, int *c);
void BEACON_VIEW_ShowRecordMessage(char *p, Rec *r)
{
    GAME_BEACON_ACCESSOR_RegisterRecordWords(r, ((struct Obj00007 *)p)->f110, ((struct Obj00007 *)p)->f96);
    BEACON_VIEW_SetupMessageText(p, (u8)BEACON_VIEW_GetActionVariant(r));
    BEACON_VIEW_StartFadeTask(p, *(u32 *)&((struct Obj00007 *)p)->f11C, (int *)(p + 0xa8));
}
