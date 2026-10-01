/*
 * function: func_021E1814
 * address: 0x021E1814
 * packet: pkt_ov137_021E1814
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
void func_021E1814(unsigned char *p,u16 *q)
{
    u16 *d=(u16 *)(p+108);
    unsigned n=8;
    do { *d++=*q++; } while(--n);
    *(int *)(p+64)=1;
}
