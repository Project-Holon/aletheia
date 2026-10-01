/*
 * function: func_021FD110
 * address: 0x021FD110
 * packet: pkt_ov186_021FD110
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: accessor after func_021FD0B8; two alignment bytes after return.
 */
void func_021FD110(char *p)
{
    *(int *)(p+0x48)=((int *)(*(int *)p+(*(unsigned short *)(p+0x40)+*(unsigned short *)(p+0x42))*8))[1];
}
