/*
 * function: POKETRADE_SAVE_ShowSummaryMon
 * address: 0x021E219C
 * packet: pkt_ov119_021E219C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * control: the pool-hole call POKETRADE_3D_AddPokemonMcss is written in both arms (x==0, then flag != 0); the compiler cross-jumps the first copy into a b.
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_02049B40 0x02049B40 arm
 *   MCSS_SetPosition 0x02015C48 thumb
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_SAVE_PrepareSummaryWindow 0x021E2054 thumb ov119
 *   POKETRADE_3D_AddPokemonMcss 0x021E35A0 thumb ov119
 *   POKETRADE_SAVE_PrintNickname 0x021E1430 thumb ov119
 *   POKETRADE_SAVE_PrintDexNumber 0x021E14DC thumb ov119
 *   POKETRADE_SAVE_PrintSpeciesName 0x021E1594 thumb ov119
 *   POKETRADE_SAVE_PrintLevel 0x021E15F8 thumb ov119
 *   POKETRADE_SAVE_PrintGender 0x021E1670 thumb ov119
 *   POKETRADE_SAVE_PrintStatLabels 0x021E1718 thumb ov119
 *   POKETRADE_SAVE_PrintHeldItem 0x021E1778 thumb ov119
 *   POKETRADE_SAVE_PrintHpValues 0x021E17E8 thumb ov119
 *   POKETRADE_SAVE_PrintStatValues 0x021E1880 thumb ov119
 *   POKETRADE_SAVE_PrintAbilityLabel 0x021E194C thumb ov119
 *   POKETRADE_SAVE_PrintMoveNames 0x021E198C thumb ov119
 *   POKETRADE_SAVE_PrintNatureName 0x021E1A44 thumb ov119
 *   POKETRADE_SAVE_PrintExperience 0x021E1AA8 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferStatusIcons 0x021E1CA8 thumb ov119
 *   POKETRADE_SAVE_DeleteTypeIcons 0x021E1CC8 thumb ov119
 *   POKETRADE_SAVE_ToggleTypeIconSet 0x021E2140 thumb ov119
 *   POKETRADE_2D_CreateMarkingIcon 0x021E5DFC thumb ov119
 *   POKETRADE_2D_CreatePokerusIcon 0x021E5F14 thumb ov119
 *   POKETRADE_2D_CreateSummaryIcons 0x021E60BC thumb ov119
 *   POKETRADE_SAVE_CreateStatusIconActor 0x021E0E68 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void MCSS_SetPosition(void *,u32 *);
extern void MCSS_ResetVanishFlag(void *);
extern void MCSS_SetVanishFlag(void *);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Obj;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(u32);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void POKETRADE_SAVE_PrepareSummaryWindow(char *,void *,int,int);
extern void POKETRADE_3D_AddPokemonMcss(char *,int,int,void *,int);
extern void POKETRADE_SAVE_PrintNickname(void *,void *,int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintDexNumber(void *,void *,int,int,int,char *);
extern void POKETRADE_SAVE_PrintSpeciesName(void *,void *,int,int,int,char *);
extern void POKETRADE_SAVE_PrintLevel(void *,void *,int,int,char *);
extern void POKETRADE_SAVE_PrintGender(void *,void *,int,int,char *,int,int);
extern void POKETRADE_SAVE_PrintStatLabels(int a, int b, int x, int y, char *p);
extern void POKETRADE_SAVE_PrintHeldItem(int a, int b, int x, int y, char *p);
extern void POKETRADE_SAVE_PrintHpValues(int a, int b, int x, int y, char *p);
extern void POKETRADE_SAVE_PrintStatValues(int a, int b, int c, int d, char *p);
extern void POKETRADE_SAVE_PrintAbilityLabel(int a, int b, int x, int y, char *p);
extern void POKETRADE_SAVE_PrintMoveNames(int a, int b, int x, int y, char *p);
extern void POKETRADE_SAVE_PrintNatureName(int a, int b, int x, int y, char *p);
extern void POKETRADE_SAVE_PrintExperience(int a, int b, int x, int y, char *p);
extern void POKETRADE_SAVE_DeleteOfferStatusIcons(char *p);
extern void POKETRADE_SAVE_DeleteTypeIcons(char *p);
extern void POKETRADE_SAVE_ToggleTypeIconSet(char *p, int a);
extern void POKETRADE_2D_CreateMarkingIcon(char *,int,void *);
extern void POKETRADE_2D_CreatePokerusIcon(char *,int,int,void *);
extern void POKETRADE_2D_CreateSummaryIcons(char *,void *,int);
extern void POKETRADE_SAVE_CreateStatusIconActor(char *,void *,int,int,int,int,u16,int);
#define I(k) (*(int *)(p+(k)))
#define Q ((void **)(p+0x844))
#define P(k) (*(void **)(p+(k)))
void POKETRADE_SAVE_ShowSummaryMon(char *p,void *mon,int side,int flag)
{
    u32 flag76;
    u32 v[3];
    int i;
    flag76=POKE_TOOL_GetPartyValue(mon,76,0);
    POKETRADE_SAVE_PrepareSummaryWindow(p,mon,side,flag);
    func_02049B40(23,5,0,448,32,((struct Obj00001 *)p)->f5F4);
    if(Q[side]==0)
        POKETRADE_3D_AddPokemonMcss(p,side,1,mon,0);
    else if(flag!=0)
        POKETRADE_3D_AddPokemonMcss(p,side,1,mon,0);
    v[0]=0xe<<14;
    v[1]=1<<14;
    v[2]=0;
    MCSS_SetPosition(Q[side],v);
    MCSS_ResetVanishFlag(Q[side]);
    if(*(void **)(p+(1-side)*4+0x844))
        MCSS_SetVanishFlag(*(void **)(p+(1-side)*4+0x844));
    GF_FONT_SetTextColor(15,2,0);
    i=0;
    P(0x6b4)=(void *)BMP_WIN_Create(3,1,0,31,24,14,0);
    POKETRADE_SAVE_PrintNickname(mon,BMP_WIN_GetBmp(P(0x6b4)),16,0,flag76,0,p);
    if(flag76==0) {
        POKETRADE_SAVE_PrintDexNumber(mon,BMP_WIN_GetBmp(P(0x6b4)),0,16,flag76,p);
        POKETRADE_SAVE_PrintSpeciesName(mon,BMP_WIN_GetBmp(P(0x6b4)),56,16,flag76,p);
        POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp(P(0x6b4)),96,i,p);
        POKETRADE_SAVE_PrintGender(mon,BMP_WIN_GetBmp(P(0x6b4)),80,i,p,i,i);
        POKETRADE_SAVE_PrintStatLabels((int)mon,(int)P(0x6b4),0,32,p);
        for(i=0;i<2;i++) {
            MSGDATA_ReadString(P(0x720),i+36,P(0x730));
            PRINTSYS_Print(BMP_WIN_GetBmp(P(0x6b4)),0,i*16+0x88,P(0x730),P(0x728));
        }
        POKETRADE_SAVE_PrintHpValues((int)mon,(int)P(0x6b4),56,32,p);
        POKETRADE_SAVE_PrintStatValues((int)mon,(int)P(0x6b4),72,48,p);
        POKETRADE_SAVE_PrintNatureName((int)mon,(int)P(0x6b4),56,136,p);
        POKETRADE_SAVE_PrintExperience((int)mon,(int)P(0x6b4),56,152,p);
        POKETRADE_SAVE_PrintHeldItem((int)mon,(int)P(0x6b4),40,168,p);
        POKETRADE_SAVE_PrintAbilityLabel((int)mon,(int)P(0x6b4),152,113,p);
        POKETRADE_SAVE_PrintMoveNames((int)mon,(int)P(0x6b4),152,128,p);
        POKETRADE_SAVE_ToggleTypeIconSet(p,(int)mon);
        POKETRADE_2D_CreateMarkingIcon(p,2,mon);
        POKETRADE_SAVE_CreateStatusIconActor(p+0x8c4,mon,I(0x9c4),12,7,0,((struct Obj00001 *)p)->f5F4,12);
    } else {
        if(P(0x960)) CLACT_SetActorDrawEnable(P(0x960),i);
        POKETRADE_SAVE_DeleteTypeIcons(p);
        POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    }
    POKETRADE_2D_CreateSummaryIcons(p,mon,flag76);
    POKETRADE_2D_CreatePokerusIcon(p,0,1,mon);
    BMP_WIN_MakeScreen(P(0x6b4));
    BMP_WIN_TransferChars(P(0x6b4));
    func_02041B6C(3);
}
