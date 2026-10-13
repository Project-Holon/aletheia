/*
 * function: BMP_MENULIST_DrawItems
 * address:  0x0202055C
 * packet:   pkt_02020408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02045738  0x02045738  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_020437DC  0x020437DC  arm
 *   BMP_MENULIST_PrintItem  0x02020408  thumb
 *   BMP_MENULIST_ShiftWindow  0x02020CA0  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_DrawItems.c \
 *       --func BMP_MENULIST_DrawItems --addr 0x0202055C --thumb
 *
 * Redraw n + 1 rows of the menu list from item `row`, starting at window
 * row `col`.  When flag is set and row > 0 the window is first scrolled by
 * one row: the band is cleared with func_02043AF4, the item above is
 * redrawn and BMP_MENULIST_ShiftWindow moves the pixels.  Every item goes through the
 * optional per-item hook at +0x08 (obj, item value, y) and then
 * BMP_MENULIST_PrintItem at x = f15, or f14 for a separator (value -3).
 *
 * Closed in wave 13 from the 2026-09-21 note (docs/notes/BMP_MENULIST_DrawItems.c.txt,
 * 96 out).  That source misread three things, all fixed here from the image:
 * the hook's second argument inside the loop is the item's value word (still
 * live in r1 from the separator test), not 0; BMP_MENULIST_ShiftWindow's last argument
 * is (step*2/8) * (func_020437DC(bitmap) / 8), the bitmap's width in tiles,
 * not step >> 3; and the x colour is an int (no truncation after the
 * ternary).  Then the permuter's type:l(step:u8->int) (the value is still
 * (u8)-truncated at its one assignment) swapped the last two stack slots.
 * EXACT* only because the extent includes 2 bytes of padding.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

struct Elem {
    const void *text;
    u32 value;
};

typedef void (*Hook)(struct Obj *obj, u32 value, u8 y);

struct Obj {
    struct Elem *arr;
    u32 unk04;
    Hook hook;
    u32 unk0C;
    u16 count;
    u16 rows;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17lo : 4;
    u8 f17hi : 4;
    u8 f18lo : 4;
    u8 f18hi : 4;
    u8 f19;
    u16 f1Alo : 3;
    u16 f1Amid : 4;
    u16 f1Apad : 2;
    u16 f1Amid2 : 6;
    u16 f1Atop : 1;
    u8 pad1C[0x20 - 0x1C];
    u16 f20;
    u16 f22;
};

struct Descriptor;
extern void *func_02045770(struct Descriptor *win);
struct Bmp;
extern u8 func_02045738(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void BMP_MENULIST_PrintItem(struct Obj *obj, const void *text, u32 x, u32 y, u32 sel);
extern void BMP_MENULIST_ShiftWindow(void *win, u32 a, u32 b, u32 c, u16 tile);

void BMP_MENULIST_DrawItems(struct Obj *obj, u16 row, u16 col, u16 n, u32 flag)
{
    int step;
    int x;
    u8 y;
    int i;
    int lim;

    step = (u8)(obj->f22 + obj->f1Amid);
    if (row != 0 && flag != 0) {
        u32 bmp;
        u8 w;
        u8 k;
        x = (obj->arr[row - 1].value != (u32)-3) ? obj->f15 : obj->f14;
        bmp = (u32)func_02045770((struct Descriptor *)obj->unk0C);
        w = func_02045738((struct Descriptor *)obj->unk0C);
        func_02043AF4((struct Bmp *)bmp, 0, 0, (u16)(w * 8),
                      (u16)(obj->f17lo + (col + 1) * step * 2), obj->f18lo);
        y = (u8)(obj->f17lo + col * step);
        if (obj->hook != 0)
            obj->hook(obj, obj->arr[row - 1].value, y);
        BMP_MENULIST_PrintItem(obj, obj->arr[row - 1].text, x, y, 0);
        k = obj->f18lo;
        BMP_MENULIST_ShiftWindow((void *)obj->unk0C, 0, step, (u8)((k << 4) | k),
                      (u16)((step * 2 / 8) * (func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)obj->unk0C))) / 8)));
    }
    lim = (u16)(n + 1);
    for (i = 0; i < lim; i++) {
        x = (obj->arr[row].value != (u32)-3) ? obj->f15 : obj->f14;
        y = (u8)(obj->f17lo + (i + col) * step);
        if (obj->hook != 0)
            obj->hook(obj, obj->arr[row].value, y);
        BMP_MENULIST_PrintItem(obj, obj->arr[row].text, x, y, 1);
        row++;
        if (row >= obj->count)
            return;
    }
}
