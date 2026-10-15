/*
 * function: BOX2_SEQ_StateSwapMenuD
 * address:  0x021E7A10
 * packet:   pkt_ov170_021E7A10
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_SEQ_GotoBox2Ui 0x021E95CC thumb
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_SEQ_SetSlotActorMode 0x021ECB60 thumb
 *   BOX2_UI_ResetSlotFrames 0x021EF508 thumb
 *   BOX2_SEQ_PrintWordset 0x021EBAF8 thumb
 *   BOX2_SEQ_OpenYesNo 0x021E8FE8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_PrintMessage 0x021EBB1C thumb ov170
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb
 *   BOX2_SEQ_PrintPromptB 0x021EBCB4 thumb
 *   BOX2_SEQ_PrintYesNo 0x021EBD78 thumb
 *
 * Item menu "give": checks the slot, then asks to swap or confirms.  A
 * four-step machine on the work word at 0xA194 (template 021E3C88).
 */

typedef unsigned short u16;

struct WinMgr;
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern int BOX2_SEQ_GotoBox2Ui(unsigned char *p, unsigned char v);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern unsigned FILE_UTIL_Check136C(u16 v);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_SEQ_SetSlotActorMode(char *w, int i, int f);
extern void BOX2_UI_ResetSlotFrames(struct WinMgr *mgr);
extern void BOX2_SEQ_PrintWordset(unsigned char *p, unsigned v, int i);
extern int BOX2_SEQ_OpenYesNo(unsigned char *p, int sel);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_SEQ_PrintMessage(unsigned char *p, int i);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern void BOX2_SEQ_PrintPromptB(unsigned char *p, int kind, int i);
extern void BOX2_SEQ_PrintYesNo(char *p, int b);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))
#define TOP(p) (*(char **)(p))

int BOX2_SEQ_StateSwapMenuD(unsigned char *p)
{
    switch (STEP(p)) {
    case 0: {
        unsigned item;
        if (*(int *)(TOP(p) + 0x24) == 4 && *(int *)(TOP(p) + 0x14) == 1) {
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 4, 0);
            BOX2_UI_OpenListPack(MGR(p));
            STEP(p) = 3;
            return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x50);
        }
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, p[0x16], p[0x14], 0x4C, 0) == 0) {
            item = BOX2_MAIN_GetPartyValueAt((void ***)p, p[0x16], p[0x14], 6, 0);
            if (item == 0)
                return BOX2_SEQ_GotoBox2Ui(p, 1);
            BOX2_SEQ_SetActorDrawEnable(WORK(p), 4, 0);
            BOX2_SEQ_SetWindow9(p, 0xE, 0);
            BOX2_UI_ToggleSlotPair(WORK(p), 0);
            if (FILE_UTIL_Check136C(item) == 1) {
                BOX2_UI_OpenListPack(MGR(p));
                STEP(p) = 1;
                return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x50);
            }
            if (p[0x16] < 0x1E)
                BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
            else
                BOX2_SEQ_SetSlotActors((char *)p, 2, 1);
            BOX2_SEQ_SetSlotActorMode(WORK(p), p[0x16], 0);
            *(unsigned char *)(WORK(p) + 0xA170) = 1;
            BOX2_UI_ResetSlotFrames(MGR(p));
            BOX2_SEQ_PrintWordset(p, item, 0x18);
            if (*(int *)(TOP(p) + 0x24) == 3)
                return BOX2_SEQ_OpenYesNo(p, 2);
            return BOX2_SEQ_OpenYesNo(p, 0);
        }
        BOX2_SEQ_SetActorDrawEnable(WORK(p), 4, 0);
        BOX2_UI_OpenListPack(MGR(p));
        STEP(p) = 2;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x50);
    }
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintMessage(p, 0x18);
        STATE(p) = 0xE;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 6);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintPromptB(p, 5, 0x18);
        STATE(p) = 0xE;
        return BOX2_SEQ_ReturnAfterClear((char *)p, 6);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintYesNo((char *)p, 1);
        STATE(p) = 0x2B;
        return 6;
    }
    return 0x50;
}
