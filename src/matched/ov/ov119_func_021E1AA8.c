/*
 * function: POKETRADE_SAVE_PrintExperience
 * address: 0x021E1AA8
 * packet: pkt_ov119_021E1AA8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   WORDSET_SetSlotFromMsgB6  0x0201EF8C  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "../include/Obj00001.h"
typedef signed short s16;
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern unsigned int POKE_TOOL_GetPartyValue(void *,unsigned int,unsigned int);
extern void WORDSET_SetSlotFromMsgB6(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
void POKETRADE_SAVE_PrintExperience(int a,int b,int x,int y,char *p)
{
    int v;
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),42,(void *)(*(int *)&((struct Obj00001 *)p)->f734));
    v=POKE_TOOL_GetPartyValue((void *)a,10,0);
    WORDSET_SetSlotFromMsgB6((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),0,v);
    WORDSET_CopyTaggedText((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
}
