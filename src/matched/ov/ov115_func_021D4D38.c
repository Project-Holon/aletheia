/*
 * function: WIFILOGIN_DISP_CreateDisplay
 * address: 0x021D4D38
 * packet: pkt_ov115_021D4D38
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware reads/writes 021D4D66, 021D4D70, 021D4D74.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   WIFILOGIN_DISP_InitBgLayersB 0x021D4FA4 thumb ov115
 *   WIFILOGIN_DISP_InitBgLayersD 0x021D5214 thumb ov115
 *   WIFILOGIN_DISP_CreateUnit 0x021D57D0 thumb ov115
 *   WIFILOGIN_DISP_CreateActors 0x021D5598 thumb ov115
 *   WIFILOGIN_DISP_InitBgLayersA 0x021D4E58 thumb ov115
 *   WIFILOGIN_DISP_InitBgLayersC 0x021D50BC thumb ov115
 *   WIFILOGIN_DISP_LoadPalette 0x021D532C thumb ov115
 *   d_021D6614 0x021D6614 data a1
 *   d_021D65E4 0x021D65E4 data a4
 *   d_021D65D4 0x021D65D4 data a4
 */
#include "../include/Obj00198.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 d_021D6614[];
extern u32 d_021D65E4[];
extern u32 d_021D65D4[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void BG_SYS_SetLcdSwap(u32);
extern void GX_DispOn(void);
extern void BG_SYS_Create(u16);
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void WIFILOGIN_DISP_InitBgLayersB(void *,u32);
extern void WIFILOGIN_DISP_InitBgLayersD(void *,u32);
extern void WIFILOGIN_DISP_CreateUnit(u8 *p);
extern void WIFILOGIN_DISP_CreateActors(u8 *p);
extern void WIFILOGIN_DISP_InitBgLayersA(u32 unused, unsigned long base);
extern void WIFILOGIN_DISP_InitBgLayersC(void *,u32);
extern void WIFILOGIN_DISP_LoadPalette(char *p);
u8 *WIFILOGIN_DISP_CreateDisplay(u16 heap, u32 mode, int a2) {
    u8 *p;
    p=func_02030734(heap,0x14bc,1,(const char *)d_021D6614,146);
    ((struct Obj00198 *)p)->fC=heap;
    ((struct Obj00198 *)p)->f8=mode;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050=0;
    BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct Obj00198 *)p)->fC);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021D65E4);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021D65D4);
    switch (((struct Obj00198 *)p)->f8) {
    case 1:
        WIFILOGIN_DISP_InitBgLayersB(p,0);
        WIFILOGIN_DISP_InitBgLayersD(p,4);
        WIFILOGIN_DISP_CreateUnit(p);
        WIFILOGIN_DISP_CreateActors(p);
        break;
    case 0:
        WIFILOGIN_DISP_InitBgLayersA((u32)p,0);
        WIFILOGIN_DISP_InitBgLayersC(p,4);
        WIFILOGIN_DISP_LoadPalette((char *)p);
        break;
    }
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(31);
    return p;
}
