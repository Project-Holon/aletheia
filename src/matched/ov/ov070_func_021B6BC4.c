/*
 * function: ITEMMENU_TryStartGive
 * address:  0x021B6BC4
 * packet:   pkt_ov070_021B6BC4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028754  0x02028754  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_ShowMessageThenWait  0x021B6AD8  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj;
extern u32 func_02028754(struct Obj *obj, u32 n);
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_ShowMessageThenWait(int p);

u32 ITEMMENU_TryStartGive(u8 *p)
{
    u32 r = 1;

    if (func_02028754(((struct Obj00002 *)p)->fC, 1)) {
        ((struct Obj00002 *)p)->f844 = 7;
        ITEMMENU_SetTask((char *)p, 0);
        return r;
    }
    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
    WORDSET_SetSlotMyStatus((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
    ITEMMENU_SetTask((char *)p, (int)((void *)ITEMMENU_ShowMessageThenWait));
    return 0;
}
