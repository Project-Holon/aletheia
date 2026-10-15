/*
 * function: ITEMMENU_UseRepel
 * address:  0x021B6934
 * packet:   pkt_ov070_021B6934
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_IsRepelItem  0x021B68E8  thumb  ov070
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   MOVE_POKEMON_SAVE_IsCooldownDone  0x0200D58C  thumb
 *   FILE_UTIL_Get_0FE4  0x02020FE4  thumb
 *   MOVE_POKEMON_SAVE_SetCooldown  0x0200D55C  thumb
 *   ITEMMENU_RemoveSelectedItems  0x021B7D20  thumb  ov070
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   ITEMMENU_RegisterItemName  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_ShowMessage  0x021BACF0  thumb  ov070
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskWaitMessage  0x021B6A14  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int   ITEMMENU_IsRepelItem(u16 id);
struct Big;
struct Blk38;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *sys);
extern u32 MOVE_POKEMON_SAVE_IsCooldownDone(struct Blk38 *p);
extern u32   FILE_UTIL_Get_0FE4(u16 a, u32 sel, u32 id);
extern void MOVE_POKEMON_SAVE_SetCooldown(struct Blk38 *p, u8 v);
struct Obj;
extern void ITEMMENU_RemoveSelectedItems(struct Obj *o, int x);
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void ITEMMENU_RegisterItemName(u8 *p, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessage(int p, int mode);
extern void  GFL_USE_PlaySeDefaultVolume(u32 se);
extern void ITEMMENU_SetTask(char *p, int k);
extern void  ITEMMENU_TaskWaitMessage(u8 *p);

void ITEMMENU_UseRepel(u8 *p)
{
    void *blk;
    u8 v;

    if (ITEMMENU_IsRepelItem(((struct Obj00002 *)p)->f84C)) {
        blk = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(((struct Obj00002 *)p)->f0));
        if (MOVE_POKEMON_SAVE_IsCooldownDone(blk)) {
            v = FILE_UTIL_Get_0FE4(((struct Obj00002 *)p)->f84C, 2, ((struct Obj00002 *)p)->f544);
            MOVE_POKEMON_SAVE_SetCooldown(blk, v);
            ITEMMENU_RemoveSelectedItems((struct Obj *)p, 1);
            MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3F, (void *)(((struct Obj00002 *)p)->f524));
            func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
            ITEMMENU_RegisterItemName(p, 1, ((struct Obj00002 *)p)->f84C);
            func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
            ITEMMENU_ShowMessage((int)p, 1);
            GFL_USE_PlaySeDefaultVolume(0x7CD);
        } else {
            MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x40, (void *)(((struct Obj00002 *)p)->f524));
            func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
            ITEMMENU_ShowMessage((int)p, 1);
        }
        ITEMMENU_SetTask((char *)p, (int)((void *)ITEMMENU_TaskWaitMessage));
    }
}
