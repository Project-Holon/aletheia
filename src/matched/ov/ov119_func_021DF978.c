/*
 * function: POKETRADE_NEGO_TickOfferSlotTimers
 * address: 0x021DF978
 * packet: pkt_ov119_021DF978
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_SetOfferIconsVisible 0x021E6308 thumb ov119
 *   POKETRADE_SAVE_DeletePartnerOfferCard 0x021E293C thumb ov119
 *   POKETRADE_3D_DeleteMcssSlot 0x021E36D8 thumb ov119
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 */
extern void POKETRADE_2D_SetOfferIconsVisible(void *,int,int);
typedef unsigned int   u32;
extern void POKETRADE_SAVE_DeletePartnerOfferCard(char *p, int i);
extern void POKETRADE_3D_DeleteMcssSlot(void *,int);
extern void func_02041300(int,int,unsigned char,int,int,int,int);
extern void func_02041B6C(u32 bit);
void POKETRADE_NEGO_TickOfferSlotTimers(void *p)
{
    int i;
    for(i=0;i<2;i++) {
        if (((unsigned char *)p+i)[0x11e2]==0) continue;
        ((unsigned char *)p+i)[0x11e2]--;
        POKETRADE_2D_SetOfferIconsVisible(p,i,0);
        if (((unsigned char *)p+i)[0x11e2]==0) {
            POKETRADE_SAVE_DeletePartnerOfferCard(p,i);
            func_02041300(1,0,(unsigned char)(i<<4),0,16,24,16);
            func_02041B6C(1);
            POKETRADE_3D_DeleteMcssSlot(p,i);
            POKETRADE_2D_SetOfferIconsVisible(p,i,1);
        }
    }
}
