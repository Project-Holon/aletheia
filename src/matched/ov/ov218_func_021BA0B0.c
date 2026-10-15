/*
 * function: UN_SELECT_SceneStepMessage
 * address:  0x021BA0B0
 * packet:   pkt_ov218_021BA0B0
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UI_SCENE_GetPhaseFrame 0x021B61FC thumb ov067
 *   UI_SCENE_AdvancePhaseFrame 0x021B6200 thumb ov067
 *   UN_SELECT_InitRecord 0x021B9924 thumb ov218
 *   UN_SELECT_DrawMessage 0x021B9B78 thumb ov218
 *   UN_SELECT_UpdateMessage 0x021B9C00 thumb ov218
 *   UN_SELECT_GetFont 0x021B9C88 thumb ov218
 *   UN_SELECT_OpenTaskMenu 0x021B9898 thumb ov218
 *   FADE_IsActive 0x0204E804 arm
 *   BRIGHTNESS_IsFinished 0x02024004 thumb
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct TaskMenu;
struct WordSet;
extern unsigned UI_SCENE_GetPhaseFrame(const unsigned char *p);
extern void UI_SCENE_AdvancePhaseFrame(u8 *a);
extern int UN_SELECT_InitRecord(void);
extern void UN_SELECT_DrawMessage(char *p, u32 id);
extern int UN_SELECT_UpdateMessage(char *p);
extern u32 UN_SELECT_GetFont(char *p);
extern struct TaskMenu *UN_SELECT_OpenTaskMenu(void *arg, struct MsgBank *bank, u32 heap);
extern int FADE_IsActive(void);
extern int BRIGHTNESS_IsFinished(int a);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern int tbl_021BAC80[];
u32 UN_SELECT_SceneStepMessage(u8 *a, u8 *b)
{
    switch (UI_SCENE_GetPhaseFrame(a)) {
    case 0:
        UN_SELECT_InitRecord();
    tail:
        UI_SCENE_AdvancePhaseFrame(a);
        break;
    case 1:
        if (FADE_IsActive() == 1) break;
        if (BRIGHTNESS_IsFinished(1) == 0) break;
        WORDSET_SetSlotFromMsgE7((struct WordSet *)(*(u32 *)(*(u8 **)(b + 0x28) + 0x14)), 0, tbl_021BAC80[*(int *)(b + 0x30)]);
        UN_SELECT_DrawMessage((char *)(*(u8 **)(b + 0x28)), 0xEA);
        goto tail;
    case 2:
        if (UN_SELECT_UpdateMessage((char *)(*(u8 **)(b + 0x28))) == 0) break;
        goto tail;
    case 3:
        *(u32 *)(b + 0x1C) = (u32)UN_SELECT_OpenTaskMenu((void *)(*(u32 *)(b + 0x18)), (struct MsgBank *)UN_SELECT_GetFont((char *)(*(u8 **)(b + 0x28))), *(u16 *)b);
        return 1;
    }
    return 0;
}
