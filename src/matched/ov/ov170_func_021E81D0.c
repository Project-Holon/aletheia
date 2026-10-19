/*
 * function: BOX2_SEQ_StateMoveItemF
 * address:  0x021E81D0
 * packet:   pkt_ov170_021E81D0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_PrintMonName 0x021EBBC8 thumb
 *   BOX2_MAIN_ClearSlot 0x021DD314 thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_UI_DrawSlot 0x021EDAB0 thumb
 *   BOX2_UI_DrawSlotByName 0x021EDB34 thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb
 *   BOX2_SEQ_Create 0x021EA1C0 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_StateMachineOpen 0x021E002C thumb
 *   BOX2_SEQ_Delete 0x021EA1E8 thumb
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *
 * Four-step machine on the work word at 0xA194 for releasing a Pokemon:
 * two confirmation messages, then the release itself (box slot in place,
 * party slot with a fade), then the view is restored.
 */

typedef unsigned char  u8;
struct Sound;
extern void BOX2_SEQ_PrintMonName(unsigned char *p, unsigned kind, int i);
extern void BOX2_MAIN_ClearSlot(char **p, int a, unsigned b);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_UI_DrawSlot(char *p, int i);
extern void BOX2_UI_DrawSlotByName(char *p, int a);
extern void BOX2_UI_ShowWindowA(char *w);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
extern void BOX2_SEQ_Create(void *p);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_StateMachineOpen(unsigned char *p);
extern void BOX2_SEQ_Delete(char *p);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void BOX2_UI_ShowWindowB(char *w);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))
#define MODE(p) (*(int *)(*(char **)(p) + 0x24))

int BOX2_SEQ_StateMoveItemF(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        BOX2_SEQ_PrintMonName(p, 1, 0x18);
        STATE(p) = 0x5B;
        STEP(p)++;
        return 6;
    case 1:
        BOX2_SEQ_PrintMonName(p, 2, 0x18);
        STATE(p) = 0x5B;
        STEP(p)++;
        return 6;
    case 2:
        BOX2_MAIN_ClearSlot((char **)p, p[0x14], p[0x16]);
        BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
        BOX2_MAIN_RefreshCursorBox((char *)p);
        BOX2_MAIN_ResetBoxView((char *)p);
        if (p[0x16] < 0x1E) {
            BOX2_UI_DrawSlot((char *)p, p[0x14]);
            BOX2_UI_DrawSlotByName((char *)p, p[0x14]);
            if (MODE(p) == 1) {
                STATE(p) = 0x2C;
            } else {
                STATE(p) = 0x11;
                BOX2_UI_ShowWindowA(WORK(p));
            }
            CURSOR_MOVE_SetCurrent(OBJ(p), p[0x16]);
            BOX2_UI_SetCursorPos((char **)p, p[0x16]);
            BOX2_SEQ_SetCursorDraw((char **)p, 1);
            BOX2_UI_ToggleSlotPair(WORK(p), 1);
            BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
            BOX2_SEQ_SetWindow9(p, 0xE, 1);
            p[0x16] = 0xFF;
            STEP(p) = 0;
            return STATE(p);
        }
        BOX2_SEQ_Create(p);
        p[0x1A] = 1;
        BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_StateMachineOpen, 0x5B);
    case 3:
        STEP(p) = 0;
        BOX2_SEQ_Delete((char *)p);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, p[0x16]);
        CURSOR_MOVE_SetCurrent(OBJ(p), p[0x16] - 0x1E);
        BOX2_UI_SetCursorPos((char **)p, p[0x16] - 0x1E);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        p[0x16] = 0xFF;
        if (MODE(p) == 0)
            return 0x31;
        BOX2_SEQ_SetWindow9(p, 0xE, 1);
        BOX2_UI_ShowWindowB(WORK(p));
        return 0x1B;
    }
    return 0x5B;
}
