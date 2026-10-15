/*
 * function: PSEL_GRAPHIC_Main
 * address: 0x021BBDE0
 * packet: pkt_ov223_021BBDE0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: A A84 unused legacy r1 omitted: full own body reads no second input, original has no setup; BB9A4 r1 truncated to u8 at BE C6/CA and parallel sites; 355D8 widened to observed full word without pre-call truncation. 35C60 return consumed as in own-overlay BB0B0.
 * symbols:
 *   PSEL_UpdateUnitAnime 0x021B9D4C thumb ov223
 *   PSEL_UpdateUnitPositions 0x021BA2B4 thumb ov223
 *   PSEL_UpdateUnitAnime2 0x021BA8D0 thumb ov223
 *   PSEL_GRAPHIC_UpdateFade 0x021BB964 thumb ov223
 *   PSEL_UpdateSelectAnime 0x021B9A8C thumb ov223
 *   PSEL_SetMode 0x021BAFC4 thumb ov223
 *   PSEL_UpdateFadeUnit 0x021BA878 thumb ov223
 *   PSEL_IsModeDone 0x021BB0B0 thumb ov223
 *   PSEL_IsUnitAnimDone 0x021BA8BC thumb ov223
 *   PSEL_SetActorPosition 0x021BAA5C thumb ov223
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   PSEL_UpdateActorPosition 0x021BAA84 thumb ov223
 *   PSEL_SelectUnit 0x021B9C90 thumb ov223
 *   PSEL_SetUnitVisible 0x021BA81C thumb ov223
 *   PSEL_GRAPHIC_SetFadeSource 0x021BB9A4 thumb ov223
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   PSEL_ShowTaskRes 0x021BB3BC thumb ov223
 *   PSEL_UpdateB414 0x021BB414 thumb ov223
 *   PSEL_SetTaskResActive 0x021BB424 thumb ov223
 *   PSEL_DeleteTaskRes 0x021BB404 thumb ov223
 *   func_02041B6C 0x02041B6C arm
 *   PSEL_IsTaskResFinished 0x021BB440 thumb ov223
 *   PSEL_SetAnimTarget 0x021B9AE4 thumb ov223
 *   PSEL_StepAnim 0x021B9B80 thumb ov223
 *   PSEL_IsAnimTargetReached 0x021B9B4C thumb ov223
 *   func_020355D8 0x020355D8 arm
 *   PSEL_GRAPHIC_OpenMenu 0x021BB450 thumb ov223
 *   PSEL_GRAPHIC_UpdateMenu 0x021BB4E8 thumb ov223
 *   PSEL_GRAPHIC_IsMenuFinished 0x021BB4F8 thumb ov223
 *   PSEL_GRAPHIC_GetMenuChoice 0x021BB508 thumb ov223
 *   PSEL_GRAPHIC_CloseMenu 0x021BB4D8 thumb ov223
 *   func_020355C4 0x020355C4 arm
 *   PSEL_UpdateB134 0x021BB134 thumb ov223
 *   PSEL_SetAnimTargetIndex 0x021B9C00 thumb ov223
 *   PSEL_StepAnimIndex 0x021B9C58 thumb ov223
 *   PSEL_ClearWin 0x021BB274 thumb ov223
 *   PSEL_UpdateB18C 0x021BB18C thumb ov223
 *   PM_VOICE_Play 0x02006984 thumb
 *   d_021BC75C 0x021BC75C data a4
 *   d_021BC794 0x021BC794 data a2
 *   d_021BC710 0x021BC710 data a2
 */
#include "../include/Obj00084.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Main;
extern void PSEL_UpdateUnitAnime(char *);
extern void PSEL_UpdateUnitPositions(struct Main *p);
extern void PSEL_UpdateUnitAnime2(char *);
extern void PSEL_GRAPHIC_UpdateFade(char *);
extern void PSEL_UpdateSelectAnime(char *);
extern void PSEL_SetMode(char *p, int idx);
extern void PSEL_UpdateFadeUnit(char *);
extern int PSEL_IsModeDone(char *),PSEL_IsUnitAnimDone(char *);
extern void PSEL_SetActorPosition(char *,int);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PSEL_UpdateActorPosition(char *);
extern void PSEL_SelectUnit(char *,u32);
extern void PSEL_SetUnitVisible(char *,u32);
extern void PSEL_GRAPHIC_SetFadeSource(unsigned char *p, int value);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern void PSEL_ShowTaskRes(char *),PSEL_UpdateB414(char *),PSEL_SetTaskResActive(char *),PSEL_DeleteTaskRes(char *),func_02041B6C(u32);
extern u32 PSEL_IsTaskResFinished(char *);
extern void PSEL_SetAnimTarget(char *,int,int),PSEL_StepAnim(char *);
extern int PSEL_IsAnimTargetReached(char *);
extern void func_020355D8(u32);
extern void PSEL_GRAPHIC_OpenMenu(char *);
extern void PSEL_GRAPHIC_UpdateMenu(char *);
extern void PSEL_GRAPHIC_CloseMenu(char *);
extern void PSEL_UpdateB134(char *);
extern void PSEL_SetAnimTargetIndex(char *,u32);
extern void PSEL_StepAnimIndex(char *);
extern void PSEL_ClearWin(char *);
extern void PSEL_UpdateB18C(char *p, int idx);
extern u32 PSEL_GRAPHIC_IsMenuFinished(char *);
extern int PSEL_GRAPHIC_GetMenuChoice(int *);
extern u8 func_020355C4(void);
extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);
extern const u8 d_021BC75C[];
extern const u16 d_021BC794[],d_021BC710[];
int PSEL_GRAPHIC_Main(char *p,u32 *state)
{
    int dirty=0;
    int choice,changed;
    u32 selected;
    PSEL_UpdateUnitAnime(p);PSEL_UpdateUnitPositions((struct Main *)p);PSEL_UpdateUnitAnime2(p);PSEL_GRAPHIC_UpdateFade(p);
    switch(*state) {
    case 0:PSEL_UpdateSelectAnime(p);if(((struct Obj00084 *)p)->f50==78)*state=1;break;
    case 1:((struct Obj00084 *)p)->f24|=4;PSEL_SetMode(p,(u32)19);*state=2;PSEL_UpdateFadeUnit(p);break;
    case 2:if(PSEL_IsModeDone(p)&&PSEL_IsUnitAnimDone(p)){*state=3;((struct Obj00084 *)p)->f8=1;}break;
    case 3:
        if(((struct Obj00084 *)p)->f8==0){
            if(*(int *)&((struct Obj00084 *)p)->f228==4){dirty=1;*(int *)&((struct Obj00084 *)p)->f228=1;}
            PSEL_SetActorPosition(p,1);GFL_USE_PlaySeDefaultVolume(1352);PSEL_UpdateActorPosition(p);
            PSEL_SelectUnit(p,((struct Obj00084 *)p)->f228);PSEL_SetUnitVisible(p,((struct Obj00084 *)p)->f228);
            selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)p,(u8)selected);
        }else{PSEL_SetActorPosition(p,0);PSEL_SelectUnit(p,4);PSEL_SetUnitVisible(p,4);PSEL_GRAPHIC_SetFadeSource((u8 *)p,(u8)3);dirty=1;}
        *state=4;break;
    case 4:
        if(((struct Obj00084 *)p)->f8==0){
            if(KEY_GetTrg()!=0){
                changed=0;
                if(KEY_GetTrg()&1){GFL_USE_PlaySeDefaultVolume(1356);PSEL_SetActorPosition(p,0);*state=8;}
                else if(KEY_GetTrg()&32){if(*(int *)&((struct Obj00084 *)p)->f228>0){--*(int *)&((struct Obj00084 *)p)->f228;changed=1;}}
                else if(KEY_GetTrg()&16){if(*(int *)&((struct Obj00084 *)p)->f228<2){++*(int *)&((struct Obj00084 *)p)->f228;changed=1;}}
                if(changed){GFL_USE_PlaySeDefaultVolume(1352);PSEL_UpdateActorPosition(p);PSEL_SelectUnit(p,((struct Obj00084 *)p)->f228);PSEL_SetUnitVisible(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)p,(u8)selected);dirty=1;}
            }else if(TOUCHPANEL_GetTrg()!=0){choice=TOUCHPANEL_HitTrg(d_021BC75C);if(choice>=0&&choice<=2){if(*(int *)&((struct Obj00084 *)p)->f228!=choice)dirty=1;GFL_USE_PlaySeDefaultVolume(1352);PSEL_SetActorPosition(p,0);*(int *)&((struct Obj00084 *)p)->f228=choice;PSEL_SelectUnit(p,choice);PSEL_SetUnitVisible(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)p,(u8)selected);((struct Obj00084 *)p)->f8=1;*state=5;}}
        }else{
            if(KEY_GetTrg()!=0){((struct Obj00084 *)p)->f8=0;*state=3;}
            else if(TOUCHPANEL_GetTrg()!=0){choice=TOUCHPANEL_HitTrg(d_021BC75C);if(choice>=0&&choice<=2){GFL_USE_PlaySeDefaultVolume(1352);*(int *)&((struct Obj00084 *)p)->f228=choice;PSEL_SelectUnit(p,choice);PSEL_SetUnitVisible(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)p,(u8)selected);dirty=1;*state=5;}}
        }break;
    case 5:PSEL_ShowTaskRes(p);*state=6;break;
    case 6:
        PSEL_UpdateB414(p);
        if(KEY_GetTrg()!=0){((struct Obj00084 *)p)->f8=0;if(KEY_GetTrg()&1){GFL_USE_PlaySeDefaultVolume(1356);PSEL_SetTaskResActive(p);*state=7;}else{PSEL_DeleteTaskRes(p);func_02041B6C(3);*state=3;}}
        else if(TOUCHPANEL_GetTrg()!=0){choice=TOUCHPANEL_HitTrg(d_021BC75C);if(choice==3){GFL_USE_PlaySeDefaultVolume(1356);PSEL_SetTaskResActive(p);*state=7;}else if(choice>=0&&choice<=2&&*(int *)&((struct Obj00084 *)p)->f228!=choice){GFL_USE_PlaySeDefaultVolume(1352);*(int *)&((struct Obj00084 *)p)->f228=choice;PSEL_SelectUnit(p,choice);PSEL_SetUnitVisible(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;PSEL_GRAPHIC_SetFadeSource((u8 *)p,(u8)selected);dirty=1;}}break;
    case 7:PSEL_UpdateB414(p);if(PSEL_IsTaskResFinished(p)){PSEL_DeleteTaskRes(p);func_02041B6C(3);*state=8;}break;
    case 8:PSEL_SetMode(p,(u32)20);PSEL_SetAnimTarget(p,*(int *)&((struct Obj00084 *)p)->f228,0);*state=9;break;
    case 9:PSEL_StepAnim(p);if(PSEL_IsModeDone(p)&&PSEL_IsAnimTargetReached(p))*state=10;break;
    case 10:func_020355D8(*(u32 *)&((struct Obj00084 *)p)->f8);PSEL_GRAPHIC_OpenMenu(p);*state=11;break;
    case 11:PSEL_GRAPHIC_UpdateMenu(p);if(PSEL_GRAPHIC_IsMenuFinished(p)){choice=PSEL_GRAPHIC_GetMenuChoice((int *)p);PSEL_GRAPHIC_CloseMenu(p);*(u32 *)&((struct Obj00084 *)p)->f8=func_020355C4();if(choice){((struct Obj00084 *)p)->f24|=8;PSEL_UpdateB134(p);*state=14;}else{PSEL_SetMode(p,(u32)19);*state=12;}}break;
    case 12:PSEL_SetAnimTarget(p,*(int *)&((struct Obj00084 *)p)->f228,1);*state=13;break;
    case 13:PSEL_StepAnim(p);if(PSEL_IsAnimTargetReached(p))*state=3;break;
    case 14:PSEL_SetAnimTargetIndex(p,((struct Obj00084 *)p)->f228);GFL_USE_PlaySeDefaultVolume(1976);*state=15;break;
    case 15:PSEL_StepAnimIndex(p);if(((struct Obj00084 *)p)->f4C==(int)*(const u16 *)((const u8 *)d_021BC794+((struct Obj00084 *)p)->f44*10)-2)*state=16;break;
    case 16:PSEL_StepAnimIndex(p);*(int *)&((struct Obj00084 *)p)->f10=0;return 10;
    }
    if(dirty){((struct Obj00084 *)p)->f24|=32;PSEL_ClearWin(p);}
    else if(((struct Obj00084 *)p)->f230!=0){((struct Obj00084 *)p)->f24|=16;PSEL_UpdateB18C(p,(u32)(((struct Obj00084 *)p)->f228));PM_VOICE_Play(d_021BC710[((struct Obj00084 *)p)->f228],0,64,0,0,0,0,0);}
    ((struct Obj00084 *)p)->f230=0;++((struct Obj00084 *)p)->f10;return 9;
}
