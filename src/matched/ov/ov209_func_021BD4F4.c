/*
 * function: ZUKAN_LIST_ClearWindow
 * address:  0x021BD4F4
 * packet:   pkt_ov209_021BD4F4
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   BMP_WIN_GetDispHeight 0x02045750 arm
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Descriptor;
struct Bmp;
extern u8 BMP_WIN_GetDispWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetDispHeight(struct Descriptor *p);
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *, u32, u32, void **, u16);
extern void *ARC_UTIL_LoadBgCharDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);

void ZUKAN_LIST_ClearWindow(u8 *p, u32 idx)
{
    void *o2;
    void *o1;
    void *t2;
    u8 *gfx;
    void *t1;
    u8 *dst;
    u16 j;
    u8 *row;
    int y;
    int h;
    u8 w;
    int x;
    u8 *map;
    struct Descriptor **ent = (struct Descriptor **)(p + 0x20);
    void *arc;
    u16 i;

    w = BMP_WIN_GetDispWidth(*(struct Descriptor **)((u8 *)ent + idx * 8));
    h = BMP_WIN_GetDispHeight(*(struct Descriptor **)((u8 *)ent + idx * 8));
    x = BMP_WIN_GetPosX(*(struct Descriptor **)((u8 *)ent + idx * 8));
    y = BMP_WIN_GetPosY(*(struct Descriptor **)((u8 *)ent + idx * 8));
    dst = BMP_GetPixels(BMP_WIN_GetBmp(*(struct Descriptor **)((u8 *)ent + idx * 8)));
    arc = func_020490F4(0x9F, 0x6B);
    t1 = ARC_UTIL_LoadPaletteDataFromHandle(arc, 0x45, 0, &o1, 0x806B);
    map = (u8 *)o1 + 0xC;
    t2 = ARC_UTIL_LoadBgCharDataFromHandle(arc, 0x39, 0, (u32)(&o2), 0x806B);
    gfx = *(u8 **)((u8 *)o2 + 0x14);
    ARC_TOOL_DeleteHandle(arc);
    if (h > 0) {
        row = map + x * 2;
        j = 0;
        do {
            for (i = 0; i < w; i++) {
                u16 c = *(u16 *)(row + (y + j) * 64 + i * 2);
                MIi_CpuCopy32(gfx + (c & 0x3FF) * 32, dst + (i + j * w) * 32, 0x20);
            }
            j++;
        } while (j < h);
    }
    func_020307B0(t2);
    func_020307B0(t1);
}
