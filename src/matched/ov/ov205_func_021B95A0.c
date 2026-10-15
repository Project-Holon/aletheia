/*
 * function: SAVE_SCREEN_Init
 * address: 0x021B95A0
 * packet: pkt_ov205_021B95A0
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082A7C 0x02082A7C arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_020071F0 0x020071F0 thumb
 */
#include "../include/Obj04611.h"
typedef unsigned short u16;
extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082A7C(unsigned,void *,unsigned);
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Sub020071E4Ctrl;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
int SAVE_SCREEN_Init(void *owner,int unused,void **args)
{
    void *context;
    char *p;
    context=*args;
    GFL_HEAP_CreateChildHeap(1,84,1<<18);
    p=PROCSYS_AllocProcWork(owner,76,84);
    func_02082A7C(0,p,76);
    ((struct Obj04611 *)p)->f0=84;
    ((struct Obj04611 *)p)->f2=36;
    ((struct Obj04611 *)p)->f4=GAMESYSTEM_GetGameData(context);
    ((struct Obj04611 *)p)->f8=GAME_DATA_GetMyStatus(((struct Obj04611 *)p)->f4);
    if(func_020071F0(GAME_DATA_GetSaveControl(((struct Obj04611 *)p)->f4))!=0)
        ((struct Obj04611 *)p)->f40=1;
    return 1;
}
