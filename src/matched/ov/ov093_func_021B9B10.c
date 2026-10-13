/*
 * function: BTL_MAIN_AddClientPoints
 * address: 0x021B9B10
 * packet: pkt_ov093_021B9B10
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 *   BTL_CLIENT_AddPoints 0x021CD9F4 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);
extern void BTL_CLIENT_AddPoints(void *,int);
void BTL_MAIN_AddClientPoints(u8 *p,u8 i,int v) {
    void *q;
    if(p[0x46e] && BTL_MAIN_IsClientUsed(p,i)) {
        q=*(void **)(p+i*4+16);
        if(q) BTL_CLIENT_AddPoints(q,v);
    }
}
