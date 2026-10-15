/*
 * function: BOX2_SEQ_StatePmVoiceMenu
 * address:  0x021E87A0
 * packet:   pkt_ov170_021E87A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_GetExitButtonPoint 0x021EF1D4 thumb
 *   BOX2_SEQ_CreateC 0x021EA808 thumb
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_MAIN_SelectBox 0x021DD1C4 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_SEQ_OpenBoxRight 0x021E1ACC thumb
 *   BOX2_SEQ_OpenBoxLeft 0x021E1A78 thumb
 *   BOX2_UI_SetMiniIconVisible 0x021EE008 thumb
 *   BOX2_SEQ_DrawListSlot 0x021EA798 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   BOX2_SEQ_GotoBox2MainWithSlot 0x021E954C thumb
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *
 * List input for the box menu: a touch pick stores the slot and leaves,
 * otherwise the list result selects a page, a jump, or a cancel.
 */

extern int BOX2_UI_GetExitButtonPoint(unsigned *a, unsigned *b);
extern void BOX2_SEQ_CreateC(char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_MAIN_SelectBox(char *p, int a);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_SEQ_OpenBoxRight(char *p);
extern int BOX2_SEQ_OpenBoxLeft(char *p);
extern void BOX2_UI_SetMiniIconVisible(char *p, int a, int b);
extern int BOX2_SEQ_DrawListSlot(unsigned char *p, int sel);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern int BOX2_SEQ_GotoBox2MainWithSlot(unsigned char *p, int id, int lo, int arg);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);

#define WORK(p) (*(char **)((p) + 0x2C))
#define LIST(p) (*(void **)(WORK(p) + 0x70))
#define STATE(p) (*(int *)((p) + 0x28))
#define CUR(p) (*(unsigned char *)(WORK(p) + 0xA17F))

int BOX2_SEQ_StatePmVoiceMenu(unsigned char *p)
{
    unsigned x, y;
    unsigned r;

    if (BOX2_UI_GetExitButtonPoint(&x, &y) == 1) {
        *(unsigned *)(WORK(p) + 0xA184) = y;
        STATE(p) = 0x61;
        BOX2_SEQ_CreateC((char *)p);
        CURSOR_MOVE_SetState(LIST(p), 0);
        return 0xF;
    }
    r = CURSOR_MOVE_PollRepeatInput(LIST(p));
    switch (r) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((char *)p, -1);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxRight, 0x61);
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((char *)p, 1);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxLeft, 0x61);
    case 1:
    case 2:
    case 3:
    case 4:
        CUR(p) = p[0x19] + r - 1;
        if (CUR(p) >= p[0x15])
            CUR(p) -= p[0x15];
        if (CUR(p) != p[0x14]) {
            BOX2_UI_SetMiniIconVisible((char *)p, 0, 0);
            return BOX2_SEQ_DrawListSlot(p, 1);
        }
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_UI_SetMiniIconVisible((char *)p, r - 1, 1);
        break;
    case 6:
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot(p, 6, 9, BOX2_SEQ_ReturnAfterClear((char *)p, 0x62));
    case (unsigned)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((char *)p, BOX2_SEQ_SetState((char *)p, 0x61));
    case (unsigned)-8:
        if (CURSOR_MOVE_GetCurrent(LIST(p)) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_SelectBox((char *)p, -1);
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxRight, 0x61);
        }
        break;
    case (unsigned)-7:
        if (CURSOR_MOVE_GetCurrent(LIST(p)) == 4) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_SelectBox((char *)p, 1);
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_OpenBoxLeft, 0x61);
        }
        break;
    }
    return 0x61;
}
