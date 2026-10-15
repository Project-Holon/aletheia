/*
 * function: ITEMMENU_ShowKeyItemRefusal
 * address:  0x021B6A78
 * packet:   pkt_ov070_021B6A78
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   ITEMMENU_ShowMessage  0x021BACF0  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskWaitMessage  0x021B6A14  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessage(int p, int mode);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskWaitMessage(u8 *p);

void ITEMMENU_ShowKeyItemRefusal(u8 *p)
{
    if (((struct Obj00002 *)p)->f84C - 0x268 <= 1) {
        MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x38, (void *)(((struct Obj00002 *)p)->f524));
        WORDSET_SetSlotMyStatus((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
        WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        ITEMMENU_ShowMessage((int)p, 1);
        ITEMMENU_SetTask((char *)p, (int)((void *)ITEMMENU_TaskWaitMessage));
    }
}
