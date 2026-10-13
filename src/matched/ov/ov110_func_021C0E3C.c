/*
 * function: PMS_SELECT_GRAPHIC_GetThumbRow
 * address: 0x021C0E3C
 * packet: pkt_ov110_021C0E3C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
void PMS_SELECT_GRAPHIC_GetThumbRow(unsigned y,int count,short *out,short *pos) {
    int n,i,a,b;
    n=count-2;
    for(i=0;i<n;i++) {
        a=137*i/n+16;
        b=(137*i+137)/n+16;
        if(i==0) { if(y<b) { *out=i; break; } }
        else if(i==n-1) { if(y>=a) { *out=i; break; } }
        else { if(a<=y && y<b) { *out=i; break; } }
    }
    if(y>152) y=152;
    else if(y<16) y=16;
    *pos=y;
}
