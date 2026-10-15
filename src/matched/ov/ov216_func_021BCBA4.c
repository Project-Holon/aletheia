/*
 * function: BEACON_DETAIL_GRA_SetupBeaconList
 * address: 0x021BCBA4
 * packet: pkt_ov216_021BCBA4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BEACON_DETAIL_GRA_InitWindows 0x021BCF08 thumb ov216
 *   GAME_BEACON_ACCESSOR_TableRingGet 0x02165AC4 thumb ov010
 *   BEACON_DETAIL_GRA_SetupSlot 0x021BD174 thumb ov216
 *   BEACON_DETAIL_GRA_SetSlotVisible 0x021BD0E4 thumb ov216
 *   BEACON_DETAIL_GRA_UpdateSlotInfo 0x021BD448 thumb ov216
 *   BEACON_DETAIL_GRA_UpdateButtons 0x021BCD60 thumb ov216
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj00051.h"
extern void BEACON_DETAIL_GRA_InitWindows(char *p);
typedef unsigned short u16;
struct Queue;
struct Rec;
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *q, struct Rec *out, u16 *tag, int delta);
typedef unsigned char  u8;
extern void BEACON_DETAIL_GRA_SetupSlot(char *p, void *record, u16 unused, u8 slot);
extern void BEACON_DETAIL_GRA_SetSlotVisible(char *p, u8 index, unsigned int enable);
extern void BEACON_DETAIL_GRA_UpdateSlotInfo(char *p);
typedef unsigned int   u32;
extern void BEACON_DETAIL_GRA_UpdateButtons(unsigned char *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
void BEACON_DETAIL_GRA_SetupBeaconList(unsigned char *p)
{
    BEACON_DETAIL_GRA_InitWindows((char *)p);
    GAME_BEACON_ACCESSOR_TableRingGet(((struct Obj00051 *)p)->f24,((struct Obj00051 *)p)->f28,(u16 *)(p+0x2c),*(p+p[0x30]+0x31));
    BEACON_DETAIL_GRA_SetupSlot((char *)p,((struct Obj00051 *)p)->f28,((struct Obj00051 *)p)->f2C,p[0x2e]);
    BEACON_DETAIL_GRA_SetSlotVisible((char *)p,p[0x2e],1);
    BEACON_DETAIL_GRA_SetSlotVisible((char *)p,p[0x2e]^1,0);
    BEACON_DETAIL_GRA_UpdateSlotInfo((char *)p); BEACON_DETAIL_GRA_UpdateButtons(p);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00051 *)p)->f2);
}
