/*
 * function: FLD3D_CI_LoadNameTexture
 * address:  0x021C2BE4
 * packet:   pkt_ov021_021C2BE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02048A0C  0x02048A0C  arm
 *   G3D_SYSTEM_GetTexVramKey  0x02047388  arm
 *   G3D_SYSTEM_GetPlttVramKey  0x020473B8  arm
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   NNS_G3dGetTex  0x0206E964  arm
 *   FLD3D_CI_FindTexture  0x021C2EDC  thumb  ov021
 *   FLD3D_CI_FindPalette  0x021C2F14  thumb  ov021
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02082A90  0x02082A90  arm
 *   BMP_ConvertToLinear  0x02044F64  arm
 *   func_02061CA4  0x02061CA4  arm
 *   func_02030830  0x02030830  arm
 * Sibling of FLD3D_CI_LoadPokemonIconTexture (same object layout at +0x88..+0x98), 16x16
 * tile copy with archive 0xB4 and file ids passed in.
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
} Obj;

typedef signed int     s32;
extern u32 func_02048A0C(u8 *a0, int i);
struct Bmp;
struct Layer;
struct Tagged;
extern u32 G3D_SYSTEM_GetTexVramKey(struct Layer *layer);
extern u32 G3D_SYSTEM_GetPlttVramKey(struct Layer *layer);
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern int FLD3D_CI_FindTexture(u8 *p, const char *name);
extern int FLD3D_CI_FindPalette(u8 *p, const char *name);
extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern struct Bmp *BMP_ConvertToLinear(struct Bmp *src, u32 keep, u16 heap);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void *func_02030830(u32 heapId);

void FLD3D_CI_LoadNameTexture(Obj *p, u32 a1, u32 a2, u32 chrFile, u32 plttFile)
{
    u32 tex;
    u32 pltt;
    u16 heap;
    u8 *buf;
    int j;
    void *h;
    void *t;
    u8 *src;
    int i;
    int k;

    heap = p->heap;
    k = 0;
    h = (void *)func_02048A0C(p->f14, 0);
    G3D_SYSTEM_GetTexVramKey(h);
    G3D_SYSTEM_GetPlttVramKey(h);
    t = NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(h));
    tex = FLD3D_CI_FindTexture(t, (const char *)a1);
    pltt = FLD3D_CI_FindPalette(t, (const char *)a2);
    p->chr = 0;
    p->pltt = 0;
    p->chrRes = ARC_UTIL_LoadBgCharDataFromArchive(0xb4, chrFile, 1, (u32)(&p->chr), heap);
    p->plttRes = ARC_UTIL_LoadPaletteBlockFromArchive(0xb4, plttFile, (u32)(&p->pltt), heap);
    src = p->chr->raw;
    buf = BMP_GetPixels(p->canvas);
    func_02082A7C(0, buf, 0x2000);
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            func_02082A90(src + k * 32, buf + (i + j * 16) * 32, 32);
            k++;
        }
    }
    BMP_ConvertToLinear(p->canvas, 0, heap);
    func_02061CA4(0, tex, (u32)BMP_GetPixels(p->canvas), 0x2000);
    func_02061CA4((void *)1, pltt, (u32)p->pltt->raw, 0x20);
    func_02030830(p->heap);
}
