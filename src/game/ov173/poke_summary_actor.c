/*
 * file:     poke_summary_actor.c
 * unit:     yes
 * function: POKE_SUMMARY_ACTOR_InitSystem, POKE_SUMMARY_ACTOR_DeleteSystem, POKE_SUMMARY_ACTOR_RegisterResources, POKE_SUMMARY_ACTOR_TransferCharacter, POKE_SUMMARY_ACTOR_SetMoveIcon, POKE_SUMMARY_ACTOR_FlushPendingTransfers, POKE_SUMMARY_ACTOR_LayoutMoveActors, POKE_SUMMARY_ACTOR_SetMoveAnim, POKE_SUMMARY_ACTOR_CreateActors, POKE_SUMMARY_ACTOR_PositionMonActor, POKE_SUMMARY_ACTOR_StartWipe, POKE_SUMMARY_ACTOR_StartProc, POKE_SUMMARY_ACTOR_StartNetRestart, POKE_SUMMARY_ACTOR_CreateSound, POKE_SUMMARY_ACTOR_UpdateSound, POKE_SUMMARY_ACTOR_Noop, POKE_SUMMARY_ACTOR_SelectRow, POKE_SUMMARY_ACTOR_HandleCursorInput, POKE_SUMMARY_ACTOR_ToggleTaskMenu, POKE_SUMMARY_ACTOR_IsTaskMenuOpen, POKE_SUMMARY_ACTOR_UpdateScrollArrows, POKE_SUMMARY_ACTOR_SetScrollAnim, POKE_SUMMARY_ACTOR_SetIdleAnim, POKE_SUMMARY_ACTOR_OpenDecideWin, POKE_SUMMARY_ACTOR_ConfirmDecide, POKE_SUMMARY_ACTOR_ConfirmDecideById, POKE_SUMMARY_ACTOR_WaitDecide, POKE_SUMMARY_ACTOR_ShowTextKind2, POKE_SUMMARY_ACTOR_ShowTextKind1Or4, POKE_SUMMARY_ACTOR_SetSubBrightness
 * address:  0x021B7658
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021B820C 0x021B820C data a4
 *   d_021B8250 0x021B8250 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02027618 0x02027618 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   func_020275F8 0x020275F8 thumb
 *   func_02027614 0x02027614 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   func_020275E8 0x020275E8 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_02049E74 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   func_020275EC 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021B85E0 0x021B85E0 data a4
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   k_83 0x00000083 data a1
 *   POKE_SUMMARY_MAIN_ExitScreen 0x021B6460 thumb ov173
 *   POKE_SUMMARY_MAIN_GetRecordWord 0x021B7438 thumb ov173
 *   ICA_ANIME_GetField1C 0x020120F4 thumb
 *   GAMESYSTEM_CallProc 0x020120B4 thumb
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   POKE_SUMMARY_MAIN_InitScreen  0x021B63AC  thumb  ov173
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   CURSOR_MOVE_Create 0x02025CD0 thumb
 *   CURSOR_MOVE_ClearSkipBit 0x02026124 thumb
 *   d_021B83A8 0x021B83A8 data a4
 *   d_021B81DC 0x021B81DC data a4
 *   CURSOR_MOVE_Delete  0x02025D14  thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   POKE_SUMMARY_MAIN_DrawMoveDetail 0x021B71C4 thumb ov173
 *   POKE_SUMMARY_MAIN_RedrawMoveList 0x021B70D8 thumb ov173
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   CURSOR_MOVE_SetSkipBit 0x0202614C thumb
 *   func_020409B4 0x020409B4 arm
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   POKE_SUMMARY_MAIN_StartTextStream  0x021B7460  thumb  ov173
 *   POKE_SUMMARY_MAIN_CountFreeMoves 0x021B7568 thumb ov173
 *   func_0207D658  0x0207D658  arm
 */
#include "../../matched/include/Obj00362.h"
#include "../../matched/include/Obj01267.h"
#include "../../matched/include/Obj24181.h"
#include "../../matched/include/Obj03857.h"
#include "../../matched/include/Obj24182.h"
#include "../../matched/include/Obj24183.h"
#include "../../matched/include/Obj24184.h"
#include "../../matched/include/Obj24185.h"
#include "../../matched/include/Obj00180.h"
#include "../../matched/include/Obj05451.h"
#include "../../matched/include/Obj24186.h"
#include "../../matched/include/Obj02217.h"
#include "../../matched/include/Obj10670.h"
#include "../../matched/include/Obj24187.h"
#include "../../matched/include/Obj06566.h"
#include "../../matched/include/Obj24188.h"
#include "../../matched/include/Obj24189.h"
#include "../../matched/include/Obj24190.h"
#include "../../matched/include/Obj24191.h"
#include "../../matched/include/Obj02506.h"
#include "../../matched/include/Obj24192.h"
#include "../../matched/include/Obj24193.h"
#include "../../matched/include/Obj24194.h"
#include "../../matched/include/Obj24195.h"
#include "../../matched/include/Obj10671.h"
#include "../../matched/include/Obj24196.h"
#include "../../matched/include/Obj08266.h"
#include "../../matched/include/Obj05452.h"
#include "../../matched/include/Obj14319.h"
#include "../../matched/include/Obj14320.h"

#define S(p) (*(char **)(p))
struct Cfg;
struct Bank;
struct Obj;
struct Sav;
struct Sub0204A9D0;
struct Vec2;
struct Ctx;
struct IcaAnime;
struct Struct_02025CD0;
struct Sound;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { OFFSET=14 } Offset;

typedef struct {short x,y;u16 unused,z;u32 a,b,c,d,e,f,g,h,i;} Row;

typedef struct {short x,y;u16 z;u8 a,b;} Position;

extern void CLACT_InitSystem(const struct Cfg *,u32,u32);
extern struct Bank *CLACT_CreateUnit(int,u8,u32);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void CLACT_DeleteActor(struct Obj *);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02027618(void);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern u32 func_020275F8(u32);
extern u32 func_02027614(void);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern u32 func_020275E8(void);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern u32 func_020275FC(u32);
extern u32 func_02027600(u32);
extern int POKEGRA_OpenHandle(int);
extern void *func_020185F0(void *);
extern u32 func_02017DBC(struct Sav *p);
extern int POKEGRA_RegisterCgrPP(int,void *,int,int,u16);
extern int POKEGRA_RegisterPalettePP(int,void *,int,int,u16,u16);
extern u32 POKEGRA_RegisterCellAnimPP(u32,u32,u32,u32,u16);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferCharacter(int,struct Sub0204A9D0 *);
extern u32 func_020307B0(void *p);
/* The original forwards the full entry r1 without halfword truncation. */
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern u8 func_020275EC(int i);
extern void CLACT_SetActorPaletteOffset(struct Obj *,u32,u32);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void POKE_SUMMARY_MAIN_ExitScreen(char *);
extern u16 POKE_SUMMARY_MAIN_GetRecordWord(char **);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern void POKE_SUMMARY_MAIN_InitScreen(u8 *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern struct Struct_02025CD0 *CURSOR_MOVE_Create(u32,u32,u32,u32,u8,u16);
extern void CURSOR_MOVE_ClearSkipBit(struct Sound *,u32);
extern u32 CURSOR_MOVE_Delete(void *a0);
extern void POKE_SUMMARY_MAIN_DrawMoveDetail(char *,int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void POKE_SUMMARY_MAIN_RedrawMoveList(char *);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern u32 APP_TASKMENU_WIN_Create(u32, u32, u32, u32, u8, u16);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void CURSOR_MOVE_SetSkipBit(struct Sound *obj, u32 idx);
extern void func_020409B4(u32);
extern void APP_TASKMENU_WIN_SetDecide(char *,int);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void POKE_SUMMARY_MAIN_StartTextStream(char *p, u32 v);
extern u8 POKE_SUMMARY_MAIN_CountFreeMoves(void ***p);
extern void func_0207D658(u32 addr, int plane, int brightness);
void POKE_SUMMARY_ACTOR_InitSystem(u8 *p, void *a1);
void POKE_SUMMARY_ACTOR_DeleteSystem(u8 *p);
void POKE_SUMMARY_ACTOR_RegisterResources(char *p,void *other);
void POKE_SUMMARY_ACTOR_TransferCharacter(u32 a,int b,u32 c,u32 d,u16 heap);
void POKE_SUMMARY_ACTOR_SetMoveIcon(u8 *p, u16 id, u16 i);
void POKE_SUMMARY_ACTOR_FlushPendingTransfers(char *p);
void POKE_SUMMARY_ACTOR_LayoutMoveActors(char *p);
void POKE_SUMMARY_ACTOR_SetMoveAnim(u8 *p, u16 id);
void POKE_SUMMARY_ACTOR_CreateActors(char *p,void *arg);
void POKE_SUMMARY_ACTOR_PositionMonActor(unsigned char *p, u32 idx, int unused);
int POKE_SUMMARY_ACTOR_StartWipe(u8 *p);
int POKE_SUMMARY_ACTOR_StartProc(char *p);
int POKE_SUMMARY_ACTOR_StartNetRestart(void *p);
void POKE_SUMMARY_ACTOR_CreateSound(u8 *p);
int POKE_SUMMARY_ACTOR_UpdateSound(int *p);
void POKE_SUMMARY_ACTOR_Noop(void);
void POKE_SUMMARY_ACTOR_SelectRow(char *p,int row,int old);
void POKE_SUMMARY_ACTOR_HandleCursorInput(char *p,int i);
void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *p, int flag);
int POKE_SUMMARY_ACTOR_IsTaskMenuOpen(char *p);
void POKE_SUMMARY_ACTOR_UpdateScrollArrows(char *p);
void POKE_SUMMARY_ACTOR_SetScrollAnim(u8 *p,int direction);
void POKE_SUMMARY_ACTOR_SetIdleAnim(u8 *p);
int POKE_SUMMARY_ACTOR_OpenDecideWin(char *p, u16 v);
int POKE_SUMMARY_ACTOR_ConfirmDecide(u8 *p,u16 n);
int POKE_SUMMARY_ACTOR_ConfirmDecideById(char *p,unsigned short id);
int POKE_SUMMARY_ACTOR_WaitDecide(u8 *p);
int POKE_SUMMARY_ACTOR_ShowTextKind2(char *p);
int POKE_SUMMARY_ACTOR_ShowTextKind1Or4(char *p);
void POKE_SUMMARY_ACTOR_SetSubBrightness(int a);
extern const struct Cfg d_021B820C;
extern u8 d_021B8250[];
extern const Row d_021B85E0[];
extern char gPokeStatusProcData[];
extern char k_83[];
extern u8 d_021B81DC[];
extern const u8 d_021B83A8[];




void POKE_SUMMARY_ACTOR_InitSystem(u8 *p, void *a1) {Offset off;struct Bank *b;CLACT_InitSystem(&d_021B820C,(u32)d_021B8250,79);off=OFFSET;b=CLACT_CreateUnit(14,0,79);off+=242;*(struct Bank **)(p+off)=b;CLACT_SetUnitDefaultRenderer(b);BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);}




void POKE_SUMMARY_ACTOR_DeleteSystem(u8 *p) {u32 i;for(i=0;i<14;i++)CLACT_DeleteActor(*(struct Obj **)(p+i*4+260));CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj00362 *)p)->f100);CLACT_ExitSystem();ARC_TOOL_DeleteHandle(((struct Obj00362 *)p)->f13C);}




void POKE_SUMMARY_ACTOR_RegisterResources(char *p,void *other)
{
    void *bank;
    u32 i;
    u32 first;
    int second;
    void *mon;
    u32 save;
    bank=func_020490F4(func_020275E4(),79);
    ((struct Obj01267 *)p)->f70=CLACT_RegisterCharacter(bank,func_02027618(),0,1,79);
    ((struct Obj01267 *)p)->f74=CLACT_RegisterCharacter(other,17,0,1,79);
    ((struct Obj01267 *)p)->f78=CLACT_RegisterCharacter(other,26,0,1,79);
    for(i=4;i<8;i++) *(int *)(p+i*4+0x70)=CLACT_RegisterCharacter(bank,func_020275F8(0),0,0,79);
    ((struct Obj01267 *)p)->f7C=CLACT_RegisterCharacter(other,23,0,1,79);
    ((struct Obj01267 *)p)->f94=CLACT_RegisterPaletteEx(bank,func_02027614(),1,0,0,4,79);
    ((struct Obj01267 *)p)->f98=CLACT_RegisterPaletteEx(other,5,1,128,0,1,79);
    ((struct Obj01267 *)p)->f9C=CLACT_RegisterPaletteEx(bank,func_020275E8(),1,192,0,3,79);
    ((struct Obj01267 *)p)->fA0=CLACT_RegisterPalette(bank,func_020275E8(),0,0,79);
    first=func_0202761C(1);
    ((struct Obj01267 *)p)->fB8=CLACT_RegisterCellAnim(bank,first,func_02027620(1),79);
    ((struct Obj01267 *)p)->fBC=CLACT_RegisterCellAnim(other,7,8,79);
    first=func_020275FC(1);
    ((struct Obj01267 *)p)->fC0=CLACT_RegisterCellAnim(bank,first,func_02027600(1),79);
    ((struct Obj01267 *)p)->fC4=CLACT_RegisterCellAnim(other,24,25,79);
    ((struct Obj01267 *)p)->fC8=CLACT_RegisterCellAnim(other,27,28,79);
    ARC_TOOL_DeleteHandle(bank);
    second=POKEGRA_OpenHandle(79);
    mon=func_020185F0(**(void ** *)&((struct Obj01267 *)p)->f0);
    save=func_02017DBC(mon);
    ((struct Obj01267 *)p)->f90=POKEGRA_RegisterCgrPP(second,mon,0,0,79);
    ((struct Obj01267 *)p)->fA4=POKEGRA_RegisterPalettePP(second,mon,0,0,128,79);
    ((struct Obj01267 *)p)->fCC=POKEGRA_RegisterCellAnimPP((u32)mon,0,1,0,79);
    func_02017DE4(mon,save);
    ARC_TOOL_DeleteHandle((void *)second);
}




void POKE_SUMMARY_ACTOR_TransferCharacter(u32 a,int b,u32 c,u32 d,u16 heap) {void *raw;struct Sub0204A9D0 *out;raw=func_02049E74((void *)a,c,d,(u32)(&out),heap);CLACT_TransferCharacter(b,out);func_020307B0(raw);}




void POKE_SUMMARY_ACTOR_SetMoveIcon(u8 *p, u16 id, u16 i) {u32 n;n=WAZA_TOOL_GetParam(id,0);*(u32 *)(p+i*8+320)=n;*(u32 *)(p+i*8+324)=1;CLACT_SetActorPaletteOffset(*(struct Obj **)(p+(i+8)*4+260),func_020275EC((u8)n),1);}




void POKE_SUMMARY_ACTOR_FlushPendingTransfers(char *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (*(u32 *)(p + i * 8 + 0x144) != 0) {
            POKE_SUMMARY_ACTOR_TransferCharacter((u32)(((struct Obj24181 *)p)->f13C), (int)(*(void **)(p + i * 4 + 0x80)), func_020275F8((u8)*(u32 *)(p + i * 8 + 0x140)), 0, 0x4f);
            *(u32 *)(p + i * 8 + 0x144) = 0;
        }
    }
}




void POKE_SUMMARY_ACTOR_LayoutMoveActors(char *p)
{
    u16 rect[2];
    u32 off;
    u32 i;
    u32 value;
    off = 0x1b8;
    for (i = 0; i < 4; i++) {
        rect[0] = 0x2f;
        rect[1] = i * 24 + 0x50;
        CLACT_AddActorSurfacePos(*(void **)(p + i * 4 + 0x114), (const struct Vec2 *)rect, 1);
        if (((struct Obj24182 *)(*(char * *)&((struct Obj03857 *)p)->f0))->f16 + i >= *(u8 *)(p + off)) {
            CLACT_SetActorDrawEnable(*(void **)(p + i * 4 + 0x114), 0);
        } else {
            value = WAZA_TOOL_GetParam(*(u16 *)(*(char * *)&((struct Obj24183 *)(*(char * *)&((struct Obj03857 *)p)->f0))->f10 + (((struct Obj24184 *)(*(char * *)&((struct Obj03857 *)p)->f0))->f16 + i) * 2), 0);
            CLACT_SetActorDrawEnable(*(void **)(p + i * 4 + 0x114), 1);
            CLACT_SetActorAnimSeq(*(void **)(p + i * 4 + 0x114), value);
        }
    }
}




void POKE_SUMMARY_ACTOR_SetMoveAnim(u8 *p, u16 id) {CLACT_SetActorAnimSeq(*(struct Obj * *)&((struct Obj24185 *)p)->f110,WAZA_TOOL_GetParam(id,2));}




/*
 * abi: B294 returns the Obj pointer stored and used by this caller.
 */
void POKE_SUMMARY_ACTOR_CreateActors(char *p,void *arg)
{
    u32 i;
    Position pos;
    POKE_SUMMARY_ACTOR_InitSystem((u8 *)p,arg);
    POKE_SUMMARY_ACTOR_RegisterResources(p,arg);
    ((struct Obj00180 *)p)->f13C=func_020490F4(func_020275E4(),79);
    for(i=0;i<14;i++) {
        pos.x=d_021B85E0[i].x;
        pos.y=d_021B85E0[i].y;
        pos.z=d_021B85E0[i].z;
        pos.a=d_021B85E0[i].a;
        pos.b=d_021B85E0[i].h;
        *(void **)(p+i*4+0x104)=CLACT_CreateActor((void *)((struct Obj00180 *)p)->f100,*(u32 *)(p+d_021B85E0[i].d*4+0x70),*(u32 *)(p+d_021B85E0[i].e*4+0x94),*(u32 *)(p+d_021B85E0[i].f*4+0xb8),&pos,d_021B85E0[i].c,79);
        CLACT_SetActorAutoAnim(*(void **)(p+i*4+0x104),0);
    }
    CLACT_SetActorAutoAnim(((struct Obj00180 *)p)->f138,1);
    CLACT_SetActorAutoAnim(((struct Obj00180 *)p)->f10C,1);
    CLACT_SetActorAutoAnim(((struct Obj00180 *)p)->f108,1);
    CLACT_SetActorAutoAnim(((struct Obj00180 *)p)->f104,1);
}





void POKE_SUMMARY_ACTOR_PositionMonActor(unsigned char *p, u32 idx, int unused)
{
    u16 local[2];

    if (idx < 4) {
        local[0] = 0x82;
        local[1] = idx * 0x18 + 0x54;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj05451 *)p)->f10C), (const struct Vec2 *)local, 1);
        CLACT_SetActorAnimFrame((struct Obj *)(((struct Obj05451 *)p)->f10C), 0);
    } else if (idx < 6) {
        local[0] = (idx - 4) * 0x28;
        local[1] = 0xa8;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj05451 *)p)->f10C), (const struct Vec2 *)local, 1);
        CLACT_SetActorAnimFrame((struct Obj *)(((struct Obj05451 *)p)->f10C), 1);
    } else {
        local[0] = 0xc0;
        local[1] = 0xa0;
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj05451 *)p)->f10C), (const struct Vec2 *)local, 1);
        CLACT_SetActorAnimFrame((struct Obj *)(((struct Obj05451 *)p)->f10C), 2);
    }
}




int POKE_SUMMARY_ACTOR_StartWipe(u8 *p) {WIPE_SYS_Start(0,0,0,0,6,1,79);((struct Obj24186 *)p)->f1B0=11;return 0;}




int POKE_SUMMARY_ACTOR_StartProc(char *p)
{
    char *q;
    u32 zero;
    POKE_SUMMARY_MAIN_ExitScreen(p);
    q = *(char * *)&((struct Obj02217 *)p)->f0;
    ((struct Obj02217 *)p)->f180 = ((struct Obj10670 *)q)->f0;
    ((struct Obj02217 *)p)->f184 = ((struct Obj10670 *)q)->f8;
    ((struct Obj02217 *)p)->f188 = ICA_ANIME_GetField1C(((struct Obj10670 *)q)->fC);
    zero = 0;
    ((struct Obj02217 *)p)->f18C = zero;
    ((struct Obj02217 *)p)->f18F = zero;
    ((struct Obj02217 *)p)->f18E = 1;
    ((struct Obj02217 *)p)->f194 = POKE_SUMMARY_MAIN_GetRecordWord((char **)p);
    ((struct Obj02217 *)p)->f18D = 2;
    ((struct Obj02217 *)p)->f190 = zero;
    ((struct Obj02217 *)p)->f198 = zero;
    GAMESYSTEM_CallProc(((struct Obj24187 *)(*(char * *)&((struct Obj02217 *)p)->f0))->fC, (u32)k_83, gPokeStatusProcData, p + 0x180);
    return 12;
}





int POKE_SUMMARY_ACTOR_StartNetRestart(void *p)
{
    unsigned char v;

    POKE_SUMMARY_MAIN_InitScreen(p);
    POKE_SUMMARY_ACTOR_PositionMonActor(p, (unsigned char)(*(unsigned short *)(((struct Obj06566 *)p)->f0 + 0x14)), 3);
    GFL_NET_RestartWithDefaultTimeout(1, 0x4f);
    v = ((struct Obj06566 *)p)->f192;
    if (v == 0) {
        v = ((struct Obj06566 *)p)->f191;
    } else {
        v = 4;
    }
    *(unsigned char *)(((struct Obj06566 *)p)->f0 + 0x1b) = v;
    ((struct Obj06566 *)p)->f1B0 = 7;
    return 0;
}




void POKE_SUMMARY_ACTOR_CreateSound(u8 *p) {struct Struct_02025CD0 *q;q=CURSOR_MOVE_Create((u32)d_021B83A8,(u32)d_021B81DC,(u32)p,1,0,79);*(struct Struct_02025CD0 * *)&((struct Obj00180 *)p)->f1C8=q;CURSOR_MOVE_ClearSkipBit((struct Sound *)q,8);POKE_SUMMARY_ACTOR_UpdateScrollArrows((char *)p);}




/*
 *   CURSOR_MOVE_Delete (0x02025D14) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
int POKE_SUMMARY_ACTOR_UpdateSound(int *p)
{
    return CURSOR_MOVE_Delete((void *)(((struct Obj24188 *)p)->f1C8));
}



void POKE_SUMMARY_ACTOR_Noop(void)
{
}





void POKE_SUMMARY_ACTOR_SelectRow(char *p,int row,int old)
{
    
    POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
    if(row<=3) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        *(u16 *)(S(p)+0x14)=row;
        if(*(u16 *)(S(p)+0x16)+*(u16 *)(S(p)+0x14)<*(u8 *)(p+0x1B8)) POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
        else POKE_SUMMARY_MAIN_DrawMoveDetail(p,-2);
    } else if(row==6) {
        if(old==3 && *(u16 *)(S(p)+0x16)+4<*(u8 *)(p+0x1B8)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),row=3);
            (*(u16 *)(S(p)+0x16))++;
            POKE_SUMMARY_MAIN_RedrawMoveList(p);
            POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
            POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
            POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,1);
        } else if(old==0) {
            if(*(u16 *)(S(p)+0x16)!=0) {
                GFL_USE_PlaySeDefaultVolume(0x54C);
                (*(u16 *)(S(p)+0x16))--;
                POKE_SUMMARY_MAIN_RedrawMoveList(p);
                POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
                POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
                POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,-1);
            }
            row=0;
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),0);
        } else {
            row=3;
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),3);
        }
    } else GFL_USE_PlaySeDefaultVolume(0x54C);
    POKE_SUMMARY_ACTOR_PositionMonActor((u8 *)p,(u8)row,3);
}





/*
 *   one --thumb, no region: EXACT, 10 bytes, blocker260E4.log.
 *   void CURSOR_MOVE_SetCurrent(unsigned char *p,unsigned value) {
 *       p[13]=value; p[14]=255; p[15]=255;
 *   }
 */
void POKE_SUMMARY_ACTOR_HandleCursorInput(char *p,int i)
{
    if(i<=3) {
        *(u16 *)(S(p)+0x14)=i;
        if(*(u16 *)(S(p)+0x16)+*(u16 *)(S(p)+0x14)<*(u8 *)(p+0x1B8)) {
            POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,1);
            POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
        } else {
            POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
            POKE_SUMMARY_MAIN_DrawMoveDetail(p,-2);
        }
    } else if(i==4) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        i=*(u16 *)(S(p)+0x14);
        (*(u16 *)(S(p)+0x16))++;
        POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
        POKE_SUMMARY_MAIN_RedrawMoveList(p);
        POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
        POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
        POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,1);
        CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
    } else if(i==5) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        i=*(u16 *)(S(p)+0x14);
        (*(u16 *)(S(p)+0x16))--;
        POKE_SUMMARY_MAIN_DrawMoveDetail(p,POKE_SUMMARY_MAIN_GetRecordWord((char **)p));
        POKE_SUMMARY_MAIN_RedrawMoveList(p);
        POKE_SUMMARY_ACTOR_ToggleTaskMenu(p,0);
        POKE_SUMMARY_ACTOR_UpdateScrollArrows(p);
        POKE_SUMMARY_ACTOR_SetScrollAnim((u8 *)p,-1);
        CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
    } else if(i==6) {
        if(*(u16 *)(p+0x1CC)!=6) {
            i=*(u16 *)(S(p)+0x14);
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
        }
    } else if(i==7) {
        i=*(u16 *)(S(p)+0x14);
        CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
    } else if(i==8) {
        if(*(u16 *)(p+0x1CC)!=6) {
            i=*(u16 *)(S(p)+0x14);
            CURSOR_MOVE_SetCurrent(*(void **)(p+0x1C8),i);
        }
    }
    POKE_SUMMARY_ACTOR_PositionMonActor((u8 *)p,(u8)i,3);
}





/*
 * extent: padding at 0x021B7F4E; separate follower POKE_SUMMARY_ACTOR_IsTaskMenuOpen at 0x021B7F50.
 */
void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *p, int flag)
{
    if (flag == 1) {
        if (*(u32 *)&((struct Obj00362 *)p)->f220 == 0) {
            *(u32 *)&((struct Obj00362 *)p)->f220 = APP_TASKMENU_WIN_Create(((struct Obj00362 *)p)->f1DC, (u32)(p + 0x1e4), 13, 21, 9, 0x4f);
            *(u32 *)&((struct Obj00362 *)p)->f224 = APP_TASKMENU_WIN_Create(((struct Obj00362 *)p)->f1DC, (u32)(p + 0x1f0), 22, 21, 9, 0x4f);
            CURSOR_MOVE_SetSkipBit(((struct Obj00362 *)p)->f1C8, 8);
            ((struct Obj00362 *)p)->f1CE = 1;
            return;
        }
    } else {
        if (*(u32 *)&((struct Obj00362 *)p)->f220 != 0) {
            APP_TASKMENU_WIN_Delete(((struct Obj00362 *)p)->f220);
            APP_TASKMENU_WIN_Delete(((struct Obj00362 *)p)->f224);
            func_020409B4(4);
            *(u32 *)&((struct Obj00362 *)p)->f220 = 0;
            *(u32 *)&((struct Obj00362 *)p)->f224 = 0;
        }
        CURSOR_MOVE_ClearSkipBit(((struct Obj00362 *)p)->f1C8, 8);
        ((struct Obj00362 *)p)->f1CE = 0;
    }
}





int POKE_SUMMARY_ACTOR_IsTaskMenuOpen(char *p)
{
    if (((struct Obj24189 *)p)->f220 != 0)
        return 1;
    return 0;
}





void POKE_SUMMARY_ACTOR_UpdateScrollArrows(char *p)
{
    if (((struct Obj00180 *)p)->f1B8 < 4) {
        CURSOR_MOVE_ClearSkipBit(((struct Obj00180 *)p)->f1C8, 4);
        CURSOR_MOVE_ClearSkipBit(((struct Obj00180 *)p)->f1C8, 5);
        return;
    }
    if (((struct Obj24190 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f16 == 0)
        CURSOR_MOVE_ClearSkipBit(((struct Obj00180 *)p)->f1C8, 5);
    else
        CURSOR_MOVE_SetSkipBit(((struct Obj00180 *)p)->f1C8, 5);
    if (((struct Obj24191 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f16 + 4 >= ((struct Obj00180 *)p)->f1B8) {
        CURSOR_MOVE_ClearSkipBit(((struct Obj00180 *)p)->f1C8, 4);
        return;
    } else {
        CURSOR_MOVE_SetSkipBit(((struct Obj00180 *)p)->f1C8, 4);
        return;
    }
}





void POKE_SUMMARY_ACTOR_SetScrollAnim(u8 *p,int direction)
{
    CLACT_SetActorAnimFrame(((struct Obj02506 *)p)->f108,0);
    CLACT_SetActorAnimFrame(((struct Obj02506 *)p)->f104,0);
    if(direction>0) {
        if(((struct Obj24192 *)(*(u8 * *)&((struct Obj02506 *)p)->f0))->f16+4 < ((struct Obj02506 *)p)->f1B8) CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f104,10);
        else CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f104,23);
        CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f108,3);
    } else {
        if(((struct Obj24193 *)(*(u8 * *)&((struct Obj02506 *)p)->f0))->f16==0) CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f108,24);
        else CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f108,11);
        CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f104,2);
    }
}




void POKE_SUMMARY_ACTOR_SetIdleAnim(u8 *p)
{
    if(((struct Obj00180 *)p)->f1B8<=4) {
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f108,17);
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f104,16);
        return;
    }
    if(((struct Obj24194 *)(*(u8 * *)&((struct Obj00180 *)p)->f0))->f16+4 < ((struct Obj00180 *)p)->f1B8) {
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f108,17);
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f104,2);
        return;
    }
    if(((struct Obj24195 *)(*(u8 * *)&((struct Obj00180 *)p)->f0))->f16==0) {
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f108,3);
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f104,16);
    }
}





int POKE_SUMMARY_ACTOR_OpenDecideWin(char *p, u16 v)
{
    char *q = p + 0x1d0;

    ((struct Obj10671 *)q)->fA = 0;
    ((struct Obj10671 *)q)->f6 = 0xd;
    ((struct Obj10671 *)q)->f8 = v;
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj24196 *)p)->f138), 9);
    return 0xd;
}




int POKE_SUMMARY_ACTOR_ConfirmDecide(u8 *p,u16 n) {u8 *q;q=p+464;((struct Obj08266 *)q)->fA=1;((struct Obj08266 *)q)->f6=0;((struct Obj08266 *)q)->f8=n;APP_TASKMENU_WIN_SetDecide(*(char **)(p+((struct Obj08266 *)q)->f6*4+544),1);return 13;}




int POKE_SUMMARY_ACTOR_ConfirmDecideById(char *p,unsigned short id) {unsigned short *q=(unsigned short *)(p+0x1d0);q[5]=1;q[3]=1;q[4]=id;APP_TASKMENU_WIN_SetDecide(*(char **)((unsigned)p+q[3]*4+0x220),1);return 13;}




int POKE_SUMMARY_ACTOR_WaitDecide(u8 *p)
{
    u8 *s;
    s=p+464;
    if(((struct Obj05452 *)s)->fA==0) {
        if(CLACT_IsActorAnimActive(*(void **)(p+260+((struct Obj05452 *)s)->f6*4))==0) return ((struct Obj05452 *)s)->f8;
    } else if(((struct Obj05452 *)s)->fA==1) {
        if(APP_TASKMENU_WIN_IsFinish(*(void **)(p+544+((struct Obj05452 *)s)->f6*4))!=0) {
            POKE_SUMMARY_ACTOR_ToggleTaskMenu((char *)p,0);
            return ((struct Obj05452 *)s)->f8;
        }
    }
    return 13;
}





int POKE_SUMMARY_ACTOR_ShowTextKind2(char *p)
{
    POKE_SUMMARY_MAIN_StartTextStream(p, 2);
    ((struct Obj14319 *)p)->f1BA = 1;
    *(u32 *)(p + 0x1ba - 0xa) = 3;
    return 2;
}




int POKE_SUMMARY_ACTOR_ShowTextKind1Or4(char *p) {unsigned char flag;if(POKE_SUMMARY_MAIN_CountFreeMoves((void ***)p)<4) {POKE_SUMMARY_MAIN_StartTextStream(p,1);flag=0;} else {POKE_SUMMARY_MAIN_StartTextStream(p,4);flag=2;}((struct Obj14320 *)p)->f1BA=flag;*(unsigned *)(p+0x1ba-10)=3;return 2;}


void POKE_SUMMARY_ACTOR_SetSubBrightness(int a)
{
    volatile unsigned short *p = (volatile unsigned short *)0x04001050;

    if (a == 1) {
        func_0207D658((u32)p, 0x1e, -8);
    } else {
        *p = 0;
    }
}
