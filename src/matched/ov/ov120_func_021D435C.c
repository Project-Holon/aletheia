/*
 * function: func_021D435C
 * address: 0x021D435C
 * packet: pkt_ov120_021D435C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: separately filed 021D437C.
 */
void func_021D435C(int n, char *p) {
    *(int *)(p+0x13c)+=n;
    if(*(int *)(p+0x13c)>=5) *(int *)(p+0x13c)=0;
    else if(*(int *)(p+0x13c)<0) *(int *)(p+0x13c)=4;
}
