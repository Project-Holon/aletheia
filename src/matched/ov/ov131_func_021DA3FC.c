/*
 * function: P_STA_SKILL_DrawHpBar
 * address: 0x021DA3FC
 * packet: pkt_ov131_021DA3FC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA486.
 * symbols:
 *   P_STATUS_GetPokeParaSource 0x021D60A4 thumb ov131
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_0202D034 0x0202D034 thumb
 *   func_0202D01C 0x0202D01C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_FillRect 0x02043AF4 arm
 */
#include "../include/Obj01061.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int P_STATUS_GetPokeParaSource(char *p);
typedef unsigned int   u32;
struct Bmp;
struct Descriptor;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern int func_0202D034(u32 a, u32 b);
extern u8 func_0202D01C(u32 a, u32 b, u32 c);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void P_STA_SKILL_DrawHpBar(u8 *a,u8 *b) {
    void *p,*bmp;
    u16 x,y;
    int kind,value,first,last;
    p=(void *)P_STATUS_GetPokeParaSource((char *)a);
    x=POKE_TOOL_GetPartyValue(p,161,0);
    y=POKE_TOOL_GetPartyValue(p,160,0);
    kind=func_0202D034(y,x);
    value=func_0202D01C(y,x,48);
    bmp=BMP_WIN_GetBmp(((struct Obj01061 *)b)->f60);
    if((u8)(kind+254)<=1) {first=7;last=8;}
    else if(kind==1) {first=9;last=10;}
    else {first=5;last=6;}
    BMP_FillRect(bmp,0,3,value,1,first);
    BMP_FillRect(bmp,0,4,value,1,last);
}
