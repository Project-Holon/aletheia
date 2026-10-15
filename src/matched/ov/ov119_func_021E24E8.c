/*
 * function: POKETRADE_SAVE_DrawOfferListWindows
 * address: 0x021E24E8
 * packet: pkt_ov119_021E24E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * zero: the literal 0 arguments of the first loop are hoisted and spilled to the slot k then reuses; k=0 is written just before the second GF_FONT_SetTextColor call, not before the loop.
 * symbols:
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   POKETRADE_PROC_IsWifiMode 0x021D8ADC thumb ov119
 *   POKETRADE_2D_CreateOfferWindows 0x021E6CB8 thumb ov119
 *   POKETRADE_2D_CreateOfferIconActor 0x021E6334 thumb ov119
 *   POKETRADE_2D_UpdateOfferWindowActors 0x021E6E7C thumb ov119
 *   POKETRADE_SAVE_PrintNickname 0x021E1430 thumb ov119
 *   POKETRADE_SAVE_PrintGender 0x021E1670 thumb ov119
 *   POKETRADE_SAVE_PrintLevel 0x021E15F8 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern int POKETRADE_PROC_IsWifiMode(char *);
extern void POKETRADE_2D_CreateOfferWindows(char *);
extern void POKETRADE_2D_CreateOfferIconActor(char *,int,int,void *,int,u32);
extern void POKETRADE_2D_UpdateOfferWindowActors(int p);
extern void POKETRADE_SAVE_PrintNickname(void *,void *,int,int,int,int,char *);
extern void POKETRADE_SAVE_PrintGender(void *,void *,int,int,char *,int,int);
extern void POKETRADE_SAVE_PrintLevel(void *,void *,int,int,char *);
#define I(k) (*(int *)(p+(k)))
#define P(k) (*(void **)(p+(k)))
void POKETRADE_SAVE_DrawOfferListWindows(char *p, int a1)
{
    void *arr[2];
    void *mon;
    u32 flag76;
    char *q1,*q2;
    int j,n;
    int k;
    POKETRADE_2D_CreateOfferWindows(p);
    arr[0]=P(0x834);
    arr[1]=P(0x830);
    GF_FONT_SetTextColor(15,2,0);
    for(j=0;j<2;j++) {
        MSGDATA_ReadString(P(0x720),128,P(0x734));
        WORDSET_SetSlotMyStatus(P(0x724),0,arr[j]);
        WORDSET_CopyTaggedText(P(0x724),P(0x730),P(0x734));
        PRINTSYS_Print(*(void **)(p+j*16+0x10f4),0,0,P(0x730),P(0x728));
    }
    k=0;
    GF_FONT_SetTextColor(15,2,k);
    for(;k<2;k++) {
        GF_FONT_SetTextColor(1,2,0);
        q1=p+(1-k)*12;
        q2=p+k*16;
        for(n=0;n<3;n++) {
            mon=*(void **)(q1+n*4+0xfd8);
            if(*(int *)(q1+n*4+0xfa4)!=-1) {
                flag76=POKE_TOOL_GetPartyValue(mon,76,0);
                POKETRADE_2D_CreateOfferIconActor(p,k,n,mon,0,1);
                POKETRADE_SAVE_PrintNickname(mon,*(void **)(q2+n*4+0x10f8),0,0,flag76,POKETRADE_PROC_IsWifiMode(p),p);
                if(flag76==0) {
                    POKETRADE_SAVE_PrintGender(mon,*(void **)(q2+n*4+0x10f8),56,16,p,0,POKETRADE_PROC_IsWifiMode(p));
                    POKETRADE_SAVE_PrintLevel(mon,*(void **)(q2+n*4+0x10f8),0,16,p);
                }
            }
        }
    }
    POKETRADE_2D_UpdateOfferWindowActors((int)p);
}
