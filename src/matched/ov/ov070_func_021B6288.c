/*
 * function: ITEMMENU_SwitchPocketCursor
 * address:  0x021B6288
 * packet:   pkt_ov070_021B6288
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02008298  0x02008298  thumb
 *   func_02008288  0x02008288  thumb
 *   func_02008270  0x02008270  thumb
 *   ITEMMENU_MoveCursorToRow  0x021BA6A4  thumb  ov070
 *   ITEMMENU_PrintPocketCount  0x021BAF38  thumb  ov070
 *   ITEMMENU_SelectTab  0x021BA96C  thumb  ov070
 *   ITEMMENU_LoadBgPaletteMode  0x021BAAA4  thumb  ov070
 */

typedef unsigned short u16;
typedef short s16;

typedef struct Obj {
    unsigned char pad000[0x14];
    void *gfx;
    unsigned char pad018[0x810 - 0x18];
    int f810;
    int f814;
} Obj;

struct MyItemSave;
extern void func_02008298(struct MyItemSave *p, u16 v);
extern void func_02008288(struct MyItemSave *p, int i, s16 a, s16 b);
extern void func_02008270(struct MyItemSave *p, int i, s16 *a, s16 *b);
extern void ITEMMENU_MoveCursorToRow(char *p);
extern void ITEMMENU_PrintPocketCount(int p, int val);
extern void ITEMMENU_SelectTab(int p, unsigned sel);
extern void ITEMMENU_LoadBgPaletteMode(int p, int mode);

void ITEMMENU_SwitchPocketCursor(Obj *o, int a, int b)
{
    s16 s[2];

    func_02008298(o->gfx, a);
    func_02008288(o->gfx, (u16)a, o->f810, o->f814 + 1);
    func_02008270(o->gfx, (u16)b, &s[1], &s[0]);
    o->f810 = s[1];
    o->f814 = s[0] - 1;
    ITEMMENU_MoveCursorToRow((char *)o);
    ITEMMENU_PrintPocketCount((int)o, b);
    ITEMMENU_SelectTab((int)o, b);
    ITEMMENU_LoadBgPaletteMode((int)o, b);
}
