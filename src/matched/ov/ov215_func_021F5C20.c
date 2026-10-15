/*
 * function: EGG_DEMO_MAIN_Init
 * address: 0x021F5C20
 * packet: pkt_ov215_021F5C20
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   EGG_DEMO_GRAPHIC_Create 0x021F63CC thumb ov215
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_020056A0 0x020056A0 thumb
 *   EGG_DEMO_MAIN_OnVBlank 0x021F5C08 thumb ov215
 *   EGG_DEMO_MAIN_LoadGraphics 0x021F5D4C thumb ov215
 *   EGG_DEMO_MAIN_InitActors 0x021F5DAC thumb ov215
 *   EGG_DEMO_MENU_Create 0x021F6060 thumb ov215
 *   EGG_DEMO_MENU_InitDialog 0x021F6280 thumb ov215
 *   func_0204047C 0x0204047C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02040EBC 0x02040EBC arm
 *   EGG_DEMO_VIEW_Create 0x021F6720 thumb ov215
 */
#include "../include/Obj03372.h"
#include "../include/Obj25737.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Context; struct GfFont;
extern void func_02040588(unsigned char which, unsigned char enable);
extern char *EGG_DEMO_GRAPHIC_Create(u32,u16);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern void *func_020056A0(u32,u32,u32);
extern void EGG_DEMO_MAIN_OnVBlank(void *unused, char *p);
extern void EGG_DEMO_MAIN_LoadGraphics(int,char *);
extern void EGG_DEMO_MAIN_InitActors(int,struct Context *);
extern void EGG_DEMO_MENU_Create(int,char *);
extern void EGG_DEMO_MENU_InitDialog(int,u8 *);
extern void func_0204047C(int,u16);
extern void func_0207D63C(u32 *,u32,u32,int,int);
extern void func_02040EBC(u32,u32);
extern char *EGG_DEMO_VIEW_Create(u32,void *);
void EGG_DEMO_MAIN_Init(int a,char *p)
{
    u8 i;
    for (i=0;i<=7;i++) func_02040588(i,0);
    ((struct Obj03372 *)p)->f4=EGG_DEMO_GRAPHIC_Create(1,((struct Obj03372 *)p)->f0);
    ((struct Obj03372 *)p)->f8=GF_FONT_Create(23,0,0,0,((struct Obj03372 *)p)->f0);
    ((struct Obj03372 *)p)->fC=PRINTSYS_QUE_Create((void *)(u32)((struct Obj03372 *)p)->f0);
    ((struct Obj03372 *)p)->f28=func_020056A0((u32)EGG_DEMO_MAIN_OnVBlank,(u32)p,1);
    EGG_DEMO_MAIN_LoadGraphics(a,p);
    EGG_DEMO_MAIN_InitActors(a,(struct Context *)p);
    EGG_DEMO_MENU_Create(a,p);
    EGG_DEMO_MENU_InitDialog(a,(u8 *)p);
    func_0204047C(0,2);
    func_0204047C(2,1);
    func_0204047C(1,0);
    func_0204047C(4,0);
    func_02040588(0,1);
    func_02040588(2,1);
    func_02040588(4,1);
    func_0207D63C((u32 *)0x04000050,1,47,0,0);
    func_02040EBC(0,0x4210);
    func_02040EBC(4,0);
    *(char * *)&((struct Obj03372 *)p)->f80=EGG_DEMO_VIEW_Create(((struct Obj03372 *)p)->f0,((struct Obj25737 *)((u32)a))->f4);
}
