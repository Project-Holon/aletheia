/*
 * function: SHINKA_DEMO_VIEW_CreateGrid
 * address:  0x0220685C
 * packet:   pkt_0220685C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208F68 0x02208F68 data
 *   func_02030734 0x02030734 arm
 *   BMP_Create 0x02043678 arm
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   POKEGRA_GetCgrArcIndex 0x0202D064 thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 *   ARC_UTIL_LoadScreenDataFromArchive 0x02049E34 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   MIi_CpuClear32 0x02082A7C arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   BMP_ConvertToLinear 0x02044F64 arm
 *   func_02061CA4 0x02061CA4 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct CharData {
    u8 pad00[0x14];
    u8 *raw;
} CharData;

typedef struct PlttData {
    u8 pad00[0xc];
    void *raw;
} PlttData;

typedef struct Grid {
    CharData *chr;
    PlttData *pltt;
    void *chrRes;
    void *plttRes;
    void *canvas;
    u32 tex;
    u32 plttAddr;
    u8 rest[0xA278 - 0x1c];
} Grid;

extern char d_02208F68[];
typedef signed int     s32;
struct Bmp;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern int POKEGRA_GetArcID(void);
extern s32 POKEGRA_GetCgrArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 POKEGRA_GetPalArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void MIi_CpuClear32(u32 fill, void *dst, u32 size);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern struct Bmp *BMP_ConvertToLinear(struct Bmp *src, u32 keep, u16 heap);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

Grid *SHINKA_DEMO_VIEW_CreateGrid(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 tex, u32 pltt, u16 heap)
{
    Grid *g = func_02030734(heap, sizeof(Grid), 1, d_02208F68, 0x720);
    u32 chrFile;
    u32 plttFile;
    u8 *src;
    u8 *buf;
    int i, j;
    int k;

    g->canvas = BMP_Create(16, 16, 32, heap);
    g->tex = tex;
    g->plttAddr = pltt;
    chrFile = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), a0, a1, a2, a3, a4, a5);
    plttFile = POKEGRA_GetPalArcIndex(POKEGRA_GetArcID(), a0, a1, a2, a3, a4, a5);
    g->chr = 0;
    g->pltt = 0;
    g->chrRes = ARC_UTIL_LoadScreenDataFromArchive(POKEGRA_GetArcID(), chrFile, 1, (u32)(&g->chr), heap);
    g->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(POKEGRA_GetArcID(), plttFile, (u32)(&g->pltt), heap);
    src = g->chr->raw;
    buf = BMP_GetPixels(g->canvas);
    MIi_CpuClear32(0, buf, 0x2000);
    k = 0;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            MIi_CpuCopy32(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 8; i < 12; i++) {
            MIi_CpuCopy32(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 0; i < 8; i++) {
            MIi_CpuCopy32(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 8; i < 12; i++) {
            MIi_CpuCopy32(src + k * 32, buf + 0x440 + (i + j * 16) * 32, 32);
            k++;
        }
    }
    BMP_ConvertToLinear(g->canvas, 0, heap);
    func_02061CA4(0, tex, (u32)BMP_GetPixels(g->canvas), 0x2000);
    func_02061CA4((void *)1, pltt, (u32)g->pltt->raw, 0x20);
    return g;
}
