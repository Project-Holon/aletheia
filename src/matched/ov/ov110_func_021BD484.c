/*
 * function: PMS_INPUT_ProcInit
 * address: 0x021BD484
 * packet: pkt_ov110_021BD484
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PMS_INPUT_Create 0x021BD5C4 thumb ov110
 *   PMS_INPUT_VIEW_StartTask 0x021B9BEC thumb ov110
 *   PMS_INPUT_VIEW_IsIdle 0x021B9C74 thumb ov110
 *   PMS_INPUT_VIEW_GetEditValue 0x021BABE8 thumb ov110
 *   PMS_INPUT_SetHandler 0x021BD7A0 thumb ov110
 *   PMS_INPUT_HandleMenu 0x021BD894 thumb ov110
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_02030D28 0x02030D28 arm
 *   d_00000043 0x00000043 data a1
 */
#include "../include/Obj03242.h"
typedef unsigned char u8;
typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
extern int func_02034AC4(s32 handle);
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
struct Obj0203159C;
extern u8 *PMS_INPUT_Create(struct Obj0203159C *owner, u8 *input);
extern void PMS_INPUT_VIEW_StartTask(u8 *p, int id);
extern int PMS_INPUT_VIEW_IsIdle(unsigned int a);
extern int PMS_INPUT_VIEW_GetEditValue(u8 *p);
extern void PMS_INPUT_SetHandler(u8 *,int (*)(u8 *,void *));
extern int PMS_INPUT_HandleMenu(u8 *,void *);
extern const u8 d_00000043[];
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void func_02030D28(struct Ctx *c);
int PMS_INPUT_ProcInit(void *a,int *state,int c,void *p) {
    u8 *obj;
    switch(*state) {
    case 0:
        func_02034AC4((int)d_00000043);
        GFL_HEAP_CreateChildHeap(1,41,0x18000);
        GFL_HEAP_CreateChildHeap(1,42,0x32000);
        obj=PMS_INPUT_Create(a,(u8 *)c);
        PMS_INPUT_VIEW_StartTask(((struct Obj03242 *)obj)->f14,0);
        ++*state;
        break;
    case 1:
        obj=p;
        if(PMS_INPUT_VIEW_IsIdle((unsigned int)(((struct Obj03242 *)obj)->f14))) {
            if(((struct Obj03242 *)obj)->f4==2) obj[0x68]=PMS_INPUT_VIEW_GetEditValue(((struct Obj03242 *)obj)->f14);
            else obj[0x68]=0;
            PMS_INPUT_VIEW_StartTask(((struct Obj03242 *)obj)->f14,4);
            ++*state;
        }
        break;
    case 2:
        obj=p;
        if(PMS_INPUT_VIEW_IsIdle((unsigned int)(((struct Obj03242 *)obj)->f14))) {
            PMS_INPUT_SetHandler(obj,PMS_INPUT_HandleMenu);
            GFL_NET_RestartWithDefaultTimeout(1,42);
            return 1;
        }
        break;
    }
    func_02030D28(((struct Obj03242 *)obj)->f7C);
    return 0;
}
