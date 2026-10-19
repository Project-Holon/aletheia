/*
 * function: ZUKAN_SEARCH_SCREEN_LoadSaveGraphics
 * address: 0x021BC5B0
 * packet: pkt_ov211_021BC5B0
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 0725C third parameter widened from matched u8: original
 * supplies full pooled 0x807E, without truncation. 073D8 legacy void
 * leaves a pointer in r0 consumed immediately by E8D8; preserve it.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_0200E8D8 0x0200E8D8 thumb
 *   func_0200E8CC 0x0200E8CC thumb
 *   func_0200E8D0 0x0200E8D0 thumb
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   DC_FlushRange 0x020862F0 arm
 *   func_0207F308 0x0207F308 arm
 *   func_0207F394 0x0207F394 arm
 *   func_0207F428 0x0207F428 arm
 *   func_0207F5B0 0x0207F5B0 arm
 *   func_0207F5C8 0x0207F5C8 arm
 *   func_0207F65C 0x0207F65C arm
 *   func_020072A4 0x020072A4 thumb
 */
#include "../include/Obj10925.h"
typedef unsigned u32;typedef unsigned char u8;
struct Big;struct Ctrl;struct Sub020073D8Ctrl;struct Sub020072A4Ctrl;
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *,u32,u32);
extern void *func_020073D8(struct Sub020073D8Ctrl *,u32,u32);
extern u32 func_0200E8D8(const void *obj);
extern void *func_0200E8CC(void *),*func_0200E8D0(void *);
extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern void BG_SYS_LoadPltt(u32,void *,u32,u32);
extern void DC_FlushRange(void *,unsigned long);
extern void func_0207F308(void),func_0207F394(const void *,u32,u32),func_0207F428(void);
extern void func_0207F5B0(void),func_0207F5C8(const void *,u32,u32),func_0207F65C(void);
extern void func_020072A4(struct Sub020072A4Ctrl *,u32);
void ZUKAN_SEARCH_SCREEN_LoadSaveGraphics(char *p)
{
    void *save,*block,*tiles,*palette;
    save=GAME_DATA_GetSaveControl(*(struct Big **)*(char * *)&((struct Obj10925 *)p)->f0);
    if(SAVE_CONTROL_LoadExtraSave(save,7,0x807e)==1){
        block=func_020073D8(save,7,0);
        if(block!=0&&func_0200E8D8(block)==1){
            tiles=func_0200E8CC(block);
            palette=func_0200E8D0(block);
            BG_SYS_LoadTileData(1,tiles,0x6000,0);
            BG_SYS_LoadPltt(1,palette,0x200,0);
            BG_SYS_LoadPltt(5,palette,0x200,0);
            DC_FlushRange(palette,0x200);
            func_0207F308();
            func_0207F394(palette,0x4000,0x200);
            func_0207F394(palette,0x6000,0x200);
            func_0207F428();
            func_0207F5B0();
            func_0207F5C8(palette,0x4000,0x200);
            func_0207F5C8(palette,0x6000,0x200);
            func_0207F65C();
        }
    }
    func_020072A4(save,7);
}
