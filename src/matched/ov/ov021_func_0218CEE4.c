/*
 * function: FIELD_G3D_MAPPER_Setup
 * address:  0x0218CEE4
 * packet:   pkt_ov021_0218CEE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3D_MAPPER_LoadTexture  0x0218D104  thumb  ov021
 *   FIELD_G3D_MAPPER_CreateGroundAnime  0x0218DC84  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   gFieldG3dMapperMapTypeTable     0x021D3DDC  data
 *   gFieldG3dMapperSrcName     0x021DD9EC  data
 *   FIELD_G3D_MAPPER_ResetCell  0x0218DD70  thumb  ov021
 *   FIELD_G3D_MAPPER_InitSlotRes  0x0218DD14  thumb  ov021
 *   FIELD_G3D_MAP_Create  0x02169148  thumb  ov010
 *   FIELD_G3D_MAP_OpenArchive  0x0216937C  thumb  ov010
 *   FIELD_G3D_MAP_SetAltTextureRes  0x021693B4  thumb  ov010
 *   FIELD_G3D_MAP_SetPlacedModels  0x021693C4  thumb  ov010
 *   FIELD_BUILDMODEL_GetHandleTable  0x0218BB04  thumb  ov021
 * Addresses are Black-image addresses.
 *
 * src is const: that lets the scheduler pull the long-lived field loads
 * (n, type, cols, rows) above the stores into p, as in the image.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Cfg {
    u32 size;
    u32 texSize;
    u32 f08;
    void *f0c;
    u32 f10;
    u16 nA;
    u16 nB;
    u32 f18;
    u32 f1c;
} Cfg;

extern void FIELD_G3D_MAPPER_LoadTexture(u8 *a, u8 *b, void *c);
extern int FIELD_G3D_MAPPER_CreateGroundAnime(int a, int b, const int *q, int c);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern char gFieldG3dMapperMapTypeTable[];
extern int gFieldG3dMapperSrcName;
extern int FIELD_G3D_MAPPER_ResetCell(u32 a);
extern void FIELD_G3D_MAPPER_InitSlotRes(int *dst, char *src, int a, int b);
struct Mgr;
extern struct Mgr *FIELD_G3D_MAP_Create(const struct Cfg *cfg, u32 heap);
extern void FIELD_G3D_MAP_OpenArchive(u8 *p, int a, int b);
extern void FIELD_G3D_MAP_SetAltTextureRes(char *p, int v);
extern void FIELD_G3D_MAP_SetPlacedModels(char *p, int v);
extern u8 *FIELD_BUILDMODEL_GetHandleTable(u8 *p);

typedef struct Src {
    int f00;
    int f04;
    u16 cols;
    u16 rows;
    u32 type;
    int f10;
    u16 f14;
    u16 f16;
    u32 n;
    int f1c;
    int f20;
    int f24[2];
    int f2c[2];
    int f34;
    u8 f38;
} Src;

typedef struct Obj {
    u16 heap;
    u16 pad02;
    int f04;
    int f08;
    u32 type;
    int f10;
    u16 f14;
    u16 f16;
    u32 n;
    int f1c;
    int f20;
    u8 *f24;
    void *f28;
    u8 f2c;
    u8 f2d;
    u16 f2e;
    u8 pad30[0x40 - 0x30];
    u8 f40;
    u8 pad41;
    u8 f42;
    u8 f43;
    void *f44;
    u8 pad48[0x60 - 0x48];
    int f60;
    int f64;
    int f68;
} Obj;

void FIELD_G3D_MAPPER_Setup(Obj *p, const Src *src, void *c)
{
    Cfg cfg;
    int i;
    int off;
    int h;

    p->f04 = src->f00;
    p->f08 = src->f04;
    p->f10 = src->f10;
    p->f14 = src->f14;
    p->f16 = src->f16;
    p->n = src->n;
    p->type = src->type;
    p->f1c = src->f1c;
    p->f2c = src->cols;
    p->f2d = src->rows;
    p->f2e = src->cols * src->rows;
    p->f40 = src->f38;
    p->f42 = p->f2e;
    p->f43 = p->f2e;
    switch (src->type) {
    case 0:
        if (src->n > p->f2e)
            p->type = 1;
        break;
    case 3:
        if (p->f14 * p->f16 > p->f2e / 2)
            p->type = 1;
        break;
    }
    p->f20 = src->f20;
    FIELD_G3D_MAPPER_LoadTexture((u8 *)p, (u8 *)src, c);
    p->f68 = FIELD_G3D_MAPPER_CreateGroundAnime(p->f2e, p->f60, src->f2c, p->heap);
    cfg.size = src->f34;
    cfg.texSize = 0;
    cfg.f08 = (u32)gFieldG3dMapperMapTypeTable;
    cfg.f0c = 0;
    cfg.f10 = 0x800;
    cfg.nA = 0x20;
    cfg.nB = 0;
    cfg.f18 = 0x1000000;
    cfg.f1c = 0x400000;
    p->f24 = func_02030734(p->heap, p->f2e * 0x28, 1, (const char *)&gFieldG3dMapperSrcName, 0x306);
    p->f28 = func_02030734(p->heap, p->f2e << 4, 1, (const char *)&gFieldG3dMapperSrcName, 0x307);
    p->f44 = func_02030734(p->heap, p->f2e, 1, (const char *)&gFieldG3dMapperSrcName, 0x308);
    for (i = 0; i < p->f2e; i++) {
        off = i * 0x28;
        FIELD_G3D_MAPPER_ResetCell((u32)(p->f24 + off + 0x18));
        FIELD_G3D_MAPPER_InitSlotRes((int *)(p->f24 + off + 4), (char *)p, i, p->heap);
        cfg.f0c = p->f24 + off + 4;
        h = (int)FIELD_G3D_MAP_Create(&cfg, p->heap);
        *(int *)(p->f24 + off) = h;
        FIELD_G3D_MAP_OpenArchive((u8 *)h, p->f10, p->heap);
        if (p->f60 != 0)
            FIELD_G3D_MAP_SetAltTextureRes((char *)h, p->f60);
        FIELD_G3D_MAP_SetPlacedModels((char *)h, (int)FIELD_BUILDMODEL_GetHandleTable((u8 *)p->f64));
    }
}
