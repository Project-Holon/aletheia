/*
 * function: ZKNSEARCH_MAIN_ShowResultLayout
 * address: 0x021BCC2C
 * packet: pkt_ov210_021BCC2C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte alignment padding at 0x021BCCA6.
 * prototype: 02012BF8 caller sets r0/r1 only; legacy own C lists two unused extra parameters.
 * symbols:
 *   BG_SYS_DrawTile 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   ZKNSEARCH_MAIN_SetActorAnimAuto 0x021BEDB8 thumb ov210
 *   ZKNSEARCH_MAIN_SetActorBgPriority 0x021BEE80 thumb ov210
 */
#include "../include/Obj14672.h"
typedef unsigned int u32;
typedef unsigned char u8;
extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);
extern void func_02041B6C(u32);
extern int GAME_DATA_CheckSaveFlag(int, int);
extern void ZKNSEARCH_MAIN_SetActorAnimAuto(int p, int i, int v);
extern void ZKNSEARCH_MAIN_SetActorBgPriority(int p, int i, unsigned v);
void ZKNSEARCH_MAIN_ShowResultLayout(char *p)
{
    BG_SYS_DrawTile(1, ((struct Obj14672 *)p)->f2BC, 0, 17, 32, 6);
    func_02041B6C(1);
    ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 2, 15);
    ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 3, 14);
    if (GAME_DATA_CheckSaveFlag(**(int * *)&((struct Obj14672 *)p)->f0, 16) == 1)
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 4, 22);
    else
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 4, 21);
    ZKNSEARCH_MAIN_SetActorBgPriority((int)p, 2, 1);
    ZKNSEARCH_MAIN_SetActorBgPriority((int)p, 3, 1);
    ZKNSEARCH_MAIN_SetActorBgPriority((int)p, 4, 1);
}
