/*
 * function: COMM_BTL_DEMO_MAIN_CreateActor
 * address: 0x021BA71C
 * packet: pkt_ov213_021BA71C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   COMM_BTL_DEMO_GRAPHIC_GetCamera 0x021BAC94 thumb ov213
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 */
#include "../include/Obj14696.h"
typedef unsigned int   u32;
extern u32 COMM_BTL_DEMO_GRAPHIC_GetCamera(char *p);extern void *UI_SCENE_CreateActor(void *,int,unsigned char,unsigned char,unsigned char,unsigned short);
void *COMM_BTL_DEMO_MAIN_CreateActor(char *p,int a,int b,unsigned short c){return UI_SCENE_CreateActor(p+8,COMM_BTL_DEMO_GRAPHIC_GetCamera(((struct Obj14696 *)p)->f0),a,b,c,((struct Obj14696 *)p)->f4);}
