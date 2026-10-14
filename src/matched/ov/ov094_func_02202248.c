/*
 * function: BTLV_INPUT_LoadScreenResources
 * address: 0x02202248
 * packet: pkt_ov094_02202248
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FC6C 0x0203FC6C arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BTLV_INPUT_InitBgLayers 0x0220255C thumb ov094
 *   BTLV_INPUT_LoadCommonGraphics 0x022033F4 thumb ov094
 *   BTLV_INPUT_CreateTargetActors 0x02205E80 thumb ov094
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   INFOWIN_Init 0x02024A20 thumb
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   BTLV_EFFECT_GetOwner 0x021F86D4 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   BTLV_INPUT_InfoWindowTask 0x02202238 thumb ov094
 *   BTLV_INPUT_ChangeScreen 0x0220270C thumb ov094
 *   d_0220A3D4 0x0220A3D4 data ov094 a4
 */
#include "../include/Obj00083.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_0220A3D4[];
struct BgVramReq;
struct Main;
extern void func_0203FC6C(const struct BgVramReq *req, u32 which);
extern void *func_020490F4(u32 id, u32 heap);
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PalAnmSlot;
extern void BTLV_INPUT_InitBgLayers(void *p);
extern void BTLV_INPUT_LoadCommonGraphics(struct Main *m);
extern void BTLV_INPUT_CreateTargetActors(char *);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern void INFOWIN_Init(u8, u8, void *, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void *BTLV_EFFECT_GetOwner(void);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void BTLV_INPUT_InfoWindowTask(void *unused, void **p);
extern void BTLV_INPUT_ChangeScreen(char *s, int mode, void *arg);
void BTLV_INPUT_LoadScreenResources(char *p)
{
    func_0203FC6C((const struct BgVramReq *)d_0220A3D4, 1);
    ((struct Obj00083 *)p)->f48 = func_020490F4(0xb, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f1F8 = (int)CLACT_CreateUnit(4, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f118 = (int)CLACT_CreateUnit(0xc, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f17C = (int)CLACT_CreateUnit(6, 0, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f1C4 = (int)CLACT_CreateUnit(3, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f20C = (int)CLACT_CreateUnit(2, 2, ((struct Obj00083 *)p)->f240);
    ((struct Obj00083 *)p)->f218 = (int)CLACT_CreateUnit(1, 1, ((struct Obj00083 *)p)->f240);
    BTLV_INPUT_InitBgLayers(p);
    BTLV_INPUT_LoadCommonGraphics((struct Main *)p);
    BTLV_INPUT_CreateTargetActors(p);
    ((struct Obj00083 *)p)->f228 = (void *)BMP_WIN_Create(6, 0, 4, 32, 12, 13, 1);
    ((struct Obj00083 *)p)->f22C = BMP_WIN_GetBmp(((struct Obj00083 *)p)->f228);
    ((struct Obj00083 *)p)->f230 = (void *)BMP_WIN_Create(6, 3, 22, 3, 2, 13, 1);
    ((struct Obj00083 *)p)->f234 = BMP_WIN_GetBmp(((struct Obj00083 *)p)->f230);
    BMP_Clear(((struct Obj00083 *)p)->f22C, 0);
    BMP_Clear(((struct Obj00083 *)p)->f234, 0);
    BMP_WIN_TransferChars(((struct Obj00083 *)p)->f228);
    BMP_WIN_TransferChars(((struct Obj00083 *)p)->f230);
    BMP_WIN_MakeScreen(((struct Obj00083 *)p)->f228);
    BMP_WIN_MakeScreen(((struct Obj00083 *)p)->f230);
    func_020409B4(6);
    INFOWIN_Init(6, 15, ((struct Obj00083 *)p)->f4C, ((struct Obj00083 *)p)->f240);
    func_02040588(6, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00083 *)p)->f240);
    PALANM_CopyHwPaletteToSlot(((struct Obj00083 *)p)->f64, 3, 0xe0, 0x20);
    ((struct Obj00083 *)p)->f68 |= 0x2000;
    if (((struct Obj00083 *)p)->f23C == 1)
        ((struct Obj00083 *)p)->f238 = func_02030DA8(BTLV_EFFECT_GetOwner(), (void (*)(void *, void *))BTLV_INPUT_InfoWindowTask, p, 0);
    BTLV_INPUT_ChangeScreen(p, 0, 0);
}
