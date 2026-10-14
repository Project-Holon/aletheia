/*
 * function: WORLDTRADE_DEPOSIT_Init
 * address: 0x021F73DC
 * packet: pkt_ov135_021F73DC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_DEPOSIT_CreateStrings 0x021F798C thumb ov135
 *   WORLDTRADE_DEPOSIT_SetupBgPlanes 0x021F75C0 thumb ov135
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   WORLDTRADE_DEPOSIT_LoadBgGraphics 0x021F76D8 thumb ov135
 *   WORLDTRADE_DEPOSIT_CreateWindows 0x021F777C thumb ov135
 *   WORLDTRADE_DEPOSIT_CreateActors 0x021F7878 thumb ov135
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 *   WORLDTRADE_DEPOSIT_DrawRequestWindow 0x021F81C8 thumb ov135
 *   WORLDTRADE_DEPOSIT_PrintMonSummary 0x021F8358 thumb ov135
 *   WORLDTRADE_INPUT_MenuCreate 0x021F9890 thumb ov135
 */
#include "../include/Obj01159.h"
#include "../include/Obj23379.h"
#include "../include/Obj23380.h"
#include "../include/Obj23381.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { void *a,*b,*obj,*d,*e,*f,*g,*h,*i; u32 j,k,l; } Init;
extern void WORLDTRADE_DEPOSIT_CreateStrings(u8 *);
extern void WORLDTRADE_DEPOSIT_SetupBgPlanes(void);
extern void WORLDTRADE_TITLE_ScrollBg(u8 *,u32,u32);
extern void WORLDTRADE_DEPOSIT_LoadBgGraphics(void *);
extern void WORLDTRADE_DEPOSIT_CreateWindows(void *);
extern void WORLDTRADE_DEPOSIT_CreateActors(u8 *);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void WORLDTRADE_ENTER_RestartNetTimeout(u8 *);
extern void WORLDTRADE_DEPOSIT_DrawRequestWindow(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
extern void WORLDTRADE_DEPOSIT_PrintMonSummary(void *,void *,void **,void *,void *,void *);
extern void *WORLDTRADE_INPUT_MenuCreate(Init *,u32,u32);
int WORLDTRADE_DEPOSIT_Init(u8 *p)
{
    Init init;
    WORLDTRADE_DEPOSIT_CreateStrings(p);
    WORLDTRADE_DEPOSIT_SetupBgPlanes();
    WORLDTRADE_TITLE_ScrollBg(p,0,0);
    WORLDTRADE_DEPOSIT_LoadBgGraphics(p);
    WORLDTRADE_DEPOSIT_CreateWindows(p);
    WORLDTRADE_DEPOSIT_CreateActors(p);
    WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
    WORLDTRADE_ENTER_RestartNetTimeout(p);
    WORLDTRADE_DEPOSIT_DrawRequestWindow(((struct Obj01159 *)p)->fB6C,((struct Obj01159 *)p)->fB70,(int)(((struct Obj01159 *)p)->fB68),p+0xD90,0,3,-1,p+0xFA0);
    WORLDTRADE_DEPOSIT_PrintMonSummary(((struct Obj01159 *)p)->fB6C,((struct Obj01159 *)p)->fB68,(void **)(p+0xD9C),((struct Obj01159 *)p)->fCC,p+0xB4C,p+0xFA0);
    init.a=p+0xD50;
    init.b=p+0xDD4;
    init.obj=((struct Obj01159 *)p)->fBF8;
    init.d=((struct Obj01159 *)p)->fD2C;
    init.e=((struct Obj01159 *)p)->fD30;
    init.f=0;
    init.g=((struct Obj01159 *)p)->fB6C;
    init.h=((struct Obj01159 *)p)->fB70;
    init.i=((struct Obj01159 *)p)->fB7C;
    init.j=((struct Obj23379 *)(*(u8 * *)&((struct Obj01159 *)p)->f0))->f10;
    init.k=((struct Obj23380 *)(*(u8 * *)&((struct Obj01159 *)p)->fE00))->f14;
    init.l=((struct Obj23381 *)(*(u8 * *)&((struct Obj01159 *)p)->f0))->f20;
    ((struct Obj01159 *)p)->fDE4=WORLDTRADE_INPUT_MenuCreate(&init,2,0);
    ((struct Obj01159 *)p)->f28=0;
    ((struct Obj01159 *)p)->f12E4=0;
    return 1;
}
