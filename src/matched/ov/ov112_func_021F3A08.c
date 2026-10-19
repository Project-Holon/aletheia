/*
 * unit: yes
 * function: MUSICAL_SHOT_SYS_Update, MUSICAL_SHOT_SYS_VBlank
 * address: 0x021F3A08
 * packet: pkt_ov112_021F3A08
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: tail stub at 0x021F3A4C; function_starts seed.
 * symbols:
 *   MUSICAL_SHOT_SYS_DrawScene 0x021F3C50 thumb ov112
 *   MUSICAL_SHOT_INFO_Main 0x021F4350 thumb ov112
 *   MUSICAL_SHOT_INFO_IsFinished 0x021F44E8 thumb ov112
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj08020.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void MUSICAL_SHOT_SYS_DrawScene(u8 *);
typedef unsigned int   u32;
extern void MUSICAL_SHOT_INFO_Main(u8 *p);
extern int MUSICAL_SHOT_INFO_IsFinished(u32 *p);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int MUSICAL_SHOT_SYS_Update(int a,int b,int c,u8 *p)
{
    MUSICAL_SHOT_SYS_DrawScene(*(u8 * *)&((struct Obj08020 *)p)->fC);
    MUSICAL_SHOT_INFO_Main(((struct Obj08020 *)p)->f10);
    CLACT_DrawSystem();
    if(MUSICAL_SHOT_INFO_IsFinished(((struct Obj08020 *)p)->f10)==1) {
        WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj08020 *)p)->f0);
        return 1;
    }
    return 0;
}
void MUSICAL_SHOT_SYS_VBlank(void) { CLACT_VBlankSystem(); }
