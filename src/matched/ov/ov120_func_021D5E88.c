/*
 * function: GTSNEGO_DISP_CreateMsgSystem
 * address: 0x021D5E88
 * packet: pkt_ov120_021D5E88
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: arg is a full-word pointer, as matched caller 021D5C60 supplies.
 * interface: 021D6100 gets p explicitly loaded despite its legacy void(void).
 * volatile: hardware 0x04001000 read/written at 0x021D5EC4/0x021D5ECA.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   GTSNEGO_DISP_InitBgLayers 0x021D6100 thumb ov120
 *   GTSNEGO_DISP_RegisterGraphics 0x021D6568 thumb ov120
 *   GTSNEGO_DISP_VBlank 0x021D6530 thumb ov120
 *   func_020056A0 0x020056A0 thumb
 *   GTSNEGO_DISP_CreateCursorActor 0x021D69A0 thumb ov120
 *   GTSNEGO_DISP_CreateTouchbar 0x021D692C thumb ov120
 *   d_021D8BC8 0x021D8BC8 data a1
 *   ov_id 0x00000043 data
 *   d_021D8B98 0x021D8B98 data a4
 *   d_021D8974 0x021D8974 data a4
 *   d_021D8B60 0x021D8B60 data a4
 */
#include "../include/Obj00987.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct DispConfig { u32 a,b,c,d; };
struct DispVram;
extern const char d_021D8BC8[];
extern const u8 ov_id[];
extern const struct DispVram d_021D8B98;
extern const u32 d_021D8974[];
extern struct DispConfig d_021D8B60;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int func_02034AC4(int);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
struct Bank;
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void GX_DispOn(void);
extern void BG_SYS_Create(u16);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void GTSNEGO_DISP_InitBgLayers(u8 *);
extern void GTSNEGO_DISP_RegisterGraphics(u8 *);
extern void GTSNEGO_DISP_VBlank(void *,u8 *);
extern void *func_020056A0(void (*)(void *,u8 *),void *,int);
extern void GTSNEGO_DISP_CreateCursorActor(u8 *);
extern void GTSNEGO_DISP_CreateTouchbar(u8 *,int);
u8 *GTSNEGO_DISP_CreateMsgSystem(u32 heap,void *arg)
{
    u8 *p;
    p=func_02030734(heap,0x164,1,d_021D8BC8,258);
    ((struct Obj00987 *)p)->fF4=heap;
    ((struct Obj00987 *)p)->f118=arg;
    func_02034AC4((int)ov_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)0x04001000|=0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct Obj00987 *)p)->fF4);
    CLACT_InitSystem((const struct Cfg *)d_021D8974,(u32)(&d_021D8B98),((struct Obj00987 *)p)->fF4);
    ((struct Obj00987 *)p)->f10=CLACT_CreateUnit(64,0,((struct Obj00987 *)p)->fF4);
    BG_SYS_SetVramBanks(&d_021D8B98);
    BG_SYS_SetGraphicsMode(&d_021D8B60);
    GTSNEGO_DISP_InitBgLayers(p);
    GTSNEGO_DISP_RegisterGraphics(p);
    ((struct Obj00987 *)p)->f14=func_020056A0(GTSNEGO_DISP_VBlank,p,0);
    ((struct Obj00987 *)p)->f124=func_02030734(((struct Obj00987 *)p)->fF4,0x200,0,d_021D8BC8,280);
    ((struct Obj00987 *)p)->f128=func_02030734(((struct Obj00987 *)p)->fF4,0x200,0,d_021D8BC8,281);
    GTSNEGO_DISP_CreateCursorActor(p);
    GTSNEGO_DISP_CreateTouchbar(p,0);
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(31);
    return p;
}
