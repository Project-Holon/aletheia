/*
 * function: WORLDTRADE_ClearAndShowPlanes
 * address:  0x021F5074
 * packet:   pkt_021F5074
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   WORLDTRADE_SetupGraphics  0x021F4EDC  thumb
 *   WORLDTRADE_SetupWindowPlanes  0x021F49A8  thumb
 *   WORLDTRADE_VBlankTask  0x021F4864  thumb
 *   tbl_02202BB8  0x02202BB8  data
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm  arm9
 *   BG_SYS_ClearSubPlanes  0x02043588  arm  arm9
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm  arm9
 *   BMP_WIN_Init  0x02045088  arm  arm9
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef volatile u16 vu16;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

typedef struct {
    u8 pad0[0xF90];
    void *vblank;
} Work;

extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 a);
extern void WORLDTRADE_SetupGraphics(u8 *p);
extern void func_0203F8F4(u16 heapId);
extern void BMP_WIN_Init(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void WORLDTRADE_SetupWindowPlanes(void);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void WORLDTRADE_VBlankTask(void *unused, Work *p);

extern const struct DispConfig tbl_02202BB8;

void WORLDTRADE_ClearAndShowPlanes(Work *p)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    WORLDTRADE_SetupGraphics((u8 *)p);
    func_0203F8F4(0x48);
    BMP_WIN_Init(0x48);
    {
        struct DispConfig c = tbl_02202BB8;

        func_0203FC28(&c);
    }
    WORLDTRADE_SetupWindowPlanes();
    *(vu16 *)0x04000050 = 0;
    *(vu16 *)0x04001050 = 0;
    if (p->vblank == 0) {
        p->vblank = func_020056A0(WORLDTRADE_VBlankTask, p, 0);
    }
}
