/*
 * function: func_021D8950
 * address: 0x021D8950
 * packet: pkt_ov129_021D8950
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 * Extent ends with two bytes of zero alignment padding.
 */

void func_021D8950(char *p,int v)  {
    *(int *)(p+0x244)=*(int *)(p+0x240);
    *(int *)(p+0x240)=v;
    *(int *)(p+0x248)=0;
    *(int *)(p+0x24c)=0;
    *(int *)(p+0x250)=0;
    *(int *)(p+0x254)=0;
    if(v)  {
        *(int *)(p+0x248)=*(unsigned short *)(p+(v-1)*4+0x21c);
        *(int *)(p+0x24c)=*(unsigned short *)(p+(v-1)*4+0x21e);
    }
    if(*(int *)(p+0x244))  {
        v=*(int *)(p+0x244);
        *(int *)(p+0x250)=*(unsigned short *)(p+(v-1)*4+0x21c);
        *(int *)(p+0x254)=*(unsigned short *)(p+(v-1)*4+0x21e);
    }
}
