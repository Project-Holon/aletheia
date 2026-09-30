/*
 * function: func_021BED84
 * address: 0x021BED84
 * packet: pkt_ov110_021BED84
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF734 0x021BF734 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BF734(void *);
void func_021BED84(u8 *p, void *q) {
    *(u16 *)p=0; p[6]=0; p[7]=0;
    *(u16 *)(p+4)=func_021BF734(q);
    *(u32 *)(p+8)=0;
    *(u16 *)(p+12)=0; *(u16 *)(p+14)=65535;
    if (*(u16 *)(p+4)>14) *(u16 *)(p+2)=(*(u16 *)(p+4)-14)/2+(*(u16 *)(p+4)&1);
    else *(u16 *)(p+2)=0;
}
