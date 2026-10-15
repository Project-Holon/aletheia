/*
 * function: BOX2_SEQ_PrintMessageMsg
 * address:  0x021EBA84
 * packet:   pkt_ov170_021EBA84
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_CreateMsgBank 0x021EAC98 thumb
 *   BOX2_SEQ_ClearMessageWindow 0x021EBA30 thumb
 *   BOX2_SEQ_PrintTextWinEx 0x021EAC28 thumb
 *   BOX2_SEQ_MakeScreen 0x021EABA0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BOX2_UI_HideSlots678 0x021EE0FC thumb
 *
 * Prints message msg of the box-menu bank into message window i.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *BOX2_SEQ_CreateMsgBank(void);
extern void BOX2_SEQ_ClearMessageWindow(unsigned char *p, void *win);
extern void BOX2_SEQ_PrintTextWinEx(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color);
extern void BOX2_SEQ_MakeScreen(void **win);
struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void BOX2_UI_HideSlots678(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i)
{
    void *bank = BOX2_SEQ_CreateMsgBank();
    BOX2_SEQ_ClearMessageWindow(p, *(void **)(WORK(p) + i * 8 + 0x94));
    BOX2_SEQ_PrintTextWinEx(WORK(p), i, bank, msg, 0, 0, *(u32 *)(WORK(p) + 0x78), 0x44F);
    BOX2_SEQ_MakeScreen((void **)(WORK(p) + 0x94 + i * 8));
    MSGDATA_Delete(bank);
    BOX2_UI_HideSlots678((char *)p);
}
