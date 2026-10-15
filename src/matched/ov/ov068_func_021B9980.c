/*
 * function: OPTION_MENU_InitGfx
 * address:  0x021B9980
 * packet:   pkt_ov068_021B9980
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note 2026-10-05 (recoup R14): func_02049658 returns u32 (as in ov210 021BC5DC); declared void it
 *   made the build copy the zero from r5 (adds rN,r5,#0) for the register zero arguments after
 *   02049BDC. EXACT in c99 and c with the u32 return.
 *
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049DF4  0x02049DF4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02049F34  0x02049F34  arm
 *   func_020307B0  0x020307B0  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   OPTION_MENU_CreateLabelWindows  0x021B9C04  thumb  ov068
 *   gOptionMenuDispConfig  0x021BB540  data  a4
 *   gOptionMenuBgLayers  0x021BB614  data  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 id;
    u32 w[8];
    u32 f24;
} Row;

typedef struct {
    u8 pad0[0xC];
    u8 *data;
} PlttData;

extern u8 gOptionMenuDispConfig[];
extern Row gOptionMenuBgLayers[];

extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern void MI_CpuCopy8(void *src, void *dst, u32 n);
extern void BG_SYS_Create(u16 heap);
extern void BMP_WIN_Init(u16 heap);
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8 id);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_Init(u32 a, u32 b, u32 c, u32 d);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void ARC_TOOL_DeleteHandle(void *a);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_020307B0(void *p);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void OPTION_MENU_CreateLabelWindows(u32 *p);

void OPTION_MENU_InitGfx(u8 *p, u16 heap)
{
    void *h;
    void *buf;
    PlttData *pd;
    int i;
    u32 id;

    MI_CpuFill8(p, 0, 0x7c);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)gOptionMenuDispConfig);
    for (i = 0; i < 6; i++) {
        id = gOptionMenuBgLayers[i].id;
        BG_SYS_InitBgLayer((u8)id, (const struct BgTemplate *)(&gOptionMenuBgLayers[i].w[0]), (u8)gOptionMenuBgLayers[i].f24);
        BG_SYS_FreeSlot(id);
        func_02040588(id, 1);
    }
    func_02040588(3, 0);
    BG_SYS_Init(4, 0, 1, 0);
    BG_SYS_Init(3, 0, 1, 0);
    h = func_020490F4(0x1b, heap);
    func_02049B68(h, 1, 0, 0, 0, heap);
    func_02049658(h, 0xd, 0, 0, 0, 0, heap);
    func_020498F4(h, 0xe, 0, 0, 0, 0, heap);
    func_02049658(h, 0, 2, 0, 0, 0, heap);
    func_020498F4(h, 2, 2, 0, 0, 0, heap);
    func_02049658(h, 0x10, 3, 1, 0, 0, heap);
    ARC_UTIL_UploadPaletteFromHandle(h, 8, 0, 0x80, 0x1e0, 0x20, heap);
    *(void **)(p + 0x54) = func_02049DF4(h, 0xf, 0, (u32)(p + 0x58), heap);
    func_02049B68(h, 8, 4, 0, 0, heap);
    func_02049658(h, 7, 5, 0, 0, 0, heap);
    func_020498F4(h, 9, 5, 0, 0, 0, heap);
    func_02049658(h, 0x10, 4, 1, 0, 0, heap);
    ARC_TOOL_DeleteHandle(h);
    buf = func_02049F34(0x1b, 1, (u32)(&pd), heap);
    MI_CpuCopy8(pd->data + 0xe0, p + 0x5c, 0x20);
    func_020307B0(buf);
    *(u32 *)(p + 0x44) = BMP_WIN_Create(4, 1, 0x13, 0x1e, 4, 4, 1);
    *(u32 *)(p + 0x48) = BMP_WIN_Create(3, 1, 1, 0x1e, 4, 0xf, 1);
    *(u32 *)(p + 0x40) = BMP_WIN_Create(0, 0, 0, 0x10, 3, 8, 1);
    OPTION_MENU_CreateLabelWindows((u32 *)p);
    func_02040588(4, 0);
}
