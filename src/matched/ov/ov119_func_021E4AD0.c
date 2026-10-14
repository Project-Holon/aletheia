/*
 * function: POKETRADE_2D_UpdateIconObjMode
 * address: 0x021E4AD0
 * packet: pkt_ov119_021E4AD0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   POKETRADE_NEGO_IsMonOwnOffer 0x021DF614 thumb ov119
 *   POKETRADE_2D_SetIconObjMode 0x021E4AB8 thumb ov119
 */
extern int POKETRADE_NEGO_IsMonOwnOffer(char *p, int a, int b);
extern void POKETRADE_2D_SetIconObjMode(int a0, int a1, int a2);
void POKETRADE_2D_UpdateIconObjMode(char *p, int a1, int a2, int a3, int a4, int a5)
{
    int flag = 0;
    if (POKETRADE_NEGO_IsMonOwnOffer(p, a1, a2)) {
        flag = 1;
    }
    POKETRADE_2D_SetIconObjMode((int)p, ((int (*)[5])(p + 0xAC0))[a5][a2], flag);
}
