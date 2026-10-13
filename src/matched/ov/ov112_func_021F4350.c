/*
 * function: func_021F4350
 * address: 0x021F4350
 * packet: pkt_ov112_021F4350
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: byte +8 is re-read after the increment at 0x021F44BA.
 * ABI: 0200A640 leaves its incoming pointer in r0; the caller copies that return.
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021F4794 0x021F4794 thumb ov112
 *   func_021F485C 0x021F485C thumb ov112
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_0200A640 0x0200A640 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 *   func_021F4804 0x021F4804 thumb ov112
 *   func_0200FB24 0x0200FB24 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   TCBL_Main 0x020310C4 arm
 *   func_02041EE4 0x02041EE4 arm
 *   d_021F8290 0x021F8290 data a1
 */
#include "../include/Obj00226.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 b[8]; } Box;
extern const Box d_021F8290;
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 WIPE_SYS_EndCheck(void);
extern void func_021F4794(u8 *,u32);
extern void func_021F485C(u8 *);
extern void APP_TASKMENU_UpdateMenu(void *);
struct Actor;
struct Descriptor;
struct Obj;
struct PrintSys;
struct Rec3;
struct TaskMenu;
struct Tcbl;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void *func_0200A640(void *);
extern void MI_CpuCopy8(const void *,void *,u32);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
extern void func_021F4804(u8 *,u32);
extern u32 func_0200FB24(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern u32 PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern u8 *TIME_ICON_CreateNode(u32,void *,u8,u8,u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void TCBL_Main(struct Tcbl *p);
extern void func_02041EE4(u32,u32,u32);
void func_021F4350(u8 *p)
{
    u8 v;
    switch (((struct Obj00226 *)p)->f4) {
    case 0:
        ((struct Obj00226 *)p)->f4=1;
        GFL_USE_PlaySeDefaultVolume(1583);
    case 1:
        if(WIPE_SYS_EndCheck()==1) {
            if(((struct Obj00226 *)p)->fC==1) {
                func_021F4794(p,3);
                ((struct Obj00226 *)p)->f4=2;
            } else ((struct Obj00226 *)p)->f4=5;
        }
        break;
    case 2:
        if(!((struct Obj00226 *)p)->f24) {
            func_021F485C(p);
            ((struct Obj00226 *)p)->f4=3;
        }
        break;
    case 3:
        APP_TASKMENU_UpdateMenu(((struct Obj00226 *)p)->f3C);
        if(APP_TASKMENU_IsFinish(((struct Obj00226 *)p)->f3C)==1) {
            v=APP_TASKMENU_GetCursorPos(*(u8 * *)&((struct Obj00226 *)p)->f3C);
            APP_TASKMENU_CloseMenu(((struct Obj00226 *)p)->f3C);
            if(v==0) MI_CpuCopy8(((struct Obj00226 *)p)->f10,func_0200A640(((struct Obj00226 *)p)->f14),432);
            if(*(int *)&((struct Obj00226 *)p)->f44) {
                ((struct Obj00226 *)p)->f4=4;
                func_021FCDEC(*(int *)&((struct Obj00226 *)p)->f44,71);
                func_021F4804(p,6);
            } else ((struct Obj00226 *)p)->f4=7;
        } else if(func_0200FB24()!=0) {
            APP_TASKMENU_CloseMenu(((struct Obj00226 *)p)->f3C);
            ((struct Obj00226 *)p)->f4=7;
        }
        break;
    case 4:
        if(func_021FCE00(((struct Obj00226 *)p)->f44,71)==1) ((struct Obj00226 *)p)->f4=7;
        else if(func_0200FB24()!=0) ((struct Obj00226 *)p)->f4=7;
        break;
    case 5:
        if((KEY_GetTrg()&2)||!TOUCHPANEL_HitTrg(&d_021F8290)) {
            GFL_USE_PlaySeDefaultVolume(1361);
            ((struct Obj00226 *)p)->f4=6;
            CLACT_SetActorAnimSeq(((struct Obj00226 *)p)->f58,9);
            CLACT_SetActorAutoAnim(((struct Obj00226 *)p)->f58,1);
        }
        break;
    case 6:
        if(!CLACT_IsActorAnimActive(((struct Obj00226 *)p)->f58)) ((struct Obj00226 *)p)->f4=7;
        break;
    case 7: break;
    }
    if(((struct Obj00226 *)p)->f24&&PRINTSYS_PrintStreamGetState(((struct Obj00226 *)p)->f24)==2) {
        PRINTSYS_PrintStreamDelete(((struct Obj00226 *)p)->f24);
        ((struct Obj00226 *)p)->f24=0;
    }
    PRINTSYS_QUE_Main(((struct Obj00226 *)p)->f38);
    if(((struct Obj00226 *)p)->f30==1&&PRINTSYS_QUE_IsFinished(((struct Obj00226 *)p)->f38)==1) {
        ((struct Obj00226 *)p)->f30=0;
        *(u8 * *)&((struct Obj00226 *)p)->f34=TIME_ICON_CreateNode(*(u32 *)&((struct Obj00226 *)p)->f18,((struct Obj00226 *)p)->f1C,15,16,((struct Obj00226 *)p)->f0);
        BMP_WIN_TransferChars(((struct Obj00226 *)p)->f1C);
    }
    TCBL_Main(((struct Obj00226 *)p)->f18);
    (*(volatile u8 *)&((struct Obj00226 *)p)->f8)++;
    if(*(volatile u8 *)&((struct Obj00226 *)p)->f8>1) {
        *(volatile u8 *)&((struct Obj00226 *)p)->f8=0;
        func_02041EE4(7,1,1);
        func_02041EE4(7,5,1);
    }
}
