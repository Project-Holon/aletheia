/*
 * function: SHINKA_DEMO_Main
 * address: 0x022040E0
 * packet: pkt_ov195_022040E0
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P23 closed EXACT*. Case 34 also calls SHINKA_DEMO_PlayResultBgm(a,s) after SHINKA_DEMO_PrintText (same as case 18), so the tails cross-jump into case 18's copy; case 39 reads W(0x90) into a local once for both SHINKA_DEMO_SetMenuText arguments (ldr before the s+0x1c add). Older 5-byte DIFF came from those two points.
 * checks: 1 fresh own callee definitions and same-overlay callers confirm arities; unit355C4 setteru8 widened tou32 because caller sends only0/1 without truncation; caller-loaded forwarder args and272A4 wide-r1 payload preserved; 2 matched03FA0/05384/055BC/056E8 and loader twins read; 3 u16 keys (only bit2 used) regresses699, a/s writable so no const; 4 Boolean call/inline-wrapper and flag-ternary idioms read; 5 fresh unfiltered idioms and04DE0/04FC4/math neighbours.
 * extent: 02204B66 and 02204BB2 are internal shared tails; true end 02204C24 (2884B).
 * symbols:
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Push 0x02031348 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_0200873C 0x0200873C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_RegisterSeen 0x0200CFA0 thumb
 *   ZUKAN_SAVE_RegisterCaught 0x0200CDE0 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   POKE_TOOL_ChangeSpecies 0x020178D8 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_020181F4 0x020181F4 thumb
 *   POKE_TOOL_GetLevelUpMove 0x02018328 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   GAME_BEACON_SetPokeEvolution 0x020272A4 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02030D28 0x02030D28 arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   YESNO_MENU_Create 0x021B6DC0 thumb ov067
 *   YESNO_MENU_Delete 0x021B709C thumb ov067
 *   YESNO_MENU_Start 0x021B70F4 thumb ov067
 *   YESNO_MENU_Close 0x021B72DC thumb ov067
 *   YESNO_MENU_Update 0x021B7378 thumb ov067
 *   YESNO_MENU_GetAnswer 0x021B76B0 thumb ov067
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   ov131_id 0x00000083 data a1
 *   ov196_id 0x000000C4 data a1
 *   ov198_id 0x000000C6 data a1
 *   SHINKA_DEMO_PrintStreamCallback 0x02205360 thumb ov195
 *   d_02208F40 0x02208F40 data a4
 *   func_0220F3E8 0x0220F3E8 thumb ov198
 *   SHINKA_DEMO_SetupScene 0x02204C24 thumb ov195
 *   SHINKA_DEMO_DeleteScene 0x02204D5C thumb ov195
 *   SHINKA_DEMO_UpdateBgm 0x02204DE0 thumb ov195
 *   SHINKA_DEMO_IsBgmState1 0x02204EA0 thumb ov195
 *   SHINKA_DEMO_RestoreBgm 0x02204EB0 thumb ov195
 *   SHINKA_DEMO_PlayEvolutionBgm 0x02204ED0 thumb ov195
 *   SHINKA_DEMO_IsBgmState2 0x02204EF0 thumb ov195
 *   SHINKA_DEMO_StartEvolutionBgm 0x02204F00 thumb ov195
 *   SHINKA_DEMO_PushBgm 0x02204F24 thumb ov195
 *   SHINKA_DEMO_PopBgm 0x02204F40 thumb ov195
 *   SHINKA_DEMO_IsBgmState4 0x02204F68 thumb ov195
 *   SHINKA_DEMO_FadeOutBgm 0x02204F78 thumb ov195
 *   SHINKA_DEMO_IsBgmState6 0x02204F90 thumb ov195
 *   SHINKA_DEMO_StartResultBgm 0x02204FA0 thumb ov195
 *   SHINKA_DEMO_IsBgmState7Or8 0x02204FC4 thumb ov195
 *   SHINKA_DEMO_PlayResultBgm 0x02204FD4 thumb ov195
 *   SHINKA_DEMO_StopBgm 0x02204FF8 thumb ov195
 *   SHINKA_DEMO_ResetActorAnims 0x02205138 thumb ov195
 *   SHINKA_DEMO_AreActorAnimsDone 0x02205168 thumb ov195
 *   SHINKA_DEMO_UpdateWindows 0x02205340 thumb ov195
 *   SHINKA_DEMO_PrintText 0x02205384 thumb ov195
 *   SHINKA_DEMO_AdvanceText 0x022053E8 thumb ov195
 *   SHINKA_DEMO_IsConfirmPressed 0x0220546C thumb ov195
 *   SHINKA_DEMO_SetupMessageBox 0x022054E8 thumb ov195
 *   SHINKA_DEMO_SetMenuText 0x022055BC thumb ov195
 *   SHINKA_DEMO_AddEvolvedPokemon 0x022056E8 thumb ov195
 *   SHINKA_DEMO_ClearPartyValue 0x02205844 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_Draw 0x022059FC thumb ov195
 *   SHINKA_DEMO_GRAPHIC_Update 0x02205A10 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_DrawEnd 0x02205A1C thumb ov195
 *   SHINKA_DEMO_GRAPHIC_GetCamera 0x02205A28 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_SetupSubBg 0x02205A34 thumb ov195
 *   SHINKA_DEMO_GRAPHIC_ReleaseSubBg 0x02205A84 thumb ov195
 *   SHINKA_DEMO_VIEW_Main 0x02205D50 thumb ov195
 *   func_0220602C 0x0220602C thumb ov195
 *   func_02206044 0x02206044 thumb ov195
 *   func_0220604C 0x0220604C thumb ov195
 *   func_02206050 0x02206050 thumb ov195
 *   func_02206058 0x02206058 thumb ov195
 *   func_0220605C 0x0220605C thumb ov195
 *   func_02206064 0x02206064 thumb ov195
 *   func_0220606C 0x0220606C thumb ov195
 *   func_02206070 0x02206070 thumb ov195
 *   func_02206074 0x02206074 thumb ov195
 *   func_02206078 0x02206078 thumb ov195
 *   func_0220878C 0x0220878C thumb ov195
 *   func_02208804 0x02208804 thumb ov195
 *   func_02208814 0x02208814 thumb ov195
 *   func_0220882C 0x0220882C thumb ov195
 *   func_02208844 0x02208844 thumb ov195
 *   func_02208850 0x02208850 thumb ov195
 *   func_02208860 0x02208860 thumb ov195
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PROCSYS_Main(void *);
/* Original explicitly prepares all four registers, despite the current forwarding own source. */
extern void PROCSYS_Push(void *,int,void *,void *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
struct Anim;
struct App;
struct Big;
struct Blk37;
struct Ctx;
struct Obj02021EE4;
struct Owner;
struct PalAnmSlot;
struct PrintSys;
struct S;
struct Scene;
struct Sub02008700Obj;
struct Sub02008C20Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *p, void *m);
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern void POKE_TOOL_ChangeSpecies(void *,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_020181F4(void *,u16,u32);
extern u16 POKE_TOOL_GetLevelUpMove(void *,u32 *,u32);
extern u32 POKEPARTY_GetCount(void *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *PALANM_Create(u32);
extern u32 PALANM_Delete(void *a0);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
/* Caller narrows only r0; r1 retains the full word, copied to the callee's u16 store. */
extern void GAME_BEACON_SetPokeEvolution(u16,u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02030D28(struct Ctx *c);
extern void func_02030DA4(void *);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern u8 func_020355C4(void);
extern void func_020355D8(u32);
extern u32 KEY_GetTrg(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32),FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern void MI_CpuFill8(void *,u32,u32);
extern void *YESNO_MENU_Create(u16,u32,u32,u32,u8,u32,u32,u32,u32);
extern void YESNO_MENU_Delete(u8 *p);
extern void YESNO_MENU_Start(struct S *s, u32 a1, u32 a2);
extern void YESNO_MENU_Close(struct S *s);
extern void YESNO_MENU_Update(struct S *p);
extern int YESNO_MENU_GetAnswer(struct S *p);
extern u8 gPokeStatusProcData[],d_02208F40[];
extern const char ov131_id[],ov196_id[],ov198_id[];
extern int SHINKA_DEMO_PrintStreamCallback(int);
extern void func_0220F3E8(u8 *);
extern void SHINKA_DEMO_SetupScene(struct App *a, struct Scene *s);
extern void SHINKA_DEMO_DeleteScene(int a, int *p);
extern void SHINKA_DEMO_UpdateBgm(char *,char *);
extern int SHINKA_DEMO_IsBgmState1(int a, int *p);
extern int SHINKA_DEMO_IsBgmState2(int a, int *p);
extern int SHINKA_DEMO_IsBgmState4(int a, int *p);
extern int SHINKA_DEMO_IsBgmState6(int a, char *b);
extern int SHINKA_DEMO_IsBgmState7Or8(int a, int *p);
extern void SHINKA_DEMO_RestoreBgm(char *,char *);
extern void SHINKA_DEMO_PlayEvolutionBgm(int a, int *p);
extern void SHINKA_DEMO_StartEvolutionBgm(int unused, char *p);
extern void SHINKA_DEMO_PushBgm(int a, int *b);
extern void SHINKA_DEMO_PopBgm(int a, int *p);
extern void SHINKA_DEMO_FadeOutBgm(int a, char *b);
extern void SHINKA_DEMO_StartResultBgm(int a, int *p);
extern void SHINKA_DEMO_PlayResultBgm(int a, int *p);
extern void SHINKA_DEMO_StopBgm(int a, char *b);
extern void SHINKA_DEMO_ResetActorAnims(int a, int *p);
extern int SHINKA_DEMO_AreActorAnimsDone(int a, int *p);
extern void SHINKA_DEMO_UpdateWindows(int a, char *b);
extern void SHINKA_DEMO_PrintText(char *,u32,u32,u32,u32,u32,u32,u32);
extern int SHINKA_DEMO_AdvanceText(char *),SHINKA_DEMO_IsConfirmPressed(char *);
extern void SHINKA_DEMO_SetupMessageBox(int a, int *p, int flag);
extern void SHINKA_DEMO_SetMenuText(char *,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32);
extern void SHINKA_DEMO_AddEvolvedPokemon(u32 *a, char *b);
extern void SHINKA_DEMO_ClearPartyValue(int a, char *b);
extern void SHINKA_DEMO_GRAPHIC_Draw(char *a);
extern void SHINKA_DEMO_GRAPHIC_Update(char *a);
extern void SHINKA_DEMO_GRAPHIC_DrawEnd(char *a);
extern void SHINKA_DEMO_GRAPHIC_SetupSubBg(void *);
extern void SHINKA_DEMO_GRAPHIC_ReleaseSubBg(int a0);
extern void SHINKA_DEMO_VIEW_Main(char *p);
extern void func_0220602C(struct Owner *o);
extern int SHINKA_DEMO_GRAPHIC_GetCamera(char *a);
extern void func_02206044(int *p);
extern void func_02206050(int *p);
extern void func_0220605C(int *p);
extern void func_02206064(int *p);
extern void func_0220878C(struct Anim *p);
extern void func_02208804(char *a);
extern void func_02208814(char *a);
extern void func_0220882C(int *p);
extern void func_02208844(int *p);
extern int func_0220604C(int *p);
extern int func_02206058(int *p);
extern int func_0220606C(int *p);
extern int func_02206070(int *p);
extern int func_02206074(int *p);
extern int func_02206078(int *p);
extern int func_02208850(int *p);
extern int func_02208860(int *p);
#define W(n) (*(u32 *)(s+(n)))
#define P(n) (*(void **)(s+(n)))
#define H(n) (*(u16 *)(s+(n)))
#define B(n) (*(u8 *)(s+(n)))
#define A(n) (*(u32 *)(a+(n)))
#define AH(n) (*(u16 *)(a+(n)))
#define AB(n) (*(u8 *)(a+(n)))
int SHINKA_DEMO_Main(int unused0,int unused1,char *a,char *s)
{
    u32 tick,keys,result;
    u8 *q;
    void *v;
    tick=PROCSYS_Main(P(0x11c));if(tick==1)return 0;
    switch(W(0x28)){
    case 0:if(W(0x2c)==0){W(0x28)=1;FADE_Start(3,16,0,-16);}else W(0x2c)--;break;
    case 1:if(!FADE_IsActive()){W(0x28)=2;SHINKA_DEMO_ResetActorAnims((int)a,(int *)s);}break;
    case 2:if(!SHINKA_DEMO_IsBgmState1((int)a,(int *)s)&&SHINKA_DEMO_AreActorAnimsDone((int)a,(int *)s)){if(W(0x8c))W(0x28)=4;else{W(0x28)=3;SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);}}break;
    case 3:W(0x88)=1;W(0x28)=4;break;
    case 4:SHINKA_DEMO_PrintText(s,W(0x78),0,0,2,W(0x10),4,0);W(0x28)=5;break;
    case 5:if(SHINKA_DEMO_AdvanceText(s)&&SHINKA_DEMO_IsConfirmPressed(s)){SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,0);W(0x28)=6;func_02206044(P(0x104));}break;
    case 6:if(func_0220604C(P(0x104))){W(0x28)=7;SHINKA_DEMO_PlayEvolutionBgm((int)a,(int *)s);}break;
    case 7:if(!SHINKA_DEMO_IsBgmState2((int)a,(int *)s)){W(0x28)=8;func_02206050(P(0x104));func_0220882C(P(0x108));GFL_USE_PlaySeDefaultVolume(0x7dc);W(0x10c)=1;W(0x2c)=0;}break;
    case 8:
        keys=KEY_GetTrg();
        if(func_0220606C(P(0x104))){if(W(0x24))W(0x28)=13;else W(0x28)=9;break;}
        if(func_02206070(P(0x104)))SHINKA_DEMO_StartEvolutionBgm((int)a,s);
        if(func_02206074(P(0x104)))SHINKA_DEMO_PushBgm((int)a,(int *)s);
        if(func_02206058(P(0x104))){func_02208844(P(0x108));if(!W(0x110)){GFL_USE_PlaySeDefaultVolume(0x7df);W(0x10c)=0;W(0x110)=1;}}
        if(func_02208850(P(0x108)))func_0220605C(P(0x104));
        if(func_02208860(P(0x108))){func_02206064(P(0x104));if(!W(0x114)){if(!W(0x24))W(0x10c)=1;W(0x114)=1;}}
        if(W(0x10c)){
            if(!W(0x118)&&W(0x2c)>=90){if(SHINKA_DEMO_IsBgmState4((int)a,(int *)s)){GFL_USE_PlaySeDefaultVolume(0x7dd);W(0x118)=1;}}
            else if(W(0x2c)==0x212||W(0x2c)==0x249||W(0x2c)==0x280||W(0x2c)==0x2b7)GFL_USE_PlaySeDefaultVolume(0x7de);
            else if(W(0x2c)==0x2e4)GFL_USE_PlaySeDefaultVolume(0x7e0);
            W(0x2c)++;
        }
        if(A(0x10)&&SHINKA_DEMO_IsBgmState4((int)a,(int *)s)&&!W(0x24)&&(keys&2)&&func_02206078(P(0x104))){W(0x24)=1;func_020355D8(0);func_02208814(P(0x108));}break;
    case 9:
        POKE_TOOL_ChangeSpecies(P(0x10),AH(8));
        if(A(0)){v=ZUKAN_SAVE_GetFromGameData((void *)A(0));ZUKAN_SAVE_RegisterSeen(v,P(0x10));ZUKAN_SAVE_RegisterCaught(v,P(0x10));}
        SHINKA_DEMO_StartResultBgm((int)a,(int *)s);if(W(0x8c))W(0x28)=11;else{SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);W(0x28)=10;}break;
    case 10:W(0x88)=1;W(0x28)=11;break;
    case 11:SHINKA_DEMO_PrintText(s,W(0x78),2,0,0,W(0x14),1,W(0x10));W(0x28)=12;break;
    case 12:if(SHINKA_DEMO_AdvanceText(s)&&!SHINKA_DEMO_IsBgmState7Or8((int)a,(int *)s)&&SHINKA_DEMO_IsConfirmPressed(s)){GAME_BEACON_SetPokeEvolution((u16)func_02017E1C(P(0x10),5,0),W(0x14));v=GAME_DATA_GetTrainerRecord((void *)A(0));func_02008DF0(v,10);func_02008DF0(v,88);W(0x28)=17;}break;
    case 13:if(W(0x24))SHINKA_DEMO_StopBgm((int)a,s);else SHINKA_DEMO_PopBgm((int)a,(int *)s);if(W(0x8c))W(0x28)=15;else{SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);W(0x28)=14;}break;
    case 14:W(0x88)=1;W(0x28)=15;break;
    case 15:SHINKA_DEMO_PrintText(s,W(0x78),1,0,2,W(0x10),4,0);W(0x28)=16;break;
    case 16:if(SHINKA_DEMO_AdvanceText(s)&&SHINKA_DEMO_IsConfirmPressed(s))W(0x28)=42;break;
    case 17:switch(AB(11)){case 14:SHINKA_DEMO_AddEvolvedPokemon((u32 *)a,s);break;case 6:case 19:case 20:SHINKA_DEMO_ClearPartyValue((int)a,s);break;}W(0x28)=18;W(0x20)=0;break;
    case 18:
        H(0x1c)=POKE_TOOL_GetLevelUpMove(P(0x10),(u32 *)(s+0x20),H(0));
        if(!H(0x1c))W(0x28)=42;else if(H(0x1c)!=0xfffe){if(H(0x1c)&0x8000){H(0x1c)&=0x7fff;W(0x28)=20;}else{W(0x28)=19;SHINKA_DEMO_PrintText(s,W(0x7c),3,0,2,W(0x10),3,(u32)(s+0x1c));SHINKA_DEMO_PlayResultBgm((int)a,(int *)s);}}break;
    case 19:if(SHINKA_DEMO_AdvanceText(s)&&SHINKA_DEMO_IsConfirmPressed(s))W(0x28)=18;break;
    case 20:W(0x28)=21;SHINKA_DEMO_PrintText(s,W(0x7c),4,0,2,W(0x10),3,(u32)(s+0x1c));break;
    case 21:if(SHINKA_DEMO_AdvanceText(s)){W(0x28)=22;SHINKA_DEMO_SetMenuText(s,W(0x90),2,4,0,4,0,W(0x90),3,4,0,4,0);YESNO_MENU_Start(P(0x9c),W(0x94),W(0x98));}break;
    case 22:
        result=YESNO_MENU_GetAnswer(P(0x9c));if(result==2)break;
        if(result==1){if(A(0xc)){W(0x28)=23;FADE_Start(3,0,16,0);}else{W(0x28)=27;FADE_Start(2,0,16,0);}}
        else if(!result)W(0x28)=36;
        YESNO_MENU_Close(P(0x9c));break;
    case 23:
        if(FADE_IsActive())break;
        SHINKA_DEMO_DeleteScene((int)a,(int *)s);W(0x28)=24;
        v=GAME_DATA_GetSaveControl((void *)A(0));
        ((u8 *)P(0x100))[0xc]=1;*(u32 *)((char *)P(0x100)+8)=A(0);*(u32 *)((char *)P(0x100)+0x24)=0;*(u32 *)P(0x100)=A(4);
        *(void **)((char *)P(0x100)+4)=func_0200873C(v);((u8 *)P(0x100))[0xe]=POKEPARTY_GetCount((void *)A(4));((u8 *)P(0x100))[0xf]=AB(0xa);*(u16 *)((char *)P(0x100)+0x14)=H(0x1c);
        ((u8 *)P(0x100))[0xd]=2;((u8 *)P(0x100))[0x10]=1;*(u32 *)((char *)P(0x100)+0x20)=0;
        func_02034AC4((int)ov131_id);PROCSYS_Push(P(0x11c),-1,gPokeStatusProcData,P(0x100));break;
    case 24:if(tick!=1)W(0x28)=25;else return 0;break;
    case 25:func_02034A5C((int)ov131_id);W(0x28)=26;SHINKA_DEMO_SetupScene((struct App *)a,(struct Scene *)s);GFL_NET_RestartWithDefaultTimeout(0,H(0));FADE_Start(3,16,0,0);break;
    case 26:
        if(!FADE_IsActive()){q=P(0x100);switch(q[0x12]){case 0:result=q[0x11];B(0x1a)=result;H(0x18)=func_02017E1C(P(0x10),result+0x36,0);W(0x28)=31;break;case 1:case 2:default:W(0x28)=36;break;}}break;
    case 27:
        if(FADE_IsActive())break;
        W(0x28)=28;YESNO_MENU_Delete(P(0x9c));W(0x9c)=0;SHINKA_DEMO_GRAPHIC_ReleaseSubBg((int)P(4));B(0xac)=func_020355C4()==0;
        P(0xa4)=func_02030734(H(0),func_02030CB0(8),0,(char *)d_02208F40,0x548);
        MI_CpuFill8(P(0xa4),0,func_02030CB0(8));P(0xa0)=func_02030CBC(8,P(0xa4));P(0xa8)=PALANM_Create(H(0));PALANM_SetAutoTransfer(P(0xa8),1);
        PALANM_AllocSlotBuffers(P(0xa8),1,0x1e0,H(0));PALANM_AllocSlotBuffers(P(0xa8),3,0x1e0,H(0));
        W(0xb0)=A(0);W(0xb4)=A(4);W(0xbc)=W(8);H(0xc0)=H(0);B(0xcf)=4;B(0xfc)=0;B(0xd0)=AB(0xa);H(0xd6)=H(0x1c);W(0xc4)=0;P(0xf4)=s+0xac;W(0xd8)=W(0xa0);W(0xdc)=W(0xa8);W(0xf0)=1;
        func_02034AC4((int)ov196_id);func_02034AC4((int)ov198_id);func_0220F3E8((u8 *)(s+0xb0));FADE_Start(2,16,0,0);break;
    case 28:func_02030D28(P(0xa0));if(B(0xfc)){W(0x28)=29;FADE_Start(2,0,16,0);}break;
    case 29:
        if(FADE_IsActive())break;
        W(0x28)=30;func_02034A5C((int)ov196_id);func_02034A5C((int)ov198_id);PALANM_FreeSlotBuffers(P(0xa8),1);PALANM_FreeSlotBuffers(P(0xa8),3);PALANM_Delete(P(0xa8));func_02030DA4(P(0xa0));func_020307B0(P(0xa4));W(0xa0)=0;W(0xa4)=0;W(0xa8)=0;
        SHINKA_DEMO_GRAPHIC_SetupSubBg(P(4));P(0x9c)=YESNO_MENU_Create(H(0),5,0,1,0,SHINKA_DEMO_GRAPHIC_GetCamera(P(4)),W(8),W(0xc),0);GFL_NET_RestartWithDefaultTimeout(0,H(0));FADE_Start(2,16,0,0);break;
    case 30:
        if(FADE_IsActive())break;
        B(0x1a)=B(0xfb);if(B(0x1a)==4)W(0x28)=36;else{H(0x18)=func_02017E1C(P(0x10),B(0x1a)+0x36,0);W(0x28)=31;}
        func_020355D8(B(0xac)?0:1);break;
    case 31:if(W(0x8c))W(0x28)=33;else{W(0x28)=32;SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);}break;
    case 32:W(0x88)=1;W(0x28)=33;break;
    case 33:SHINKA_DEMO_PrintText(s,W(0x7c),5,(u32)SHINKA_DEMO_PrintStreamCallback,2,W(0x10),3,(u32)(s+0x18));W(0x28)=34;break;
    case 34:if(SHINKA_DEMO_AdvanceText(s)){func_020181F4(P(0x10),H(0x1c),B(0x1a));W(0x28)=35;SHINKA_DEMO_PrintText(s,W(0x7c),6,0,2,W(0x10),3,(u32)(s+0x1c));SHINKA_DEMO_PlayResultBgm((int)a,(int *)s);}break;
    case 35:if(SHINKA_DEMO_AdvanceText(s))W(0x28)=18;break;
    case 36:if(W(0x8c))W(0x28)=38;else{W(0x28)=37;SHINKA_DEMO_SetupMessageBox((int)a,(int *)s,1);}break;
    case 37:W(0x88)=1;W(0x28)=38;break;
    case 38:SHINKA_DEMO_PrintText(s,W(0x7c),7,0,4,0,3,(u32)(s+0x1c));W(0x28)=39;break;
    case 39:if(SHINKA_DEMO_AdvanceText(s)){W(0x28)=40;{u32 w=W(0x90);SHINKA_DEMO_SetMenuText(s,w,4,3,(u32)(s+0x1c),4,0,w,5,3,(u32)(s+0x1c),4,0);}YESNO_MENU_Start(P(0x9c),W(0x94),W(0x98));}break;
    case 40:
        result=YESNO_MENU_GetAnswer(P(0x9c));if(result==2)break;
        if(result==1){W(0x28)=41;SHINKA_DEMO_PrintText(s,W(0x7c),8,0,2,W(0x10),3,(u32)(s+0x1c));}else if(!result)W(0x28)=20;
        YESNO_MENU_Close(P(0x9c));break;
    case 41:if(SHINKA_DEMO_AdvanceText(s))W(0x28)=18;break;
    case 42:if(W(0x24)){FADE_Start(3,0,16,2);W(0x28)=43;}else if(SHINKA_DEMO_IsBgmState4((int)a,(int *)s)){SHINKA_DEMO_FadeOutBgm((int)a,s);FADE_Start(3,0,16,2);W(0x28)=43;}break;
    case 43:if(!SHINKA_DEMO_IsBgmState6((int)a,s)){W(0x28)=44;SHINKA_DEMO_RestoreBgm(a,s);}break;
    case 44:if(!FADE_IsActive()){W(0x28)=45;return 1;}break;
    case 45:return 1;
    }
    SHINKA_DEMO_UpdateBgm(a,s);
    if(W(0x28)!=24&&W(0x28)!=25){
        if(P(0x9c))YESNO_MENU_Update(P(0x9c));
        SHINKA_DEMO_UpdateWindows((int)a,s);PRINTSYS_QUE_Main(P(0xc));SHINKA_DEMO_VIEW_Main(P(0x104));func_0220878C(P(0x108));SHINKA_DEMO_GRAPHIC_Draw(P(4));SHINKA_DEMO_GRAPHIC_Update(P(4));func_02208804(P(0x108));func_0220602C(P(0x104));SHINKA_DEMO_GRAPHIC_DrawEnd(P(4));
    }
    return 0;
}
