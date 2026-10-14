/*
 * function: POKETRADE_SAVE_DrawPartnerOfferCard
 * address: 0x021E272C
 * packet: pkt_ov119_021E272C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: each final handle index is recomputed through a 32-bit long local;
 * an int copy CSEs the shift and shortens the function by four bytes.
 * symbols:
 *   d_021E7924 0x021E7924 data a4
 *   d_021E791C 0x021E791C data a4
 *   d_021E7974 0x021E7974 data a4
 *   d_021E790C 0x021E790C data a4
 *   func_02017E1C 0x02017E1C thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   POKETRADE_PROC_IsWifiMode 0x021D8ADC thumb ov119
 *   POKETRADE_SAVE_PrintNickname 0x021E1430 thumb ov119
 *   POKETRADE_SAVE_PrintGender 0x021E1670 thumb ov119
 *   POKETRADE_SAVE_PrintLevel 0x021E15F8 thumb ov119
 *   POKETRADE_SAVE_PrintHeldItem 0x021E1778 thumb ov119
 *   POKETRADE_SAVE_CreateStatusIconActor 0x021E0E68 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferStatusIcons 0x021E1CA8 thumb ov119
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int a,b;} Pair;
typedef struct {u32 a,b,c,d;} Quad;
extern const Pair d_021E7924,d_021E791C,d_021E790C;
extern const Quad d_021E7974;
extern u32 func_02017E1C(void *,u32,u32);
struct Cfg;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern int BMP_WIN_Create(u32,u8,u32,u32,u8,u8,u8);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern int POKETRADE_PROC_IsWifiMode(char *p);
extern void POKETRADE_SAVE_PrintNickname(void *,void *,int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintGender(void *,void *,int,int,char *,int,int);
extern void POKETRADE_SAVE_PrintLevel(void *,void *,int,int,char *);
extern void POKETRADE_SAVE_PrintHeldItem(int,int,int,int,char *);
extern void POKETRADE_SAVE_CreateStatusIconActor(char *,void *,int,int,int,int,u16,int);
extern void POKETRADE_SAVE_DeleteOfferStatusIcons(char *p);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void POKETRADE_SAVE_DrawPartnerOfferCard(char *p,int i,void *mon)
{
    Pair a=d_021E7924;
    Pair b=d_021E791C;
    Quad colors=d_021E7974;
    Pair c=d_021E790C;
    u32 flag;
    int layer,idx2;
    u32 col,col2;
    int index;
    char *items,*items2;
    flag=func_02017E1C(mon,76,0);
    index=i*4;
    if(*(int *)(p+i*4+0x5c4)) {
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+i*4+0x5c4)));
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+i*4+0x5cc)));
    }
    layer=*(int *)((char *)&a+index);
    items=p+0x5c4;
    *(int *)(items+index)=BMP_WIN_Create(1,layer,0,14,5,5,0);
    items2=p+0x5cc;
    *(int *)(items2+index)=BMP_WIN_Create(1,layer,17,13,2,5,0);
    idx2=i*2;
    col=((u32 *)&colors)[idx2];
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index)),(u8)(col|(col<<4)));
    col2=((u32 *)&colors)[idx2+1];
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items2+index)),(u8)(col2|(col2<<4)));
    GF_FONT_SetTextColor(1,2,(u8)col);
    {
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index));
        POKETRADE_SAVE_PrintNickname(mon,window,16,4,flag,POKETRADE_PROC_IsWifiMode(p),p);
    }
    if(flag==0) {
        char *first=p+0x5c4;
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(first+index));
        POKETRADE_SAVE_PrintGender(mon,window,80,4,p,1,POKETRADE_PROC_IsWifiMode(p));
        POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp((struct Descriptor *)*(int *)(first+index)),16,19,p);
        GF_FONT_SetTextColor(1,2,(u8)col2);
        POKETRADE_SAVE_PrintHeldItem((int)mon,*(int *)(items2+index),0,0,p);
        POKETRADE_SAVE_CreateStatusIconActor(p+0x8c4+(i+1)*20,mon,((struct Obj00001 *)p)->f9C4,*(int *)((char *)&b+index)+16,16,0,((struct Obj00001 *)p)->f5F4,*(int *)((char *)&c+index));
    } else POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    {
        char *first=p+0x5c4;
        char *second=p+0x5cc;
        long endindex=(long)i*4;
        BMP_WIN_TransferChars((struct Descriptor *)*(int *)(first+endindex));
        BMP_WIN_TransferChars((struct Descriptor *)*(int *)(second+endindex));
        BMP_WIN_MakeScreen((struct Cfg *)(*(int *)(first+endindex)));
        BMP_WIN_MakeScreen((struct Cfg *)(*(int *)(second+endindex)));
    }
    func_02041B6C(1);
    *(u8 *)(p+i+0x11e2)=120;
}
