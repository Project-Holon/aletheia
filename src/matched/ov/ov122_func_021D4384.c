/*
 * function: INTRUDE_COMM_VIEW_BuildRowList
 * address: 0x021D4384
 * packet: pkt_ov122_021D4384
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P7 lane V6. Shape taken from the ov122 twin 021D44BC (same callees, same object). Struct with real fields (pad at 0x3c) closed it; earlier drafts used raw offsets.
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { int f00, f04, f08, f0c; } Row;
typedef struct { char pad00[0xc]; u16 heap; u16 pad0e; void *f10[11]; int pad3c; void *f40; void *f44; int pad48; void *f4C; int pad50; void *f54; char pad58[0x348-0x58]; int f348; } Object;
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void BMP_MENUWORK_DrawWindowBorder(void *, unsigned);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BUTTON_MAN_Delete(void *);
extern void func_02041B6C(u32);
void INTRUDE_COMM_VIEW_BuildRowList(int count, int *values, Object *p, Row *rows, const int *xs, const int *ys)
{
    int i, x, y;
    p->f348 = count;
    func_02049B40(23, 5, 4, 384, 32, p->heap);
    for (i = 0; i < 11; i++) {
        if (p->f10[i]) {
            BMP_WIN_ClearScreen(p->f10[i]);
            BMP_MENUWORK_DrawWindowBorder(p->f10[i], 2);
            BMP_WIN_Delete(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    for (i = 0; i < count; i++) {
        p->f10[i] = (void *)BMP_WIN_Create(7, (u8)rows[i].f00, (u8)rows[i].f04, (u8)rows[i].f08, rows[i].f0c, 13, 0);
        BMP_Clear(BMP_WIN_GetBmp(p->f10[i]), 0);
        func_02045CAC(p->f44, (int)values[i], p->f54);
        if (xs) x = xs[i] - (func_0201D304(p->f54, (u32)p->f4C, 0) >> 1);
        else x = 0;
        if (ys) y = ys[i] - (func_0201D42C(p->f54, p->f4C) >> 1);
        else y = 0;
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->f10[i]), x, y, p->f54, p->f4C, 0x39e3);
        BMP_WIN_TransferChars(p->f10[i]);
        BMP_WIN_MakeScreen(p->f10[i]);
    }
    if (p->f40) BUTTON_MAN_Delete(p->f40);
    p->f40 = 0;
    func_02041B6C(7);
}
