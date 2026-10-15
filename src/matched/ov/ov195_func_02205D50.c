/*
 * function: SHINKA_DEMO_VIEW_Main
 * address: 0x02205D50
 * packet: pkt_ov195_02205D50
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   PM_VOICE_Play 0x02006984 thumb
 *   PM_VOICE_IsAnyActive 0x02006650 thumb
 *   MCSS_SetPaletteFade 0x02015F50 thumb
 *   SHINKA_DEMO_VIEW_OtherSlot 0x02206264 thumb ov195
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   MCSS_CheckPaletteFade 0x0201600C thumb
 *   SHINKA_DEMO_VIEW_SetModelPosX 0x022063AC thumb ov195
 *   SHINKA_DEMO_VIEW_SetModelsPos 0x02206768 thumb ov195
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   NNS_G2dRestartMCAnimation 0x02064CBC arm
 *   SHINKA_DEMO_VIEW_StartFadeOut 0x022067BC thumb ov195
 *   SHINKA_DEMO_VIEW_AreModelsState0 0x022067FC thumb ov195
 *   SHINKA_DEMO_VIEW_BeginIntro 0x0220672C thumb ov195
 *   SHINKA_DEMO_VIEW_AreModelsState4 0x0220682C thumb ov195
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   MCSS_Main 0x02014C08 thumb
 *   SHINKA_DEMO_VIEW_Update 0x02206604 thumb ov195
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct McssFade;
struct Obj;
struct Owner;
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);
extern int PM_VOICE_IsAnyActive(void);
typedef signed int     s32;
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern u8 SHINKA_DEMO_VIEW_OtherSlot(u8);
extern void MCSS_SetAnmStopFlag(void *);
extern int MCSS_CheckPaletteFade(void *);
extern void SHINKA_DEMO_VIEW_SetModelPosX(char *,u32);
extern void SHINKA_DEMO_VIEW_SetModelsPos(char *,u32,u32,u32);
extern void *MCSS_GetAnimCtrl(void *);
extern void NNS_G2dRestartMCAnimation(struct Obj *);
extern void SHINKA_DEMO_VIEW_StartFadeOut(struct Owner *);
extern int SHINKA_DEMO_VIEW_AreModelsState0(char *);
extern void SHINKA_DEMO_VIEW_BeginIntro(struct Owner *);
extern int SHINKA_DEMO_VIEW_AreModelsState4(char *);
extern void MCSS_ResetVanishFlag(void *);
extern void MCSS_SetVanishFlag(void *);
extern void MCSS_ResetAnmStopFlag(void *);
extern void MCSS_Main(char *);
extern void SHINKA_DEMO_VIEW_Update(struct Owner *);
#define W(n) (*(u32 *)(p+(n)))
#define P(n) (*(void **)(p+(n)))
#define B(n) (*(u8 *)(p+(n)))
#define NODE(i) (*(void **)(p+0x50+(u32)(i)*4))
void SHINKA_DEMO_VIEW_Main(char *p)
{
    switch(W(0x14)) {
    case 0:
        if(W(0x1c)) {
            u32 a,b;
            W(0x14)=1;
            a=POKE_TOOL_GetPartyValue(P(4),5,0);
            b=POKE_TOOL_GetPartyValue(P(4),0x6f,0);
            PM_VOICE_Play(a,b,0x40,0,0,0,0,0);
        }
        break;
    case 1:
        if(!PM_VOICE_IsAnyActive()){W(0x14)=2;W(0x20)=1;}
        break;
    case 2:if(W(0x24))W(0x14)=3;break;
    case 3:
        W(0x14)=4;
        MCSS_SetPaletteFade((struct McssFade *)NODE(B(0x48)),0,16,0,0x7fff);
        MCSS_SetPaletteFade((struct McssFade *)NODE(SHINKA_DEMO_VIEW_OtherSlot(B(0x48))),16,16,0,0x7fff);
        MCSS_SetAnmStopFlag(NODE(B(0x48)));
        break;
    case 4:if(!MCSS_CheckPaletteFade(NODE(B(0x48))))W(0x14)=5;break;
    case 5:
        if(W(0x18)>=8){W(0x14)=6;W(0x18)=0;}
        else W(0x18)++;
        break;
    case 6:
        W(0x14)=8;
        SHINKA_DEMO_VIEW_SetModelPosX(p,0x100000);
        SHINKA_DEMO_VIEW_SetModelsPos(p,0,0xfffff800,0);
        W(0x5c)=0;
        NNS_G2dRestartMCAnimation((struct Obj *)MCSS_GetAnimCtrl(NODE(B(0x48))));
        break;
    case 7:
        if(W(0x18)>=1){W(0x14)=8;W(0x18)=0;}
        else W(0x18)++;
        break;
    case 8:W(0x14)=9;SHINKA_DEMO_VIEW_StartFadeOut((struct Owner *)p);break;
    case 9:
        if(SHINKA_DEMO_VIEW_AreModelsState0(p)){W(0x14)=10;W(0x38)=1;SHINKA_DEMO_VIEW_BeginIntro((struct Owner *)p);}
        break;
    case 10:if(SHINKA_DEMO_VIEW_AreModelsState4(p))W(0x14)=11;break;
    case 11:
        if(W(0x18)>=30){W(0x14)=13;W(0x18)=0;W(0x3c)=1;W(0x28)=1;}
        else W(0x18)++;
        break;
    case 12:if(SHINKA_DEMO_VIEW_AreModelsState4(p)){W(0x14)=13;W(0x3c)=1;W(0x28)=1;}break;
    case 13:if(W(0x2c))W(0x14)=14;break;
    case 14:
        W(0x14)=15;
        if(W(0x40))W(0x18)=0;
        else {
            B(0x48)=SHINKA_DEMO_VIEW_OtherSlot(B(0x48));
            MCSS_ResetVanishFlag(NODE(B(0x48)));
            MCSS_SetVanishFlag(NODE(SHINKA_DEMO_VIEW_OtherSlot(B(0x48))));
            W(0x18)=30;
        }
        SHINKA_DEMO_VIEW_SetModelPosX(p,0);
        SHINKA_DEMO_VIEW_SetModelsPos(p,0x100000,0xfffff800,0);
        W(0x5c)=1;
        break;
    case 15:if(W(0x30))W(0x14)=16;break;
    case 16:
        W(0x14)=17;
        MCSS_SetPaletteFade((struct McssFade *)NODE(B(0x48)),16,0,1,0x7fff);
        break;
    case 17:
        if(!MCSS_CheckPaletteFade(NODE(B(0x48)))){W(0x14)=18;MCSS_ResetAnmStopFlag(NODE(B(0x48)));}
        break;
    case 18:
        if(!W(0x18)){W(0x14)=19;W(0x18)=0;}
        else W(0x18)--;
        break;
    case 19:
        {
            void *obj;
            u32 a,b;
            W(0x14)=20;
            if(W(0x40))obj=P(4);else obj=P(0x10);
            a=POKE_TOOL_GetPartyValue(obj,5,0);
            b=POKE_TOOL_GetPartyValue(obj,0x6f,0);
            PM_VOICE_Play(a,b,0x40,0,0,0,0,0);
        }
        break;
    case 20:if(!PM_VOICE_IsAnyActive()){W(0x14)=21;W(0x18)=0;W(0x34)=1;}break;
    case 21:case 22:break;
    }
    if(W(0x5c))MCSS_Main(P(0x4c));
    SHINKA_DEMO_VIEW_Update((struct Owner *)p);
}
