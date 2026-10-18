/*
 * function: FLD3D_CI_LoadPokemonIconTexture
 * address:  0x021C2918
 * packet:   pkt_ov021_021C2918
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BMP_Create  0x02043678  arm
 *   func_02048A0C  0x02048A0C  arm
 *   G3D_SYSTEM_GetTexVramKey  0x02047388  arm
 *   G3D_SYSTEM_GetPlttVramKey  0x020473B8  arm
 *   POKEGRA_GetArcID  0x0202D060  thumb
 *   POKEGRA_GetCgrArcIndex  0x0202D064  thumb
 *   POKEGRA_GetPalArcIndex  0x0202D0D4  thumb
 *   ARC_UTIL_LoadScreenDataFromArchive  0x02049E34  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   BMP_ConvertToLinear  0x02044F64  arm
 *   func_02061CA4  0x02061CA4  arm
 *   func_02030830  0x02030830  arm
 * Twin of ov195 SHINKA_DEMO_VIEW_CreateGrid (same tile-copy body). The far argument block
 * at +0x9C needs a local pointer (`a = p->args`), and the two size calls
 * must land in int locals before the (u16) << 3 conversions.
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

typedef struct Obj {
    u8 pad00[0x10];
    u16 heap;
    u16 pad12;
    void *f14;
    u8 pad18[0x88 - 0x18];
    CharData *chr;
    PlttData *pltt;
    void *canvas;
    void *chrRes;
    void *plttRes;
    u32 args[5];
} Obj;

typedef signed int     s32;
struct Bmp;
struct Layer;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_02048A0C(u8 *a0, int i);
extern u32 G3D_SYSTEM_GetTexVramKey(struct Layer *layer);
extern u32 G3D_SYSTEM_GetPlttVramKey(struct Layer *layer);
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
extern void *func_02030830(u32 heapId);

void FLD3D_CI_LoadPokemonIconTexture(Obj *p)
{
    u16 heap;
    u8 *buf;
    int j;
    u32 tex;
    u32 pltt;
    u8 *src;
    u32 chrFile;
    u32 plttFile;
    void *h;
    u32 *a;
    int t1;
    int t2;
    int i;
    int k;

    heap = p->heap;
    p->canvas = BMP_Create(16, 16, 32, heap);
    k = 0;
    h = (void *)func_02048A0C(p->f14, 0);
    t1 = G3D_SYSTEM_GetTexVramKey(h);
    t2 = G3D_SYSTEM_GetPlttVramKey(h);
    tex = (u16)t1 << 3;
    pltt = (u16)t2 << 3;
    a = p->args;
    chrFile = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), a[0], a[1], a[2], a[3], 0, a[4]);
    plttFile = POKEGRA_GetPalArcIndex(POKEGRA_GetArcID(), a[0], a[1], a[2], a[3], 0, a[4]);
    p->chr = 0;
    p->pltt = 0;
    p->chrRes = ARC_UTIL_LoadScreenDataFromArchive(POKEGRA_GetArcID(), chrFile, 1, (u32)(&p->chr), heap);
    p->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(POKEGRA_GetArcID(), plttFile, (u32)(&p->pltt), heap);
    src = p->chr->raw;
    buf = BMP_GetPixels(p->canvas);
    MIi_CpuClear32(0, buf, 0x2000);
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
    BMP_ConvertToLinear(p->canvas, 0, heap);
    func_02061CA4(0, tex, (u32)BMP_GetPixels(p->canvas), 0x2000);
    func_02061CA4((void *)1, pltt, (u32)p->pltt->raw, 0x20);
    func_02030830(p->heap);
}
