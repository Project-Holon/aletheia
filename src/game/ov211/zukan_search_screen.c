/*
 * file:     zukan_search_screen.c
 * unit:     yes
 * function: ZUKAN_SEARCH_SCREEN_SetupVram, ZUKAN_SEARCH_SCREEN_VBlank, ZUKAN_SEARCH_SCREEN_RegisterVBlank, ZUKAN_SEARCH_SCREEN_UnregisterVBlank, ZUKAN_SEARCH_SCREEN_InitBg, ZUKAN_SEARCH_SCREEN_DeleteBg, ZUKAN_SEARCH_SCREEN_LoadGraphics, ZUKAN_SEARCH_SCREEN_LoadSaveGraphics, ZUKAN_SEARCH_SCREEN_Init, ZUKAN_SEARCH_SCREEN_Delete, ZUKAN_SEARCH_SCREEN_WaitWipe, ZUKAN_SEARCH_SCREEN_WaitWipeExit, ZUKAN_SEARCH_SCREEN_HandleInput, ZUKAN_SEARCH_SCREEN_Update, ZUKAN_SEARCH_SCREEN_Tick
 * address:  0x021BC2B0
 * region:   ov211
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021BC990    0x021BC990 data ov211
 *   BG_SYS_Update 0x020419E4 arm
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021BC8C8 0x021BC8C8 data a4
 *   d_021BC910 0x021BC910 data a4
 *   d_021BC930 0x021BC930 data a4
 *   d_021BC950 0x021BC950 data a4
 *   d_021BC970 0x021BC970 data a4
 *   d_021BC8F0 0x021BC8F0 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   open 0x020490F4 arm
 *   kind 0x02008550 thumb
 *   palette 0x02049B68 arm
 *   screen 0x02049658 arm
 *   tiles 0x020498F4 arm
 *   close 0x02049238 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   SAVE_CONTROL_GetExtraSaveRecord 0x020073D8 thumb
 *   MISC_SAVEDATA_GetFlags6200 0x0200E8D8 thumb
 *   MISC_SAVEDATA_EmptyHook 0x0200E8CC thumb
 *   MISC_SAVEDATA_GetScratchBase 0x0200E8D0 thumb
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   GX_BeginLoadBGExtPltt 0x0207F308 arm
 *   GX_LoadBGExtPltt 0x0207F394 arm
 *   GX_EndLoadBGExtPltt 0x0207F428 arm
 *   GXS_BeginLoadBGExtPltt 0x0207F5B0 arm
 *   GXS_LoadBGExtPltt 0x0207F5C8 arm
 *   GXS_EndLoadBGExtPltt 0x0207F65C arm
 *   SAVE_CONTROL_DeleteExtraSave 0x020072A4 thumb
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ZUKAN_StartWipeIn 0x021C93A8 thumb ov212
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   TOUCHPANEL_GetCont   0x02035C38  arm
 *   UI_SetInputMode   0x020355D8  arm
 *   KEY_GetTrg   0x020362DC  arm
 *   ZUKAN_StartWipeOut   0x021C93C4  thumb ov212
 *   sound 0x020061E4 thumb
 *   setup 0x02041EE4 arm
 *   adjust 0x02041FB0 arm
 *   tick 0x021BC890 thumb ov211
 *   transition 0x0202208C thumb
 *   idle 0x020221A4 thumb
 *   BG_SYS_SetScrollY  0x02041F6C  arm
 */

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Big;
struct Ctrl;
struct Sub020073D8Ctrl;
struct Sub020072A4Ctrl;

typedef struct
{
    int v[12];
} ZukanSearchVramConfig;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct DispConfigData { u32 words[4]; } DispConfigData;

typedef struct BgTemplateData { u32 words[8]; } BgTemplateData;

typedef unsigned char  u8;

#include "zukan_search_types.h"

extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Update(void);
extern void *GFL_USE_AddMainTask(unsigned,unsigned,unsigned);
extern void TCB_DeleteTask(struct Node *);
extern void BG_SYS_Create(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_ClearLayerEx(int, u16);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned),BG_SYS_SetSubPlaneVisible(unsigned,unsigned),BG_SYS_FreeLayerBuf(unsigned),BG_SYS_Delete(void);
extern void *open(u32,u16);
extern int kind(void *);
extern void palette(void *,u32,u32,u32,u32,u16);
extern void screen(void *,u32,u32,u32,u32,u32,u16);
extern void tiles(void *,u32,u32,u32,u32,u32,u16);
extern void close(void *);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *,u32,u32);
extern void *SAVE_CONTROL_GetExtraSaveRecord(struct Sub020073D8Ctrl *,u32,u32);
extern u32 MISC_SAVEDATA_GetFlags6200(const void *obj);
extern void *MISC_SAVEDATA_EmptyHook(void *),*MISC_SAVEDATA_GetScratchBase(void *);
extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern void BG_SYS_LoadPltt(u32,void *,u32,u32);
extern void DWCi_ScreenDC_FlushRange(void *,unsigned long);
extern void GX_BeginLoadBGExtPltt(void),GX_LoadBGExtPltt(const void *,u32,u32),GX_EndLoadBGExtPltt(void);
extern void GXS_BeginLoadBGExtPltt(void),GXS_LoadBGExtPltt(const void *,u32,u32),GXS_EndLoadBGExtPltt(void);
extern void SAVE_CONTROL_DeleteExtraSave(struct Sub020072A4Ctrl *,u32);
extern void BG_SYS_SetMainVisiblePlanes(unsigned),BG_SYS_SetSubVisiblePlanes(unsigned),BG_SYS_SetLcdSwap(unsigned);
extern void ZUKAN_StartWipeIn(unsigned);
extern void ZUKAN_SEARCH_SCREEN_UnregisterVBlank(struct ZukanSearchWork *),ZUKAN_SEARCH_SCREEN_DeleteBg(void),BG_SYS_SetMainVisiblePlanes(unsigned),BG_SYS_SetSubVisiblePlanes(unsigned);
extern unsigned WIPE_SYS_EndCheck(void);
extern int  TOUCHPANEL_GetCont(void);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetTrg(void);
extern void ZUKAN_StartWipeOut(u32 heap);
extern void sound(int);
extern void setup(u32,u32,u32);
extern void adjust(u32,u32,u32);
extern void tick(void);
extern void transition(void *,u32,u32,u32,u32,u32,u32);
extern u32 idle(void);
extern void BG_SYS_SetScrollY(u32 which, u32 op, u32 value);
void ZUKAN_SEARCH_SCREEN_SetupVram(void);
void ZUKAN_SEARCH_SCREEN_VBlank(void);
void ZUKAN_SEARCH_SCREEN_RegisterVBlank(struct ZukanSearchWork *p);
void ZUKAN_SEARCH_SCREEN_UnregisterVBlank(struct ZukanSearchWork *p);
void ZUKAN_SEARCH_SCREEN_InitBg(void);
void ZUKAN_SEARCH_SCREEN_DeleteBg(void);
void ZUKAN_SEARCH_SCREEN_LoadGraphics(struct ZukanSearchWork *p);
void ZUKAN_SEARCH_SCREEN_LoadSaveGraphics(struct ZukanSearchWork *p);
int ZUKAN_SEARCH_SCREEN_Init(struct ZukanSearchWork *p);
int ZUKAN_SEARCH_SCREEN_Delete(struct ZukanSearchWork *p);
int ZUKAN_SEARCH_SCREEN_WaitWipe(void);
int ZUKAN_SEARCH_SCREEN_WaitWipeExit(void);
int ZUKAN_SEARCH_SCREEN_HandleInput(struct ZukanSearchWork *p);
int ZUKAN_SEARCH_SCREEN_Update(struct ZukanSearchWork *p);
void ZUKAN_SEARCH_SCREEN_Tick(void);
extern ZukanSearchVramConfig d_021BC990;
extern unsigned char SDK_AUTOLOAD_MAIN_TWL_START[];
extern const DispConfigData d_021BC8C8;
extern const BgTemplateData d_021BC910, d_021BC930, d_021BC950, d_021BC970, d_021BC8F0;




void ZUKAN_SEARCH_SCREEN_SetupVram(void)
{
    ZukanSearchVramConfig buf = d_021BC990;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)(&buf));
}



void ZUKAN_SEARCH_SCREEN_VBlank(void){BG_SYS_Update();*(unsigned *)((unsigned)SDK_AUTOLOAD_MAIN_TWL_START+0x3FF8)|=1;}



void ZUKAN_SEARCH_SCREEN_RegisterVBlank(struct ZukanSearchWork *p){p->vblankNode=GFL_USE_AddMainTask((unsigned)ZUKAN_SEARCH_SCREEN_VBlank,(unsigned)p,0);}



void ZUKAN_SEARCH_SCREEN_UnregisterVBlank(struct ZukanSearchWork *p){TCB_DeleteTask((struct Node *)p->vblankNode);}



void ZUKAN_SEARCH_SCREEN_InitBg(void)
{
    DispConfigData a;
    BgTemplateData b, c, d, e, f;
    BG_SYS_Create(0x7e);
    a = d_021BC8C8;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&a));
    b = d_021BC910;
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)(&b), 2);
    BG_SYS_ClearSlot(3);
    c = d_021BC930;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&c), 0);
    BG_SYS_InitRun(1, 0x20, 0x7fe0, 0x807e);
    BG_SYS_ClearLayerEx(1, 0x3ff);
    d = d_021BC950;
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&d), 0);
    BG_SYS_ClearSlot(2);
    e = d_021BC970;
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)(&e), 2);
    BG_SYS_ClearSlot(7);
    f = d_021BC8F0;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&f), 0);
    BG_SYS_ClearSlot(5);
    BG_SYS_SetMainPlaneVisible(14, 1);
    BG_SYS_SetSubPlaneVisible(10, 1);
}



void ZUKAN_SEARCH_SCREEN_DeleteBg(void){BG_SYS_SetMainPlaneVisible(14,0);BG_SYS_SetSubPlaneVisible(10,0);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(7);BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(3);BG_SYS_Delete();}



void ZUKAN_SEARCH_SCREEN_LoadGraphics(struct ZukanSearchWork *p)
{
    void *arc;
    arc=open(159,0x807E);
    if(kind(p->owner->context)==0) {
        palette(arc,102,2,0x4000,0,126);
        palette(arc,102,2,0x6000,0,126);
        palette(arc,102,6,0x4000,0,126);
        palette(arc,102,6,0x6000,0,126);
    } else {
        palette(arc,103,2,0x4000,0,126);
        palette(arc,103,2,0x6000,0,126);
        palette(arc,103,6,0x4000,0,126);
        palette(arc,103,6,0x6000,0,126);
    }
    screen(arc,105,2,0,0,0,126);
    screen(arc,105,5,0,0,0,126);
    tiles(arc,108,3,0,0,0,126);
    tiles(arc,111,1,0,0,0,126);
    tiles(arc,110,2,0,0,0,126);
    tiles(arc,112,7,0,0,0,126);
    tiles(arc,109,5,0,0,0,126);
    close(arc);
}



/*
 * prototype: 0725C third parameter widened from matched u8: original
 * supplies full pooled 0x807E, without truncation. 073D8 legacy void
 * leaves a pointer in r0 consumed immediately by E8D8; preserve it.
 */
void ZUKAN_SEARCH_SCREEN_LoadSaveGraphics(struct ZukanSearchWork *p)
{
    void *save,*block,*tiles,*palette;
    save=GAME_DATA_GetSaveControl(p->owner->gameData);
    if(SAVE_CONTROL_LoadExtraSave(save,7,0x807e)==1){
        block=SAVE_CONTROL_GetExtraSaveRecord(save,7,0);
        if(block!=0&&MISC_SAVEDATA_GetFlags6200(block)==1){
            tiles=MISC_SAVEDATA_EmptyHook(block);
            palette=MISC_SAVEDATA_GetScratchBase(block);
            BG_SYS_LoadTileData(1,tiles,0x6000,0);
            BG_SYS_LoadPltt(1,palette,0x200,0);
            BG_SYS_LoadPltt(5,palette,0x200,0);
            DWCi_ScreenDC_FlushRange(palette,0x200);
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(palette,0x4000,0x200);
            GX_LoadBGExtPltt(palette,0x6000,0x200);
            GX_EndLoadBGExtPltt();
            GXS_BeginLoadBGExtPltt();
            GXS_LoadBGExtPltt(palette,0x4000,0x200);
            GXS_LoadBGExtPltt(palette,0x6000,0x200);
            GXS_EndLoadBGExtPltt();
        }
    }
    SAVE_CONTROL_DeleteExtraSave(save,7);
}



/*
 * volatile: hardware halfword stores to 04000050 at 021BC684 and
 * 04001050 at 021BC688; original clears display blend controls.
 */
int ZUKAN_SEARCH_SCREEN_Init(struct ZukanSearchWork *p)
{
    BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    BG_SYS_SetLcdSwap(0);ZUKAN_SEARCH_SCREEN_SetupVram();ZUKAN_SEARCH_SCREEN_InitBg();
    ZUKAN_SEARCH_SCREEN_LoadGraphics(p);ZUKAN_SEARCH_SCREEN_LoadSaveGraphics(p);
    GFL_NET_RestartWithDefaultTimeout(1,126);BG_SYS_SetSubPlaneVisible(16,1);
    ZUKAN_SEARCH_SCREEN_RegisterVBlank(p);ZUKAN_StartWipeIn(126);
    return 2;
}



int ZUKAN_SEARCH_SCREEN_Delete(struct ZukanSearchWork *p){ZUKAN_SEARCH_SCREEN_UnregisterVBlank(p);ZUKAN_SEARCH_SCREEN_DeleteBg();*(volatile unsigned short *)0x04000050=0;*(volatile unsigned short *)0x04001050=0;BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);return 6;}



int ZUKAN_SEARCH_SCREEN_WaitWipe(void){if(WIPE_SYS_EndCheck()==1)return 4;return 2;}



int ZUKAN_SEARCH_SCREEN_WaitWipeExit(void){if(WIPE_SYS_EndCheck()==1)return 1;return 3;}




int ZUKAN_SEARCH_SCREEN_HandleInput(struct ZukanSearchWork *p)
{
    u32 v = 1;

    if (p->counter == 0x12C)
        return 5;
    p->counter = p->counter + 1;
    if (TOUCHPANEL_GetCont() == 1) {
        UI_SetInputMode(1);
        return 5;
    }
    if (KEY_GetTrg() & 1) {
        UI_SetInputMode(0);
        return 5;
    }
    if (KEY_GetTrg() & 2) {
        UI_SetInputMode(0);
        v = 0;
        p->owner->state = v;
        ZUKAN_StartWipeOut(0x7E);
        return 3;
    }
    if (KEY_GetTrg() & 0x400) {
        UI_SetInputMode(0);
        p->owner->state = v;
        ZUKAN_StartWipeOut(0x7E);
        return 3;
    }
    return 4;
}



int ZUKAN_SEARCH_SCREEN_Update(struct ZukanSearchWork *p)
{
    switch(p->state) {
    case 0:
        if(p->timer == 26) {
            sound(1597);
            p->timer=0;
            p->state++;
        } else {
            setup(3,5,8); setup(1,5,8); setup(2,5,8); setup(5,5,8);
            p->timer++;
        }
        break;
    case 1:
        if(p->timer == 32) {
            sound(1598);
            adjust(3,9,128); adjust(3,12,120); adjust(7,9,128); adjust(7,12,96);
            p->timer=0;
            p->state++;
        } else { p->timer++; }
        break;
    case 2:
        tick();
        if(p->timer == 4) {
            transition(0,0,0,0,6,4,126);
            p->timer=0;
            p->state++;
        } else { p->timer++; }
        break;
    case 3:
        tick();
        if(idle() == 1) {
            p->owner->state=2;
            return 1;
        }
        break;
    }
    return 5;
}


void ZUKAN_SEARCH_SCREEN_Tick(void)
{
    BG_SYS_SetScrollY(3, 4, 0x80);
    BG_SYS_SetScrollY(3, 7, 0x80);
    BG_SYS_SetScrollY(7, 4, 0x80);
    BG_SYS_SetScrollY(7, 7, 0x80);
}
