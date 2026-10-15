/*
 * function: UN_SELECT_SceneDelete
 * address: 0x021B95D0
 * packet: pkt_ov218_021B95D0
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware BLDCNT writes at 021B9614 and 021B9618
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_02030EAC 0x02030EAC arm
 *   UN_SELECT_DeleteFrameList 0x021B9E28 thumb ov218
 *   UI_SCENE_Delete 0x021B613C thumb ov067
 *   UN_SELECT_DeleteRecord 0x021B9A80 thumb ov218
 *   UN_SELECT_DeleteActor 0x021BA4B4 thumb ov218
 *   UN_SELECT_ReleaseActors 0x021BA2EC thumb ov218
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   UN_SELECT_Delete 0x021B9888 thumb ov218
 *   UN_SELECT_GRAPHIC_Delete 0x021BA8F0 thumb ov218
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data a1
 */
#include "../include/Obj01983.h"
typedef unsigned short u16;
struct Node;
struct TaskMenuState;
struct Proc;
extern void FADE_Start(unsigned int, int, int, int);
extern int FADE_IsActive(void);
extern void func_02030EAC(struct Node *);
extern void UN_SELECT_DeleteFrameList(char *);
extern void UI_SCENE_Delete(void *);
extern void UN_SELECT_DeleteRecord(char *);
extern void UN_SELECT_DeleteActor(char *);
extern void UN_SELECT_ReleaseActors(char *);
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
typedef unsigned char  u8;
extern void UN_SELECT_Delete(u8 *p);
extern void UN_SELECT_GRAPHIC_Delete(char *);
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void func_02034A5C(int);
extern char ov067_id[];
int UN_SELECT_SceneDelete(struct Proc *ctx, int *state, void *unused, char *p)
{
    switch (*state) {
    case 0:
        FADE_Start(3, 0, 16, 1);
        ++*state;
        break;
    case 1:
        if (FADE_IsActive() != 1)
            ++*state;
        break;
    case 2: {
        u16 heap;
        func_02030EAC(*(struct Node * *)&((struct Obj01983 *)p)->f23C);
        *(volatile u16 *)0x04000050 = 0;
        *(volatile u16 *)0x04001050 = 0;
        UN_SELECT_DeleteFrameList(p);
        UI_SCENE_Delete(((struct Obj01983 *)p)->f24);
        UN_SELECT_DeleteRecord(*(char * *)&((struct Obj01983 *)p)->f28);
        UN_SELECT_DeleteActor(p);
        UN_SELECT_ReleaseActors(p);
        APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj01983 *)p)->f18);
        UN_SELECT_Delete(((struct Obj01983 *)p)->f8);
        UN_SELECT_GRAPHIC_Delete(*(char * *)&((struct Obj01983 *)p)->f4);
        heap = ((struct Obj01983 *)p)->f0;
        func_020315D4(ctx);
        GFL_HEAP_DeleteChecked(heap);
        func_02034A5C((int)ov067_id);
        return 1;
    }
    }
    return 0;
}
