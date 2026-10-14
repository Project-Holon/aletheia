/*
 * function: POKETRADE_SAVE_DrawSummaryPage
 * address: 0x021E1E00
 * packet: pkt_ov119_021E1E00
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * initialization: side is assigned 0/1 by the original signed p+f54 comparison; both Pair.v[2] snapshots are initialized by complete table copies.
 * arithmetic: ROM b={0,128} makes b.v[side]+16 equal 16/144; mode is forwarded unchanged and no input domain is added.
 * interface: 020450F0's second argument is explicitly narrowed to u8 at 021E1E5A/60; its own body accepts u32.
 * symbols:
 *   d_021E7944 0x021E7944 data a4
 *   d_021E793C 0x021E793C data a4
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045CAC 0x02045CAC arm
 *   POKETRADE_2D_UploadWindowPalette 0x021E6294 thumb ov119
 *   POKETRADE_SAVE_PrintNickname 0x021E1430 thumb ov119
 *   POKETRADE_SAVE_PrintLevel 0x021E15F8 thumb ov119
 *   POKETRADE_SAVE_PrintStatLabels 0x021E1718 thumb ov119
 *   POKETRADE_SAVE_PrintHeldItem 0x021E1778 thumb ov119
 *   POKETRADE_SAVE_PrintHpValues 0x021E17E8 thumb ov119
 *   POKETRADE_SAVE_PrintStatValues 0x021E1880 thumb ov119
 *   POKETRADE_SAVE_PrintGender 0x021E1670 thumb ov119
 *   POKETRADE_2D_CreateMarkingIcon 0x021E5DFC thumb ov119
 *   POKETRADE_2D_CreatePokerusIcon 0x021E5F14 thumb ov119
 *   POKETRADE_SAVE_CreateStatusIconActor 0x021E0E68 thumb ov119
 *   POKETRADE_SAVE_DeleteStatusIconActor 0x021E0E4C thumb ov119
 *   POKETRADE_2D_DeleteMarkingIcon 0x021E5EF8 thumb ov119
 *   POKETRADE_SAVE_PrintAbilityLabel 0x021E194C thumb ov119
 *   POKETRADE_SAVE_PrintMoveNames 0x021E198C thumb ov119
 *   POKETRADE_SAVE_PrintNatureName 0x021E1A44 thumb ov119
 *   POKETRADE_SAVE_PrintExperience 0x021E1AA8 thumb ov119
 *   POKETRADE_2D_LoadSummaryBackground 0x021E40EC thumb ov119
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { int v[2]; } Pair;
extern const Pair d_021E7944, d_021E793C;
struct Descriptor;
struct Cfg;
struct MsgBank;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern void func_02041B6C(u32);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void POKETRADE_2D_UploadWindowPalette(char *,int,u32);
extern void POKETRADE_SAVE_PrintNickname(void *,void *,int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintLevel(void *,void *,int,int,char *);
extern void POKETRADE_SAVE_PrintStatLabels(int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintHeldItem(int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintHpValues(int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintStatValues(int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintGender(void *,void *,int,int,char *,int,int);
extern void POKETRADE_2D_CreateMarkingIcon(char *,int,void *);
extern void POKETRADE_2D_CreatePokerusIcon(char *,int,int,void *);
extern void POKETRADE_SAVE_CreateStatusIconActor(char *,void *,int,int,int,int,u16,int);
extern void POKETRADE_SAVE_DeleteStatusIconActor(char *p);
extern void POKETRADE_2D_DeleteMarkingIcon(void *);
extern void POKETRADE_SAVE_PrintAbilityLabel(int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintMoveNames(int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintNatureName(int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintExperience(int,int,int,int,char *);
extern void POKETRADE_2D_LoadSummaryBackground(char *p, int a1, int a2);
#define I(k) (*(int *)(p+(k)))
#define P(k) (*(void **)(p+(k)))
void POKETRADE_SAVE_DrawSummaryPage(char *p,int mode,void *mon)
{
    Pair a=d_021E7944;
    Pair b=d_021E793C;
    int side=0;
    u32 flag;
    if(I(0xf54)<128) side=1;
    POKETRADE_2D_UploadWindowPalette(p,11,4);
    if(P(0x6b4)) BMP_WIN_Delete(P(0x6b4));
    I(0x6b4)=BMP_WIN_Create(6,(u8)a.v[side],0,16,18,11,0);
    GF_FONT_SetTextColor(14,15,0);
    flag=func_02017E1C(mon,76,0);
    if(mode==0) {
        POKETRADE_SAVE_PrintNickname(mon,BMP_WIN_GetBmp(P(0x6b4)),32,0,flag,0,p);
        if(flag==0) {
            POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp(P(0x6b4)),32,16,p);
            POKETRADE_SAVE_PrintStatLabels((int)mon,I(0x6b4),8,32,p);
            POKETRADE_SAVE_PrintHeldItem((int)mon,I(0x6b4),24,128,p);
            POKETRADE_SAVE_PrintHpValues((int)mon,I(0x6b4),64,32,p);
            POKETRADE_SAVE_PrintStatValues((int)mon,I(0x6b4),80,48,p);
            POKETRADE_SAVE_PrintGender(mon,BMP_WIN_GetBmp(P(0x6b4)),96,0,p,0,0);
            POKETRADE_2D_CreateMarkingIcon(p,side,mon);
            POKETRADE_2D_CreatePokerusIcon(p,side,0,mon);
            POKETRADE_SAVE_CreateStatusIconActor(p+0x8c4,mon,I(0x9c4),b.v[side]+16,16,1,((struct Obj00001 *)p)->f5F4,13);
        } else {
            POKETRADE_SAVE_DeleteStatusIconActor(p+0x8c4);
        }
    } else {
        POKETRADE_SAVE_DeleteStatusIconActor(p+0x8c4);
        POKETRADE_2D_DeleteMarkingIcon(p+0x950);
        POKETRADE_2D_DeleteMarkingIcon(p+0x964);
        POKETRADE_2D_DeleteMarkingIcon(p+0x978);
        if(flag==0) {
            POKETRADE_SAVE_PrintAbilityLabel((int)mon,I(0x6b4),8,0,p);
            POKETRADE_SAVE_PrintMoveNames((int)mon,I(0x6b4),16,16,p);
            func_02045CAC(P(0x720),36,P(0x730));
            PRINTSYS_Print(BMP_WIN_GetBmp(P(0x6b4)),8,80,P(0x730),P(0x728));
            POKETRADE_SAVE_PrintNatureName((int)mon,I(0x6b4),16,96,p);
            func_02045CAC(P(0x720),37,P(0x730));
            PRINTSYS_Print(BMP_WIN_GetBmp(P(0x6b4)),8,112,P(0x730),P(0x728));
            POKETRADE_SAVE_PrintExperience((int)mon,I(0x6b4),16,128,p);
        }
    }
    POKETRADE_2D_LoadSummaryBackground(p,side,mode);
    BMP_WIN_MakeScreen(P(0x6b4));
    BMP_WIN_TransferChars(P(0x6b4));
    func_02041B6C(6);
}
