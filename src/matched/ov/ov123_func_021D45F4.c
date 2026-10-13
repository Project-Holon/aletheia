/*
 * function: func_021D45F4
 * address:  0x021D45F4
 * packet:   pkt_ov123_021D45F4
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wD6 lane17): closed by the real callee prototypes: func_0201DD68 takes no
 *   argument (so count is spilled and reloaded for the +0x25C store) and the record pointer is not
 *   const (the a/b/c loads stay after the outgoing stack-argument stores).
 *
 * symbols:
 *   func_0201DD68  0x0201DD68  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   func_02049B40  0x02049B40  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u32 a, b, c, d;
} Rec;

extern void func_0201DD68(void);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BUTTON_MAN_Delete(void *p);
extern void func_020409B4(u32 index);

typedef struct {
    u8 pad0[0xC];
    u16 heap;
    u8 pad1[2];
    void *obj[4];
    void *res;
    void *bank;
    u8 pad2[8];
    void *font;
    u8 pad3[4];
    void *str;
    u8 pad4[0x25C - 0x3C];
    int n;
} Own;

void func_021D45F4(int count, u32 *tbl, Own *owner, Rec *recs, u32 *xs, u32 *ys)
{
    int i;
    int j;
    int a;
    int b;

    owner->n = count;
    func_0201DD68();
    for (i = 0; i < 4; i++) {
        if (owner->obj[i] != 0) {
            BMP_WIN_ClearScreen(owner->obj[i]);
            func_0201F7A8(owner->obj[i], 2);
            BMP_WIN_Delete(owner->obj[i]);
        }
        owner->obj[i] = 0;
    }
    func_02049B40(0x17, 5, 4, 0x100, 0x20, owner->heap);
    for (j = 0; j < count; j++) {
        Rec *r = &recs[j];
        owner->obj[j] = (void *)BMP_WIN_Create(7, (u8)r->a, (u8)r->b, (u8)r->c, (u8)r->d, 8, 0);
        BMP_Clear(BMP_WIN_GetBmp(owner->obj[j]), 0);
        func_02045CAC(owner->bank, tbl[j], owner->str);
        GF_FONT_SetTextColor(0xF, 2, 0);
        if (xs != 0)
            a = xs[j] - func_0201D304(owner->str, (u32)owner->font, 0) / 2;
        else
            a = 0;
        if (ys != 0)
            b = ys[j] - func_0201D42C(owner->str, owner->font) / 2;
        else
            b = 0;
        PRINTSYS_Print(BMP_WIN_GetBmp(owner->obj[j]), (s16)a, (s16)b, owner->str, owner->font);
        BMP_WIN_TransferChars(owner->obj[j]);
        BMP_WIN_MakeScreen(owner->obj[j]);
    }
    if (owner->res != 0)
        BUTTON_MAN_Delete(owner->res);
    owner->res = 0;
    func_020409B4(7);
}
