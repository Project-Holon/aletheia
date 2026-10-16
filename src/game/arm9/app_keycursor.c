/*
 * file:     app_keycursor.c
 * unit:     yes
 * function: APP_KEYCURSOR_Create, APP_KEYCURSOR_Delete, APP_KEYCURSOR_DrawMark, APP_KEYCURSOR_Animate, APP_KEYCURSOR_Update, func_02028748, func_02028754
 * address:  0x020285A4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from app_keycursor.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   BMP_CreateFromBuffer      0x020436FC  arm
 *   app_keycursor_File 0x020A74F0  data
 *   BMP_Delete  0x020437AC  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   BMP_Blit  0x020439A0  arm
 *   PRINTSYS_PrintStreamGetState   0x0201CE30  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "app_keycursor_shared_types.h"

typedef signed short   s16;

typedef signed int     s32;

struct Bmp {
    void *pixels;
    u16   width;
    u16   height;
    u16   depth;
    u16   kind;
};

/* Cursor work: one 2x2-tile bitmap and the blink state of one text cursor. */
struct KeyCursor {
    struct Bmp *item;  /* 0x00 */
    u8   phase;        /* 0x04 */
    u8   tick;         /* 0x05 */
    u8   held;         /* 0x06 */
    u8   live : 1;     /* 0x07 bit 0 */
    u8   flip : 1;     /* 0x07 bit 1 */
    u16  id;           /* 0x08 */
};

/* Flag word at 0x14 of an object defined elsewhere (see misplaced notes). */
struct Obj {
    u8  pad_00[0x14];
    u32 flags;
};

struct Descriptor;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heap);

extern void BMP_Delete(struct Bmp *bmp);

extern u16  BMP_GetWidth(const struct Bmp *bmp);

extern u16 BMP_GetHeight(const struct Bmp *bmp);

extern void BMP_FillRect(const struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);

extern void BMP_Blit(struct Bmp *dst, const struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);

extern u32   PRINTSYS_PrintStreamGetState(void *p);

extern u32   KEY_GetTrg(void);

extern int TOUCHPANEL_GetTrg(void);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern u32 func_020307B0(void *p);

struct KeyCursor *APP_KEYCURSOR_Create(u16 id, u32 live, u32 flip, u16 heap, void *pixels);

void APP_KEYCURSOR_Delete(struct KeyCursor *k);

void APP_KEYCURSOR_DrawMark(struct KeyCursor *k, const struct Bmp *bmp, u32 color);

void APP_KEYCURSOR_Animate(struct KeyCursor *k, const struct Bmp *bmp, u32 color);

void APP_KEYCURSOR_Update(struct KeyCursor *k, void *p, void *cell);

void func_02028748(struct Obj *obj, int n, int mask);

u32 func_02028754(struct Obj *obj, u32 n);

extern const char app_keycursor_File[];

/*
 * TU: app_keycursor.c (__FILE__ 0x020A74F0, line 149).
 */
struct KeyCursor *APP_KEYCURSOR_Create(u16 id, u32 live, u32 flip, u16 heap,
                                void *pixels)
{
    struct KeyCursor *k;

    k = func_02030734(heap, sizeof(struct KeyCursor), 1, app_keycursor_File,
                      149);

    k->id = id;
    k->live = live;
    k->flip = flip;
    k->item = BMP_CreateFromBuffer(pixels, 2, 2, 0x20, heap);

    return k;
}

void APP_KEYCURSOR_Delete(struct KeyCursor *k)
{
    BMP_Delete(k->item);
    func_020307B0(k);
}

void APP_KEYCURSOR_DrawMark(struct KeyCursor *k, const struct Bmp *bmp, u32 color)
{
    u16 w = BMP_GetWidth(bmp) - 11;
    u16 h = BMP_GetHeight(bmp) - 9;

    BMP_FillRect(bmp, (s16)w, (s16)(h + k->phase), 0xa, 7, (u8)color);
}

void APP_KEYCURSOR_Animate(struct KeyCursor *k, const struct Bmp *bmp, u32 color)
{
    u16 w;
    u16 h;

    APP_KEYCURSOR_DrawMark(k, bmp, color);

    k->tick = k->tick + 1;
    if (k->tick >= 8) {
        k->tick = 0;
        k->phase = k->phase + 1;
        k->phase = (s32)k->phase % 3;
    }

    w = BMP_GetWidth(bmp) - 11;
    h = BMP_GetHeight(bmp) - 9;

    BMP_Blit(k->item, bmp, 0, 2, w, h + k->phase, 0xa, 7, 0);
}

void APP_KEYCURSOR_Update(struct KeyCursor *k, void *p, void *cell)
{
    u32 mode = PRINTSYS_PrintStreamGetState(p);

    switch (mode) {
    case 2:
        k->held = 0;
        return;
    case 1:
    {
        u32 r = 0;

        if (k->live) {
            r = KEY_GetTrg() & 3;
        }
        if (r == 0) {
            if (k->flip) {
                r = TOUCHPANEL_GetTrg();
            }
        }
        if (r != 0) {
            k->held = 1;
            APP_KEYCURSOR_DrawMark(k, BMP_WIN_GetBmp(cell), k->id);
            BMP_WIN_TransferChars(cell);
            return;
        }
        if (k->held != 0) {
            return;
        }
        APP_KEYCURSOR_Animate(k, BMP_WIN_GetBmp(cell), k->id);
        BMP_WIN_TransferChars(cell);
        return;
    }
    case 0:
        k->held = 0;
        return;
    }
}

/*
 * A pair of leaf accessors over a 32-bit flag word at offset 0x14: or
 * `mask << n` into it, and test bit `n`.  Neither calls anything.
 */
void func_02028748(struct Obj *obj, int n, int mask)
{
    obj->flags = obj->flags | (mask << n);
}

u32 func_02028754(struct Obj *obj, u32 n)
{
    return (obj->flags >> n) & 1;
}
