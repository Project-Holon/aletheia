/*
 * function: func_021FD328
 * address: 0x021FD328
 * packet: pkt_ov132_021FD328
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void *func_021FD328(int a,char *p)
{
    u8 i;
    for(i=0;i<4;i++) *(int *)(p+i*0x30+0x68)=0;
    *(int *)(p+0x158)=0;
    return *(void **)(p+0x13c);
}
