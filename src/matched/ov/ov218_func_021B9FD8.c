/*
 * function: UN_SELECT_SceneStepList,UN_SELECT_IsMessageDone
 * unit: yes
 * address: 0x021B9FD8
 * packet: pkt_ov218_021B9FD8
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the task-state call merges a ternary int argument; a narrow prototype emitted an extra truncation pair despite the callee storing a halfword.
 * function_starts: 0x021BA0AC (four-byte return-one follower)
 * ov067 tokens follow same-overlay A138's task-state interface and 9890's 63D0 target.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   FRAME_LIST_SetRowPalette 0x021B9280 thumb ov067
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 *   UN_SELECT_UpdateTouchBar 0x021B9890 thumb ov218
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   UN_SELECT_SetMode 0x021B9F98 thumb ov218
 */
#include "../include/Obj02931.h"
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
struct S;
extern int FRAME_LIST_Update(struct S *p);
extern int FRAME_LIST_GetSelectedIndex(char *);
extern int FRAME_LIST_GetCursor(char *);
typedef unsigned char  u8;
extern void FRAME_LIST_SetRowPalette(u8 *p, int a, u32 b);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void UI_SCENE_SetNextScene(unsigned char *,int);
extern void UN_SELECT_UpdateTouchBar(void *);
extern int TOUCHBAR_GetPressedButtonIdIfDone(unsigned char *);
extern void UN_SELECT_SetMode(u8 *p, int mode);
int UN_SELECT_SceneStepList(unsigned char *task,char *p)
{
    int active=0;
    int selected;
    ((struct Obj02931 *)p)->f32C=0;
    if(KEY_GetTrg()&0x200)active=1;
    else if(KEY_GetTrg()&0x100)active=1;
    if(active) ((struct Obj02931 *)p)->f32C=1;
    if((u32)FRAME_LIST_Update(((struct Obj02931 *)p)->f2C)<4){
        selected=FRAME_LIST_GetSelectedIndex(*(char * *)&((struct Obj02931 *)p)->f2C);
        if(*(u32 *)((u32)p+0x34+(u32)selected*4)==1){
            ((struct Obj02931 *)p)->f30=selected;
            FRAME_LIST_SetRowPalette(((struct Obj02931 *)p)->f2C,(unsigned short)FRAME_LIST_GetCursor(*(char * *)&((struct Obj02931 *)p)->f2C),3);
            GFL_USE_PlaySeDefaultVolume(1356);
            UI_SCENE_SetNextScene(task,**(unsigned char * *)&((struct Obj02931 *)p)->f20==131-selected ? 2 : 1);
            return 1;
        }
    }
    UN_SELECT_UpdateTouchBar(((struct Obj02931 *)p)->f8);
    switch(TOUCHBAR_GetPressedButtonIdIfDone(*(unsigned char * *)&((struct Obj02931 *)p)->f8)){
    case -1:case 0:case 2:case 3:case 4:case 5:break;
    case 1:
        UN_SELECT_SetMode((u8 *)p,1);
        UI_SCENE_SetNextScene(task,65534);
        return 1;
    }
    return 0;
}
int UN_SELECT_IsMessageDone(void) { return 1; }
