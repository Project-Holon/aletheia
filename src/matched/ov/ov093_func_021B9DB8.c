/*
 * function: func_021B9DB8
 * address: 0x021B9DB8
 * packet: pkt_ov093_021B9DB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
typedef unsigned int u32;
void func_021B9DB8(char *p) {
    u32 i;
    char *q;
    for(i=0;i<4;i++) {
        q=p+i*40;
        *(u32 *)(q+32)=0;
        *(u16 *)(q+42)=0;
        *(u32 *)(q+44)=0;
    }
    for(i=0;i<4;i++) *(u32 *)(p+i*4+0x3e0)=0;
}
