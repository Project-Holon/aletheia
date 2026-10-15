/*
 * function: ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc
 * address:  0x021BC844
 * packet:   pkt_ov208_021BC844
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049740  0x02049740  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C8D98  0x021C8D98  data
 *   data_021C80E0  0x021C80E0  data
 *   data_021C80E8  0x021C80E8  data
 *   data_021C80F0  0x021C80F0  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208BgArc {
    u32 chr;
    u32 scr;
    u32 size;
};

struct Ov208Win {
    u32 chrOfs;
    u8  layer;
    u8  kind;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_02041B6C(u32 bit);
extern const char data_021C8D98[];
extern const u8 data_021C80E0[2][4];
extern const u8 data_021C80E8[2][4];
extern const struct Ov208BgArc data_021C80F0[2];

struct Ov208Win *ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal)
{
    struct Ov208Win *w;
    void *h;
    u32 sub;
    u32 type;
    u32 scr;

    w = func_02030734(heap, sizeof(*w), 1, data_021C8D98, 0x323);
    if (layer < 4) {
        sub = 0;
        type = 0;
    } else {
        sub = 1;
        type = 4;
    }
    h = func_020490F4(0x9f, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, data_021C80F0[sub].chr, type, data_021C80E8[sub][kind] << 5, pal << 5,
                  0x20, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, data_021C80F0[sub].chr, type, data_021C80E0[sub][kind] << 5,
                  objPal << 5, 0x20, heap);
    w->chrOfs = func_02049740(h, data_021C80F0[sub].scr, layer, 0, 0, heap);
    scr = data_021C80F0[sub].size;
    if (kind == 3 && sub == 0)
        scr = 0x20;
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, scr, layer, 0, (u16)w->chrOfs, 0, 0, heap);
    BG_SYS_FillTileMap(layer, 0, 0x15, 0x20, 3, pal);
    BG_SYS_FillTileMap(layer, 0, 0, 0x20, 0x15, objPal);
    ARC_TOOL_DeleteHandle(h);
    func_02041B6C(layer);
    w->layer = layer;
    w->kind = 4;
    return w;
}
