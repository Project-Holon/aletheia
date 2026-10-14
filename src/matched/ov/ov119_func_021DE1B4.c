/*
 * function: POKETRADE_NEGO_ShowOfferSummary
 * address: 0x021DE1B4
 * packet: pkt_ov119_021DE1B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsMonValid 0x021D89EC thumb ov119
 *   POKETRADE_SAVE_ShowSummaryMon 0x021E219C thumb ov119
 *   POKETRADE_2D_UpdateOfferIconHighlight 0x021E6440 thumb ov119
 */
typedef unsigned char  u8;
extern int POKETRADE_PROC_IsMonValid(const u8 *p);
extern void POKETRADE_SAVE_ShowSummaryMon(char *p, void *mon, int side, int flag);
extern void POKETRADE_2D_UpdateOfferIconHighlight(int p, int a, int b);
typedef struct { char pad[0xfd8]; void *obj[2][3]; } State;
void POKETRADE_NEGO_ShowOfferSummary(State *p,int index)
{
    int col=index%3;
    int row=index/3;
    int other=1-row;
    void *obj=p->obj[other][col];
    if(POKETRADE_PROC_IsMonValid(obj)) {
        POKETRADE_SAVE_ShowSummaryMon((char *)p,obj,other,1);
        POKETRADE_2D_UpdateOfferIconHighlight((int)p,row,col);
    }
}
