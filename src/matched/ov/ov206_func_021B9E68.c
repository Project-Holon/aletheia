/*
 * function: ZUKAN_INFO_Create
 * address: 0x021B9E68
 * packet: pkt_ov206_021B9E68
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: a3 is u16 here (u16 field, strh); the matched caller ov206_func_021B9DE0 declares it unsigned.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   ZUKAN_INFO_LoadResources 0x021BBE5C thumb ov206
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_020498F4 0x020498F4 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02049990 0x02049990 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   func_020307B0 0x020307B0 arm
 *   ZUKAN_INFO_CreateBgBmp 0x021BAFC4 thumb ov206
 *   ZUKAN_INFO_FlushMainWindow 0x021BB0FC thumb ov206
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_INFO_Task 0x021BA864 thumb ov206
 *   ZUKAN_INFO_CreateIconActors 0x021BB304 thumb ov206
 *   ZUKAN_INFO_InitFormGfx 0x021BB9E0 thumb ov206
 *   ZUKAN_INFO_CreateWindows 0x021BA890 thumb ov206
 *   ZUKAN_INFO_RefreshDisplay 0x021BBC38 thumb ov206
 *   ZUKAN_INFO_SetActors 0x021BB13C thumb ov206
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021BC220 0x021BC220 data
 */
#include "../include/Obj00022.h"
#include "../include/Obj25394.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021BC220[];
typedef signed int     s32;
struct ArcFile;
struct NitroFileHeader;
struct Personal;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, int v, int n);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
struct S;
struct State;
extern void ZUKAN_INFO_LoadResources(struct S *p);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
extern u32 func_020307B0(void *p);
extern void ZUKAN_INFO_CreateBgBmp(char *p);
extern void ZUKAN_INFO_FlushMainWindow(void *obj);
extern void *func_020056A0(void (*cb)(int, char *), void *arg, int pri);
extern void ZUKAN_INFO_Task(int unused, char *p);
extern void ZUKAN_INFO_CreateIconActors(char *p);
extern void ZUKAN_INFO_InitFormGfx(struct State *p);
extern void ZUKAN_INFO_CreateWindows(char *p);
extern void ZUKAN_INFO_RefreshDisplay(struct S *p);
extern void ZUKAN_INFO_SetActors(void *a0, void *a1, void *a2, void *a3);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void BG_SYS_PushTile(u32 layer);
static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000040 = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    *(volatile u16 *)0x04000044 = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}
static inline void G2_SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x04000048 & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x04000048 = (u16)tmp;
}
static inline void G2_SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}
void *ZUKAN_INFO_Create(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9,
                    u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16)
{
    char *p;
    void *h;
    void *buf;
    void *res;
    char *data;
    u8 i;
    u8 k;
    int x;
    int y;
    u32 hh;

    p = func_02030734(heap, 0x2b4, 0, d_021BC220, 0x42f);
    MI_CpuFill8(p, 0, 0x2b4);
    ((struct Obj00022 *)p)->f0 = heap;
    ((struct Obj00022 *)p)->fC = a1;
    ((struct Obj00022 *)p)->fE = a2;
    ((struct Obj00022 *)p)->f10 = a3;
    ((struct Obj00022 *)p)->f12 = a4;
    ((struct Obj00022 *)p)->f14 = a5;
    ((struct Obj00022 *)p)->f4 = a6;
    ((struct Obj00022 *)p)->f8 = a7;
    ((struct Obj00022 *)p)->f18 = a8;
    ((struct Obj00022 *)p)->f1C = a9;
    ((struct Obj00022 *)p)->f20 = a10;
    ((struct Obj00022 *)p)->f24 = a11;
    ((struct Obj00022 *)p)->f28 = a12;
    ((struct Obj00022 *)p)->f2C = (void *)PRINTSYS_QUE_Create((void *)(((struct Obj00022 *)p)->f0));
    *(u32 *)&((struct Obj00022 *)p)->f1B8 = a14;
    *(u32 *)&((struct Obj00022 *)p)->f1BC = a15;
    *(u32 *)&((struct Obj00022 *)p)->f1C0 = a16;
    if (((struct Obj00022 *)p)->f1C == 0) {
        ((struct Obj00022 *)p)->f48 = 0;
        ((struct Obj00022 *)p)->f4C = 3;
        ((struct Obj00022 *)p)->f4D = 2;
        ((struct Obj00022 *)p)->f4E = 0;
    } else {
        ((struct Obj00022 *)p)->f48 = 4;
        ((struct Obj00022 *)p)->f4C = 7;
        ((struct Obj00022 *)p)->f4D = 6;
        ((struct Obj00022 *)p)->f4E = 4;
    }
    BG_SYS_SetVisibleLayer(((struct Obj00022 *)p)->f4C, ((struct Obj00022 *)p)->f20);
    BG_SYS_SetVisibleLayer(((struct Obj00022 *)p)->f4D, (u8)(((struct Obj00022 *)p)->f20 + 1));
    BG_SYS_SetVisibleLayer(((struct Obj00022 *)p)->f4E, (u8)(((struct Obj00022 *)p)->f20 + 2));
    ((struct Obj00022 *)p)->f38 = 0;
    ((struct Obj00022 *)p)->f39 = 0;
    switch (((struct Obj00022 *)p)->f18) {
    case 0:
        ((struct Obj00022 *)p)->f54 = 0;
        break;
    case 1:
        ((struct Obj00022 *)p)->f54 = 5;
        break;
    case 2:
        ((struct Obj00022 *)p)->f54 = 7;
        break;
    }
    ((struct Obj00022 *)p)->f58 = 0;
    ((struct Obj00022 *)p)->f5C = 0;
    ((struct Obj00022 *)p)->f60 = 0;
    ((struct Obj00022 *)p)->f64 = 0;
    ((struct Obj00022 *)p)->f194 = 0;
    if (((struct Obj00022 *)p)->f18 == 2 && ((struct Obj00022 *)p)->f1C == 0) {
        ((struct Obj00022 *)p)->f1B4 = -0x18;
    } else {
        ((struct Obj00022 *)p)->f1B4 = 0;
    }
    ZUKAN_INFO_LoadResources((struct S *)p);
    hh = (u16)POKE_PERSONAL_GetParam(((struct Obj00022 *)p)->f26C, 0x20);
    if (((struct Obj00022 *)p)->fE >= hh) ((struct Obj00022 *)p)->fE = 0;
    h = ((struct Obj00022 *)p)->f1C4;
    func_02049B68(h, 9, ((struct Obj00022 *)p)->f48, 0, 0x60, ((struct Obj00022 *)p)->f0);
    ((struct Obj00022 *)p)->f30 = func_02049740(h, 0x19, ((struct Obj00022 *)p)->f4D, 0x1000, 0, ((struct Obj00022 *)p)->f0);
    func_020498F4(h, 0x28, ((struct Obj00022 *)p)->f4D, (u16)((struct Obj00022 *)p)->f30, 0x800, 0, ((struct Obj00022 *)p)->f0);
    ((struct Obj00022 *)p)->f34 = func_02049740(h, 0x19, ((struct Obj00022 *)p)->f4E, 0x1000, 0, ((struct Obj00022 *)p)->f0);
    func_020498F4(h, 0x1f, ((struct Obj00022 *)p)->f4E, (u16)((struct Obj00022 *)p)->f34, 0x800, 0, ((struct Obj00022 *)p)->f0);
    ((struct Obj00022 *)p)->f40 = 0;
    ((struct Obj00022 *)p)->f44 = 0;
    if (((struct Obj00022 *)p)->f18 == 2 && ((struct Obj00022 *)p)->f1C == 1) {
        BG_SYS_SetTileEntry(((struct Obj00022 *)p)->f4D, 0, 0, 0, 0x20, 3, 0x11);
        h = ((struct Obj00022 *)p)->f1C4;
        ARC_UTIL_UploadPaletteFromHandle(h, 2, ((struct Obj00022 *)p)->f48, 0, 0x80, 0x40, ((struct Obj00022 *)p)->f0);
        ((struct Obj00022 *)p)->f3C = func_02049740(h, 0xc, ((struct Obj00022 *)p)->f4E, 0x2000, 0, ((struct Obj00022 *)p)->f0);
        ((struct Obj00022 *)p)->f40 = 1;
        func_02049990(h, 0x24, ((struct Obj00022 *)p)->f4E, 0x400, (u16)((struct Obj00022 *)p)->f3C, 0x800, 0, ((struct Obj00022 *)p)->f0);
        BG_SYS_FillTileMap(((struct Obj00022 *)p)->f4E, 0, 0x20, 0x20, 0x15, 4);
        BG_SYS_FillTileMap(((struct Obj00022 *)p)->f4E, 0, 0x35, 0x20, 3, 5);
    }
    h = ((struct Obj00022 *)p)->f1C4;
    buf = func_02030734(((struct Obj00022 *)p)->f0, ARC_TOOL_GetHandleMemberSize(h, 9), 0, d_021BC220, 0x4f7);
    ARC_TOOL_ReadHandleMember(h, 9, buf);
    NNS_G2dGetUnpackedPaletteData(buf, &res);
    data = *(char * *)&((struct Obj25394 *)res)->fC;
    for (i = 0; i < 5; i++) {
        *(u16 *)(p + i * 2 + 0x1a0) = *(u16 *)(data + i * 2 + 0x22);
        *(u16 *)(p + i * 2 + 0x1aa) = *(u16 *)(data + i * 2 + 0x42);
    }
    func_020307B0(buf);
    ZUKAN_INFO_CreateBgBmp(p);
    ZUKAN_INFO_FlushMainWindow(p);
    ((struct Obj00022 *)p)->f50 = func_020056A0(ZUKAN_INFO_Task, p, 1);
    ZUKAN_INFO_CreateIconActors(p);
    ZUKAN_INFO_InitFormGfx((struct State *)p);
    if (((struct Obj00022 *)p)->f18 == 0 || ((struct Obj00022 *)p)->f18 == 2) {
        ZUKAN_INFO_CreateWindows(p);
        ZUKAN_INFO_RefreshDisplay((struct S *)p);
    }
    for (k = 0; k < 2; k++) {
        *(int *)(p + k * 4 + 0xac) = 0;
    }
    ((struct Obj00022 *)p)->fB4 = 0;
    switch (((struct Obj00022 *)p)->f18) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    ZUKAN_INFO_SetActors(p, (void *)x, (void *)((u16)(y + ((struct Obj00022 *)p)->f1B4)), (void *)(((struct Obj00022 *)p)->fB4));
    if (((struct Obj00022 *)p)->f18 == 0) {
        ((struct Obj00022 *)p)->f68 = 0x88;
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x2000;
        G2_SetWnd0Position(0, 8, 100, ((struct Obj00022 *)p)->f68);
        G2_SetWnd0InsidePlane(0x1f, 1);
        G2_SetWndOutsidePlane(0x1f, 0);
        G2x_SetBlendBrightness_((u32)((volatile u16 *)0x04000050), 0x10, -0x10);
    }
    BG_SYS_FillScrollArea(((struct Obj00022 *)p)->f4D, 3, -((struct Obj00022 *)p)->f1B4);
    BG_SYS_FillScrollArea(((struct Obj00022 *)p)->f4E, 3, -((struct Obj00022 *)p)->f1B4);
    BG_SYS_FillScrollArea(((struct Obj00022 *)p)->f4C, 3, -((struct Obj00022 *)p)->f1B4);
    BG_SYS_PushTile(((struct Obj00022 *)p)->f4D);
    BG_SYS_PushTile(((struct Obj00022 *)p)->f4E);
    return p;
}
