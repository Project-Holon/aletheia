/*
 * function: BOX2_SEQ_DeleteBox2UiB
 * address: 0x021E5524
 * packet: pkt_ov170_021E5524
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb ov170
 *   BOX2_SEQ_Delete 0x021EA1E8 thumb ov170
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb ov170
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb ov170
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb ov170
 *   CURSOR_MOVE_SetCurrent  0x020260E4  thumb  arm9
 */
extern void BOX2_MAIN_UpdateBoxSlots(unsigned char *);
extern void BOX2_SEQ_Delete(char *p);
typedef unsigned char  u8;
struct Sound;
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern void BOX2_UI_SetCursorPos(char **, unsigned);
extern void BOX2_SEQ_SetCursorDraw(char **, int);
extern void BOX2_UI_DeleteSlotObjects(char *, int, int, int);
extern void BOX2_SEQ_PrintPrompt(unsigned char *, int, int, int);
extern void BOX2_UI_ToggleSlotPair(char *, int);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
#define WORK(p) (*(char **)((p) + 0x2c))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
int BOX2_SEQ_DeleteBox2UiB(unsigned char *p)
{
    unsigned r = *(unsigned *)(*(char **)(WORK(p) + 0x60) + 0xac);
    BOX2_MAIN_UpdateBoxSlots(p);
    BOX2_SEQ_Delete((char *)p);
    BOX2_UI_ToggleSlotPair(WORK(p), 1);
    BOX2_UI_DeleteSlotObjects((char *)p, 0, 0, 1);
    if (p[0x16] != 0xff) {
        BOX2_SEQ_PrintPrompt(p, p[0x16], 1, 0x18);
        r = 0x23;
    }
    CURSOR_MOVE_SetCurrent(OBJ(p), r);
    BOX2_UI_SetCursorPos((char **)p, r);
    return 0x2c;
}
