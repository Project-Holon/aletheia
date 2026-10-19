/*
 * function: ZUKAN_DETAIL_VOICE_Main
 * address: 0x021C270C
 * packet: pkt_ov208_021C270C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetHeadbar 0x021BC3B8 thumb ov208
 *   func_021BC3BC 0x021BC3BC thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb ov208
 *   ZUKAN_DETAIL_VOICE_CreateNumberActors 0x021C2C44 thumb ov208
 *   ZUKAN_DETAIL_VOICE_LoadPokemonGraphics 0x021C2E6C thumb ov208
 *   ZUKAN_DETAIL_VOICE_CreateTimerWindow 0x021C3218 thumb ov208
 *   ZUKAN_DETAIL_VOICE_DrawSpeciesName 0x021C3280 thumb ov208
 *   ZUKAN_DETAIL_VOICE_LoadWindowPalette 0x021C3354 thumb ov208
 *   ZUKAN_DETAIL_VOICE_NoOpB 0x021C3378 thumb ov208
 *   func_021BC9BC 0x021BC9BC thumb ov208
 *   func_021BC844 0x021BC844 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SetNumberDigits 0x021C2DE0 thumb ov208
 *   ZUKAN_DETAIL_VOICE_CreateWaveformWindow 0x021C35DC thumb ov208
 *   func_021BC758 0x021BC758 thumb ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeIn 0x021BC718 thumb ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessFull 0x021BC4F4 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SetActorsNormalMode 0x021C3AA8 thumb ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOut 0x021BC6D8 thumb ov208
 *   func_021BDAD0 0x021BDAD0 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode 0x021BDAAC thumb ov208
 *   func_021BDAD4 0x021BDAD4 thumb ov208
 *   func_021BDBB8 0x021BDBB8 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled 0x021BDC48 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq 0x021BDC14 thumb ov208
 *   func_021BE840 0x021BE840 thumb ov208
 *   func_021BE82C 0x021BE82C thumb ov208
 *   func_021BE844 0x021BE844 thumb ov208
 *   ZUKAN_DETAIL_COMMON_IsFadeBusy 0x021BC6C8 thumb ov208
 *   func_021BDBA0 0x021BDBA0 thumb ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOutAlt 0x021BC6F8 thumb ov208
 *   func_021BE854 0x021BE854 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled 0x021BDAE8 thumb ov208
 *   ZUKAN_DETAIL_VOICE_RestoreBgm 0x021C2BF4 thumb ov208
 *   func_021C3514 0x021C3514 thumb ov208
 *   ZUKAN_DETAIL_VOICE_SetActorsAlphaMode 0x021C3B14 thumb ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone 0x021BC508 thumb ov208
 *   func_021C3380 0x021C3380 thumb ov208
 *   ZUKAN_DETAIL_VOICE_UpdateWaveformDelay 0x021C3650 thumb ov208
 *   func_021C301C 0x021C301C thumb ov208
 *   ZUKAN_DETAIL_VOICE_FlushTimerWindow 0x021C3318 thumb ov208
 *   ZUKAN_DETAIL_COMMON_TickFlashEffect 0x021BC99C thumb ov208
 *   func_021BC46C 0x021BC46C thumb ov208
 *   ZUKAN_DETAIL_COMMON_UpdatePaletteAnim 0x021BC678 thumb ov208
 *   ZUKAN_DETAIL_VOICE_UpdateBgmFade 0x021C2C1C thumb ov208
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor; struct Ov208Win; struct Ov208PalFade; struct Ov208Scene; struct Ov208Fade; struct Ov208Icon; struct Ov208Blend; struct Key;
extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern int ZUKAN_DETAIL_COMMON_GetHeadbar(char *p);
extern u16 func_021BC3BC(char *);
extern int ZUKAN_DETAIL_COMMON_GetSource(int *p);
extern void BG_SYS_ChangeScrollImmediate(u32,u32,u32);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPriority(int,u16);
extern void CLACT_SetActorObjMode(struct Actor *,u32);
extern int GAME_DATA_ContainsRecentId(int,int);
struct S;
extern void ZUKAN_DETAIL_VOICE_CreateNumberActors(u16 *heap, struct S *st, int a2);
extern void ZUKAN_DETAIL_VOICE_LoadPokemonGraphics(u16 *,u8 *,int,u32);
extern void ZUKAN_DETAIL_VOICE_CreateTimerWindow(u16 *,u8 *,int);
extern void ZUKAN_DETAIL_VOICE_DrawSpeciesName(u16 *,u8 *,struct Key *);
extern void ZUKAN_DETAIL_VOICE_LoadWindowPalette(unsigned short *p, void *a1, int a2);
extern void ZUKAN_DETAIL_VOICE_NoOpB(void *a0, void *a1, int a2, int a3, int a4);
extern u32 func_021BC9BC(int,u16,u8,u8,u8,u8,u32,u32,u32,u32,u32);
extern struct Ov208Win *func_021BC844(u16,u32,u8,u8,u8);
extern void ZUKAN_DETAIL_VOICE_SetNumberDigits(void *,u8 *,void *,int,u16);
extern void ZUKAN_DETAIL_VOICE_CreateWaveformWindow(u16 *,u8 *,int);
extern void func_021BC758(struct Ov208PalFade *);
extern void ZUKAN_DETAIL_COMMON_StartFadeIn(char *p);
extern void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int flag, int *p);
extern void ZUKAN_DETAIL_VOICE_SetActorsNormalMode(void *,u8 *,int);
extern void ZUKAN_DETAIL_COMMON_StartFadeOut(char *p);
extern int func_021BDAD0(struct Ov208Fade *);
extern void ZUKAN_DETAIL_TOUCHBAR_SetMode(struct Ov208Scene *,u32,u32,u32);
extern void func_021BDAD4(struct Ov208Fade *,int);
extern void func_021BDBB8(struct Ov208Scene *,u32);
extern void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *,u32);
extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(char *p, int b);
extern int func_021BE840(struct Ov208Icon *);
extern void func_021BE82C(struct Ov208Icon *,int);
extern void func_021BE844(struct Ov208Icon *);
extern int ZUKAN_DETAIL_COMMON_IsFadeBusy(char *p);
extern void func_021BDBA0(struct Ov208Scene *);
extern void ZUKAN_DETAIL_COMMON_StartFadeOutAlt(char *p);
extern void func_021BE854(struct Ov208Icon *);
extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(char *p, int v);
extern void ZUKAN_DETAIL_VOICE_RestoreBgm(void *unused, char *p, void *a2);
extern void func_021C3514(u16 *,u8 *,int);
extern void ZUKAN_DETAIL_VOICE_SetActorsAlphaMode(void *,u8 *,int);
extern void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, int *p);
extern void func_021C3380(u16 *,u8 *,int);
extern void ZUKAN_DETAIL_VOICE_UpdateWaveformDelay(u16 *,u8 *,int);
extern void func_021C301C(u16 *,u8 *,int);
extern void ZUKAN_DETAIL_VOICE_FlushTimerWindow(u16 *,u8 *,int);
extern void ZUKAN_DETAIL_COMMON_TickFlashEffect(char *p);
extern void func_021BC46C(struct Ov208Blend *,struct Ov208Blend *);
extern void ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(char *p);
extern void ZUKAN_DETAIL_VOICE_UpdateBgmFade(int unused, char *p, int a2);
#define W(o) (*(u32 *)(p+(o)))
/* Explicit caller r2 loads preserve trailing arguments on setup/update helpers. */
int ZUKAN_DETAIL_VOICE_Main(void *unused,int *seq,u16 *heap,u8 *p,int key)
{
    void *scene;
    struct Ov208Icon *icon;
    u8 i;
    int ready;
    scene=(void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    icon=(struct Ov208Icon *)ZUKAN_DETAIL_COMMON_GetHeadbar((char *)key);
    switch(*seq){
    case 0:
        *seq=1;
        for(i=0;i<=7;i++){
            if(i!=1 && i!=5){
                BG_SYS_ChangeScrollImmediate(i,0,0);
                BG_SYS_ChangeScrollImmediate(i,3,0);
                BG_SYS_FreeSlot(i);
            }
        }
        BG_SYS_SetPriority(2,1);
        BG_SYS_SetPriority(3,2);
        BG_SYS_SetPriority(0,3);
        BG_SYS_SetPriority(6,1);
        BG_SYS_SetPriority(4,3);
        ZUKAN_DETAIL_VOICE_CreateNumberActors(heap,(struct S *)p,key);
        ZUKAN_DETAIL_VOICE_LoadPokemonGraphics(heap,p,key,W(0x5c));
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)((p+W(0x5c)*4)+0x54)),1);
        ZUKAN_DETAIL_VOICE_CreateTimerWindow(heap,p,key);
        ZUKAN_DETAIL_VOICE_DrawSpeciesName(heap,p,(struct Key *)key);
        ZUKAN_DETAIL_VOICE_LoadWindowPalette(heap,p,key);
        ZUKAN_DETAIL_VOICE_NoOpB(heap,p,key,0,0);
        W(0x78)=func_021BC9BC(0,*heap,2,1,0,5,0x9f,1,0xb,0x2a,0);
        W(0x7c)=(u32)func_021BC844(*heap,2,0,2,3);
        W(0x80)=(u32)func_021BC844(*heap,2,4,1,2);
        ZUKAN_DETAIL_VOICE_SetNumberDigits(heap,p,(void *)key,0,0);
        ZUKAN_DETAIL_VOICE_CreateWaveformWindow(heap,p,key);
        func_021BC758((struct Ov208PalFade *)W(0xc8));
        ZUKAN_DETAIL_COMMON_StartFadeIn((char *)W(0xc8));
        break;
    case 1:
        *seq=2;
        ZUKAN_DETAIL_COMMON_SetBrightnessFull(0,(int *)W(0xc0));
        ZUKAN_DETAIL_COMMON_SetBrightnessFull(1,(int *)W(0xc4));
        ZUKAN_DETAIL_VOICE_SetActorsNormalMode(heap,p,key);
        break;
    case 2:
        *seq=3;
        ZUKAN_DETAIL_COMMON_StartFadeOut((char *)W(0xc8));
        if(func_021BDAD0(scene)!=2){
            ZUKAN_DETAIL_TOUCHBAR_SetMode(scene,0,2,func_021BC3BC((char *)key)>1);
            func_021BDAD4(scene,0);
        }else func_021BDBB8(scene,2);
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene,0);
        ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(scene,GAME_DATA_ContainsRecentId(ZUKAN_DETAIL_COMMON_GetSource((int *)key),0x13));
        if(func_021BE840(icon)!=2){
            func_021BE82C(icon,2);
            func_021BE844(icon);
        }
        break;
    case 3:
        if(ZUKAN_DETAIL_COMMON_IsFadeBusy((char *)W(0xc8))==0 && func_021BDAD0(scene)==2 && func_021BE840(icon)==2){
            func_021BDBA0(scene);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene,1);
            *seq=4;
        }
        break;
    case 4:
        if(W(0xcc)!=0){
            *seq=5;
            ZUKAN_DETAIL_COMMON_StartFadeOutAlt((char *)W(0xc8));
            func_021BE854(icon);
            if(W(0xcc)==2)ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(scene,0);
            ZUKAN_DETAIL_VOICE_RestoreBgm(heap,(char *)p,(void *)key);
        }else func_021C3514(heap,p,key);
        break;
    case 5:
        ready=0;
        if(ZUKAN_DETAIL_COMMON_IsFadeBusy((char *)W(0xc8))==0 && func_021BE840(icon)==0){
            if(W(0xcc)==2){
                if(func_021BDAD0(scene)==0)ready=1;
            }else ready=1;
        }
        if(ready)*seq=6;
        break;
    case 6:
        *seq=7;
        ZUKAN_DETAIL_VOICE_SetActorsAlphaMode(heap,p,key);
        ZUKAN_DETAIL_COMMON_SetBrightnessNone(0,(int *)W(0xc0));
        ZUKAN_DETAIL_COMMON_SetBrightnessNone(1,(int *)W(0xc4));
        break;
    case 7:
        return 1;
    }
    if(*seq>=3){
        func_021C3380(heap,p,key);
        ZUKAN_DETAIL_VOICE_UpdateWaveformDelay(heap,p,key);
        func_021C301C(heap,p,key);
    }
    if(*seq>=2){
        ZUKAN_DETAIL_VOICE_FlushTimerWindow(heap,p,key);
        ZUKAN_DETAIL_COMMON_TickFlashEffect((char *)W(0x7c));
        ZUKAN_DETAIL_COMMON_TickFlashEffect((char *)W(0x80));
    }
    func_021BC46C((struct Ov208Blend *)W(0xc0),(struct Ov208Blend *)W(0xc4));
    ZUKAN_DETAIL_COMMON_UpdatePaletteAnim((char *)W(0xc8));
    ZUKAN_DETAIL_VOICE_UpdateBgmFade((int)heap,(char *)p,key);
    return 0;
}
