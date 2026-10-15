/*
 * function: COMM_BTL_DEMO_MAIN_UpdateExit
 * address: 0x021B9D4C
 * packet: pkt_ov213_021B9D4C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_BTL_DEMO_MAIN_GetSoundId 0x021B98DC thumb ov213
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 *   COMM_BTL_DEMO_MAIN_Exit 0x021B9830 thumb ov213
 */
#include "../include/Obj14692.h"
#include "../include/Obj25691.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int COMM_BTL_DEMO_MAIN_GetSoundId(int,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void UI_SCENE_SetNextScene(unsigned char *task, int value);
extern void COMM_BTL_DEMO_MAIN_Exit(u8 *task, char *p);
int COMM_BTL_DEMO_MAIN_UpdateExit(u8 *task,char *p) {if(((struct Obj14692 *)p)->f49CC==2){GFL_USE_PlaySeDefaultVolume(COMM_BTL_DEMO_MAIN_GetSoundId(4,((struct Obj25691 *)(*(char * *)&((struct Obj14692 *)p)->f4))->f50));UI_SCENE_SetNextScene(task,2);return 1;}COMM_BTL_DEMO_MAIN_Exit(task,p);return 1;}
