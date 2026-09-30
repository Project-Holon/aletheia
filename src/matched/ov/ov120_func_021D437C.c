/*
 * function: func_021D437C
 * address: 0x021D437C
 * packet: pkt_ov120_021D437C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: separately filed 021D439C.
 */
void func_021D437C(int n, char *p) {
    *(int *)(p+0x140)+=n;
    if(*(int *)(p+0x140)>=5) *(int *)(p+0x140)=0;
    else if(*(int *)(p+0x140)<0) *(int *)(p+0x140)=4;
}
