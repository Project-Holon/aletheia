/*
 * function: DUP_FITTING_InitFrames
 * address:  0x021B6F00
 * packet:   pkt_ov133_021B6F00
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_SAVE_IsPropOwned 0x0200A644 thumb
 *   MUSICAL_SAVE_IsPropNew 0x0200A680 thumb
 *   MUSICAL_SAVE_GetOutfits 0x0200A628 thumb
 *   MUSICAL_MCSS_CreateActorPool 0x021F48C0 thumb ov112
 *   MUSICAL_MCSS_GetActorPoolResource 0x021F4F10 thumb ov112
 *   MUSICAL_MCSS_CreateResourceArc 0x021F4B3C thumb ov112
 *   MUSICAL_MCSS_FreeResourceArc 0x021F4B4C thumb ov112
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   MUSICAL_MCSS_GetElemSizeFlags 0x021F4F70 thumb ov112
 *   MUSICAL_MCSS_SetElemFlag 0x021F4EE8 thumb ov112
 *   MUSICAL_MCSS_AddImageNoVram 0x021F4C1C thumb ov112
 *   MUSICAL_MCSS_SetElemVisible 0x021F4E6C thumb ov112
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   MUSICAL_MCSS_TransferVram 0x021F4DE0 thumb ov112
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_GetTexVramKey 0x02047388 arm
 *   G3D_SYSTEM_GetPlttVramKey 0x020473B8 arm
 *   G3D_SYSTEM_GetPlttDataAddr 0x020473EC arm
 *   G3D_SYSTEM_GetResourceFile 0x02046F48 arm
 *   G3D_SYSTEM_GetResourceTex 0x02047250 arm
 *   NNS_G3dPlttSetPlttKey 0x0206A124 arm
 *   NNS_G3dPlttLoad 0x0206A12C arm
 *   DC_FlushRange 0x020862F0 arm
 *   BILLBOARD_GetImageSizeFromFlags 0x0204EDD0 arm
 *   BILLBOARD_AddImageFromVramKeys 0x0204F044 arm
 *   BILLBOARD_AddImageFromArchive 0x0204EFC8 arm
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   DUP_FITTING_SortFrames 0x021B9028 thumb ov133
 *   DUP_FITTING_ITEM_CreateList 0x021BA0CC thumb ov133
 *   DUP_FITTING_ITEM_CreateElem 0x021BA19C thumb ov133
 *   DUP_FITTING_ITEM_InsertElem 0x021BA100 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_AddFitElemById 0x021B7368 thumb ov133
 *   DUP_FITTING_FreeHeldElem 0x021B7A18 thumb ov133
 *   DUP_FITTING_SetModelTransform 0x021B765C thumb ov133
 *   d_020A8148    0x020A8148 data
 *   d_021BA3E0    0x021BA3E0 data ov133 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct Vec { int x, y, z; } Vec;
struct Big;
extern u32 MUSICAL_SAVE_IsPropOwned(struct Big *p, u8 index);
extern u32 MUSICAL_SAVE_IsPropNew(struct Big *p, u8 index);
typedef signed int     s32;
struct Board;
struct Desc;
struct Layer;
struct Object;
struct Tagged;
struct Vec3;
extern u8 *MUSICAL_SAVE_GetOutfits(struct Big *p);
extern struct Object *MUSICAL_MCSS_CreateActorPool(u32 owner, int count, u16 heap);
extern u32 MUSICAL_MCSS_GetActorPoolResource(u8 *p);
extern void *MUSICAL_MCSS_CreateResourceArc(int type);
extern void MUSICAL_MCSS_FreeResourceArc(struct Tagged *a0);
extern u8 *MUSICAL_MCSS_GetElemPtr(u8 *, int);
extern int MUSICAL_MCSS_GetElemSizeFlags(int *);
extern void MUSICAL_MCSS_SetElemFlag(u8 *, u8 *, int);
extern u8 *MUSICAL_MCSS_AddImageNoVram(u8 *, int, u32, Vec *);
extern void MUSICAL_MCSS_SetElemVisible(u8 *, u8 *, u32);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
extern void MUSICAL_MCSS_TransferVram(char *p, char *e, void *a2);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern u32 G3D_SYSTEM_GetTexVramKey(struct Layer *layer);
extern u32 G3D_SYSTEM_GetPlttVramKey(struct Layer *layer);
extern int G3D_SYSTEM_GetPlttDataAddr(int a0);
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern void *G3D_SYSTEM_GetResourceTex(void *);
extern void NNS_G3dPlttSetPlttKey(int *p, int v);
extern void NNS_G3dPlttLoad(void *, u32);
extern void DC_FlushRange(void *, u32);
extern void BILLBOARD_GetImageSizeFromFlags(int, u16 *, u16 *);
extern int BILLBOARD_AddImageFromVramKeys(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6);
extern u32 BILLBOARD_AddImageFromArchive(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6);
extern s32 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void BILLBOARD_SetElemVisible(void *, u32, u32 *);
extern void DUP_FITTING_SortFrames(u8 *, int, u16);
extern u8 *DUP_FITTING_ITEM_CreateList(u16, int);
struct Object;
extern u8 *DUP_FITTING_ITEM_CreateElem(u16 heap, struct Object *q, u8 *r, int *v);
extern void DUP_FITTING_ITEM_InsertElem(u8 *p, u8 *q);
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern void DUP_FITTING_AddFitElemById(u8 *p, u16 id);
extern void DUP_FITTING_FreeHeldElem(u8 *);
extern void *DUP_FITTING_SetModelTransform(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
extern u32 (*d_020A8148)(u32, u32, u32);
extern u32 d_021BA3E0[];

void DUP_FITTING_InitFrames(u8 *p)
{
    int i;
    int j;
    u32 zero;
    u8 *table;
    void *h;
    int w;
    u32 flags;
    u32 vram;
    u32 hgt;
    u32 sz;
    u16 sizes[2];
    u16 dims[2];
    u16 *pal;
    u32 n;
    u8 k;
    u8 *buf;
    void *res;
    u8 *e;

    *(u16 *)(p + 0xa8) = 0;
    zero = 0;
    for (i = 0; i < 250; i++) {
        if (MUSICAL_SAVE_IsPropOwned(*(void **)(*(u8 **)(p + 4) + 8), i) == 1) {
            *(u16 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xac) = i;
            *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xb8) = zero;
            if (MUSICAL_SAVE_IsPropNew(*(void **)(*(u8 **)(p + 4) + 8), i) == 1)
                *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xbc) = 1;
            else
                *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xbc) = zero;
            (*(u16 *)(p + 0xa8))++;
        }
    }
    for (j = 0; *(u16 *)(p + 0xa8) + j < 250; j++) {
        *(u16 *)(p + (*(u16 *)(p + 0xa8) + j) * 0x14 + 0xac) = 0xff;
        *(u32 *)(p + (*(u16 *)(p + 0xa8) + j) * 0x14 + 0xb8) = 0;
        *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xbc) = 1;
    }

    *(u8 **)(p + 0x1884) = (u8 *)MUSICAL_MCSS_CreateActorPool((u32)(*(void **)(p + 0x188c)), 0x98, *(u16 *)p);
    table = (u8 *)MUSICAL_MCSS_GetActorPoolResource(*(u8 **)(p + 0x1884));

    for (i = 0; i < *(u16 *)(p + 0xa8); i++) {
        h = MUSICAL_MCSS_CreateResourceArc(*(u16 *)(p + i * 0x14 + 0xac));
        G3D_SYSTEM_TransVramTexture(h);
        w = G3D_SYSTEM_GetTexVramKey(h);
        hgt = G3D_SYSTEM_GetPlttVramKey(h);
        sz = ((hgt & 0xFFFF0000) >> 16) << 3;
        vram = d_020A8148(sz, 0, 0);
        flags = MUSICAL_MCSS_GetElemSizeFlags((int *)MUSICAL_MCSS_GetElemPtr(table, *(u16 *)(p + i * 0x14 + 0xac)));
        BILLBOARD_GetImageSizeFromFlags(flags, &sizes[1], &sizes[0]);
        *(u32 *)(p + i * 0x14 + 0xb0) = BILLBOARD_AddImageFromVramKeys(*(void **)(p + 0x188c), w, hgt, 0, flags, sizes[1], sizes[0]);
        pal = (u16 *)G3D_SYSTEM_GetPlttDataAddr((int)h);
        n = sz >> 1;
        for (k = 0; k < n; k++) {
            u16 c = pal[k];
            u32 b = (u32)(u8)((c & 0x7C00) >> 10) >> 3;
            u32 r = (u32)(u8)(c & 0x1F) >> 3;
            u32 g = (u32)(u8)((c & 0x3E0) >> 5) >> 3;
            pal[k] = r | (g << 5) | (b << 10);
        }
        buf = G3D_SYSTEM_GetResourceFile(h);
        res = G3D_SYSTEM_GetResourceTex(h);
        NNS_G3dPlttSetPlttKey(res, vram);
        DC_FlushRange(buf, *(u32 *)(buf + 8));
        NNS_G3dPlttLoad(res, 1);
        *(u32 *)(p + i * 0x14 + 0xb4) = BILLBOARD_AddImageFromVramKeys(*(void **)(p + 0x188c), w, vram, 0, flags, sizes[1], sizes[0]);
        MUSICAL_MCSS_FreeResourceArc(h);
    }

    DUP_FITTING_SortFrames(p, 8, 0);
    *(u8 **)(p + 0x181c) = DUP_FITTING_ITEM_CreateList(*(u16 *)p, 0xe);
    *(u8 **)(p + 0x1820) = DUP_FITTING_ITEM_CreateList(*(u16 *)p, 0x80);
    *(u8 **)(p + 0x1824) = DUP_FITTING_ITEM_CreateList(*(u16 *)p, 9);
    *(u8 **)(p + 0x1828) = DUP_FITTING_ITEM_CreateList(*(u16 *)p, 4);

    for (i = 0; i < 14; i++) {
        Vec v = {0, 0, 0};
        e = DUP_FITTING_ITEM_CreateElem(*(u16 *)p, *(void **)(p + 0x1884), p + 0xac + i * 0x14, (int *)(&v));
        DUP_FITTING_ITEM_InsertElem(*(void **)(p + 0x181c), e);
        MUSICAL_MCSS_SetElemFlag(*(u8 **)(p + 0x1884), (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(e), 0);
    }

    {
    Vec v2 = {0, 0, 0};
    *(u16 *)(p + 0x50) = 0;
    flags = MUSICAL_MCSS_GetElemSizeFlags((int *)MUSICAL_MCSS_GetElemPtr(table, *(u16 *)(p + 0x50)));
    BILLBOARD_GetImageSizeFromFlags(flags, &dims[1], &dims[0]);
    h = MUSICAL_MCSS_CreateResourceArc(*(u16 *)(p + 0x50));
    G3D_SYSTEM_TransVramTexture(h);
    w = G3D_SYSTEM_GetTexVramKey(h);
    *(u32 *)(p + 0x54) = BILLBOARD_AddImageFromVramKeys(*(void **)(p + 0x188c), w, G3D_SYSTEM_GetPlttVramKey(h), 0, flags, dims[1], dims[0]);
    *(u8 **)(p + 0x4c) = MUSICAL_MCSS_AddImageNoVram(*(u8 **)(p + 0x1884), *(u16 *)(p + 0x50), *(u32 *)(p + 0x54), &v2);
    MUSICAL_MCSS_SetElemVisible(*(u8 **)(p + 0x1884), *(u8 **)(p + 0x4c), 0);
    MUSICAL_MCSS_SetElemRotZ((u32)(*(u8 **)(p + 0x1884)), (u32)(*(u8 **)(p + 0x4c)), 0x1000, 0x1000);
    MUSICAL_MCSS_TransferVram((char *)(*(u8 **)(p + 0x1884)), (char *)(*(u8 **)(p + 0x4c)), h);
    MUSICAL_MCSS_FreeResourceArc(h);
    }

    *(u32 *)(p + 0x58) = BILLBOARD_AddImageFromArchive(*(void **)(p + 0x188c), 0x2e, 0x19, 2, 0x22, 0x20, 0x20);
    for (k = 0; k < 14; k++) {
        Vec v3 = {0, 0, 0};
        n = BILLBOARD_AddElem(*(void **)(p + 0x188c), *(u32 *)(p + 0x58), 0x1000, 0x1000, (struct Vec3 *)(&v3), 0x1f, 0, 0);
        *(u32 *)(p + k * 4 + 0x5c) = n;
        BILLBOARD_SetElemVisible(*(void **)(p + 0x188c), n, d_021BA3E0);
    }

    *(u16 *)(p + 0x94) = 0;
    e = MUSICAL_SAVE_GetOutfits(*(void **)(*(u8 **)(p + 4) + 8));
    for (k = 0; k < 8; k++) {
        if (e[k * 6] != 10)
            DUP_FITTING_AddFitElemById(p, *(u16 *)(e + k * 6 + 2));
    }
    DUP_FITTING_FreeHeldElem(p);
    *(u32 *)(p + 0x1834) = *(u16 *)(p + 0xa8) * 0x1249 - 0x8000;
    DUP_FITTING_SetModelTransform(p, 0, 0, 0x48, 0x30);
}
