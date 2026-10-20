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
 *   GFL_HEAP_Free  0x020307B0  arm
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   BMP_Blit  0x020439A0  arm
 *   BMP_CURSOR_TileData     0x0209E8CC  data
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   BMP_CreateFromBuffer  0x020436FC  arm
 */
#include "bmp_menulist_shared_types.h"

#include "gfl_heap_wrap.h"

#include "bmp_win.h"


struct Strbuf;

#include "strbuf.h"

typedef short s16_p07;
#include "bmp.h"
struct GfFont;
struct PrintQueue;

#include "printsys.h"



struct MenuCursor *BMP_CURSOR_Create(u32 heap);

void BMP_CURSOR_Delete(struct MenuCursor *cursor);

void BMP_CURSOR_Draw(struct MenuCursor *cursor, u32 x, u32 y, struct MenuTarget *target, void *printer, u32 param);

void BMP_CURSOR_SetTileBitmap(struct MenuCursor *cursor, int heap);

extern const char BMP_CURSOR_FILE_NAME[];

extern const u8 BMP_CURSOR_TileData[];

struct MenuCursor *BMP_CURSOR_Create(u32 heap)
{
    struct MenuCursor *cursor = GFL_HEAP_Alloc((u16)heap, 0xc, 1, BMP_CURSOR_FILE_NAME, 0x3a);

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
    GFL_HEAP_Free(cursor);
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
        PRINTSYS_PrintQue(printer, BMP_WIN_GetBmp(target->win), (s16)x, (s16)y, cursor->aux, (struct GfFont *)param);
        target->dirty = 1;
    } else if (cursor->tile != 0) {
        BMP_Blit(cursor->tile, BMP_WIN_GetBmp(target->win), 0, 0,
                      x + 2, y + 2, 8, 8, 0xf);
        BMP_WIN_TransferChars(target->win);
    }
}

void BMP_CURSOR_SetTileBitmap(struct MenuCursor *cursor, int heap)
{
    cursor->tile = BMP_CreateFromBuffer((void *)BMP_CURSOR_TileData, 1, 1, 0x20, heap);
}
