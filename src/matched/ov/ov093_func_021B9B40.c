/*
 * function: func_021B9B40
 * address: 0x021B9B40
 * packet: pkt_ov093_021B9B40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT* (2 bytes alignment padding)
 */
typedef unsigned char u8;
typedef unsigned int u32;
void func_021B9B40(u8 *p) {
    int i;
    p[24] = 0;
    for(i=0;i<6;i++) ((u32 *)p)[i]=0;
}
