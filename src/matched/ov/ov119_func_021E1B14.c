/*
 * function: POKETRADE_SAVE_DrawOfferCardWindow
 * address: 0x021E1B14
 * packet: pkt_ov119_021E1B14
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: retain the pre-increment byte index and independent old/base locals;
 * splitting old's base assignment and naming the else-side p+0x8c4
 * address settles the early r4/r7 allocation. No signature mutation.
 * symbols:
 *   gOfferCardWindowPosA 0x021E7934 data a4
 *   gOfferCardWindowPosB 0x021E7914 data a4
 *   gOfferCardWindowPosC 0x021E794C data a4
 *   func_02017E1C 0x02017E1C thumb
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   POKETRADE_PROC_IsWifiMode 0x021D8ADC thumb ov119
 *   POKETRADE_SAVE_PrintNickname 0x021E1430 thumb ov119
 *   POKETRADE_SAVE_PrintGender 0x021E1670 thumb ov119
 *   POKETRADE_SAVE_PrintLevel 0x021E15F8 thumb ov119
 *   POKETRADE_SAVE_PrintHeldItem 0x021E1778 thumb ov119
 *   POKETRADE_SAVE_CreateStatusIconActor 0x021E0E68 thumb ov119
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   POKETRADE_SAVE_DeleteStatusIconActor 0x021E0E4C thumb ov119
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int a,b;} Pair;
extern const Pair gOfferCardWindowPosA,gOfferCardWindowPosB,gOfferCardWindowPosC;
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
struct Cfg;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void GF_FONT_SetTextColor(u32,u32,u32);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern int POKETRADE_PROC_IsWifiMode(char *p);
extern void POKETRADE_SAVE_PrintNickname(void *,void *,int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintGender(void *,void *,int,int,char *,int,int);
extern void POKETRADE_SAVE_PrintLevel(void *,void *,int,int,char *);
extern void POKETRADE_SAVE_PrintHeldItem(int,int,int,int,char *);
extern void POKETRADE_SAVE_CreateStatusIconActor(char *,void *,int,int,int,int,u16,int);
extern void CLACT_SetActorBgPriority(void *,u32);
extern void POKETRADE_SAVE_DeleteStatusIconActor(char *p);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void POKETRADE_SAVE_DrawOfferCardWindow(char *p,int i,void *mon)
{
    Pair a=gOfferCardWindowPosA;
    Pair b=gOfferCardWindowPosB;
    Pair c=gOfferCardWindowPosC;
    u32 flag;
    const char *old;
    u32 index;
    char *tmp;
    flag=func_02017E1C(mon,76,0);
    func_02049B40(23,5,0,448,32,((struct Obj00001 *)p)->f5F4);
    old=p;
    old=old+0x5bc;
    index=i*4;
    if(*(const int *)(old+index))BMP_WIN_Delete((struct Descriptor *)(*(const int *)(old+index)));
    *(int *)(p+0x5bc+index)=(int)BMP_WIN_Create(3,(u8)(*(int *)((char *)&a+index)),1,14,20,14,0);
    GF_FONT_SetTextColor(15,2,0);
    {
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(p+0x5bc+index));
        POKETRADE_SAVE_PrintNickname(mon,window,16,0,flag,POKETRADE_PROC_IsWifiMode(p),p);
    }
    if(flag==0) {
        char *items=p+0x5bc;
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index));
        POKETRADE_SAVE_PrintGender(mon,window,80,0,p,0,POKETRADE_PROC_IsWifiMode(p));
        GF_FONT_SetTextColor(15,2,0);
        POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index)),16,19,p);
        POKETRADE_SAVE_PrintHeldItem((int)mon,*(int *)(items+index),16,128,p);
        i++;
        POKETRADE_SAVE_CreateStatusIconActor(p+0x8c4+i*20,mon,((struct Obj00001 *)p)->f9C4,*(int *)((char *)&b+index)+16,16,0,((struct Obj00001 *)p)->f5F4,*(int *)((char *)&c+index));
        CLACT_SetActorBgPriority(*(void **)(p+i*20+0x8d4),1);
    } else {
        tmp=p+0x8c4;
        POKETRADE_SAVE_DeleteStatusIconActor(tmp+(i+1)*20);
    }
    BMP_WIN_TransferChars((struct Descriptor *)*(const int *)(old+index));
    BMP_WIN_MakeScreen((struct Cfg *)(*(const int *)(old+index)));
    func_02041B6C(3);
}
