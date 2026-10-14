/*
 * function: HALL_OF_FAME_CreateTrainerSceneObjects
 * address: 0x021B7D80
 * packet: pkt_ov180_021B7D80
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 CLACT_SetUnitRenderer; all concrete bytes match, 29/30 sites resolve.
 *   src/matched/arm9/unit_0204B22C.c defines CLACT_SetUnitRenderer but its function:
 *   line lists only CLACT_SetUnitDrawEnable. the integrator must add the missing unit entry.
 *   Scratch one --arm, dsi/1.1p1 -O4,p -lang c99: EXACT, 24 bytes, no sites.
 *   Verified C:
 *   typedef unsigned char u8;
 *   typedef unsigned int u32;
 *   struct Bank {
 *       u8 pad00[8]; void *f8; u8 pad0c[2];
 *       u8 source:4; u8 mode:4; u8 pad0f[9];
 *   };
 *   void CLACT_SetUnitRenderer(struct Bank *bank,void *p) {
 *       bank->f8=p;
 *       bank->source=1;
 *   }
 * arity: caller consumes live r0 after void 75A4/2DA48/2DA18;
 *   B0F4 forwards caller-loaded object and flag to BE38; 2DA04's unused
 *   trailing parameters are neither supplied nor read/forwarded in its body.
 * symbols:
 *   HALL_OF_FAME_LoadUiResources 0x021B7C78 thumb ov180
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetRendererCulling 0x0204B0F4 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   HALL_OF_FAME_CreateActorFromTemplate 0x021B75A4 thumb ov180
 *   HALL_OF_FAME_SetActorVisible 0x021B746C thumb ov180
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02008550 0x02008550 thumb
 *   POKEGRA_OpenTrainerHandle 0x0202DA04 thumb
 *   POKEGRA_RegisterTrainerCgr 0x0202DA48 thumb
 *   POKEGRA_RegisterTrainerPalette 0x0202DA18 thumb
 *   POKEGRA_RegisterTrainerCellAnim 0x0202DA6C thumb
 *   HALL_OF_FAME_CreateTrainerPlates 0x021B79F4 thumb ov180
 *   gHallOfFameRendererSetup 0x021B82B4 data a4
 *   gHallOfFameRingTopTemplate 0x021B8204 data a4
 *   gHallOfFameRingBottomTemplate 0x021B81EC data a4
 *   gHallOfFameTrainerTopTemplate 0x021B824C data a4
 *   gHallOfFameTrainerBottomTemplate 0x021B8264 data a4
 */

#include "../include/G_021B81EC.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u32 w[8]; } Setup;
struct Actor; struct Bank; struct Player;
extern const Setup gHallOfFameRendererSetup;
extern struct G_021B81EC gHallOfFameRingBottomTemplate;
extern const char gHallOfFameRingTopTemplate[], gHallOfFameTrainerTopTemplate[], gHallOfFameTrainerBottomTemplate[];
extern void HALL_OF_FAME_LoadUiResources(char *);
struct Obj;
struct Sub0200852CObj;
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
extern void CLACT_SetRendererCulling(struct Actor *a0, int a1);
extern void CLACT_SetUnitRenderer(struct Bank *,void *);
extern struct Obj *HALL_OF_FAME_CreateActorFromTemplate(char *p, const char *q);
extern void HALL_OF_FAME_SetActorVisible(int *,int,int);
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern signed int CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern void ARC_TOOL_DeleteHandle(u8 *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern int POKEGRA_OpenTrainerHandle(int);
extern u32 POKEGRA_RegisterTrainerCgr(u32,u32,u32,u32);
typedef signed int     s32;
extern s32 POKEGRA_RegisterTrainerPalette(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int POKEGRA_RegisterTrainerCellAnim(int a0, int a1, int a2, unsigned short a3);
extern void HALL_OF_FAME_CreateTrainerPlates(char *);
void HALL_OF_FAME_CreateTrainerSceneObjects(char *p) {
    Setup s;
    u8 *h;
    int mode;
    HALL_OF_FAME_LoadUiResources(p);
    s=gHallOfFameRendererSetup;
    *(struct Actor **)(p+0x9118)=(struct Actor *)CLACT_CreateRenderer((u8 *)&s,2,141);
    CLACT_SetRendererCulling(*(struct Actor **)(p+0x9118),1);
    CLACT_SetUnitRenderer(*(struct Bank **)(p+0x9044),*(void **)(p+0x9118));
    *(u32 *)(p+0x9064)=(u32)HALL_OF_FAME_CreateActorFromTemplate(p,gHallOfFameRingTopTemplate);
    *(u32 *)(p+0x9068)=(u32)HALL_OF_FAME_CreateActorFromTemplate(p,((char *)&gHallOfFameRingBottomTemplate));
    HALL_OF_FAME_SetActorVisible((int *)p,7,0); HALL_OF_FAME_SetActorVisible((int *)p,8,0);
    h=func_020490F4(216,0x808d);
    *(int *)(p+0x90e0)=CLACT_RegisterCharacter(h,25,0,1,141);
    *(u32 *)(p+0x90fc)=CLACT_RegisterPalette(h,3,1,0,141);
    *(int *)(p+0x9114)=CLACT_RegisterCellAnim(h,27,33,141);
    ARC_TOOL_DeleteHandle(h);
    mode=1;
    if(!func_02008550((const struct Sub0200852CObj *)(*(struct Player **)(*(char **)p+4)))) mode=0;
    h=(u8 *)POKEGRA_OpenTrainerHandle(0x808d);
    *(u32 *)(p+0x90d8)=POKEGRA_RegisterTrainerCgr((u32)h,mode,0,141);
    *(u32 *)(p+0x90f4)=POKEGRA_RegisterTrainerPalette((u32)h,mode,0,192,141);
    *(int *)(p+0x910c)=POKEGRA_RegisterTrainerCellAnim(mode,2,0,141);
    *(u32 *)(p+0x90dc)=POKEGRA_RegisterTrainerCgr((u32)h,mode,1,141);
    *(u32 *)(p+0x90f8)=POKEGRA_RegisterTrainerPalette((u32)h,mode,1,96,141);
    *(int *)(p+0x9110)=POKEGRA_RegisterTrainerCellAnim(mode,0,1,141);
    ARC_TOOL_DeleteHandle(h);
    *(u32 *)(p+0x905c)=(u32)HALL_OF_FAME_CreateActorFromTemplate(p,gHallOfFameTrainerTopTemplate);
    *(u32 *)(p+0x9060)=(u32)HALL_OF_FAME_CreateActorFromTemplate(p,gHallOfFameTrainerBottomTemplate);
    HALL_OF_FAME_CreateTrainerPlates(p);
}
