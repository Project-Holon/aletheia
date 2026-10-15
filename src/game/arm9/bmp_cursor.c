/*
 * file:     bmp_cursor.c
 * unit:     yes
 * function: BMP_CURSOR_Create, BMP_CURSOR_Delete, BMP_CURSOR_Draw, BMP_CURSOR_SetTileBitmap
 * address:  0x02020D18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from bmp_menulist.c by tools/splitfile.py.
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_CURSOR_FILE_NAME     0x020A73A0  data
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_Delete  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   BMP_Blit  0x020439A0  arm
 *   BMP_CURSOR_TileData     0x0209E8CC  data
 *   func_02030734   0x02030734  arm
 *   BMP_CreateFromBuffer  0x020436FC  arm
 */
#include "bmp_menulist_shared_types.h"

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern u32 func_020307B0(void *block);

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern void STRBUF_Delete(void *res);

extern void BMP_Delete(struct Bmp *bmp);

extern void PRINTSYS_PrintQue(void *printer, struct Bmp *bmp, u32 x, u32 y, void *text, u32 param);

extern void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 w, u32 h, u32 key);

extern struct Bmp *BMP_CreateFromBuffer(const void *pixels, u32 widthTiles, u32 heightTiles, u32 sizeBytes, u16 heap);

struct MenuCursor *BMP_CURSOR_Create(u32 heap);

void BMP_CURSOR_Delete(struct MenuCursor *cursor);

void BMP_CURSOR_Draw(struct MenuCursor *cursor, u32 x, u32 y, struct MenuTarget *target, void *printer, u32 param);

void BMP_CURSOR_SetTileBitmap(struct MenuCursor *cursor, int heap);

extern const char BMP_CURSOR_FILE_NAME[];

extern const u8 BMP_CURSOR_TileData[];

struct MenuCursor *BMP_CURSOR_Create(u32 heap)
{
    struct MenuCursor *cursor = func_02030734((u16)heap, 0xc, 1, BMP_CURSOR_FILE_NAME, 0x3a);

    if (cursor != 0) {
        cursor->mode = 0;
    }
    return cursor;
}

/*
 * A destructor: frees two owned sub-objects at +4 and +8 if present, then
 * hands the object itself to a common finalizer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_CURSOR_Delete.c \
 *       --func BMP_CURSOR_Delete --addr 0x02020D3C --cc 1.1p1 --thumb
 */
void BMP_CURSOR_Delete(struct MenuCursor *cursor)
{
    if (cursor->aux != 0) {
        STRBUF_Delete(cursor->aux);
    }
    if (cursor->tile != 0) {
        BMP_Delete(cursor->tile);
    }
    func_020307B0(cursor);
}

/*
 * Blits one cursor/icon out of its cell holder, choosing between two
 * targets by the descriptor's mode word: mode 1 draws through the
 * 0x0201C6FC window path and latches a "drawn" flag on the caller's
 * handle, anything else falls back to the plain 8x8 palette-0xf blit
 * at 0x020439A0 when a surface is configured, and releases the cell
 * afterwards.
 */
void BMP_CURSOR_Draw(struct MenuCursor *cursor, u32 x, u32 y, struct MenuTarget *target,
                   void *printer, u32 param)
{
    if (cursor->mode == 1) {
        PRINTSYS_PrintQue(printer, BMP_WIN_GetBmp(target->win), (s16)x, (s16)y, cursor->aux, param);
        target->dirty = 1;
    } else if (cursor->tile != 0) {
        BMP_Blit(cursor->tile, BMP_WIN_GetBmp(target->win), 0, 0,
                      x + 2, y + 2, 8, 8, 0xf);
        BMP_WIN_TransferChars(target->win);
    }
}

void BMP_CURSOR_SetTileBitmap(struct MenuCursor *cursor, int heap)
{
    cursor->tile = BMP_CreateFromBuffer(BMP_CURSOR_TileData, 1, 1, 0x20, heap);
}
