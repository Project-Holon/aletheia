/*
 * function: POKETRADE_SAVE_PrintMoveNames
 * address: 0x021E198C
 * packet: pkt_ov119_021E198C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb  arm9
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
extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
void POKETRADE_SAVE_PrintMoveNames(int a,int b,int x,int y,char *p)
{
    int i,v;
    for(i=0;i<4;i++) {
        v=POKE_TOOL_GetPartyValue((void *)a,54+i,0);
        if(v) {
            MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),45,(void *)(*(int *)&((struct Obj00001 *)p)->f734));
            WORDSET_SetSlotFromMsgCB((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),0,v);
            WORDSET_CopyTaggedText((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));
            PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y+16*i,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
        }
    }
}
