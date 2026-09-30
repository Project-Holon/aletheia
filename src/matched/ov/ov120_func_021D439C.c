/*
 * function: func_021D439C
 * address: 0x021D439C
 * packet: pkt_ov120_021D439C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: handed caller 021D43BC.
 */
void func_021D439C(int n, char *p) {
    *(int *)(p+0x144)+=n;
    if(*(int *)(p+0x144)>=4) *(int *)(p+0x144)=0;
    else if(*(int *)(p+0x144)<0) *(int *)(p+0x144)=3;
}
