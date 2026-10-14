/*
 * function: POKETRADE_PROC_ShowIntroMessage
 * address: 0x021D9750
 * packet: pkt_ov119_021D9750
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_BuildPartyPacket 0x021D9670 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_PROC_BuildPartyPacket(char *p);
void POKETRADE_PROC_ShowIntroMessage(char *p)
{
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 6, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_BuildPartyPacket);
}
