/*
 * function: COMM_BTL_DEMO_MAIN_DeleteGraphics
 * address: 0x021BA7B8
 * packet: pkt_ov213_021BA7B8
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded 0x021BA9C0 thumb ov213
 *   COMM_BTL_DEMO_MAIN_DeleteEffectManager 0x021BA8D4 thumb ov213
 *   G3D_UTIL_Delete 0x02047E54 arm
 */
#include "../include/Obj10931.h"
struct Rec;
extern void COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded(void *);
extern void COMM_BTL_DEMO_MAIN_DeleteEffectManager(char *p);
extern void G3D_UTIL_Delete(struct Rec *p);
void COMM_BTL_DEMO_MAIN_DeleteGraphics(char *p){COMM_BTL_DEMO_MAIN_UnloadObjectIfLoaded(p);COMM_BTL_DEMO_MAIN_DeleteEffectManager(p);G3D_UTIL_Delete(((struct Obj10931 *)p)->f8);}
