/*
 * function: func_021FD68C
 * address: 0x021FD68C
 * packet: pkt_ov132_021FD68C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void *func_021FD68C(int a,char *p)
{
    char *q;
    q=*(char **)(p+0x140);
    return *(char **)(q+0x10)+*(u8 *)(p+0x14c)*0x3800;
}
