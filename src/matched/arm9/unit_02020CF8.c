/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02020CF8
 * packet:   pkt_02020408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BMP_MENULIST_ResetCursorTile, BMP_MENULIST_GetUserData, BMP_MENULIST_SetCancelDisabled, BMP_CURSOR_Create
 *
 * symbols:
 *   func_02020D18_File  0x020A73A0  data
 *   BMP_MENULIST_DrawCursor  0x020206C0  thumb
 *   BMP_CURSOR_SetTileBitmap  0x02020DC8  thumb
 *
 * BMP_MENULIST_GetUserData and BMP_MENULIST_SetCancelDisabled carry no label in the generated listing:
 * they are a two-instruction word getter and a two-instruction byte setter
 * with no register-saving prologue, so disasm.py's prologue sweep never
 * fires on them and the listing prints them as a run of data between
 * BMP_MENULIST_ResetCursorTile and BMP_CURSOR_Create
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * BMP_CURSOR_Create is a debug-allocator constructor in the
 * `sub_02030734(heap, size, count, file, line)` shape documented for
 * playtime.c: it allocates a 12-byte object tagged with the string at
 * 0x020A73A0 and line 0x3a, zeroing the first word when the allocation
 * succeeds.  0x020A73A0 spells "bmp_cursor.c", the second original source
 * file name this project has recovered (after playtime.c); the functions
 * keep their sub_<address> names because the file identity is attested and
 * the individual entry points are not.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020CF8.c \
 *       --addr 0x02020CF8 --thumb
 */
#include "../include/Obj17238.h"
#include "../include/Obj17240.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u8    pad[0x3C];
    void *unk3C;
};

extern void BMP_CURSOR_SetTileBitmap(char *p, int a);
extern void BMP_MENULIST_DrawCursor(struct Obj *p);

void BMP_MENULIST_ResetCursorTile(struct Obj *p, int heap)
{
    BMP_CURSOR_SetTileBitmap(p->unk3C, heap);
    BMP_MENULIST_DrawCursor(p);
}

u32 BMP_MENULIST_GetUserData(u8 *p)
{
    return ((struct Obj17238 *)p)->f1C;
}

void BMP_MENULIST_SetCancelDisabled(u8 *p, u32 v)
{
    p[0x4A] = v;
}

extern const char func_02020D18_File[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void *BMP_CURSOR_Create(u32 heap)
{
    void *p = func_02030734((u16)heap, 0xc, 1, func_02020D18_File, 0x3a);

    if (p != 0) {
        ((struct Obj17240 *)p)->f0 = 0;
    }
    return p;
}
