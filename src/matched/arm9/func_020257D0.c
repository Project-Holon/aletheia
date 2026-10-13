/*
 * unit:     no
 * function: BMP_OAM_UploadChars
 * address:  0x020257D0
 * packet:   pkt_020257D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * status:   EXACT
 *
 * symbols:
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   func_020862F0  0x020862F0  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   CLACT_GetCharacterVramAddress  0x0204ABBC  arm
 *   GX_LoadOBJ     0x0207E780  arm
 *   GXS_LoadOBJ    0x0207E804  arm
 *
 * Upload a tiled bitmap to OBJ VRAM one cell row at a time.  The engine
 * selector at +0x64 picks GX_LoadOBJ or GXS_LoadOBJ once, up front, and the
 * chosen function pointer is spilled to [sp] and reached through blx r3 for
 * every one of the (rows x cols) transfers.
 *
 * The 0x80-or-remainder width is the tell: a full cell row is 0x80 bytes,
 * and only the last column of the last row uploads the partial remainder
 * ((w % 32) / 8) * 32, which falls back to a whole 0x80 when it lands on
 * zero.  The signed shift quartet around the remainder is what says the
 * width helper hands back a signed int, not the u16 its other callers use.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

struct Obj {
    void *bmp;
    u8    pad04[0x64 - 4];
    u32   engine;
    u32   cell[24];
    u8    padC8[2];
    u8    cols;
    u8    rows;
};

struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void  func_020862F0(void *p, u32 n);
typedef unsigned short u16;
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern int CLACT_GetCharacterVramAddress(u32 idx, u32 flag);
extern void  GX_LoadOBJ(void *src, u32 off, u32 n);
extern void  GXS_LoadOBJ(void *src, u32 off, u32 n);

void BMP_OAM_UploadChars(struct Obj *o)
{
    void (*load)(void *, u32, u32);
    u8 *base;
    s32 cols;
    s32 rows;
    s32 x;
    u32 vram;
    s32 y;
    u32 off;
    u32 last;
    u32 odd;
    u32 n;
    u32 rowsz;
    void *src;

    base = (u8 *)BMP_GetPixels(o->bmp);
    func_020862F0(base, BMP_GetByteSize(o->bmp));
    if (o->engine == 0) {
        load = GX_LoadOBJ;
    } else {
        load = GXS_LoadOBJ;
    }
    cols = (s32)((u32)BMP_GetWidth(o->bmp) >> 3);
    rows = (s32)((u32)BMP_GetHeight(o->bmp) >> 3);
    last = (u32)((((s32)(u32)BMP_GetWidth(o->bmp) % 32) / 8) * 32);
    if (last == 0) {
        last = 0x80;
    }
    off = 0;
    y = 0;
    rowsz = cols << 5;
    y = 0;
    {
        s32 nr = o->rows;
        if (nr <= 0) {
            return;
        }
    }
    odd = rows & 1;
    do {
        for (x = 0; x < o->cols; x++) {
            if (x == o->cols - 1) {
                n = last;
            } else {
                n = 0x80;
            }
            src = (void *)CLACT_GetCharacterVramAddress(o->cell[x + y * o->cols], o->engine);
            vram = (u32)src;
            load(base + off, vram, n);
            if (y == o->rows - 1 && odd != 0) {
            } else {
                vram += 0x80;
                load(base + rowsz, vram, n);
            }
            off += n;
            rowsz += n;
        }
        off += cols << 5;
        rowsz += cols << 5;
        y++;
    } while (y < o->rows);
}
