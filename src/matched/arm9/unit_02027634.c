/*
 * unit:     yes
 * function: APP_ICON_LoadTouchBar, APP_ICON_GetItemCellFileId, APP_ICON_GetItemPaletteFileId, APP_ICON_GetItemAnimFileId,
 *           APP_ICON_GetItemFrameFileId, APP_ICON_GetItemDataFileId, APP_ICON_GetItemExtraFileId, APP_ICON_GetItemAnim2FileId,
 *           APP_ICON_GetItemFrame2FileId, APP_ICON_GetSealCellFileId, APP_ICON_GetSealPaletteFileId, APP_ICON_GetSealAnimFileId,
 *           APP_ICON_GetSealFrameFileId
 * address:  0x02027634
 * packet:   pkt_02027634
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *
 * beacon_status.c, 0x02027634..0x020276C4: load the beacon status palette,
 * copy its 0x60 colours into the archive's copy and re-base each entry
 * (colour index + base, palette number in the top nibble), then twelve
 * unlabelled 4-byte resource-id getters in groups of four (two constants,
 * two offsets of their argument).
 *
 * What closed the loader after docs/notes/pkt_02027634.c.txt (100 bytes
 * against 96): the palette is a u16[0x60] FIELD at +0x540 of one struct
 * type, and the archive data is that same struct 0xC bytes into the file;
 * with both written as `->pal` the offset 0x540 is one constant kept in r7
 * and the +0xC is added on its own, which is the image.  The re-base is
 * `(pal << 12) + (base + (c & 0xfff))`.
 *
 * Integrator: seed the twelve leaves 0x02027694..0x020276C0 (members).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BeaconGfx {
    u8  pad[0x540];
    u16 pal[0x60];
};

extern u32 BG_SYS_GetBuf(int channel);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *arc, u32 id, u32 comp, void **out, u32 heap);
extern void  MI_CpuCopy8(void *dst, const void *src, u32 size);
extern u32 func_020307B0(void *p);

void APP_ICON_LoadTouchBar(void *arc, int id, u32 heap, int base, u32 pal)
{
    struct BeaconGfx *g;
    void *data;
    void *h;
    int i;

    g = (struct BeaconGfx *)BG_SYS_GetBuf(id);
    h = ARC_UTIL_LoadPaletteDataFromHandle(arc, 0x1d, 0, &data, heap);
    MI_CpuCopy8(((struct BeaconGfx *)((u8 *)data + 0xc))->pal, g->pal, 0xc0);
    func_020307B0(h);
    for (i = 0; i < 0x60; i++)
        g->pal[i] = (pal << 12) + (base + (g->pal[i] & 0xfff));
}

u32 APP_ICON_GetItemCellFileId(void)
{
    return 0x42;
}

u32 APP_ICON_GetItemPaletteFileId(void)
{
    return 0x41;
}

u32 APP_ICON_GetItemAnimFileId(u32 i)
{
    return i + 0x43;
}

u32 APP_ICON_GetItemFrameFileId(u32 i)
{
    return i + 0x46;
}

u32 APP_ICON_GetItemDataFileId(void)
{
    return 0x49;
}

u32 APP_ICON_GetItemExtraFileId(void)
{
    return 0x4a;
}

u32 APP_ICON_GetItemAnim2FileId(u32 i)
{
    return i + 0x4b;
}

u32 APP_ICON_GetItemFrame2FileId(u32 i)
{
    return i + 0x4e;
}

u32 APP_ICON_GetSealCellFileId(void)
{
    return 0xb;
}

u32 APP_ICON_GetSealPaletteFileId(void)
{
    return 0xc;
}

u32 APP_ICON_GetSealAnimFileId(u32 i)
{
    return i + 0xd;
}

u32 APP_ICON_GetSealFrameFileId(u32 i)
{
    return i + 0x10;
}

