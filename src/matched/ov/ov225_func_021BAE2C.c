/*
 * function: func_021BAE2C
 * address: 0x021BAE2C
 * packet: pkt_ov225_021BAE2C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: initialise offset after cursor clear, letting zero schedule at
 * that call's argument setup rather than before the touch-mode setter.
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_020355D8 0x020355D8 arm
 *   func_021BB034 0x021BB034 thumb ov225
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_021BB074 0x021BB074 thumb ov225
 *   func_021BB1F4 0x021BB1F4 thumb ov225
 *   func_021BB044 0x021BB044 thumb ov225
 *   func_021BB088 0x021BB088 thumb ov225
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 */
#include "../include/Obj00074.h"
#include "../include/Obj26201.h"
#include "../include/Obj26202.h"
#include "../include/Obj26203.h"
#include "../include/Obj26204.h"
#include "../include/Obj26205.h"
#include "../include/Obj26206.h"
#include "../include/Obj26207.h"
#include "../include/Obj26208.h"
#include "../include/Obj26209.h"
#include "../include/Obj26210.h"
#include "../include/Obj26211.h"
#include "../include/Obj26212.h"
#include "../include/Obj26213.h"
#include "../include/Obj26214.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct Obj;struct Vec2 {short x,y;};
extern u32 CLACT_GetActorDrawEnable(struct Obj *);
extern u32 TOUCHPANEL_GetPointCont(u32 *,u32 *),TOUCHPANEL_GetPointTrg(u32 *,u32 *);
extern void func_020355D8(u8);
extern u16 func_021BB034(u16 **),func_021BB074(u16 **),func_021BB044(u16 **);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void CLACT_AddActorSurfacePos(struct Obj *,const struct Vec2 *,u32);
extern u16 func_021BB1F4(void *,u16,u16);
extern void func_021BB088(char *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
int func_021BAE2C(char *p)
{
    u32 dragx,dragy;
    struct Vec2 drag;
    u32 clickx,clicky;
    struct Vec2 click;
    if(CLACT_GetActorDrawEnable(*(struct Obj * *)&((struct Obj00074 *)p)->f5C)==0) return 0;
    if(((struct Obj00074 *)p)->f88) {
        if(TOUCHPANEL_GetPointCont(&dragx,&dragy)) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
            offset=0;
            drag.x=240;
            if(dragy>=8) offset=dragy-8;
            drag.y=offset;
            if(drag.y<17) drag.y=17;
            else if(drag.y>135) drag.y=135;
            CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&drag,1);
            selection=func_021BB1F4(p,(u16)(func_021BB074((u16 **)p)+1),(u16)dragy);
            if(selection!=((struct Obj26201 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC) {
                ((struct Obj26202 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC=selection;
                end=func_021BB044((u16 **)p);
                if(((struct Obj00074 *)p)->f8C || ((struct Obj26203 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE<((struct Obj26204 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC || end<((struct Obj26205 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE) {
                    ((struct Obj26207 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE=((struct Obj26206 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC;
                    ((struct Obj00074 *)p)->f8C=1;
                }
                func_021BB088(p);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else ((struct Obj00074 *)p)->f88=0;
        return 1;
    } else {
        if(TOUCHPANEL_GetPointTrg(&clickx,&clicky) && clickx>=240 && clickx<=247 && clicky>=17 && clicky<=150) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
            offset=0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            ((struct Obj00074 *)p)->f88=1;
            click.x=240;
            if(clicky>=8) offset=clicky-8;
            click.y=offset;
            if(click.y<17) click.y=17;
            else if(click.y>135) click.y=135;
            CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C,&click,1);
            selection=func_021BB1F4(p,(u16)(func_021BB074((u16 **)p)+1),(u16)clicky);
            if(selection!=((struct Obj26208 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC) {
                ((struct Obj26209 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC=selection;
                end=func_021BB044((u16 **)p);
                if(((struct Obj00074 *)p)->f8C || ((struct Obj26210 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE<((struct Obj26211 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC || end<((struct Obj26212 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE) {
                    ((struct Obj26214 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE=((struct Obj26213 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC;
                    ((struct Obj00074 *)p)->f8C=1;
                }
                func_021BB088(p);
            }
        }
        if(((struct Obj00074 *)p)->f88) return 1;
        return 0;
    }
}
