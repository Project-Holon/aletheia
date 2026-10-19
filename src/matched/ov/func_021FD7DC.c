/*
 * function: WORLDTRADE_LIST_PrintRecordRow
 * address:  0x021FD7DC
 * packet:   pkt_021FD7DC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   WORLDTRADE_DEPOSIT_PrintBankString  0x021F7FD4  thumb
 *   WORLDTRADE_DEPOSIT_PrintModeLabel  0x021F8104  thumb
 *   WORLDTRADE_DEPOSIT_FindLevelBracketIndex  0x021F886C  thumb
 *   WORLDTRADE_DEPOSIT_PrintConditionLabel  0x021F8178  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 name;
    s8 mode;
    s8 key;
    s8 val;
} Rec;

typedef struct {
    void *win;
} Pane;

struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void WORLDTRADE_DEPOSIT_PrintBankString(void *win, void *bank, u32 index, u32 y, u16 color, void *g);
extern void WORLDTRADE_DEPOSIT_PrintModeLabel(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);
extern int WORLDTRADE_DEPOSIT_FindLevelBracketIndex(int key, int val, int which);
extern void WORLDTRADE_DEPOSIT_PrintConditionLabel(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);

void WORLDTRADE_LIST_PrintRecordRow(Pane *pane, void *bank, void *names, Rec *rec, void *g)
{
    BMP_Clear(BMP_WIN_GetBmp(pane->win), 0);
    WORLDTRADE_DEPOSIT_PrintBankString(pane->win, names, rec->name, 0, 0x440, g);
    WORLDTRADE_DEPOSIT_PrintModeLabel(pane->win, bank, rec->mode, 0, 0x49, 0, 0x440, g);
    WORLDTRADE_DEPOSIT_PrintConditionLabel(pane->win, bank, WORLDTRADE_DEPOSIT_FindLevelBracketIndex(rec->key, rec->val, 0), 0, 0x68, 0, 0x440, 0, (u32)g);
}
