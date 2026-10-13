/*
 * file:     bmp.c
 * unit:     yes
 * function: BG_SYS_ClearGraphicsMemory, BG_SYS_SetVramBanks, BG_SYS_ClearMainBgPlanes, BG_SYS_ClearMainObjPlane, BG_SYS_ClearMainPlanes, BG_SYS_SetMainPlaneVisible, BG_SYS_SetMainVisiblePlanes, BG_SYS_ClearSubBgPlanes, BG_SYS_ClearSubObjPlane, BG_SYS_ClearSubPlanes, BG_SYS_SetSubPlaneVisible, BG_SYS_SetSubVisiblePlanes, BG_SYS_ResetSubDisplay, func_0204363C, func_02043658, BG_SYS_GetSubVisiblePlanes, BMP_Create, BMP_CreateFromBuffer, BMP_CreateFromVram, BMP_Delete, BMP_GetPixels, BMP_GetWidth, BMP_GetHeight, BMP_GetByteSize, BMP_CopyPixels, BMP_CreateFromArchive, BMP_InitFromCharData, BMP_GetTileBytes, BMP_Blit, BMP_BlitPaletteOffset, BMP_FillRect, BMP_Clear, BMP_Blit4bpp, BMP_Blit8bpp, BMP_Blit4bppTo8bpp, BMP_Blit4bppToVram, BMP_Blit8bppToVram, BMP_FillRect4bpp, BMP_FillRect8bpp, BMP_FillRect4bppVram, BMP_FillRect8bppVram, BMP_ConvertToLinear, BMP_WIN_Init, BMP_WIN_Exit, BMP_WIN_Create, BMP_WIN_CreateAt, func_02045210, BMP_WIN_Delete, BMP_WIN_TransferChars, BMP_WIN_MakeScreen, BMP_WIN_DrawFrame, BMP_WIN_ClearScreen, BMP_WIN_GetBgLayer, BMP_WIN_GetWidth, BMP_WIN_GetHeight, BMP_WIN_GetDispWidth, BMP_WIN_GetDispHeight, BMP_WIN_GetPosX, BMP_WIN_GetPosY, BMP_WIN_GetCharOffset, BMP_WIN_GetBmp, BMP_WIN_GetPalette, BMP_WIN_SetPosX, BMP_WIN_SetPosY, BMP_WIN_SetDispHeight, BMP_WIN_SetPalette, STRBUF_SetEosChar, STRBUF_Create, STRBUF_Delete, STRBUF_Clear, STRBUF_Copy, STRBUF_Clone, STRBUF_IsEqual, STRBUF_GetLength, STRBUF_Truncate, STRBUF_SetString, STRBUF_SetStringN, STRBUF_SetChars, STRBUF_ToChars, STRBUF_GetChars, STRBUF_GetEosChar, STRBUF_Append, STRBUF_AppendChar
 * address:  0x0204335C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bmp.c at 0x02045B38 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_020808F4  0x020808F4  arm
 *   func_0208091C  0x0208091C  arm
 *   func_020809A0  0x020809A0  arm
 *   func_020809C8  0x020809C8  arm
 *   func_02080908  0x02080908  arm
 *   func_02080940  0x02080940  arm
 *   func_020809B4  0x020809B4  arm
 *   func_020809F0  0x020809F0  arm
 *   func_02080964  0x02080964  arm
 *   func_02080978  0x02080978  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_02080100  0x02080100  arm
 *   func_020806B0  0x020806B0  arm
 *   func_020807BC  0x020807BC  arm
 *   func_0207FFD0  0x0207FFD0  arm
 *   func_020801F8  0x020801F8  arm
 *   func_0208074C  0x0208074C  arm
 *   func_0208083C  0x0208083C  arm
 *   func_02080294  0x02080294  arm
 *   func_0208040C  0x0208040C  arm
 *   gVisiblePlanes  0x02146A48  data
 *   func_0207D46C  0x0207D46C  arm
 *   func_02030734  0x02030734  arm
 *   bmp_File       0x020A7E68  data
 *   func_020307B0  0x020307B0  arm
 *   ARC_UTIL_LoadMember       0x0204A1BC  arm
 *   func_02062A4C       0x02062A4C  arm
 *   OS_Terminate        0x02088234  arm
 *   MIi_CpuCopy32       0x02082A90  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   sBmpWinHeapRecord     0x02146A50  data
 *   bmpWin_File   0x020A7E70  data
 *   func_0204169C  0x0204169C  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_0203FAF0  0x0203FAF0  arm
 *   sub_0203FB44  0x0203FB44  arm
 *   sub_020416B8  0x020416B8  arm
 *   sub_02040B1C  0x02040B1C  arm
 *   func_02041680  0x02041680  arm
 *   func_020410D0  0x020410D0  arm
 *   func_02041300  0x02041300  arm
 *   sStrbufStatics  0x020A7E7C  data
 *   MI_CpuCopy8  0x02082D44  arm
 */

struct Bmp;
struct CharData;
struct Strbuf;
struct BmpWin;
typedef unsigned int u32;

typedef enum {
    GX_OBJVRAMMODE_CHAR_2D      = 0x00000000,
    GX_OBJVRAMMODE_CHAR_1D_32K  = 0x00000010,
    GX_OBJVRAMMODE_CHAR_1D_64K  = 0x00100010,
    GX_OBJVRAMMODE_CHAR_1D_128K = 0x00200010,
    GX_OBJVRAMMODE_CHAR_1D_256K = 0x00300010
} GXOBJVRamModeChar;

typedef enum { GX_VRAM_NONE = 0 } GXVRam;

struct DispVram {
    GXVRam main_bg;             /* +0x00 */
    GXVRam main_bg_expltt;      /* +0x04 */
    GXVRam sub_bg;              /* +0x08 */
    GXVRam sub_bg_expltt;       /* +0x0C */
    GXVRam main_obj;            /* +0x10 */
    GXVRam main_obj_expltt;     /* +0x14 */
    GXVRam sub_obj;             /* +0x18 */
    GXVRam sub_obj_expltt;      /* +0x1C */
    GXVRam teximage;            /* +0x20 */
    GXVRam texpltt;             /* +0x24 */
    GXOBJVRamModeChar main_mapping;     /* +0x28 */
    GXOBJVRamModeChar sub_mapping;      /* +0x2C */
};

typedef unsigned short u16;

typedef unsigned char u8;

/*
 * Where a bitmap's pixels live (Bmp.storage).  A VRAM destination cannot be
 * written a byte at a time, so the VRAM workers read-modify-write halfwords.
 */
enum {
    BMP_STORAGE_OWNED    = 0,   /* pixel buffer allocated with the Bmp, freed with it */
    BMP_STORAGE_BORROWED = 1,   /* caller's buffer, not freed by BMP_Delete */
    BMP_STORAGE_VRAM     = 2    /* caller's buffer in VRAM, halfword writes only */
};

/* Tile byte sizes (Bmp.tileBytes): one 8x8 tile at 4 and at 8 bits per pixel. */
#define BMP_TILE_BYTES_4BPP 0x20
#define BMP_TILE_BYTES_8BPP 0x40

/*
 * A tiled character bitmap.  width and height are in pixels, the pixels are
 * stored as 8x8 tiles of tileBytes bytes each.
 */
struct Bmp {
    u8  *pixels;     /* 0x00 */
    u16  width;      /* 0x04 */
    u16  height;     /* 0x06 */
    u16  tileBytes;  /* 0x08 */
    u16  storage;    /* 0x0a, BMP_STORAGE_* */
};

typedef signed int     s32;

/* Unpacked character resource (the NNS_G2d character data record). */
struct CharData {
    u16   heightTiles;       /* +0x00 */
    u16   widthTiles;        /* +0x02 */
    u32   pixelFormat;       /* +0x04, 3 = 4bpp, 4 = 8bpp */
    u32   mappingType;       /* +0x08 */
    u32   characterFormat;   /* +0x0C */
    u32   size;              /* +0x10, byte size of rawData */
    void *rawData;           /* +0x14 */
};

typedef signed short   s16_p07;

#define BMP_WIN_MAGIC 0x7fb2

/*
 * A bitmap window: a rectangle of a BG layer backed by a Bmp.  One object
 * for every view the accessors and the constructors take.
 */
struct BmpWin {
    u16 magic : 15;          /* +0x00, BMP_WIN_MAGIC while live */
    u16 is8bpp : 1;          /*        BG layer uses 8bpp characters */
    u8  bgLayer;             /* +0x02 */
    u8  posX;                /* +0x03, in tiles */
    u8  posY;                /* +0x04 */
    u8  width;               /* +0x05, in tiles */
    u8  height;              /* +0x06 */
    u8  dispWidth;           /* +0x07, on-screen extent, starts equal to width */
    u8  dispHeight;          /* +0x08, starts equal to height */
    u8  palette;             /* +0x09 */
    u16 charOffset;          /* +0x0a, first character number in BG VRAM */
    struct Bmp *bmp;         /* +0x0c */
};

/*
 * The data at 0x020A7E7C is one small object, not two independent
 * words: STRBUF_Create loads 0x020A7E80 out of a pool as the allocators
 * fourth argument, and that word is this symbol plus four
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading it as a separate object splits one symbol into two and loses
 * the relocation: 0x020A7E80 has exactly one pool reference image-wide
 * and so no witness of its own, while the base has thirty-six.
 */
struct StrbufStatics {
    u16  eosChar;    /* 0x020A7E7C, the end-of-string code (0xFFFF) */
    u16  pad;
    char file[1];    /* 0x020A7E80, the "strbuf.c" file name handed to the allocator */
};

#define STRBUF_MAGIC 0xB6F8D2ECu

/* A bounded string of u16 characters; chars[] holds capacity entries plus the end code. */
struct Strbuf {
    u16 capacity;    /* +0x00 */
    u16 length;      /* +0x02 */
    u32 magic;       /* +0x04, STRBUF_MAGIC while live */
    u16 chars[1];    /* +0x08 */
};

extern void func_0208068C(u32 banks);
extern void func_02082AC0(u32 data, void *dest, u32 size);
extern void func_02080B98(void);
extern int func_020808F4(void);
extern void func_0207D46C(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern s32 func_02062A4C(void *resource, struct CharData **out);
extern void  OS_Terminate(void);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern u8 func_0204169C(int channel);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern u32 func_0203FAF0(u32 layer, u32 offset, u32 units);
extern void sub_0203FB44(u32 layer, u32 offset, u32 size);
extern u8 sub_020416B8(int channel);
extern void sub_02040B1C(int index, const void *src, u32 size, u32 tile);
extern u8 func_02041680(int channel);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041300(u32 index, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 m);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
void BG_SYS_ClearGraphicsMemory(u32 keepBanks);
void BG_SYS_SetVramBanks(const struct DispVram *banks);
void BG_SYS_ClearMainBgPlanes(void);
void BG_SYS_ClearMainObjPlane(void);
void BG_SYS_ClearMainPlanes(void);
void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
void BG_SYS_SetMainVisiblePlanes(u32 planes);
void BG_SYS_ClearSubBgPlanes(void);
void BG_SYS_ClearSubObjPlane(void);
void BG_SYS_ClearSubPlanes(void);
void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void BG_SYS_SetSubVisiblePlanes(u32 planes);
void BG_SYS_ResetSubDisplay(void);
void func_0204363C(u32 swap);
u32 func_02043658(void);
u32 BG_SYS_GetSubVisiblePlanes(void);
struct Bmp *BMP_Create(u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);
struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);
struct Bmp *BMP_CreateFromVram(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId);
void BMP_Delete(struct Bmp *bmp);
void *BMP_GetPixels(const struct Bmp *bmp);
u16 BMP_GetWidth(const struct Bmp *bmp);
u16 BMP_GetHeight(const struct Bmp *bmp);
u32 BMP_GetByteSize(const struct Bmp *bmp);
void BMP_CopyPixels(const struct Bmp *src, struct Bmp *dst);
struct Bmp *BMP_CreateFromArchive(u32 arcId, u32 memberId, u32 compressed, u32 heapId);
void BMP_InitFromCharData(struct Bmp *bmp, struct CharData *charData, u32 heapId);
u8 BMP_GetTileBytes(struct Bmp *bmp);
void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 w, u32 h, u16 colorKey);
void BMP_BlitPaletteOffset(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 w, u32 h, u16 colorKey, u16 paletteBase);
void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 w, u16 h, u8 value);
void BMP_Clear(struct Bmp *bmp, u8 value);
void BMP_Blit4bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey);
void BMP_Blit8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey);
void BMP_Blit4bppTo8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY, u32 w, u32 h, u16 colorKey, u8 paletteBase);
void BMP_Blit4bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16_p07 dstX, s16_p07 dstY, u16 w, u16 h, u16 colorKey);
void BMP_Blit8bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16_p07 dstX, s16_p07 dstY, u16 w, u16 h, u16 colorKey);
void BMP_FillRect4bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u32 value);
void BMP_FillRect8bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value);
void BMP_FillRect4bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value);
void BMP_FillRect8bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value);
struct Bmp *BMP_ConvertToLinear(struct Bmp *bmp, u32 keepCopy, u16 heapId);
void BMP_WIN_Init(u16 heapId);
void BMP_WIN_Exit(void);
struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir);
struct BmpWin *BMP_WIN_CreateAt(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u32 charOffset);
struct BmpWin *BMP_WIN_Alloc(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u32 charOffset, u8 is8bpp);
u32 BMP_WIN_Delete(struct BmpWin *win);
void BMP_WIN_TransferChars(struct BmpWin *win);
void BMP_WIN_MakeScreen(struct BmpWin *win);
void BMP_WIN_DrawFrame(struct BmpWin *win, u16 baseTile, u32 palette);
void BMP_WIN_ClearScreen(struct BmpWin *win);
u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
u8 BMP_WIN_GetWidth(struct BmpWin *win);
u8 BMP_WIN_GetHeight(struct BmpWin *win);
u8 BMP_WIN_GetDispWidth(struct BmpWin *win);
u8 BMP_WIN_GetDispHeight(struct BmpWin *win);
u8 BMP_WIN_GetPosX(struct BmpWin *win);
u8 BMP_WIN_GetPosY(struct BmpWin *win);
u16 BMP_WIN_GetCharOffset(struct BmpWin *win);
struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
u8 BMP_WIN_GetPalette(struct BmpWin *win);
void BMP_WIN_SetPosX(struct BmpWin *win, u8 posX);
void BMP_WIN_SetPosY(struct BmpWin *win, u8 posY);
void BMP_WIN_SetDispHeight(struct BmpWin *win, u8 dispHeight);
void BMP_WIN_SetPalette(struct BmpWin *win, u8 palette);
void STRBUF_SetEosChar(u16 eosChar);
struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
void STRBUF_Delete(struct Strbuf *strbuf);
void STRBUF_Clear(struct Strbuf *strbuf);
void STRBUF_Copy(struct Strbuf *dst, struct Strbuf *src);
struct Strbuf *STRBUF_Clone(struct Strbuf *src, u32 heapId);
int STRBUF_IsEqual(struct Strbuf *lhs, struct Strbuf *rhs);
u16 STRBUF_GetLength(struct Strbuf *strbuf);
void STRBUF_Truncate(struct Strbuf *strbuf, u32 newLength);
void STRBUF_SetString(struct Strbuf *strbuf, const u16 *srcChars);
void STRBUF_SetStringN(struct Strbuf *strbuf, const u16 *srcChars, u32 charCount);
void STRBUF_SetChars(struct Strbuf *strbuf, const void *srcChars, u32 charCount);
void STRBUF_ToChars(struct Strbuf *strbuf, u16 *out, u32 maxChars);
u16 *STRBUF_GetChars(struct Strbuf *strbuf);
u16 STRBUF_GetEosChar(void);
void STRBUF_Append(struct Strbuf *dst, struct Strbuf *src);
void STRBUF_AppendChar(struct Strbuf *strbuf, u16 ch);
/* [0] = sub engine, [1] = main engine; bit n = BG n, bit 4 = OBJ */
extern u32 gVisiblePlanes[2];
extern const char bmp_File[];       /* "bmp.c" */
extern u16 *sBmpWinHeapRecord;      /* 4-byte block, first halfword = the heap id */
extern const char bmpWin_File[];    /* "bmp_win.c" */
extern struct StrbufStatics sStrbufStatics;



/*
 * Blank the graphics state: disable every VRAM bank the caller's mask does
 * not name, then zero main VRAM (0x06800000, 0xa4000 bytes), both OAM
 * halves (0x07000000 and 0x07000400, filled with 0xc0 so every sprite sits
 * off-screen) and both palette halves (0x05000000 and 0x05000400).
 * func_02082AC0 is the four-byte-granular clear helper, taking the fill
 * word first and the destination second.
 *
 * The 0x1ff mask is never pooled: the compiler already has 0xffff in a
 * register for the complement and rematerialises 0x1ff from it with
 * `sub r0, r1, #0xfe00`
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 */
void BG_SYS_ClearGraphicsMemory(u32 keepBanks)
{
    func_0208068C((keepBanks ^ 0xffff) & 0x1ff);

    func_02082AC0(0, (void *)0x06800000, 0xa4000);
    func_02080B98();

    func_02082AC0(0xc0, (void *)0x07000000, 0x400);
    func_02082AC0(0, (void *)0x05000000, 0x400);
    func_02082AC0(0xc0, (void *)0x07000400, 0x400);
    func_02082AC0(0, (void *)0x05000400, 0x400);
}


extern void func_0208091C(void);   /* GX_ResetBankForBGExtPltt */
extern int func_020809A0(void);
extern void func_020809C8(void);   /* GX_ResetBankForSubBGExtPltt */
extern void func_02080908(void);
extern void func_02080940(void);   /* GX_ResetBankForOBJExtPltt */
extern void func_020809B4(void);
extern void func_020809F0(void);   /* GX_ResetBankForSubOBJExtPltt */
extern int func_02080964(void);
extern void func_02080978(void);
extern void func_0207FDCC(GXVRam v);   /* GX_SetBankForBG */
extern void func_02080100(GXVRam v);   /* GX_SetBankForBGExtPltt */
extern void func_020806B0(GXVRam v);   /* GX_SetBankForSubBG */
extern void func_020807BC(GXVRam v);   /* GX_SetBankForSubBGExtPltt */
extern void func_0207FFD0(GXVRam v);   /* GX_SetBankForOBJ */
extern void func_020801F8(GXVRam v);   /* GX_SetBankForOBJExtPltt */
extern void func_0208074C(GXVRam v);   /* GX_SetBankForSubOBJ */
extern void func_0208083C(GXVRam v);   /* GX_SetBankForSubOBJExtPltt */
extern void func_02080294(GXVRam v);   /* GX_SetBankForTex */
extern void func_0208040C(GXVRam v);   /* GX_SetBankForTexPltt */

#define reg_GX_DISPCNT      (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT  (*(volatile u32 *)0x04001000)

static inline void GX_SetOBJVRamModeChar(GXOBJVRamModeChar mode)
{
    reg_GX_DISPCNT = (u32)(reg_GX_DISPCNT & ~(0x00300000 | 0x00000010) | mode);
}

static inline void GXS_SetOBJVRamModeChar(GXOBJVRamModeChar mode)
{
    reg_GXS_DB_DISPCNT = (u32)(reg_GXS_DB_DISPCNT & ~(0x00300000 | 0x00000010) | mode);
}

/*
 * bg_sys.c: apply a VRAM bank descriptor.  Disable every bank, set the ten
 * bank assignments (TwlSDK GX_SetBankFor*, 0x0207FDCC..0x0208040C), then the
 * main and sub OBJ-VRAM character mapping through the SDK inlines
 * GX_SetOBJVRamModeChar / GXS_SetOBJVRamModeChar (nitro/gx/gx.h).
 *
 * Closed in wave 16 by the SDK-inline lever: the two mapping words are
 * GXOBJVRamModeChar enum fields passed straight into the inlines, and the
 * descriptor is `const`.  With u32 fields and parameters the same body is
 * 33 bytes out; with a non-const or volatile descriptor 29; every earlier
 * spelling (locals a/b, volatile struct) capped at 6 (r3/ip pair in the
 * DISPCNT tail, docs/notes/BG_SYS_SetVramBanks.c.txt).
 */
void BG_SYS_SetVramBanks(const struct DispVram *banks)
{
    func_020808F4();
    func_0208091C();
    func_020809A0();
    func_020809C8();
    func_02080908();
    func_02080940();
    func_020809B4();
    func_020809F0();
    func_02080964();
    func_02080978();
    func_0207FDCC(banks->main_bg);
    func_02080100(banks->main_bg_expltt);
    func_020806B0(banks->sub_bg);
    func_020807BC(banks->sub_bg_expltt);
    func_0207FFD0(banks->main_obj);
    func_020801F8(banks->main_obj_expltt);
    func_0208074C(banks->sub_obj);
    func_0208083C(banks->sub_obj_expltt);
    func_02080294(banks->teximage);
    func_0208040C(banks->texpltt);
    GX_SetOBJVRamModeChar(banks->main_mapping);
    GXS_SetOBJVRamModeChar(banks->sub_mapping);
}


/*
 * The tail of the packet: two one-line mask-downs of the same 32-bit word
 * at +4 of the object that starts at 0x02146A48, and the wrapper that runs
 * both.  Each accessor keeps only the bits its own half owns (0x10 for the
 * first, 0x0f for the second), so calling both in sequence clears the word
 * outright; the wrapper is the reset path.
 *
 * Kept as one unit so the two `bl` sites in BG_SYS_ClearMainPlanes are `local`: they
 * are that pair's only callers image-wide, and split into three files
 * neither could attest the other
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md in
 * reverse).
 */
void BG_SYS_ClearMainBgPlanes(void)
{
    gVisiblePlanes[1] &= 0x10;
}


void BG_SYS_ClearMainObjPlane(void)
{
    gVisiblePlanes[1] &= 0xf;
}


void BG_SYS_ClearMainPlanes(void)
{
    BG_SYS_ClearMainBgPlanes();
    BG_SYS_ClearMainObjPlane();
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * The engine-A visible-plane trio, against gVisiblePlanes[1] and DISPCNT at
 * 0x04000000: toggle one plane only if the requested state differs, replace
 * the whole set, and reset to the one plane in bit 4.  The register address
 * is a rotated ARM immediate here (`mov r2, #0x4000000`), where the
 * engine-B twins at 0x02043598 / 0x020435F4 must pool 0x04001000.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020434DC.c \
 *       --addr 0x020434DC --arm
 */
void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable)
{
    if (enable == 1) {
        if (gVisiblePlanes[1] & mask) {
            return;
        }
    } else if (!(gVisiblePlanes[1] & mask)) {
        return;
    }

    gVisiblePlanes[1] ^= mask;
    *(volatile u32 *)0x04000000 =
        (*(volatile u32 *)0x04000000 & ~0x1f00) | (gVisiblePlanes[1] << 8);
}


void BG_SYS_SetMainVisiblePlanes(u32 planes)
{
    gVisiblePlanes[1] = planes;
    *(volatile u32 *)0x04000000 =
        (*(volatile u32 *)0x04000000 & ~0x1f00) | (planes << 8);
}


void BG_SYS_ClearSubBgPlanes(void)
{
    gVisiblePlanes[0] &= 0x10;
}


/*
 * Two of the engine-B visible-plane mask writers, 0x02043570-0x02043598.
 *
 *   0x02043570  keep only the four background bits of the software copy
 *               gVisiblePlanes[0] (mask 0xF)
 *   0x02043588  the pair call: run the sibling at 0x02043558, which keeps
 *               only bit 4 (the OBJ plane), then the one above, so the two
 *               together clear the software copy outright
 *
 * 0x02043570 has exactly one branch reference image-wide, the `bl` at
 * 0x02043590 inside 0x02043588, so folding the two into one unit costs no
 * witness (docs/idioms/a-unit-attests-only-its-own-start-address.md): the
 * interior address is nobody else's sole witness.
 *
 * The mask constants are plain `and` immediates, not a bitfield: both fit an
 * ARM rotated immediate and neither carries a narrowing shift pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02043570.c \
 *       --addr 0x02043570 --cc 1.1p1 --arm
 */
void BG_SYS_ClearSubObjPlane(void)
{
    gVisiblePlanes[0] &= 0xF;
}


void BG_SYS_ClearSubPlanes(void)
{
    BG_SYS_ClearSubBgPlanes();
    BG_SYS_ClearSubObjPlane();
}


/*
 * The engine-B half of the visible-plane toggle: if the requested state
 * already holds, return; otherwise flip the bit in the software copy at
 * gVisiblePlanes[0] and rewrite bits 8..12 of GXS_DISPCNT (0x04001000) from
 * it.  The engine-A twin at 0x020434DC is the same code against
 * gVisiblePlanes[1] and 0x04000000; that one is materialised with a `mov`
 * because 0x04000000 is an ARM rotated immediate while 0x04001000 is not
 * and costs a pool word.
 *
 * The register address is a cast constant, not a relocation, so this file's
 * only attestable site is gVisiblePlanes.
 */
void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable)
{
    if (enable == 1) {
        if (gVisiblePlanes[0] & mask) {
            return;
        }
    } else if (!(gVisiblePlanes[0] & mask)) {
        return;
    }

    gVisiblePlanes[0] ^= mask;
    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & ~0x1f00) | (gVisiblePlanes[0] << 8);
}


/*
 * Engine-B "replace the whole visible-plane set": store the software copy
 * and rewrite bits 8..12 of GXS_DISPCNT from it.  Twin of BG_SYS_SetMainVisiblePlanes.
 */
void BG_SYS_SetSubVisiblePlanes(u32 planes)
{
    gVisiblePlanes[0] = planes;
    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & ~0x1f00) | (planes << 8);
}


/*
 * Three display-control leaves, 0x0204361C-0x02043668.  The two after the
 * first save no lr, so disasm.py does not label them and they print as a
 * run of `.word`s between literal pools; neither has a branch reference
 * anywhere in the image, so folding them into this unit costs no witness.
 *
 *   0x0204361C  reset the sub engine, then turn on bit 16 of GXS_DISPCNT
 *   0x0204363C  write the LCD-swap bit (bit 15) of POWCNT1 from bit 0 of
 *               the argument; the plain `orr ..., lsl #15` with no
 *               narrowing says this is arithmetic on the register word, not
 *               a one-bit bitfield (which would carry an `lsr #16` shifter
 *               operand, see the bitfield-cast idiom)
 *   0x02043658  read back gVisiblePlanes[1], the main-engine software copy
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204361C.c \
 *       --addr 0x0204361C --cc 1.1p1 --arm
 */
void BG_SYS_ResetSubDisplay(void)
{
    func_0207D46C();
    *(volatile u32 *)0x04001000 |= 0x10000;
}


void func_0204363C(u32 swap)
{
    *(volatile u16 *)0x04000304 =
        (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
}


u32 func_02043658(void)
{
    return gVisiblePlanes[1];
}


/*
 * Read back gVisiblePlanes[0], the sub-engine software copy of the visible
 * plane set that BG_SYS_SetSubVisiblePlanes writes.  Twin of the third leaf in
 * src/matched/unit_0204361C.c, which reads element 1.  Saves no lr, so
 * disasm.py does not label it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_GetSubVisiblePlanes.c \
 *       --func BG_SYS_GetSubVisiblePlanes --addr 0x02043668 --cc 1.1p1 --arm
 */
u32 BG_SYS_GetSubVisiblePlanes(void)
{
    return gVisiblePlanes[0];
}



/*
 * TU: bmp.c.  The __FILE__ pointer at 0x020A7E68 reads "bmp.c", lines 97
 * and 103 here.
 *
 * Allocate a bitmap descriptor and its pixel buffer on the same heap.  The
 * width and height reach the descriptor multiplied by 8 (they arrive in
 * tiles), the buffer is widthTiles * heightTiles * tileBytes bytes, and the descriptor is
 * allocated uncleared while the buffer is cleared.  The `__FILE__` pointer
 * is reloaded into r3 for the second call rather than kept, because r3 is
 * an argument register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Create.c \
 *       --func BMP_Create --addr 0x02043678 --cc 1.1p1 --arm
 */
struct Bmp *BMP_Create(u32 widthTiles, u32 heightTiles, u32 tileBytes, u16 heapId)
{
    struct Bmp *bmp;

    bmp = func_02030734(heapId, sizeof(struct Bmp), 0, bmp_File, 97);

    bmp->width  = widthTiles * 8;
    bmp->height = heightTiles * 8;
    bmp->tileBytes  = tileBytes;

    bmp->pixels = func_02030734(heapId, tileBytes * (widthTiles * heightTiles), 1,
                                bmp_File, 103);
    bmp->storage = BMP_STORAGE_OWNED;

    return bmp;
}



/*
 * TU: bmp.c (__FILE__ 0x020A7E68, line 123).
 *
 * Wrap a pixel buffer the caller already owns in a fresh descriptor: same
 * 0xc-byte descriptor BMP_Create builds, but nothing is allocated for
 * the pixels and the storage halfword at +0x0a is BMP_STORAGE_BORROWED.  The heap id is the fifth
 * argument and arrives on the stack as a halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_CreateFromBuffer.c  *       --func BMP_CreateFromBuffer --addr 0x020436FC --cc 1.1p1 --arm
 */
struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes,
                            u16 heapId)
{
    struct Bmp *bmp;

    bmp = func_02030734(heapId, sizeof(struct Bmp), 0, bmp_File, 123);

    bmp->width  = widthTiles * 8;
    bmp->height = heightTiles * 8;
    bmp->pixels = pixels;
    bmp->tileBytes  = tileBytes;
    bmp->storage   = BMP_STORAGE_BORROWED;

    return bmp;
}



/*
 * TU: bmp.c (__FILE__ 0x020A7E68, line 148).
 *
 * Wrap a pixel buffer the caller already owns in a fresh descriptor: same
 * 0xc-byte descriptor BMP_Create builds, but nothing is allocated for
 * the pixels and the storage halfword at +0x0a is BMP_STORAGE_VRAM.  The heap id is the fifth
 * argument and arrives on the stack as a halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_CreateFromVram.c  *       --func BMP_CreateFromVram --addr 0x02043754 --cc 1.1p1 --arm
 */
struct Bmp *BMP_CreateFromVram(void *pixels, u32 widthTiles, u32 heightTiles, u32 tileBytes,
                            u16 heapId)
{
    struct Bmp *bmp;

    bmp = func_02030734(heapId, sizeof(struct Bmp), 0, bmp_File, 148);

    bmp->width  = widthTiles * 8;
    bmp->height = heightTiles * 8;
    bmp->pixels = pixels;
    bmp->tileBytes  = tileBytes;
    bmp->storage   = BMP_STORAGE_VRAM;

    return bmp;
}



/*
 * Destructor: release the owned buffer at +0x00 first, but only when the
 * halfword count at +0x0a is zero, then release the object itself.  The
 * guard is inverted in the original (`bne` over the first release), which
 * is the source order of a plain `if (bmp->storage == BMP_STORAGE_OWNED)` with no else.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Delete.c \
 *       --func BMP_Delete --addr 0x020437AC --cc 1.1p1 --arm
 */
void BMP_Delete(struct Bmp *bmp)
{
    if (bmp->storage == BMP_STORAGE_OWNED)
        func_020307B0(bmp->pixels);

    func_020307B0(bmp);
}



/*
 * TU: bmp.c.  Accessor for the pixel buffer of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetPixels.c  *       --func BMP_GetPixels --addr 0x020437D4 --cc 1.1p1 --arm
 */
void *BMP_GetPixels(const struct Bmp *bmp)
{
    return bmp->pixels;
}



/*
 * TU: bmp.c.  Accessor for the pixel width of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetWidth.c  *       --func BMP_GetWidth --addr 0x020437DC --cc 1.1p1 --arm
 */
u16 BMP_GetWidth(const struct Bmp *bmp)
{
    return bmp->width;
}



/*
 * TU: bmp.c.  Accessor for the pixel height of a bitmap descriptor.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetHeight.c  *       --func BMP_GetHeight --addr 0x020437E4 --cc 1.1p1 --arm
 */
u16 BMP_GetHeight(const struct Bmp *bmp)
{
    return bmp->height;
}



/*
 * TU: bmp.c.  Byte size of a bitmap's pixel buffer: tileBytes * ((width / 8) * height / 8). The first division is an `lsr` because the width comes out of a u16 field and is known non-negative; the second is a signed `asr` triple because it divides an int product.
 * Saves no lr, so disasm.py leaves it unlabelled and it prints inside a run
 * of `.word`s; it is kept as its own file rather than folded into a unit so
 * that its callers have a `matched` witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetByteSize.c  *       --func BMP_GetByteSize --addr 0x020437EC --cc 1.1p1 --arm
 */
u32 BMP_GetByteSize(const struct Bmp *bmp)
{
    return bmp->tileBytes * ((bmp->width / 8) * bmp->height / 8);
}



/*
 * TU: bmp.c.  Copy one bitmap's pixels over another's, clipped to whichever
 * of the two buffers is smaller.  Both sizes come from BMP_GetByteSize rather
 * than from the descriptors directly, and the comparison is unsigned
 * (`movlo`), so the sizes are u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_CopyPixels.c \
 *       --func BMP_CopyPixels --addr 0x02043814 --cc 1.1p1 --arm
 */
void BMP_CopyPixels(const struct Bmp *src, struct Bmp *dst)
{
    u32 copySize;
    u32 dstSize;

    copySize = BMP_GetByteSize(src);
    dstSize = BMP_GetByteSize(dst);

    if (dstSize < copySize)
        copySize = dstSize;

    MIi_CpuCopy32(src->pixels, dst->pixels, copySize);
}



/*
 * bmp.c's "load a bitmap out of an archive" entry point,
 * 0x0204384C-0x02043900 including its three pool words.  It allocates the
 * twelve-byte bitmap object ("bmp.c", line 266), opens the archive member,
 * asks 0x02062A4C for the decoded header, hands both to the constructor at
 * 0x02043900 and releases the archive handle.  A header that does not
 * resolve is fatal: `OS_Terminate` and then NULL.
 *
 * The archive-handle argument is `(heap & 0x7FFF) | 0x8000` narrowed to a
 * halfword, which is what the `and`/`orr` against the pooled 0x7FFF followed
 * by the `lsl #16`/`lsr #16` pair spells: 0x7FFF is not an ARM rotated
 * immediate and costs a pool word, 0x8000 is one.
 *
 * The zero in r4 is the allocator's alignment argument and the NULL return
 * in one register; it is materialised once, before the call, and survives to
 * the failure epilogue
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * The failure arm falls through the `bne`, so the source tests `== 0` and
 * not the success condition
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to the constructor at 0x02043900 resolves on the `matched` class
 * through src/matched/unit_02043900.c, which lives in this same shard, so
 * `manifest --verify --shard pkt_0204384C` has to run twice from a cold
 * shard: the first pass records 0x02043900 and the second one sees it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204384C.c \
 *       --addr 0x0204384C --cc 1.1p1 --arm
 */
struct Bmp *BMP_CreateFromArchive(u32 arcId, u32 memberId, u32 compressed, u32 heapId)
{
    struct Bmp *bmp;
    void       *resource;
    struct CharData *charData;

    bmp = (struct Bmp *)func_02030734(heapId, sizeof(struct Bmp), 0, bmp_File, 266);
    resource = (void *)ARC_UTIL_LoadMember(arcId, memberId, compressed, (u16)((heapId & 0x7FFF) | 0x8000));
    if (func_02062A4C(resource, &charData) == 0) {
        OS_Terminate();
        return 0;
    }
    BMP_InitFromCharData(bmp, charData, heapId);
    func_020307B0(resource);
    return bmp;
}



/*
 * bmp.c's bitmap constructor, 0x02043900-0x02043994 including its two pool
 * words.  The file-name pool word is 0x020A7E68, which spells "bmp.c", and
 * the line number is 321.  The accessor that follows at 0x02043994 is kept
 * in its own file so its manifest entry survives
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).
 *
 * The header the constructor reads is a resource record: two halfword cell
 * counts at +0 and +2 (stored back multiplied by eight, so the bitmap's +4
 * and +6 are pixel extents and the record's are tiles), a format word at +4,
 * a byte size at +0x10 and the source pointer at +0x14.  Format 3 means a
 * +8 of 0x20 and format 4 means 0x40; anything else leaves +8 untouched.
 *
 * The literal zero is written once into r6 and spends its life as three
 * different things: the allocator's alignment argument, the halfword stored
 * at +0xA, and nothing else
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * The format test is a two-case `switch`, not an `if`/`else if` chain, and
 * the difference is four bytes and the whole tail's schedule: the chain
 * predicates the first arm in place (`moveq`/`strheq` then `beq` over the
 * rest) and needs no joining `b`, while the switch puts the first case out
 * of line at 0x0204396C and reaches the join with the `b` at 0x02043968.
 * With the chain the two stores after the allocation also come out in the
 * other order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02043900.c \
 *       --addr 0x02043900 --cc 1.1p1 --arm
 */
void BMP_InitFromCharData(struct Bmp *bmp, struct CharData *charData, u32 heapId)
{
    bmp->width = charData->widthTiles * 8;
    bmp->height = charData->heightTiles * 8;
    bmp->pixels = func_02030734(heapId, charData->size, 0, bmp_File, 321);
    bmp->storage = BMP_STORAGE_OWNED;
    switch (charData->pixelFormat) {
    case 3:
        bmp->tileBytes = BMP_TILE_BYTES_4BPP;
        break;
    case 4:
        bmp->tileBytes = BMP_TILE_BYTES_8BPP;
        break;
    }
    MIi_CpuCopy32(charData->rawData, bmp->pixels, charData->size);
}




/*
 * bmp.c's accessor for the halfword at +8, the field the blit dispatcher at
 * 0x020439A0 compares between source and destination.  The `ldrh` followed
 * by `and r0, r0, #0xff` is the field's own width against the function's:
 * the field is a halfword and the return type is a byte, so the truncation
 * is at the return, not at the load.  No relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetTileBytes.c \
 *       --func BMP_GetTileBytes --addr 0x02043994 --cc 1.1p1 --arm
 */
u8 BMP_GetTileBytes(struct Bmp *bmp)
{
    return bmp->tileBytes;
}



/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * bmp.c's nine-argument blit dispatcher.  Source and destination bitmaps must agree
 * on the halfword at +8; after that the halfword at +0xA of the destination picks
 * one of two families and the +8 value picks between the 0x20 member of that
 * family and the general one.
 *
 * The two families have different prototypes, and that is what the shift
 * pairs in the second arm are: the 0x020445F4 family takes the two register
 * coordinates and the last two stack arguments as `u16` and the middle two
 * as `s16`, so every one of the six is re-extended at the call
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * does not apply; these are equal-amount pairs, plain narrowing casts).  The
 * 0x02043B98 family takes all nine wide and needs none of it.  This
 * function's own parameters must therefore be the wide types: a `u16`
 * parameter would arrive already extended and the call would not re-extend
 * it.
 *
 * Both branch polarities are the source order
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): the `!= 2` arm
 * falls through, and inside each arm the `== 0x20` arm falls through.  The
 * five outgoing stack stores are written out in both arms of the first
 * family and the compiler tail-merges them ahead of the `cmp`
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md); in the
 * second family it keeps two copies instead, because the narrowing makes the
 * two blocks different lengths.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Blit.c \
 *       --func BMP_Blit --addr 0x020439A0 --cc 1.1p1 --arm
 */
void BMP_Blit(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY,
                   int dstX, int dstY, u32 w, u32 h, u16 colorKey)
{
    if (src->tileBytes != dst->tileBytes) {
        return;
    }
    if (dst->storage != BMP_STORAGE_VRAM) {
        if (src->tileBytes == BMP_TILE_BYTES_4BPP) {
            BMP_Blit4bpp(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey);
        } else {
            BMP_Blit8bpp(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey);
        }
    } else {
        if (src->tileBytes == BMP_TILE_BYTES_4BPP) {
            BMP_Blit4bppToVram(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey);
        } else {
            BMP_Blit8bppToVram(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey);
        }
    }
}



/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * bmp.c's ten-argument forwarder onto 0x0204427C.  The first four arguments
 * pass through in their registers; the six stacked ones are copied down to
 * the outgoing frame, and the last two are re-read narrow: the ninth with a
 * plain `ldrh` (the parameter and the callee's are both halfwords, so the
 * load is the declared width and nothing else is needed) and the tenth with
 * `ldrh` plus `and ip, ip, #0xff`, which is a halfword parameter narrowed to
 * the callee's byte one.  A word parameter narrowed to a byte would have
 * been a single `ldrb` off the home slot, so the `ldrh` is what names the
 * incoming width.
 *
 * Every one of the 72 concrete bytes is reproduced.  The single relocation
 * stays wildcarded: 0x0204427C is called from here and from nowhere else in
 * the image, so the `label` class has no witness outside the compared range,
 * it is not in the manifest, and a one-function range admits no cut.  It
 * closes when 0x0204427C is matched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/BMP_BlitPaletteOffset.c \
 *       --func BMP_BlitPaletteOffset --addr 0x02043AAC --cc 1.1p1 --arm
 */
void BMP_BlitPaletteOffset(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY,
                   u32 dstX, u32 dstY, u32 w, u32 h, u16 colorKey,
                   u16 paletteBase)
{
    BMP_Blit4bppTo8bpp(src, dst, srcX, srcY, dstX, dstY, w, h, colorKey, paletteBase);
}



/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * bmp.c's six-argument fill dispatcher, the single-bitmap sibling of the
 * blit dispatcher at 0x020439A0: the same two-level switch on the source
 * bitmap's +0xA and +8 halfwords, over four workers, but with nothing to
 * narrow, so the two outgoing stack words are one `stm sp, {r4, lr}` written
 * out in each arm rather than a tail-merged run of `str`s.
 *
 * Both `ldrh`s are hoisted ahead of their `cmp`s and the +8 load is issued
 * even on the path that will not use it; that is scheduling, not a third
 * read of the struct.
 *
 * The fall-through arm is the source order in both tests
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): `!= 2` first,
 * then `== 0x20`.
 *
 * Every one of the 104 concrete bytes is reproduced; all four relocations
 * stay wildcarded for the same reason as src/pending/BMP_Blit.c: each of
 * the four fill workers is called from this dispatcher and from nowhere else
 * in the image, so no site has a `label` witness outside the compared range,
 * none of the four is in the manifest, and the range is one function so
 * there is no cut.  0x02044CE0 already has a near-miss note,
 * docs/notes/BMP_FillRect8bpp.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/BMP_FillRect.c \
 *       --func BMP_FillRect --addr 0x02043AF4 --cc 1.1p1 --arm
 */
void BMP_FillRect(struct Bmp *bmp, u32 x, u32 y, u32 w, u16 h, u8 value)
{
    if (bmp->storage != BMP_STORAGE_VRAM) {
        if (bmp->tileBytes == BMP_TILE_BYTES_4BPP) {
            BMP_FillRect4bpp(bmp, x, y, w, h, value);
        } else {
            BMP_FillRect8bpp(bmp, x, y, w, h, value);
        }
    } else {
        if (bmp->tileBytes == BMP_TILE_BYTES_4BPP) {
            BMP_FillRect4bppVram(bmp, x, y, w, h, value);
        } else {
            BMP_FillRect8bppVram(bmp, x, y, w, h, value);
        }
    }
}


/*
 * Clears a tiled character buffer to a constant pixel value.  The tile
 * count is (width/8) * (height/8) and the byte count is that times the
 * per-tile size at +8, 0x20 for 4bpp and 0x40 for 8bpp.  In the 4bpp case
 * the fill value is a nibble, so it is replicated into both halves of the
 * byte before the fill.
 */
void BMP_Clear(struct Bmp *bmp, u8 value)
{
    u32 size = ((u32)bmp->width >> 3) * ((u32)bmp->height >> 3) * bmp->tileBytes;

    if (bmp->tileBytes == BMP_TILE_BYTES_4BPP) {
        value = (value & 0xf) | ((value & 0xf) << 4);
    }

    MI_CpuFill8(bmp->pixels, value, size);
}


static inline s32 ClipBlitRect(struct Bmp *src, const struct Bmp *dst, s32 *srcX, s32 *srcY,
                           s32 *dstX, s32 *dstY, u32 *w, u32 *h)
{
    u32 clippedH = *h;
    u32 clippedW = *w;
    if (clippedW > src->width)
        clippedW = src->width;
    if (*dstX >= dst->width || *dstX <= -(s32)clippedW)
        return 0;
    if (clippedH > src->height)
        clippedH = src->height;
    if (*dstY >= dst->height || *dstY <= -(s32)clippedH)
        return 0;
    if (*dstX < 0) {
        clippedW += *dstX;
        *srcX -= *dstX;
        *dstX = 0;
    } else if (*dstX + clippedW > dst->width) {
        clippedW -= *dstX + clippedW - dst->width;
    }
    if (*dstY < 0) {
        clippedH += *dstY;
        *srcY -= *dstY;
        *dstY = 0;
    } else if (*dstY + clippedH > dst->height) {
        clippedH -= *dstY + clippedH - dst->height;
    }
    *w = clippedW;
    *h = clippedH;
    return 1;
}


/*
 * bmp.c blit worker, 4bpp tiled source onto a 4bpp tiled destination,
 * byte read-modify-write of one nibble, optional colour key (0xFFFF =
 * none).  The 4bpp sibling of BMP_Blit8bpp (same dispatcher arm, same
 * inlined clip helper, same parameter types) and the byte-store sibling
 * of BMP_Blit4bppToVram.
 *
 * Levers on top of BMP_Blit8bpp's, each measured:
 *   - the store is written `(v << sh) | (*p & (0xf0 >> sh))`: the other
 *     operand order lets the compiler hoist the *p load above the source
 *     read, which costs a spill slot (984 bytes against 948);
 *   - both loops read the source through a pointer q computed BEFORE the
 *     destination pointer, with the source tile-row local assigned first:
 *     the preheader then computes the source row and product first, as the
 *     image does (100 out otherwise).
 */
void BMP_Blit4bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY,
                   u32 w, u32 h, u16 colorKey)
{
    s32 srcRowTiles, dstRowTiles;
    u32 row, col;
    s32 curDstX, curSrcX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    u32 pixel, shift;
    u8 *dstPtr;
    u8 *srcPtr;

    if (!ClipBlitRect(src, dst, &srcX, &srcY, &dstX, &dstY, &w, &h))
        return;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curDstX++, curSrcX++) {
                srcTileY = (srcY * 4) & 0x3fe0;
                srcPtr = (u8 *)((u32)src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0)
                           + srcTileY * srcRowTiles + ((srcY * 4) & 0x1c));
                dstTileY = (dstY * 4) & 0x3fe0;
                dstPtr = (u8 *)((u32)dst->pixels + ((curDstX >> 1) & 3) + ((curDstX * 4) & 0x3fe0)
                           + dstTileY * dstRowTiles);
                dstPtr += (dstY * 4) & 0x1c;
                shift = (u32)(curDstX << 31) >> 29;
                pixel = (*srcPtr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                *dstPtr = (pixel << shift) | (*dstPtr & (0xf0 >> shift));
            }
    } else {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curSrcX++, curDstX++) {
                srcKeyedTileY = (srcY * 4) & 0x3fe0;
                srcPtr = (u8 *)((u32)src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0)
                           + srcKeyedTileY * srcRowTiles + ((srcY * 4) & 0x1c));
                dstKeyedTileY = (dstY * 4) & 0x3fe0;
                dstPtr = (u8 *)((u32)dst->pixels + ((curDstX >> 1) & 3) + ((curDstX * 4) & 0x3fe0)
                           + dstKeyedTileY * dstRowTiles);
                dstPtr += (dstY * 4) & 0x1c;
                pixel = (*srcPtr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                if (pixel != colorKey) {
                    shift = (u32)(curDstX << 31) >> 29;
                    *dstPtr = (pixel << shift) | (*dstPtr & (0xf0 >> shift));
                }
            }
    }
}


/*
 * bmp.c blit worker, 8bpp tiled source onto an 8bpp tiled destination,
 * byte stores, optional colour key (0xFFFF = none).  Reached from the blit
 * dispatcher BMP_Blit's first arm (destination not in VRAM), which passes all nine
 * arguments wide; the key is ldrh'd off the stack here, so it is u16 on
 * this side.
 *
 * The prologue is an inlined clip helper returning a flag (the image's
 * mov r4,#0 / mov r4,#1 / cmp r4,#0).  Width and height are clamped to the
 * source, the destination origin is rejected when fully outside, and a
 * negative origin is folded into the width/height and the source origin.
 * All the comparisons against the clipped extents are unsigned
 * (movhi/subhi) and those against the destination origin signed (bge/bgt),
 * which is what fixes the u32 extents and the s32 origins.
 *
 * Levers, each measured (compiled bytes out):
 *   - dst is `const struct Surf *` in the helper: that is what makes the
 *     compiler re-read dst->width after the clip (812 bytes without);
 *   - the helper reads *h BEFORE *w into its locals (88 out; 701 the
 *     other way);
 *   - the keyed loop reads the source through a pointer q and tests *q
 *     (14 out; a u8 temporary gives 65 and a different schedule);
 *   - the inner loop headers: dxx before xx in the initialisers, and the
 *     keyed loop steps xx before dxx (a three-register rotation, 12 -> 4
 *     -> 0);
 *   - the address arithmetic is the family's single integer sum over
 *     (u32)pixels (BMP_FillRect8bpp) with one tile-row local per address.
 */
void BMP_Blit8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY,
                   u32 w, u32 h, u16 colorKey)
{
    s32 srcRowTiles, dstRowTiles;
    u32 row, col;
    s32 curDstX, curSrcX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    u8 pixel;
    u8 *dstPtr;
    u8 *srcPtr;

    if (!ClipBlitRect(src, dst, &srcX, &srcY, &dstX, &dstY, &w, &h))
        return;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curDstX++, curSrcX++) {
                srcTileY = (srcY * 8) & 0x7fc0;
                pixel = *(u8 *)((u32)src->pixels + (curSrcX & 7) + ((curSrcX * 8) & 0x7fc0)
                            + srcTileY * srcRowTiles + ((srcY * 8) & 0x38));
                dstTileY = (dstY * 8) & 0x7fc0;
                *(u8 *)((u32)dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0)
                        + dstTileY * dstRowTiles + ((dstY * 8) & 0x38)) = pixel;
            }
    } else {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curSrcX++, curDstX++) {
                srcKeyedTileY = (srcY * 8) & 0x7fc0;
                srcPtr = (u8 *)((u32)src->pixels + (curSrcX & 7) + ((curSrcX * 8) & 0x7fc0)
                           + srcKeyedTileY * srcRowTiles + ((srcY * 8) & 0x38));
                dstKeyedTileY = (dstY * 8) & 0x7fc0;
                dstPtr = (u8 *)((u32)dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0)
                           + dstKeyedTileY * dstRowTiles);
                dstPtr += (dstY * 8) & 0x38;
                if (*srcPtr != colorKey)
                    *dstPtr = *srcPtr;
            }
    }
}



/*
 * bmp.c blit worker, 4bpp tiled source expanded onto an 8bpp tiled
 * destination with a palette offset: every source nibble is widened to a
 * byte and `pal` is added to it unless it is zero.  With key == 0xFFFF every
 * pixel is stored (a zero nibble stays zero); otherwise zero nibbles are
 * skipped.  Reached only through the forwarder BMP_BlitPaletteOffset, whose narrowing
 * loads fix the u16 key and u8 pal.  Same inlined clip helper and parameter
 * types as BMP_Blit4bpp / BMP_Blit8bpp; source-side masks are the 4bpp ones
 * (0x3fe0 / 0x1c), destination-side the 8bpp ones (0x7fc0 / 0x38).
 *
 * Three levers in the keyed loop, each measured against
 * docs/notes/pkt_02043B98.c.txt's 276-byte best:
 *   - the source pointer is computed BEFORE the destination pointer (as in
 *     BMP_Blit4bpp) and the keyed store is `v += pal; *p = v;` inside the
 *     braces: 888 bytes, 114 out (q-then-p with `*p = v + pal` is 880);
 *   - `xx * 4` bound to a named temporary (`xx4`) in the keyed loop:
 *     4 out (tools/permuter.py anneal, then ablated to this one lever);
 *   - the keyed source pointer is plain pointer arithmetic on src->pixels,
 *     not the `(u32)` sum: that fixes the last `add`/`ldrb` operand order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Blit4bppTo8bpp.c \
 *       --func BMP_Blit4bppTo8bpp --addr 0x0204427C --cc 1.1p1 --arm
 */
void BMP_Blit4bppTo8bpp(struct Bmp *src, struct Bmp *dst, s32 srcX, s32 srcY, s32 dstX, s32 dstY,
                   u32 w, u32 h, u16 colorKey, u8 paletteBase)
{
    s32 srcRowTiles, dstRowTiles;
    u32 row, col;
    s32 curDstX, curSrcX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    u32 pixel;
    u8 *dstPtr;
    u8 *srcPtr;
    s32 srcX4;

    if (!ClipBlitRect(src, dst, &srcX, &srcY, &dstX, &dstY, &w, &h))
        return;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curDstX++, curSrcX++) {
                srcTileY = (srcY * 4) & 0x3fe0;
                srcPtr = (u8 *)((u32)src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0)
                           + srcTileY * srcRowTiles + ((srcY * 4) & 0x1c));
                dstTileY = (dstY * 8) & 0x7fc0;
                dstPtr = (u8 *)((u32)dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0)
                           + dstTileY * dstRowTiles);
                dstPtr += (dstY * 8) & 0x38;
                pixel = (*srcPtr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                if (pixel != 0)
                    pixel += paletteBase;
                *dstPtr = pixel;
            }
    } else {
        for (row = 0; row < h; row++, srcY++, dstY++)
            for (col = 0, curDstX = dstX, curSrcX = srcX; col < w; col++, curSrcX++, curDstX++) {
                srcKeyedTileY = (srcY * 4) & 0x3fe0;
                dstKeyedTileY = (dstY * 8) & 0x7fc0;
                srcX4 = curSrcX * 4;
                srcPtr = src->pixels + ((curSrcX >> 1) & 3) + (srcX4 & 0x3fe0) + srcKeyedTileY * srcRowTiles
                    + ((srcY * 4) & 0x1c);
                dstPtr = (u8 *)((u32)dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0)
                           + dstKeyedTileY * dstRowTiles);
                dstPtr += (dstY * 8) & 0x38;
                pixel = (*srcPtr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                if (pixel != 0) {
                    pixel += paletteBase;
                    *dstPtr = pixel;
                }
            }
    }
}



/*
 * bmp.c blit worker, 4bpp tiled source onto a 4bpp tiled destination that
 * is written a HALFWORD at a time (BMP_FillRect4bppVram's read-modify-write
 * store), with an optional colour key (0xFFFF = none).  Reached from the
 * blit dispatcher BMP_Blit's VRAM-destination arm, whose shift pairs give
 * the narrow parameter types (x, y, w, h u16; dx, dy s16); the key is
 * loaded with ldrh here, so it is u16 on this side.  The plain and keyed
 * loops are written out in full, each with its OWN pair of tile-row
 * locals (sharing one pair across both loops costs ~150 bytes of
 * allocation).
 *
 * The clip against the destination goes through a fresh temporary t.
 * Reusing xend/yend for the difference makes the compiler emit the
 * conditional add with the reused variable as the first operand
 * (add fp, r5, r2) where the image has add fp, r2, r5; that was the
 * last 4 bytes.
 */
void BMP_Blit4bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16_p07 dstX, s16_p07 dstY, u16 w, u16 h, u16 colorKey)
{
    s32 srcXEnd, srcYEnd, srcRowTiles, dstRowTiles;
    s32 curSrcY, curSrcX, curDstY, curDstX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    u32 srcAddr, dstAddr;
    s32 dstOdd;
    u32 word;
    u16 highByte, lowByte;
    s32 dstRoom;
    u32 pixel, shift;
    dstRoom = dst->width - dstX;
    if (dstRoom < w)
        srcXEnd = srcX + dstRoom;
    else
        srcXEnd = w + srcX;
    dstRoom = dst->height - dstY;
    if (dstRoom < h)
        srcYEnd = srcY + dstRoom;
    else
        srcYEnd = h + srcY;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (curSrcY = srcY, curDstY = dstY; curSrcY < srcYEnd; curSrcY++, curDstY++)
            for (curSrcX = srcX, curDstX = dstX; curSrcX < srcXEnd; curSrcX++, curDstX++)
                if (curDstX >= 0 && curDstY >= 0) {
                    srcTileY = (curSrcY * 4) & 0x3fe0;
                    srcAddr = (u32)src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0) + srcTileY * srcRowTiles;
                    srcAddr += (curSrcY * 4) & 0x1c;
                    dstTileY = (curDstY * 4) & 0x3fe0;
                    dstAddr = (u32)dst->pixels + ((curDstX >> 1) & 3) + ((curDstX * 4) & 0x3fe0) + dstTileY * dstRowTiles;
                    dstAddr += (curDstY * 4) & 0x1c;
                    if (dstAddr & 1) {
                        dstAddr -= 1;
                        dstOdd = 1;
                    } else
                        dstOdd = 0;
                    word = *(u16 *)dstAddr;
                    highByte = word >> 8;
                    lowByte = word & 0xff;
                    pixel = (*(u8 *)srcAddr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                    shift = (u32)(curDstX << 31) >> 29;
                    if (dstOdd == 0)
                        *(u16 *)dstAddr = (((0xf0 >> shift) & lowByte) | (pixel << shift)) | (highByte << 8);
                    else
                        *(u16 *)dstAddr = (((highByte & (0xf0 >> shift)) | (pixel << shift)) << 8) | lowByte;
                }
    } else {
        for (curSrcY = srcY, curDstY = dstY; curSrcY < srcYEnd; curSrcY++, curDstY++)
            for (curSrcX = srcX, curDstX = dstX; curSrcX < srcXEnd; curSrcX++, curDstX++)
                if (curDstX >= 0 && curDstY >= 0) {
                    srcKeyedTileY = (curSrcY * 4) & 0x3fe0;
                    srcAddr = (u32)src->pixels + ((curSrcX >> 1) & 3) + ((curSrcX * 4) & 0x3fe0) + srcKeyedTileY * srcRowTiles;
                    srcAddr += (curSrcY * 4) & 0x1c;
                    dstKeyedTileY = (curDstY * 4) & 0x3fe0;
                    dstAddr = (u32)dst->pixels + ((curDstX >> 1) & 3) + ((curDstX * 4) & 0x3fe0) + dstKeyedTileY * dstRowTiles;
                    dstAddr += (curDstY * 4) & 0x1c;
                    if (dstAddr & 1) {
                        dstAddr -= 1;
                        dstOdd = 1;
                    } else
                        dstOdd = 0;
                    word = *(u16 *)dstAddr;
                    highByte = word >> 8;
                    lowByte = word & 0xff;
                    pixel = (*(u8 *)srcAddr >> ((u32)(curSrcX << 31) >> 29)) & 0xf;
                    if (pixel != colorKey) {
                        shift = (u32)(curDstX << 31) >> 29;
                        if (dstOdd == 0)
                            *(u16 *)dstAddr = (((0xf0 >> shift) & lowByte) | (pixel << shift)) | (highByte << 8);
                        else
                            *(u16 *)dstAddr = (((highByte & (0xf0 >> shift)) | (pixel << shift)) << 8) | lowByte;
                    }
                }
    }
}



/*
 * bmp.c blit worker, 8bpp tiled source onto an 8bpp tiled destination
 * written a HALFWORD at a time: when the destination byte is odd the
 * store covers it and the byte before, both taken from the source pair
 * ending at the source pixel; otherwise the source pair starting at it.
 * Optional colour key (0xFFFF = none), compared against the source byte.
 * Reached from BMP_Blit's VRAM-destination arm (x, y, w, h u16; dx, dy s16;
 * the key is ldrh'd, so u16 here).
 *
 * The same four levers as BMP_Blit4bppToVram, all measured:
 *   - the address is one integer sum over (u32)pixels with the in-tile
 *     row added afterwards;
 *   - each of the four tile-row masks has its own function-scope local
 *     (shared locals: 149 out; none: 31);
 *   - in the odd arm d is decremented BEFORE the two loads, which keeps
 *     the shared first load in each arm (326 out otherwise);
 *   - the clip goes through a fresh temporary t with u16 x/y; reusing
 *     xend/yend flips the operands of the conditional add (4 out), and
 *     a fresh t with s32 x/y reshuffles the allocation (167 out).
 */
void BMP_Blit8bppToVram(struct Bmp *src, struct Bmp *dst, u16 srcX, u16 srcY, s16_p07 dstX, s16_p07 dstY, u16 w, u16 h, u16 colorKey)
{
    s32 srcXEnd, srcYEnd, srcRowTiles, dstRowTiles;
    s32 curSrcY, curSrcX, curDstY, curDstX;
    s32 srcTileY, dstTileY, srcKeyedTileY, dstKeyedTileY;
    u32 srcAddr, dstAddr;
    u16 word;
    s32 dstRoom;
    dstRoom = dst->width - dstX;
    if (dstRoom < w)
        srcXEnd = srcX + dstRoom;
    else
        srcXEnd = w + srcX;
    dstRoom = dst->height - dstY;
    if (dstRoom < h)
        srcYEnd = srcY + dstRoom;
    else
        srcYEnd = h + srcY;
    srcRowTiles = (src->width + (src->width & 7)) >> 3;
    dstRowTiles = (dst->width + (dst->width & 7)) >> 3;
    if (colorKey == 0xffff) {
        for (curSrcY = srcY, curDstY = dstY; curSrcY < srcYEnd; curSrcY++, curDstY++)
            for (curSrcX = srcX, curDstX = dstX; curSrcX < srcXEnd; curSrcX++, curDstX++)
                if (curDstX >= 0 && curDstY >= 0) {
                    srcTileY = (curSrcY * 8) & 0x7fc0;
                    srcAddr = (u32)src->pixels + (curSrcX & 7) + ((curSrcX * 8) & 0x7fc0) + srcTileY * srcRowTiles;
                    srcAddr += (curSrcY * 8) & 0x38;
                    dstTileY = (curDstY * 8) & 0x7fc0;
                    dstAddr = (u32)dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0) + dstTileY * dstRowTiles;
                    dstAddr += (curDstY * 8) & 0x38;
                    if (dstAddr & 1) {
                        dstAddr -= 1;
                        word = (((u8 *)srcAddr)[0] << 8) | ((u8 *)srcAddr)[-1];
                    } else {
                        word = ((u8 *)srcAddr)[0] | (((u8 *)srcAddr)[1] << 8);
                    }
                    *(u16 *)dstAddr = word;
                }
    } else {
        for (curSrcY = srcY, curDstY = dstY; curSrcY < srcYEnd; curSrcY++, curDstY++)
            for (curSrcX = srcX, curDstX = dstX; curSrcX < srcXEnd; curSrcX++, curDstX++)
                if (curDstX >= 0 && curDstY >= 0) {
                    srcKeyedTileY = (curSrcY * 8) & 0x7fc0;
                    srcAddr = (u32)src->pixels + (curSrcX & 7) + ((curSrcX * 8) & 0x7fc0) + srcKeyedTileY * srcRowTiles;
                    srcAddr += (curSrcY * 8) & 0x38;
                    dstKeyedTileY = (curDstY * 8) & 0x7fc0;
                    dstAddr = (u32)dst->pixels + (curDstX & 7) + ((curDstX * 8) & 0x7fc0) + dstKeyedTileY * dstRowTiles;
                    dstAddr += (curDstY * 8) & 0x38;
                    if (dstAddr & 1) {
                        dstAddr -= 1;
                        word = (((u8 *)srcAddr)[0] << 8) | ((u8 *)srcAddr)[-1];
                    } else {
                        word = ((u8 *)srcAddr)[0] | (((u8 *)srcAddr)[1] << 8);
                    }
                    if (*(u8 *)srcAddr != colorKey)
                        *(u16 *)dstAddr = word;
                }
    }
}



/*
 * bmp.c fill worker, 4bpp tiled (two pixels per byte), reached from the
 * fill dispatcher BMP_FillRect.  Clips right/bottom before the loops and
 * left/top per pixel (signed cmp/cmpge/blt triple), then merges the
 * nibble: odd x takes the high nibble, even x the low one.
 *
 * THE LEVERS (2026-09-22, wave 10), each measured:
 *   - the address is one integer sum over (u32)s->pixels, with only the
 *     tile-row mask lifted into a function-scope local (same lever as
 *     BMP_FillRect8bpp);
 *   - the in-tile row is added to the POINTER afterwards (`p += ...`),
 *     which is what makes the load/store `[p, row]` rather than
 *     `[row, p]` (6 out when it is a fifth term of the sum);
 *   - `hi = value << 4` is assigned INSIDE the guarded body.  LICM then
 *     hoists the shift out of both loops but the `(u8)` narrowing only
 *     one level, so the raw shift is live across the outer loop and is
 *     spilled together with tilesWide: that one extra value is the whole
 *     `sub sp, sp, #8` frame the earlier passes could not reach (208
 *     bytes with hi computed once before the loops);
 *   - the even arm's `(u8)(*p & 0xf0)` is the unfolded `and #0xff`.
 */
void BMP_FillRect4bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u32 value)
{
    s32 row;
    s32 col;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileRowOffset;
    u8 *pixelPtr;
    u32 highNibble;

    if (right > bmp->width)
        right = bmp->width;
    if (bottom > bmp->height)
        bottom = bmp->height;
    tilesWide = (bmp->width + (bmp->width & 7)) >> 3;

    for (row = y; row < bottom; row++)
        for (col = x; col < right; col++)
            if (col >= 0 && row >= 0) {
                highNibble = value << 4;
                tileRowOffset = (row * 4) & 0x3fe0;
                pixelPtr = (u8 *)((u32)bmp->pixels + ((col >> 1) & 3) + ((col * 4) & 0x3fe0)
                           + tileRowOffset * tilesWide);
                pixelPtr += (row * 4) & 0x1c;
                if (col & 1)
                    *pixelPtr = (*pixelPtr & 0x0f) | (u8)highNibble;
                else
                    *pixelPtr = (u8)(*pixelPtr & 0xf0) | value;
            }
}



/*
 * bmp.c fill worker (8bpp tiled, one byte per pixel), reached from the
 * fill dispatcher BMP_FillRect.  Clips right/bottom against the
 * descriptor before the loops and left/top per pixel (the signed
 * cmp/cmpge/blt triple), then stores the fill byte at the 8x8-tiled
 * address.  0x02044CE0 and 0x02044EBC are byte-identical twins.
 *
 * THE LEVER (2026-09-22, wave 10): the address is ONE integer expression
 * over the pixel pointer cast to u32, evaluated inside the guarded body,
 * with only the tile-row mask lifted into a function-scope local.  The
 * compiler hoists that local and the product out of the inner loop into
 * the preheader AFTER the entry test (the image's placement) but does not
 * fold the tile row and the in-tile row into one mla, which it does for
 * every pointer-arithmetic or subscript spelling.  Pointer arithmetic
 * (u8 *) with the same terms stays at 17 out; the per-row locals of the
 * older best source at 81.
 */
void BMP_FillRect8bpp(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 row;
    s32 col;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileRowOffset;

    if (right > bmp->width)
        right = bmp->width;
    if (bottom > bmp->height)
        bottom = bmp->height;
    tilesWide = (bmp->width + (bmp->width & 7)) >> 3;

    for (row = y; row < bottom; row++)
        for (col = x; col < right; col++)
            if (col >= 0 && row >= 0) {
                tileRowOffset = (row * 8) & 0x7fc0;
                *(u8 *)((u32)bmp->pixels + (col & 7) + ((col * 8) & 0x7fc0)
                        + tileRowOffset * tilesWide + ((row * 8) & 0x38)) = value;
            }
}



/*
 * bmp.c fill worker, 4bpp tiled plotted through a HALFWORD read-modify-
 * write (the pixel's byte is halfword-aligned downward, merged, and the
 * pair stored back with strh).  Reached from BMP_FillRect.
 *
 * Levers (2026-09-22, wave 10), each measured:
 *   - the address is the family's single integer sum over (u32)s->pixels
 *     with the tile-row mask in a function-scope local and the in-tile row
 *     added afterwards (BMP_FillRect4bpp);
 *   - hi/lo are u16 locals of a u32 halfword read: `hi = c >> 8` becomes
 *     the image's lsl #8 / lsr #16, and `lo = c & 0xff` its and / lsl #16
 *     with the lsr #16 folded into every use;
 *   - odd is set inside the `if (a & 1)`, which lets tst/subne and the
 *     movne/moveq pair share one flag setting;
 *   - the even arm is written first (`odd == 0`), the fall-through order;
 *   - right is computed and clamped BEFORE bottom is computed: bottom lives
 *     in its spill slot from its first store, and initialising both up
 *     front adds a reload (312 bytes).
 */
void BMP_FillRect4bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 row;
    s32 col;
    s32 right;
    s32 bottom;
    s32 tilesWide;
    s32 tileRowOffset;
    u32 addr;
    s32 addrOdd;
    u32 word;
    u16 highByte, lowByte;
    u32 shift;

    right = x + w;
    if (right > bmp->width)
        right = bmp->width;
    bottom = y + h;
    if (bottom > bmp->height)
        bottom = bmp->height;
    tilesWide = (bmp->width + (bmp->width & 7)) >> 3;

    for (row = y; row < bottom; row++)
        for (col = x; col < right; col++)
            if (col >= 0 && row >= 0) {
                tileRowOffset = (row * 4) & 0x3fe0;
                addr = (u32)bmp->pixels + ((col >> 1) & 3) + ((col * 4) & 0x3fe0)
                    + tileRowOffset * tilesWide;
                addr += (row * 4) & 0x1c;
                if (addr & 1) {
                    addr -= 1;
                    addrOdd = 1;
                } else
                    addrOdd = 0;
                word = *(u16 *)addr;
                highByte = word >> 8;
                lowByte = word & 0xff;
                shift = (u32)(col << 31) >> 29;
                if (addrOdd == 0)
                    *(u16 *)addr = (((0xf0 >> shift) & lowByte) | (value << shift)) | (highByte << 8);
                else
                    *(u16 *)addr = (((highByte & (0xf0 >> shift)) | (value << shift)) << 8) | lowByte;
            }
}



void BMP_FillRect8bppVram(struct Bmp *bmp, s32 x, s32 y, s32 w, u16 h, u8 value)
{
    s32 row;
    s32 col;
    s32 right = x + w;
    s32 bottom = y + h;
    s32 tilesWide;
    s32 tileRowOffset;

    if (right > bmp->width)
        right = bmp->width;
    if (bottom > bmp->height)
        bottom = bmp->height;
    tilesWide = (bmp->width + (bmp->width & 7)) >> 3;

    for (row = y; row < bottom; row++)
        for (col = x; col < right; col++)
            if (col >= 0 && row >= 0) {
                tileRowOffset = (row * 8) & 0x7fc0;
                *(u8 *)((u32)bmp->pixels + (col & 7) + ((col * 8) & 0x7fc0)
                        + tileRowOffset * tilesWide + ((row * 8) & 0x38)) = value;
            }
}



/*
 * bmp.c de-tile entry point: builds a new descriptor of the same extent
 * and tile size, copies the 8x8-tiled pixels of src into it in linear order,
 * and either returns it or (keepCopy == 0) copies it back over src, frees it
 * and returns NULL.
 *
 * WHAT CLOSED IT (wave 12, 2026-09-23), after three passes stuck at 6
 * bytes on the f04/f06 load-register pair: the four extents are u16
 * LOCALS, `w = width / 8` etc.  The `lsl #13 / lsr #16` pair the older
 * sources spelled as `(u32)(f * 8192) >> 16` is simply the u16 truncation
 * of an unsigned divide by 8.  With all four u16 the residue drops to 13,
 * and assigning them in the order h, w, dep, d (height before width) is
 * what gives the image's colouring; declaration order is inert.
 */
struct Bmp *BMP_ConvertToLinear(struct Bmp *bmp, u32 keepCopy, u16 heapId)
{
    struct Bmp *linear;
    s32 index, byteCount;
    u16 widthTiles;
    u16 heightTiles;
    u16 tileRowBytes;
    u16 tileBytes;

    heightTiles = bmp->height / 8;
    widthTiles = bmp->width / 8;
    tileBytes = bmp->tileBytes;
    tileRowBytes = tileBytes / 8;
    linear = BMP_Create(widthTiles, heightTiles, tileBytes, heapId);
    byteCount = widthTiles * heightTiles * tileBytes;
    for (index = 0; index < byteCount; index++) {
        s32 pixelRow, rowOffset, tileColumn, byteInTileRow;
        pixelRow = index / (widthTiles * tileRowBytes);
        rowOffset = index % (widthTiles * tileRowBytes);
        byteInTileRow = rowOffset % tileRowBytes;
        tileColumn = rowOffset / tileRowBytes;
        linear->pixels[index] = bmp->pixels[(pixelRow % 8) * tileRowBytes + byteInTileRow + (pixelRow / 8 * widthTiles + tileColumn) * tileBytes];
    }
    if (keepCopy == 0) {
        BMP_CopyPixels(linear, bmp);
        BMP_Delete(linear);
        linear = 0;
    }
    return linear;
}



/*
 * The one-time init of the BG subsystem's heap record.  Four bytes are
 * allocated on the heap the caller names, the pointer is published in the
 * global at 0x02146A50, and the heap id itself is written back into the
 * first halfword of the block.  Every later allocation in this family reads
 * that halfword back out (see src/matched/BMP_WIN_MakeScreen.c, which spells it
 * (*sBmpWinHeapRecord & 0x7fff) | 0x8000), so the block is the subsystem's record
 * of which heap it owns.
 *
 * The allocator's fourth and fifth arguments are the same debug site string
 * and tag pair used everywhere else in this file; here the tag is 0x4f.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Init.c \
 *       --func BMP_WIN_Init --addr 0x02045088 --cc 1.1p1 --arm
 */
void BMP_WIN_Init(u16 heapId)
{
    u16 *heapRecord = func_02030734(heapId, 4, 0, bmpWin_File, 0x4f);

    sBmpWinHeapRecord = heapRecord;
    *heapRecord = heapId;
}



/*
 * The teardown that pairs with BMP_WIN_Init: free the four-byte heap record
 * published at 0x02146A50 and clear the pointer, doing nothing if it was
 * never allocated.  The idempotent shape (test, free, null out) is why the
 * global is read once into a callee-saved register and stored back through
 * the same register rather than re-loaded from the pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Exit.c \
 *       --func BMP_WIN_Exit --addr 0x020450C8 --cc 1.1p1 --arm
 */
void BMP_WIN_Exit(void)
{
    if (sBmpWinHeapRecord == 0)
        return;

    func_020307B0(sBmpWinHeapRecord);
    sBmpWinHeapRecord = 0;
}



/*
 * Set up a BG layer whose character data is placed at a VRAM offset chosen
 * by the allocator.  func_0204169C says whether the layer is 8bpp; that
 * decides both the flag handed to BMP_WIN_Alloc and whether a cell costs one
 * or two units, and the unit count is scaled by 32 to bytes before
 * func_0203FA08 is asked for room.  A returned -1 (not 0) is the allocator's
 * failure answer, and the function reports failure as 0.
 *
 * BMP_WIN_CreateAt, the next function, is the same routine for the case where
 * the caller already knows the offset: it calls func_0203FAF0 to reserve
 * that exact offset instead, passes a count rather than a byte size, and
 * forwards the caller's offset straight through as BMP_WIN_Alloc's seventh
 * argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Create.c \
 *       --func BMP_WIN_Create --addr 0x020450F0 --cc 1.1p1 --arm
 */
struct BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir)
{
    u8 is8bpp;
    u32 charCount;
    s32 offset;

    if (func_0204169C(bgLayer) == 0) {
        is8bpp = 0;
        charCount = width * height;
    } else {
        is8bpp = 1;
        charCount = width * height * 2;
    }

    offset = func_0203FA08(bgLayer, charCount * 32, allocDir);
    if (offset == -1)
        return 0;

    return BMP_WIN_Alloc(bgLayer, posX, posY, width, height, palette, offset, is8bpp);
}



/*
 * closed:   blocker func_0203FAF0 is now a manifest entry (matched class)
 *
 * Every concrete byte is right; the file is capped at MATCH by one
 * relocation site, the bl to func_0203FAF0 at +0x44.  Blocking evidence
 * class: none available.  0x0203FAF0 has exactly one witness image wide and
 * it is the call inside this very function (--suggest-split reports "the
 * whole range as one file is NOT viable", best partition 0 pieces), so no
 * cut of this range can attest it.  It unsticks the moment either
 * 0x0203FAF0 itself is taken EXACT (the `matched` class) or a second caller
 * of it turns up in another packet.
 *
 * The fixed-offset twin of BMP_WIN_Create: the caller already knows where the
 * layer's character data goes, so func_0203FAF0 is asked to reserve that
 * offset (answering 0 on failure, not -1), the cell count is passed in units
 * rather than scaled to bytes, and the caller's own offset is what reaches
 * BMP_WIN_Alloc as the seventh argument.
 *
 * The 8bpp test and the doubling of the unit count are identical to
 * BMP_WIN_Create; only the missing `lsl #5` and the different failure
 * convention separate the two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_CreateAt.c \
 *       --func BMP_WIN_CreateAt --addr 0x02045180 --cc 1.1p1 --arm
 */
struct BmpWin *BMP_WIN_CreateAt(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u32 charOffset)
{
    u8 is8bpp;
    u32 charCount;

    if (func_0204169C(bgLayer) == 0) {
        is8bpp = 0;
        charCount = width * height;
    } else {
        is8bpp = 1;
        charCount = width * height * 2;
    }

    if (func_0203FAF0(bgLayer, charOffset, charCount) == 0)
        return 0;

    return BMP_WIN_Alloc(bgLayer, posX, posY, width, height, palette, charOffset, is8bpp);
}



/*
 * The constructor shared by BMP_WIN_Create and BMP_WIN_CreateAt: build the
 * sixteen-byte descriptor for one BG layer on the subsystem heap recorded by
 * BMP_WIN_Init, fill in its geometry, and attach the tile buffer
 * BMP_Create hands back.
 *
 *   +0x00  u16  two bitfields: a 15-bit tag set to 0x7fb2, and the 8bpp
 *               flag in bit 15
 *   +0x02  u8   layer
 *   +0x03  u8   screen base
 *   +0x04  u8   character base
 *   +0x05  u8   width in tiles       (also at +0x07)
 *   +0x06  u8   height in tiles      (also at +0x08)
 *   +0x09  u8   palette
 *   +0x0a  u16  character offset in VRAM
 *   +0x0c  void *tile buffer
 *
 * The tag is one 15-bit field, not two adjacent fields of 8 and 7 bits:
 * splitting it produces two read-modify-writes (bic #0xff / orr #0xb2 then
 * bic #0x7f00 / orr #0x7f00) instead of the single masked write the original
 * has, where the constant 0x7fb2 needs two `orr`s only because it is not one
 * ARM immediate.  The 8bpp bit is a second read-modify-write because its
 * assignment is separated from the tag by the byte stores.
 *
 * The width parameter is u8, not u32: assigning a u32 to the two u8 width
 * fields makes the compiler materialise `(u8)width` once with `and #0xff`
 * and store that register twice, where the original stores the incoming
 * register directly.  Same for the width argument of BMP_Create.
 *
 * The 0xffff8000 mask is materialised as `sub r0, fp, #0x8000` off the
 * register already holding the allocator's zero third argument, the
 * rematerialisation idiom in
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Alloc.c \
 *       --func BMP_WIN_Alloc --addr 0x02045210 --cc 1.1p1 --arm
 */
struct BmpWin *BMP_WIN_Alloc(u32 bgLayer, u32 posX, u32 posY,
                             u8 width, u8 height, u8 palette, u32 charOffset,
                             u8 is8bpp)
{
    struct BmpWin *win;
    u32 tileBytes = is8bpp == 0 ? BMP_TILE_BYTES_4BPP : BMP_TILE_BYTES_8BPP;

    win = func_02030734(*sBmpWinHeapRecord, 0x10, 0, bmpWin_File, 0xd5);

    win->magic = BMP_WIN_MAGIC;
    win->bgLayer = bgLayer;
    win->posX = posX;
    win->posY = posY;
    win->width = width;
    win->height = height;
    win->dispWidth = width;
    win->dispHeight = height;
    win->palette = palette;
    win->charOffset = charOffset;
    win->is8bpp = is8bpp;

    win->bmp = BMP_Create(width, height, tileBytes, *sBmpWinHeapRecord);
    return win;
}



/*
 * The descriptor family's destructor: release the payload through
 * sub_0203FB44, release the heap handle through BMP_Delete, then free
 * the descriptor itself with the generic free at 0x020307B0 (the same
 * free STRBUF_Delete tail-calls).
 *
 * The payload size is (win->width * win->height) * 32, doubled when the top bit
 * of the halfword at +0 is set. That bit is a 1-wide bitfield, not a
 * mask: `ldrh` followed by `lsl #16` / `lsrs #31` is the bitfield extract
 * shape (shift the field to the top, then all the way down by 32 minus
 * its width), and a plain `win->is8bpp` mask test folds to a single
 * `tst`. Declaring the halfword as a 15-bit field plus a 1-bit field is
 * what reproduces it.
 *
 * Both arms of the doubling compute the u8 * u8 product themselves, which
 * is why `smulbb` appears twice under opposite predicates rather than
 * once before the test. Writing the shared multiply above the `if` and
 * only the doubling inside it produces one unconditional `smulbb` and a
 * different register assignment throughout; this is
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md seen from
 * the entry side.
 *
 * The whole conditional is predicated, so there is no branch at all: the
 * `s` suffix on the `lsrs` is the test, and the three following
 * instructions carry `eq`/`ne`. Because there is no branch, the only
 * thing that fixes their order is source order: the `eq` arm is emitted
 * first, so the undoubled case has to be written as the `if` and the
 * doubled case as the `else`, even though `if (bit) double` reads more
 * naturally (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Delete.c \
 *       --func BMP_WIN_Delete --addr 0x020452E8 --cc 1.1p1 --arm
 */
u32 BMP_WIN_Delete(struct BmpWin *win)
{
    u32 charCount;

    if (win->is8bpp == 0) {
        charCount = win->width * win->height;
    } else {
        charCount = (win->width * win->height) * 2;
    }
    sub_0203FB44(win->bgLayer, win->charOffset, charCount * 32);
    BMP_Delete(win->bmp);
    return func_020307B0(win);
}



/*
 * One of the descriptor family's two teardown/commit paths (the other is
 * BMP_WIN_Delete immediately before it). It sizes the descriptor's payload
 * as
 *
 *   sub_020416B8(win->bgLayer) * (win->width * win->height)
 *
 * and passes that, the heap handle obtained from d->heap via
 * BMP_GetPixels, and win->charOffset on to sub_02040B1C.
 *
 * The u8 * u8 product compiles to `smulbb`, not `mul`: the compiler knows
 * both operands came from `ldrb` and fit in sixteen bits, so it uses the
 * halfword multiply. The second multiply, against a call result of
 * unknown range, has to be a full `mul`.
 *
 * The product is computed before the BMP_GetPixels call and so has to
 * survive it, which is what buys the callee-saved r4 and turns
 * push {r4, lr} into push {r3, r4, r5, lr}: r5 holds the descriptor
 * pointer across all three calls and r3 is the alignment filler.
 *
 * win->bgLayer is loaded twice, once for each call that takes it, rather than
 * kept in a register: re-reading the field is cheaper than spending a
 * third callee-saved register on it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_TransferChars.c \
 *       --func BMP_WIN_TransferChars --addr 0x02045334 --cc 1.1p1 --arm
 */
void BMP_WIN_TransferChars(struct BmpWin *win)
{
    u32 byteCount;

    byteCount = (win->width * win->height) * sub_020416B8(win->bgLayer);
    sub_02040B1C(win->bgLayer, BMP_GetPixels(win->bmp), byteCount, win->charOffset);
}



/*
 * Fill a rectangle of the screen described by the configuration block with
 * a run of consecutive tile numbers.  func_02041680 says whether the layer
 * is 8bpp (answer 1, one byte per cell) or 16bpp (two bytes per cell, each
 * carrying the palette number from +9 in its top nibble); either way a
 * scratch buffer of w*h cells is allocated from the heap named by the word
 * behind 0x02146A50, filled with an increasing counter seeded from +0xa,
 * handed to func_020410D0 and freed again.
 *
 * The palette nibble is hoisted as `lsl r4, r2, #0x1c` before the branch
 * and consumed as `orr r2, r5, r4, lsr #16` inside the loop: that is one
 * `(x & 0xf) << 12`, split so that only the cheap half stays in the loop,
 * not two separate shifts.
 *
 * The two allocation sites carry different line numbers, 0x133 and 0x13e,
 * and that is load-bearing: give both the same constant and the compiler
 * hoists the single pool load above the branch, which costs one
 * instruction, one pool word and shifts every later pc-relative offset.
 * Eleven source lines apart matches the two arms of one if/else.
 */
void BMP_WIN_MakeScreen(struct BmpWin *win)
{
    u16 charCount = win->width * win->height;
    u32 paletteBits = (win->palette & 0xf) << 12;
    u16 tile = win->charOffset;
    void *cells;
    s32 index;

    if (func_02041680(win->bgLayer) != 1) {
        u16 *chars = func_02030734((u16)((*sBmpWinHeapRecord & 0x7fff) | 0x8000),
                               charCount * 2, 0, bmpWin_File, 0x133);

        cells = chars;
        for (index = 0; index < charCount; index++) {
            chars[index] = tile | paletteBits;
            tile = tile + 1;
        }
    } else {
        u8 *chars = func_02030734((u16)((*sBmpWinHeapRecord & 0x7fff) | 0x8000),
                              charCount, 0, bmpWin_File, 0x13e);

        cells = chars;
        for (index = 0; index < charCount; index++) {
            chars[index] = (u8)tile;
            tile = tile + 1;
        }
    }

    func_020410D0(win->bgLayer, win->posX, win->posY, win->dispWidth,
                  win->dispHeight, (u32)cells, 0, 0, win->width, win->height);
    func_020307B0(cells);
}



/*
 * The eight-piece frame around a window: base tile + 0..7 drawn at the
 * corners and edges one cell outside the on-screen extent (+7/+8), with the
 * palette nibble in the top of each cell unless the layer is 8bpp
 * (func_02041680 answers 1).
 *
 * Closed in wave 15 from a 2-byte residue (`mov r6, r2` against `mov r4,
 * r2`, the image gives pal and the palette bits one register).  Two facts,
 * each flat alone: the palette bits are computed IN PLACE in the pal
 * parameter as two compound statements (`pal &= 0xf; pal <<= 12;`), which
 * is what coalesces pal with its shifted value; and base is a u16
 * parameter (tile number), which restores the image's scheduling of the
 * sixth and seventh calls that the in-place form otherwise disturbs.  A
 * single-expression `pal = (pal & 0xf) << 12` or a separate pn local keeps
 * the 2-byte tie.  Found by tools/permuter.py hill (type:p base u32->u16)
 * from the in-place source.
 */
void BMP_WIN_DrawFrame(struct BmpWin *win, u16 baseTile, u32 palette)
{
    if (func_02041680(win->bgLayer) != 1) {
        palette &= 0xf;
        palette <<= 12;
    } else {
        palette = 0;
    }

    func_02041300(win->bgLayer, (u16)(palette | baseTile), (u8)(win->posX - 1),
                  (u8)(win->posY - 1), 1, 1, 0x11);
    func_02041300(win->bgLayer, (u16)(palette | (baseTile + 1)), win->posX,
                  (u8)(win->posY - 1), win->dispWidth, 1, 0x11);
    func_02041300(win->bgLayer, (u16)(palette | (baseTile + 2)),
                  (u8)(win->posX + win->dispWidth), (u8)(win->posY - 1),
                  1, 1, 0x11);
    func_02041300(win->bgLayer, (u16)(palette | (baseTile + 3)),
                  (u8)(win->posX - 1), win->posY, 1, win->dispHeight, 0x11);
    func_02041300(win->bgLayer, (u16)(palette | (baseTile + 4)),
                  (u8)(win->posX + win->dispWidth), win->posY,
                  1, win->dispHeight, 0x11);
    func_02041300(win->bgLayer, (u16)(palette | (baseTile + 5)),
                  (u8)(win->posX - 1), (u8)(win->posY + win->dispHeight),
                  1, 1, 0x11);
    func_02041300(win->bgLayer, (u16)(palette | (baseTile + 6)), win->posX,
                  (u8)(win->posY + win->dispHeight), win->dispWidth, 1, 0x11);
    func_02041300(win->bgLayer, (u16)(palette | (baseTile + 7)),
                  (u8)(win->posX + win->dispWidth),
                  (u8)(win->posY + win->dispHeight), 1, 1, 0x11);
}



/*
 * A seven-argument forwarder over the descriptor object whose leaf
 * accessor bank is src/matched/unit_02045730.c: it unpacks six u8 fields
 * and a constant zero out of the descriptor and hands them to
 * sub_02041300, which is where the actual work happens.
 *
 *   func_02041300(win->bgLayer, 0, win->posX, win->posY, win->width, win->height, 0)
 *
 * Register arguments are r0..r3, and the remaining three ride the 12-byte
 * stack frame the prologue carves out with `sub sp, sp, #0xc`. The
 * compiler spots that the last two stack slots are adjacent and writes
 * win->width (already in r0) and the zero (already in r1) with a single
 * `stmib sp, {r0, r1}` rather than two stores, which is what makes the
 * second and third stack argument order legible: had the zero been
 * anywhere but last, the store pair would not have fused.
 *
 * The single-register prologue is `stmdb sp!, {lr}` / `ldm sp!, {pc}`
 * rather than push/pop of a pair, because nothing here needs a
 * callee-saved register: every field load feeds its argument slot
 * directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_ClearScreen.c \
 *       --func BMP_WIN_ClearScreen --addr 0x020456F8 --cc 1.1p1 --arm
 */
void BMP_WIN_ClearScreen(struct BmpWin *win)
{
    func_02041300(win->bgLayer, 0, win->posX, win->posY, win->width, win->height, 0);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           BMP_WIN_GetDispHeight, BMP_WIN_GetPosX, BMP_WIN_GetPosY, BMP_WIN_GetCharOffset,
 *           BMP_WIN_GetBmp, BMP_WIN_GetPalette, BMP_WIN_SetPosX, BMP_WIN_SetPosY,
 *           BMP_WIN_SetDispHeight, BMP_WIN_SetPalette
 *
 * The leaf accessor bank of the allocator family's descriptor object.
 * Fourteen relocation-free 8-byte functions in a row, each one load or
 * store of a single field, which is why they can be folded into one unit
 * with no witnesses required at all.
 *
 * The descriptor they read is the argument block the surrounding
 * constructors carry around (BMP_WIN_TransferChars, at the head of this packet,
 * uses the same offsets: +2, +5, +6, +0xa, +0xc). The fields this bank
 * exposes:
 *
 *   +0x02  u8   BMP_WIN_GetBgLayer get
 *   +0x03  u8   BMP_WIN_GetPosX get / BMP_WIN_SetPosX set
 *   +0x04  u8   BMP_WIN_GetPosY get / BMP_WIN_SetPosY set
 *   +0x05  u8   BMP_WIN_GetWidth get
 *   +0x06  u8   BMP_WIN_GetHeight get
 *   +0x07  u8   BMP_WIN_GetDispWidth get
 *   +0x08  u8   BMP_WIN_GetDispHeight get / BMP_WIN_SetDispHeight set
 *   +0x09  u8   BMP_WIN_GetPalette get / BMP_WIN_SetPalette set
 *   +0x0a  u16  BMP_WIN_GetCharOffset get
 *   +0x0c  void *  BMP_WIN_GetBmp get
 *
 * BMP_WIN_GetBmp is the heap-handle getter of this family: the pointer it
 * returns at +0xc is what BMP_WIN_TransferChars feeds to BMP_GetPixels before the
 * allocation call at 0x02040B1C, so +0xc is the descriptor's heap /
 * owning-context handle rather than a payload pointer. It carries the
 * largest fan-in of the whole bank (1149 branch references image-wide),
 * which is consistent with every user of a descriptor reaching for its
 * heap handle.
 *
 * Only BMP_WIN_GetBgLayer, BMP_WIN_GetWidth, BMP_WIN_GetHeight, BMP_WIN_GetDispWidth,
 * BMP_WIN_GetDispHeight, BMP_WIN_GetPosX, BMP_WIN_GetPosY, BMP_WIN_GetCharOffset, BMP_WIN_GetBmp,
 * BMP_WIN_GetPalette and BMP_WIN_SetPalette carry labels in the listing.
 * BMP_WIN_SetPosX, BMP_WIN_SetPosY and BMP_WIN_SetDispHeight are unlabelled followers:
 * they save no lr, so disasm.py folds them into BMP_WIN_GetPalette's extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). They
 * should be seeded into layout/function_starts.txt by the integrator.
 *
 * Field names are left descriptive rather than semantic: this whole
 * family is scheduled for a semantic rename once the allocator's argument
 * shapes settle.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045730.c \
 *       --addr 0x02045730 --arm --cc 1.1p1
 */
u8 BMP_WIN_GetBgLayer(struct BmpWin *win)
{
    return win->bgLayer;
}


u8 BMP_WIN_GetWidth(struct BmpWin *win)
{
    return win->width;
}


u8 BMP_WIN_GetHeight(struct BmpWin *win)
{
    return win->height;
}


u8 BMP_WIN_GetDispWidth(struct BmpWin *win)
{
    return win->dispWidth;
}


u8 BMP_WIN_GetDispHeight(struct BmpWin *win)
{
    return win->dispHeight;
}


u8 BMP_WIN_GetPosX(struct BmpWin *win)
{
    return win->posX;
}


u8 BMP_WIN_GetPosY(struct BmpWin *win)
{
    return win->posY;
}


u16 BMP_WIN_GetCharOffset(struct BmpWin *win)
{
    return win->charOffset;
}


struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win)
{
    return win->bmp;
}


u8 BMP_WIN_GetPalette(struct BmpWin *win)
{
    return win->palette;
}


void BMP_WIN_SetPosX(struct BmpWin *win, u8 posX)
{
    win->posX = posX;
}


void BMP_WIN_SetPosY(struct BmpWin *win, u8 posY)
{
    win->posY = posY;
}


void BMP_WIN_SetDispHeight(struct BmpWin *win, u8 dispHeight)
{
    win->dispHeight = dispHeight;
}


void BMP_WIN_SetPalette(struct BmpWin *win, u8 palette)
{
    win->palette = palette;
}



/*
 * Setter for the allocator family's global u16 stamp at 0x020A7E7C: the
 * value every object of this family copies into its own +0x8 field when
 * it is constructed (STRBUF_Create) or reset (STRBUF_Clear). Those two
 * functions are its readers, and their literal pools at 0x02045804 and
 * 0x02045834 are the outside witnesses for this file's own pool word,
 * which is why the three are kept in separate files rather than folded
 * into one unit: a single tu over 0x020457A0..0x02045838 would swallow
 * every pool copy of the address and cap at MATCH
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * 0x020A7E7C sits immediately before the __FILE__ string at 0x020A7E80
 * that STRBUF_Create passes to the allocator, so it is the last word of
 * data before the packed string area.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetEosChar.c \
 *       --func STRBUF_SetEosChar --addr 0x020457A0 --cc 1.1p1 --arm
 */
void STRBUF_SetEosChar(u16 eosChar)
{
    sStrbufStatics.eosChar = eosChar;
}



/*
 * The constructor of the u16-array object, and a clean specimen of the
 * debug-allocator calling convention this whole family is built on:
 *
 *   func_02030734(heapId, size, clear, site, tag)
 *
 * The fifth argument is a u16 passed on the stack, which the callee reads
 * back with a halfword load at [sp, #0x18]; here it is 100. It looks like
 * a __LINE__-style debug tag, but that is not established: the fourth
 * argument, which would be the matching __FILE__, is 0x020A7E80, and that
 * address is above the arm9 static image end (0x020A6800, from
 * layout/layout.json), so it is BSS, not a string constant in a packed
 * string area. Whatever the pair means, it is not the literal
 * __FILE__/__LINE__ shape of
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md, and it is
 * deliberately not written as such here.
 *
 * The allocation size, 2 * capacity + 0xa, is what pins the object
 * layout: a 0xa-byte header followed by capacity u16 entries.
 *
 *   +0x00  u16  capacity
 *   +0x02  u16  used
 *   +0x04  u32  magic, 0xECD2F8B6 while live
 *   +0x08  u16  stamp, copied from g_020A7E7C
 *   +0x0a  u16  entries[capacity]
 *
 * The zero that becomes the allocator's third argument is the same
 * register that later stores `used = 0`, so the two share one `mov
 * r4, #0`; writing the third argument as a named local instead splits
 * them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Create.c \
 *       --func STRBUF_Create --addr 0x020457B0 --cc 1.1p1 --arm
 */
struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId)
{
    struct Strbuf *strbuf;

    strbuf = (struct Strbuf *)func_02030734(heapId, capacity * 2 + 0xa, 0,
                                        sStrbufStatics.file, 100);
    strbuf->magic = STRBUF_MAGIC;
    strbuf->capacity = (u16)capacity;
    strbuf->length = 0;
    strbuf->chars[0] = sStrbufStatics.eosChar;
    return strbuf;
}



/*
 * The destructor of the u16-array object STRBUF_Create builds: it kills
 * the 0xECD2F8B6 liveness magic at +0x4 and then tail-calls the family's
 * generic free at 0x020307B0, which is the counterpart of the allocation
 * entry at 0x02030734 (it is also what BMP_WIN_Delete finishes with).
 * Clearing the magic before the free is what makes a stale pointer
 * detectable rather than merely dangling.
 *
 * The tail call is the usual shape for this compiler: one section per
 * function means no displacement branch is available, so the target
 * becomes a pool word and a bx
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). The pool word at
 * 0x02045818 is the whole reason the listing extent runs to 0x0204581C.
 *
 * layout/symbols_sdk.json carries the name ENV_SetResourceSet for
 * 0x020307B0. That looks like a signature-matcher false positive rather
 * than a real SDK export (0x020307B0 is game code in arm9_main and its
 * only observed role here is teardown), so the canonical sub_ name is
 * used instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Delete.c \
 *       --func STRBUF_Delete --addr 0x02045808 --cc 1.1p1 --arm
 */
void STRBUF_Delete(struct Strbuf *strbuf)
{
    strbuf->magic = 0;
    func_020307B0(strbuf);
}



/*
 * Resets one of the allocator family's u16-array objects in place: drops
 * the used count back to zero and re-stamps the object from the global at
 * 0x020A7E7C. It is the constructor body of STRBUF_Create minus the
 * allocation, the capacity store and the magic store, so it is the "reuse
 * this buffer" entry of the pair.
 *
 * The object shape, from STRBUF_Create's allocation of 2 * capacity + 0xa
 * bytes:
 *
 *   +0x00  u16  capacity
 *   +0x02  u16  used
 *   +0x04  u32  magic (0xECD2F8B6 when live, 0 once STRBUF_Delete kills it)
 *   +0x08  u16  stamp, copied from g_020A7E7C
 *   +0x0a  u16  entries[capacity]
 *
 * The pool word is attested by the copies in STRBUF_SetEosChar and
 * STRBUF_Create, which is why this function is its own file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Clear.c \
 *       --func STRBUF_Clear --addr 0x0204581C --cc 1.1p1 --arm
 */
void STRBUF_Clear(struct Strbuf *strbuf)
{
    strbuf->length = 0;
    strbuf->chars[0] = sStrbufStatics.eosChar;
}


/*
 * Copies the live part of one u16-array object into another, refusing the
 * copy if the destination cannot hold it. The guard is `capacity <=
 * used`, not `<`, so the destination needs strictly more capacity than
 * the source has entries; the extra slot is the +0x8 stamp, which the
 * copy carries along by starting two bytes before the entry array and
 * moving (used + 1) halfwords.
 *
 * See src/matched/STRBUF_Create.c for the object layout. The trailing
 * `dst->used = src->used` re-reads the field rather than reusing the
 * cached value the guard and the length computation share: the two
 * objects are unrelated pointers, so the MI_CpuCopy8 call may alias
 * src->used and the load cannot be hoisted across it. Writing the tail as
 * an assignment from the cached local instead loses that reload and four
 * bytes with it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Copy.c \
 *       --func STRBUF_Copy --addr 0x02045838 --cc 1.1p1 --arm
 */
void STRBUF_Copy(struct Strbuf *dst, struct Strbuf *src)
{
    u16 length;

    length = src->length;
    if (dst->capacity <= length) {
        return;
    }
    MI_CpuCopy8(&src->chars[0], &dst->chars[0], (length + 1) * 2);
    dst->length = src->length;
}


/*
 * Clones a u16-array object: allocate one with exactly enough room
 * (used + 1 slots, the +1 being the stamp slot that STRBUF_Copy's guard
 * insists on), then copy into it.
 *
 * The heap id is never touched in this function's body. STRBUF_Create
 * takes (capacity, heapId) and only r0 is set up here, so r1 arrives
 * untouched from this function's own second parameter: the shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * read in reverse, where the "leftover" register really is a passed
 * argument and naming it is what makes the code compile to two
 * instructions instead of three.
 *
 * `used + 1` reaches STRBUF_Create with no narrowing, which is what pins
 * that function's first parameter to a full word rather than the u16 its
 * own body would suggest: see
 * docs/idioms/a-missing-truncation-at-the-call-site-widens-the-parameter.md.
 * With a u16 prototype this function comes out eight bytes long and
 * STRBUF_Create still matches, so the call site is the only evidence for
 * the width.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Clone.c  *       --func STRBUF_Clone --addr 0x02045874 --cc 1.1p1 --arm
 */
struct Strbuf *STRBUF_Clone(struct Strbuf *src, u32 heapId)
{
    struct Strbuf *clone;

    clone = STRBUF_Create(src->length + 1, heapId);
    STRBUF_Copy(clone, src);
    return clone;
}


/*
 * Halfword-string equality with the buffer module's terminator stamp: the
 * first element is compared directly, then the loop walks both strings while
 * they agree, succeeding as soon as either side meets the global terminator
 * (0xFFFF) rather than the other buffer.
 *
 * Two shapes are load-bearing:
 *  - `int i = 0;` at its declaration puts the `mov ip, #0` ahead of the
 *    guard's compare; assigning i after the guard lands it after the
 *    terminator pool load instead.
 *  - The guard must NOT be a bare `if (..) return 0;`: mwcc predicates that
 *    into `movne r0, ip; popne {r3, pc}`.  Folding it into one shared exit
 *    (the `if (a->w[0] == b->w[0])` arm holding the loop, a single
 *    `return 0;` after it) makes the guard a real `bne` to that exit, which
 *    is what the image has.  The identical `goto fail` spelling compiles to
 *    the same bytes.
 *
 * The 0x020A7E7C ABS32 sits in this function's own pool (0x020458F4, inside
 * the compared range) and resolves off the `literal` class: the same word is
 * in the pools of the already-matched STRBUF_SetString, STRBUF_SetStringN and
 * STRBUF_SetEosChar.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_IsEqual.c \
 *       --func STRBUF_IsEqual --addr 0x0204589C --cc 1.1p1 --arm
 */
int STRBUF_IsEqual(struct Strbuf *lhs, struct Strbuf *rhs)
{
    int index = 0;

    if (lhs->chars[0] == rhs->chars[0]) {
        do {
            if (lhs->chars[index] == sStrbufStatics.eosChar) {
                return 1;
            }
            index++;
        } while (lhs->chars[index] == rhs->chars[index]);
    }

    return 0;
}


/*
 * Reads the used-slot count of a u16-array object (see
 * src/matched/STRBUF_Create.c for the layout). A relocation-free leaf; it
 * is the public reader for the field STRBUF_Truncate and STRBUF_Copy write
 * directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_GetLength.c  *       --func STRBUF_GetLength --addr 0x020458F8 --cc 1.1p1 --arm
 */
u16 STRBUF_GetLength(struct Strbuf *strbuf)
{
    return strbuf->length;
}


/*
 * Truncates a u16-array object back to `index` slots, writing the stamp
 * into the slot that becomes the new terminator. It is the inverse of
 * whatever appends, and it is a no-op when `index` is not strictly below
 * the current count, so it can only ever shrink.
 *
 * The whole body is predicated on `lo` with no branch at all, which is
 * why the guard has to be an unsigned comparison: `index` is a full u32
 * (nothing masks it before `add r3, r0, r1, lsl #1`) while `used` is a
 * zero-extended u16, so the comparison is unsigned on both sides and a
 * signed `int` index produces `lt` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Truncate.c  *       --func STRBUF_Truncate --addr 0x02045900 --cc 1.1p1 --arm
 */
void STRBUF_Truncate(struct Strbuf *strbuf, u32 newLength)
{
    if (newLength < strbuf->length) {
        strbuf->chars[newLength] = sStrbufStatics.eosChar;
        strbuf->length = newLength;
    }
}



/*
 * strbuf.c's `strcpy`-into-a-bounded-buffer: the terminator is the halfword
 * at 0x020A7E7C (0xFFFF), the buffer's capacity is the halfword at +0 and
 * the count is kept at +2, with the halfword array starting at +8.  The
 * first copy stops on the terminator, the second on a full buffer, and the
 * terminator is always written at the end - which is why the exit block is
 * shared and why the count is re-read there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetString.c \
 *       --func STRBUF_SetString --addr 0x02045924 --cc 1.1p1 --arm
 */
void STRBUF_SetString(struct Strbuf *strbuf, const u16 *srcChars)
{
    strbuf->length = 0;
    while (*srcChars != sStrbufStatics.eosChar) {
        if (strbuf->length >= strbuf->capacity - 1)
            break;
        strbuf->chars[strbuf->length++] = *srcChars;
        srcChars++;
    }
    strbuf->chars[strbuf->length] = sStrbufStatics.eosChar;
}



/*
 * strbuf.c's bounded copy of a counted string: refuse anything longer than
 * the buffer, copy until the source's own terminator shows up or the last
 * usable slot is filled, and only when the whole source was copied (the
 * count landed exactly on n-1) append the terminator.  The `n > cap` guard
 * is a predicated `pophi`, and the final conditional store is the ARM
 * `ldreq`/`addeq`/`strheq` triple.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetStringN.c \
 *       --func STRBUF_SetStringN --addr 0x02045994 --cc 1.1p1 --arm
 */
void STRBUF_SetStringN(struct Strbuf *strbuf, const u16 *srcChars, u32 charCount)
{
    u32 index;

    if (charCount > strbuf->capacity)
        return;

    for (index = 0; index < charCount - 1; index++) {
        strbuf->chars[index] = srcChars[index];
        if (strbuf->chars[index] == sStrbufStatics.eosChar)
            break;
    }

    strbuf->length = index;
    if (index == charCount - 1)
        strbuf->chars[charCount - 1] = sStrbufStatics.eosChar;
}



/*
 * Append n halfwords to a counted buffer: the count is the halfword at +2,
 * the current length is the halfword at +0, the data starts at +8, and the
 * whole thing is halfword-indexed, which is why the copy size is `n * 2`.
 * A null count and an over-long count are both refused, each as its own
 * predicated early return on the entry compare (`movs` for the first, a
 * `pophi` for the unsigned second).
 *
 * The stored count is one less than n, and it is computed from the incoming
 * value rather than by re-reading the field, so it is a subtraction on r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetChars.c \
 *       --func STRBUF_SetChars --addr 0x02045A00 --cc 1.1p1 --arm
 */
void STRBUF_SetChars(struct Strbuf *strbuf, const void *srcChars, u32 charCount)
{
    if (charCount == 0)
        return;
    if (charCount > strbuf->capacity)
        return;

    MI_CpuCopy8(srcChars, strbuf->chars, charCount * 2);
    strbuf->length = charCount - 1;
}



/*
 * Copies at most `n` slots out of a u16-array object into a caller's
 * buffer, stopping after the slot that equals the stamp, and forcing a
 * stamp into the last output slot if the loop ran to the limit without
 * finding one. In other words the stamp is this container's terminator
 * value and this is its bounded, always-terminated extraction.
 *
 * Two shape tells worth keeping:
 *
 *  - The stamp is re-read from the global on every iteration
 *    (`ldrh ip, [r3]` inside the loop, from a pool base hoisted out of
 *    it). It is not volatile: the store into the caller's buffer may
 *    alias it, so the load cannot be hoisted. Caching it in a local
 *    before the loop removes the reload and shortens the body.
 *  - The final store is written as a pointer expression, not a subscript.
 *    `add r1, r1, r2, lsl #1` followed by `strh r0, [r1, #-2]` scales,
 *    adds, then subtracts the element size, which is what
 *    `*(out + n - 1)` produces; `out[n - 1]` folds to a single scaled
 *    offset instead
 *    (docs/idioms/pointer-minus-one-scales-before-the-subtraction.md).
 *
 * The loop is the compiler's usual rotation of a counted `for`: a
 * zero-trip guard at the top, the increment and the bound test at the
 * bottom, and the `break` falling straight into the `i == n` test that
 * distinguishes "found the terminator" from "ran out of room". Because
 * `break` leaves the counter un-incremented, that one comparison is the
 * whole post-condition and no separate flag is needed. The entire tail is
 * predicated on `eq`, so it costs no branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_ToChars.c \
 *       --func STRBUF_ToChars --addr 0x02045A38 --cc 1.1p1 --arm
 */
void STRBUF_ToChars(struct Strbuf *strbuf, u16 *out, u32 maxChars)
{
    u32 index;
    u16 ch;

    for (index = 0; index < maxChars; index++) {
        ch = strbuf->chars[index];
        out[index] = ch;
        if (sStrbufStatics.eosChar == ch) {
            break;
        }
    }
    if (index == maxChars) {
        *(out + maxChars - 1) = sStrbufStatics.eosChar;
    }
}


/*
 * Returns the address of the u16-array object's slot array, which begins
 * at +0x8 with the stamp slot. A single `add r0, r0, #8` and `bx lr`: the
 * function exists only so callers outside this file need not know the
 * header size.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_GetChars.c  *       --func STRBUF_GetChars --addr 0x02045A90 --cc 1.1p1 --arm
 */
u16 *STRBUF_GetChars(struct Strbuf *strbuf)
{
    return strbuf->chars;
}


/*
 * A two-instruction ARM read accessor used all over the ARM9 image (the
 * halfword at 0x020A7E7C, a UI/input mode word).  The literal pool word is
 * attested by sole-ref/data: 0x020A7E7C is a mapped pool-word object with 99
 * referring sites, none of them this 16-byte range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_GetEosChar.c \
 *       --func STRBUF_GetEosChar --addr 0x02045A98 --cc 1.1p1 --arm --region arm9
 */
u16 STRBUF_GetEosChar(void)
{
    return sStrbufStatics.eosChar;
}



/*
 * The two mutators of the u16 vector STRBUF_Create allocates, folded into one
 * translation unit covering 0x02045AA8..0x02045B38 (both functions and the
 * single trailing pool word).  See src/matched/STRBUF_AppendChar.c for the object
 * layout this pair pins down, in particular why the entries begin at +0x8
 * and why one slot past `capacity` is reserved for a terminator.
 *
 * STRBUF_Append concatenates one vector onto another, copying src->used + 1
 * halfwords so that the source's terminator becomes the destination's.
 * STRBUF_AppendChar pushes a single entry and re-plants the terminator behind it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045AA8.c \
 *       --addr 0x02045AA8 --arm
 */
void STRBUF_Append(struct Strbuf *dst, struct Strbuf *src)
{
    u16 count = src->length;

    if (dst->length + count + 1 > dst->capacity)
        return;

    MI_CpuCopy8(&src->chars[0], &dst->chars[dst->length], (count + 1) * 2);
    dst->length = dst->length + src->length;
}


void STRBUF_AppendChar(struct Strbuf *strbuf, u16 ch)
{
    if (strbuf->length + 1 >= strbuf->capacity)
        return;

    strbuf->chars[strbuf->length++] = ch;
    strbuf->chars[strbuf->length] = sStrbufStatics.eosChar;
}
