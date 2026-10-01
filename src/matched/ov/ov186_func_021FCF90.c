/*
 * function: func_021FCF90
 * address: 0x021FCF90
 * packet: pkt_ov186_021FCF90
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: scroll range update after func_021FCF54.
 */
int func_021FCF90(char *p,int change)
{
    if(*(unsigned short *)(p+0x42)!=0 && change==-1) {
        *(unsigned short *)(p+0x42)+=(unsigned short)change;
        return 1;
    }
    if(*(unsigned short *)(p+0x42)+*(unsigned short *)(p+0x44)<*(unsigned *)(p+4) && change==1) {
        *(unsigned short *)(p+0x42)+=(unsigned short)change;
        return 1;
    }
    return 0;
}
