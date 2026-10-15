/*
 * function: WORLDTRADE_DEPOSIT_PrintMonSummary
 * address:  0x021F8358
 * packet:   pkt_021F8358
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
 * symbols:
 *   tbl_02202EB0  0x02202EB0  data  a4
 *   WORLDTRADE_ADAPTER_CreateString  0x02202670  thumb
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_DEPOSIT_GetModeColor  0x021F7F80  thumb
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb  arm9
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   STRBUF_Create  0x020457B0  arm  arm9
 *   STRBUF_Delete  0x02045808  arm  arm9
 *   MSGDATA_ReadString  0x02045CAC  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u16 species;
    u8 form;
    u8 gender;
} MonTag;

extern const u32 tbl_02202EB0[];

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_CalcBoxLevel(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 WORLDTRADE_ADAPTER_CreateString(u32 a, u32 b, u32 c, u32 d);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern int WORLDTRADE_INPUT_PrintStringAlignedLine(void *win, void *str, u32 c, u32 d, u32 e, u16 f, void *g);
extern u16 WORLDTRADE_DEPOSIT_GetModeColor(int mode);
extern void STRBUF_Delete(struct U16Vec *vec);

void WORLDTRADE_DEPOSIT_PrintMonSummary(void *bank, void *ws, void **win, void *mon, MonTag *out, void *g)
{
    int i;
    int form;
    void *title;
    void *place;
    void *name;
    void *tmp;
    u32 has;
    u32 gender;

    name = STRBUF_Create(0xB, 0x48);
    tmp = STRBUF_Create(0xB, 0x48);
    func_02017E88(mon, 0x73, (u32)name);
    form = func_02017E88(mon, 0x6E, 0) + 1;
    gender = POKE_TOOL_CalcBoxLevel(mon);
    has = func_02017E88(mon, 0xAD, 0);
    title = func_02045EC0(bank, 0x6E);
    WORDSET_SetSlotNumber(ws, 3, gender, 3, 0, 1);
    place = (void *)WORLDTRADE_ADAPTER_CreateString((u32)ws, (u32)bank, 0x72, 0x48);
    if (form != 3) {
        MSGDATA_ReadString(bank, tbl_02202EB0[form], tmp);
    }
    for (i = 0; i < 3; i++) {
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
    }
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], title, 1, 0, 0, 0x3C40, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[1], name, 0, 0, 0, 0x3C40, g);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[2], place, 0, 0, 2, 0x3C40, g);
    if (form != 3 && has != 0) {
        WORLDTRADE_INPUT_PrintStringAlignedLine(win[1], tmp, 0x46, 0, 0, WORLDTRADE_DEPOSIT_GetModeColor(form - 1), g);
    }
    out->species = func_02017E88(mon, 5, 0);
    out->form = form;
    out->gender = gender;
    STRBUF_Delete(place);
    STRBUF_Delete(tmp);
    STRBUF_Delete(name);
    STRBUF_Delete(title);
}
