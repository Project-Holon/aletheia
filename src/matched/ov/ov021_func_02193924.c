/*
 * function: FIELD_WFBC_PatchLandData
 * address:  0x02193924
 * packet:   pkt_ov021_02193924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_WFBC_BLOCK_GetCell  0x02194038  thumb  ov021
 *   LAND_DATA_PATCH_Create  0x021C939C  thumb  ov021
 *   LAND_DATA_PATCH_OverwriteAttr  0x021C93E4  thumb  ov021
 *   LAND_DATA_PATCH_AddBuildModels  0x021C9450  thumb  ov021
 *   LAND_DATA_PATCH_Delete  0x021C93D0  thumb  ov021
 *
 * The cell comes back from FIELD_WFBC_BLOCK_GetCell as a 4-byte struct in r0; the high
 * nibble is read before the low one.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u8 lo:4; u8 hi:4; u8 b; u16 c; } Cell;
extern Cell FIELD_WFBC_BLOCK_GetCell(void *a, int b, int c);
extern u32 *LAND_DATA_PATCH_Create(u32 a, u32 heap);
extern void LAND_DATA_PATCH_OverwriteAttr(u32 a, u8 *q, u32 x, u32 y, u32 z, u32 w, u32 n, u32 cnt);
extern u32 LAND_DATA_PATCH_AddBuildModels(u32 a, u32 b, u32 c, u32 d, int e, int f);
extern void LAND_DATA_PATCH_Delete(void **q);

int FIELD_WFBC_PatchLandData(u8 *a, void *q, int c, int d, int e, int f, int g, u16 h)
{
    Cell cell = FIELD_WFBC_BLOCK_GetCell(a + 0x18, f, g);
    u32 *t;
    int x, y;
    int lo, hi;

    if (cell.b != 0xFF) {
        x = (f * 8) & 0x1F;
        y = (g * 8) & 0x1F;
        t = LAND_DATA_PATCH_Create(cell.c, (u16)((h & 0x7FFF) | 0x8000));
        hi = cell.hi;
        lo = cell.lo;
        LAND_DATA_PATCH_OverwriteAttr((u32)t, q, lo * 8, hi * 8, x, y, 8, 8);
        if (lo == 0 && hi == 0) {
            e = LAND_DATA_PATCH_AddBuildModels((u32)t, c, d, e, x, y);
        }
        LAND_DATA_PATCH_Delete((void **)t);
    }
    return e;
}
