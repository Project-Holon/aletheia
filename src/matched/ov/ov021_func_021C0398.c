/*
 * function: EVENT_DISAPPEAR_RunSpinFade
 * address:  0x021C0398
 * packet:   pkt_ov021_021C0398
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinEaseIn  0x021C7260  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_TASK_CreateWait  0x021C77D8  thumb  ov021
 *   FIELD_TASK_CreateFade  0x021C7814  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_CAMERA_ANIME_Create  0x0218FE80  thumb  ov021
 *   FIELD_CAMERA_ANIME_SetData  0x0218FEA0  thumb  ov021
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 *   FIELD_CAMERA_ANIME_ApplyStartParam  0x0218FEC0  thumb  ov021
 *   FIELD_CAMERA_ANIME_Start  0x0218FF00  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   FIELD_CAMERA_ANIME_Restore  0x0218FF20  thumb  ov021
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 */
#include "../include/Obj01863.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct { u32 w[8]; } Blk32;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned short u16;
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void *FIELD_TASK_CreatePlayerSpinEaseIn(u32 a, u16 b, int c);
extern void *FIELD_TASK_CreatePlayerSpinLinear(u32 a, u32 b, u32 c);
extern u32 FIELD_TASK_CreateWait(u32 a, u32 b);
extern u32 FIELD_TASK_CreateFade(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void *FIELD_CAMERA_ANIME_Create(void *a);
extern void FIELD_CAMERA_ANIME_SetData(u8 *p, u32 v);
extern void FIELD_CAMERA_ANIME_Setup(u32 a);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(u32 a, u8 *b);
extern void FIELD_CAMERA_ANIME_ApplyStartParam(u8 *o);
extern int FIELD_CAMERA_ANIME_Start(u32 a);
extern int FIELD_TASK_MANAGER_IsEmpty(u32 a);
extern void FIELD_CAMERA_ANIME_Restore(u8 *a);
extern void FIELD_CAMERA_ANIME_Delete(void *a0);

int EVENT_DISAPPEAR_RunSpinFade(u32 task, int *st, u8 *p)
{
    u32 obj;
    u32 h;
    u32 d;
    u32 a;
    u32 b;
    u32 c;
    u32 e;

    obj = ((struct Obj01863 *)p)->f4;
    FIELDMAP_GetFieldPlayer((void *)obj);
    h = (u32)FIELDMAP_GetCamera((void *)(((struct Obj01863 *)p)->f4));
    d = FIELDMAP_GetTaskManager((u8 *)obj);

    switch (*st) {
    case 0:
        a = (u32)FIELD_TASK_CreatePlayerSpinEaseIn(obj, 0x14, 3);
        b = (u32)FIELD_TASK_CreatePlayerSpinLinear(obj, 0x14, 5);
        c = FIELD_TASK_CreateWait(obj, 0x1e);
        e = FIELD_TASK_CreateFade(obj, 3, 0, 0x10, 1);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (u32 *)a, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (u32 *)b, a);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (u32 *)c, 0);
        FIELD_TASK_MANAGER_AddTask((u8 *)d, (u32 *)e, c);
        if (((struct Obj01863 *)p)->f10 != 0)
            GFL_USE_PlaySeDefaultVolume(0x6E7);
        else
            GFL_USE_PlaySeDefaultVolume(0x676);
        b = (u32)FIELD_CAMERA_ANIME_Create((void *)obj);
        ((struct Obj01863 *)p)->f24 = 0x3c;
        ((struct Obj01863 *)p)->f68 = 1;
        ((struct Obj01863 *)p)->f6C = 1;
        ((struct Obj01863 *)p)->f70 = b;
        FIELD_CAMERA_ANIME_SetData((u8 *)b, (u32)(p + 0x24));
        FIELD_CAMERA_ANIME_Setup(((struct Obj01863 *)p)->f70);
        FIELD_CAMERA_ANIME_GetCurrentParam(h, p + 0x28);
        *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
        ((struct Obj01863 *)p)->f4C -= 0x64000;
        FIELD_CAMERA_ANIME_ApplyStartParam((u8 *)(((struct Obj01863 *)p)->f70));
        FIELD_CAMERA_ANIME_Start(((struct Obj01863 *)p)->f70);
        *st = *st + 1;
        break;
    case 1:
        if (FIELD_TASK_MANAGER_IsEmpty(d))
            *st = *st + 1;
        break;
    case 2:
        FIELD_CAMERA_ANIME_Restore((u8 *)(((struct Obj01863 *)p)->f70));
        FIELD_CAMERA_ANIME_Delete((void *)(((struct Obj01863 *)p)->f70));
        return 1;
    }
    return 0;
}
