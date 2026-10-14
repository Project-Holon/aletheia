/*
 * function: POKETRADE_NEGO_ShowOfferSlotMon
 * address: 0x021DF918
 * packet: pkt_ov119_021DF918
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_SetOfferIconsVisible 0x021E6308 thumb ov119
 *   POKETRADE_SAVE_DeletePartnerOfferCard 0x021E293C thumb ov119
 *   POKETRADE_3D_DeleteMcssSlot 0x021E36D8 thumb ov119
 *   POKETRADE_2D_LoadMonPalette 0x021E6F0C thumb ov119
 *   POKETRADE_SAVE_DrawPartnerOfferCard 0x021E272C thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   POKETRADE_3D_AddPokemonMcssFlipped 0x021E36A8 thumb ov119
 */
extern void POKETRADE_2D_SetOfferIconsVisible(void *,int,int);
typedef unsigned int   u32;
extern void POKETRADE_SAVE_DeletePartnerOfferCard(char *p, int i);
extern void POKETRADE_3D_DeleteMcssSlot(void *,int);
extern void POKETRADE_2D_LoadMonPalette(char *p, int side, void *mon);
extern void POKETRADE_SAVE_DrawPartnerOfferCard(char *p, int i, void *mon);
extern void func_02041B6C(u32 bit);
extern void POKETRADE_3D_AddPokemonMcssFlipped(void *,int,int,void *,int,int);
void POKETRADE_NEGO_ShowOfferSlotMon(void *p,int i,void *v)
{
    int one;
    POKETRADE_2D_SetOfferIconsVisible(p,i,0);
    if (((unsigned char *)p+i)[0x11e2]) {
        POKETRADE_SAVE_DeletePartnerOfferCard(p,i);
        POKETRADE_3D_DeleteMcssSlot(p,i);
    }
    POKETRADE_2D_LoadMonPalette(p,i,v);
    POKETRADE_SAVE_DrawPartnerOfferCard(p,i,v);
    one=1;
    func_02041B6C(1);
    POKETRADE_3D_AddPokemonMcssFlipped(p,i,one-i,v,one-i,one);
}
