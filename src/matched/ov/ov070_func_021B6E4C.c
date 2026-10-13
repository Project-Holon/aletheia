/*
 * function: ITEMMENU_TryStartSell
 * address:  0x021B6E4C
 * packet:   pkt_ov070_021B6E4C
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
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_ShowMessageThenWait  0x021B6AD8  thumb  ov070
 *   ITEMMENU_RemoveSelectedItems  0x021B7D20  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj;
extern u32 func_02028754(struct Obj *obj, u32 n);
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_ShowMessageThenWait(int p);
extern void ITEMMENU_RemoveSelectedItems(struct Obj *o, int x);

u32 ITEMMENU_TryStartSell(u8 *p)
{
    if (((struct Obj00002 *)p)->f848 == 0) {
        if (func_02028754(((struct Obj00002 *)p)->fC, 3)) {
            ((struct Obj00002 *)p)->f844 = 0xE;
            ITEMMENU_SetTask((char *)p, 0);
            ITEMMENU_RemoveSelectedItems((struct Obj *)p, 1);
            return 1;
        }
        MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
        func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        ITEMMENU_SetTask((char *)p, (int)((void *)ITEMMENU_ShowMessageThenWait));
        return 0;
    }
    return 0;
}
