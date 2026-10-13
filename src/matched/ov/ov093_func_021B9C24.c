/*
 * function: BTL_SLOT_MoveToEnd
 * address: 0x021B9C24
 * packet: pkt_ov093_021B9C24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
void BTL_SLOT_MoveToEnd(u8 *p, u8 i) {
    u32 t=((u32 *)p)[i];
    for(;i<p[24]-1;i++) ((u32 *)p)[i]=((u32 *)p)[i+1];
    ((u32 *)p)[i]=t;
}
