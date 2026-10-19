/*
 * function: WORLDTRADE_SEARCH_StateNameMenuInput
 * address:  0x021FEC00
 * packet:   pkt_021FEC00
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   WORLDTRADE_INPUT_MenuUpdate  0x021F99F0  thumb
 *   WORLDTRADE_SEARCH_SetBlendEffect  0x021FF570  thumb
 *   WORLDTRADE_DEPOSIT_SetListRangeEntry  0x021F89A8  thumb
 *   WORLDTRADE_DEPOSIT_PrintName  0x021F7F9C  thumb
 *   WORLDTRADE_DEPOSIT_SetGenderFromEvent  0x021F7B9C  thumb
 *   WORLDTRADE_DEPOSIT_PrintModeLabelAligned  0x021F8098  thumb
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb  arm9
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb  arm9
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[4];
    u16 x4;
    u16 x6;
    u16 x8;
    u16 xA;
    u8 padC[0x20 - 0xC];
    u32 x20;
} Target;

typedef struct {
    u8 pad0[0x28];
    u32 state;
    u8 pad2C[0xB56 - 0x2C];
    u16 sel;
    s8 mode;
    u8 padB59[0xB6C - 0xB59];
    void *bankA;
    void *bankB;
    u8 padB74[0xD94 - 0xB74];
    void *winA;
    u8 padD98[0xD9C - 0xD98];
    void *winB;
    u8 padDA0[0xDE4 - 0xDA0];
    void *obj;
    u8 padDE8[0xE00 - 0xDE8];
    Target *target;
    u8 padE04[0xEEC - 0xE04];
    u8 area[0xFA0 - 0xEEC];
    u8 g[4];
} Work;

extern int WORLDTRADE_INPUT_MenuUpdate(void *obj);
extern void WORLDTRADE_SEARCH_SetBlendEffect(u32 v);
struct CharBuf;
struct Descriptor;
extern void WORLDTRADE_DEPOSIT_SetListRangeEntry(u8 *p, int i, u16 a, u16 b);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void WORLDTRADE_DEPOSIT_PrintName(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);
extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern int WORLDTRADE_DEPOSIT_SetGenderFromEvent(u8 *p, int event);
extern void WORLDTRADE_DEPOSIT_PrintModeLabelAligned(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);

int WORLDTRADE_SEARCH_StateNameMenuInput(Work *p)
{
    int r = WORLDTRADE_INPUT_MenuUpdate(p->obj);
    u32 h;
    u32 v;

    switch (r) {
    case -2:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        p->state = 0;
        WORLDTRADE_DEPOSIT_SetListRangeEntry(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        break;
    case -1:
        break;
    default:
        WORLDTRADE_SEARCH_SetBlendEffect(0);
        p->sel = r;
        p->state = 0;
        BMP_Clear(BMP_WIN_GetBmp(p->winA), 0);
        WORLDTRADE_DEPOSIT_PrintName(p->winA, p->bankB, r, 0, 0, 0x3C40, p->g);
        h = (u32)POKE_PERSONAL_Create((u16)r, 0, 0x48);
        v = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x14);
        POKE_PERSONAL_Delete((void *)h);
        p->target->x20 = v;
        WORLDTRADE_DEPOSIT_SetListRangeEntry(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        if (WORLDTRADE_DEPOSIT_SetGenderFromEvent((u8 *)(&p->sel), p->target->x20) != 0) {
            BMP_Clear(BMP_WIN_GetBmp(p->winB), 0);
            WORLDTRADE_DEPOSIT_PrintModeLabelAligned(p->winB, p->bankA, p->mode, 1, 0, 0, 0x3C40, p->g);
        }
        break;
    }
    return 2;
}
