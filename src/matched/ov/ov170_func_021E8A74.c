/*
 * function: BOX2_SEQ_StateMoveMenuC
 * address:  0x021E8A74
 * packet:   pkt_ov170_021E8A74
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb
 *   func_02007A80 0x02007A80 thumb
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_SEQ_PrintIndexedMessage 0x021EBC28 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   CURSOR_MOVE_ClearSkipBit 0x02026124 thumb
 *   d_021EF9C8 0x021EF9C8 data
 *   d_021EF93C 0x021EF93C data
 *   d_021EF964 0x021EF964 data
 *   d_021EF978 0x021EF978 data
 *   d_021EF98C 0x021EF98C data
 *   d_021EF9A0 0x021EF9A0 data
 *   d_021EF9E0 0x021EF9E0 data
 *   d_021EF928 0x021EF928 data
 *   d_021EF9F8 0x021EF9F8 data
 *
 * Three-step machine on the work word at 0xA194 for the box-list menu:
 * fade out, open the menu for list kind 0xA17C (two kinds pick the long
 * menu when a save flag is set), then print the prompt and lock the list.
 */

struct WinMgr;
extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_IsWindowMoving(char *p);
extern int func_02007A80(void *save, unsigned bits);
extern void BOX2_SEQ_DrawFrameList(unsigned char *p, const void *e, unsigned n);
extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_PrintIndexedMessage(unsigned char *p, int kind, int i);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
typedef unsigned int   u32;
struct Sound;
extern void CURSOR_MOVE_ClearSkipBit(struct Sound *obj, u32 idx);
extern const unsigned char d_021EF9C8[];
extern const unsigned char d_021EF93C[];
extern const unsigned char d_021EF964[];
extern const unsigned char d_021EF978[];
extern const unsigned char d_021EF98C[];
extern const unsigned char d_021EF9A0[];
extern const unsigned char d_021EF9E0[];
extern const unsigned char d_021EF928[];
extern const unsigned char d_021EF9F8[];

#define WORK(p) (*(char **)((p) + 0x2C))
#define LIST(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define KIND(p) (*(unsigned char *)(WORK(p) + 0xA17C))
#define SAVE(p) (*(void **)(*(char **)(p) + 4))

int BOX2_SEQ_StateMoveMenuC(unsigned char *p)
{
    int flag;

    switch (STEP(p)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
        BOX2_MAIN_RefreshCursorBox((char *)p);
        BOX2_UI_OpenListPack(MGR(p));
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x64);
    case 1:
        if (KIND(p) == 0) {
            if (func_02007A80(SAVE(p), 1) == 1)
                BOX2_SEQ_DrawFrameList(p, d_021EF9C8, 6);
            else
                BOX2_SEQ_DrawFrameList(p, d_021EF93C, 5);
        } else if (KIND(p) == 1) {
            BOX2_SEQ_DrawFrameList(p, d_021EF964, 5);
        } else if (KIND(p) == 2) {
            BOX2_SEQ_DrawFrameList(p, d_021EF978, 5);
        } else if (KIND(p) == 3) {
            BOX2_SEQ_DrawFrameList(p, d_021EF98C, 5);
        } else if (KIND(p) == 4) {
            BOX2_SEQ_DrawFrameList(p, d_021EF9A0, 5);
        } else if (KIND(p) == 5) {
            if (func_02007A80(SAVE(p), 2) == 1)
                BOX2_SEQ_DrawFrameList(p, d_021EF9E0, 6);
            else
                BOX2_SEQ_DrawFrameList(p, d_021EF928, 5);
        } else if (KIND(p) == 6) {
            BOX2_SEQ_DrawFrameList(p, d_021EF9F8, 6);
        }
        BOX2_UI_CloseListPack(MGR(p));
        STEP(p)++;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowMoving, 0x64);
    case 2:
        STEP(p) = 0;
        if (KIND(p) == 0)
            BOX2_SEQ_PrintIndexedMessage(p, 2, 0x18);
        else
            BOX2_SEQ_PrintIndexedMessage(p, 3, 0x18);
        flag = 0;
        if (KIND(p) == 0) {
            if (func_02007A80(SAVE(p), 1) == 0)
                flag = 1;
        } else if (KIND(p) == 5) {
            if (func_02007A80(SAVE(p), 2) == 0)
                flag = 1;
        } else if (KIND(p) != 6) {
            flag = 1;
        }
        if (flag == 1) {
            BOX2_UI_MoveCursor((char **)p, 0xB, 1);
            CURSOR_MOVE_ClearSkipBit(LIST(p), 0);
        } else {
            BOX2_UI_MoveCursor((char **)p, 0xB, 0);
        }
        return 0x65;
    }
    return 0x64;
}
