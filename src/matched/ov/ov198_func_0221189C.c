/*
 * function: func_0221189C
 * address: 0x0221189C
 * packet: pkt_ov198_0221189C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02210EFC 0x02210EFC thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 */
typedef unsigned char u8;
typedef struct { u8 lo:7; u8 high:1; } Bits;
extern unsigned func_02210EFC(unsigned);
extern int func_022110D4(u8 *,int);
int func_0221189C(u8 *p)
{
    u8 i;
    if(func_02210EFC((unsigned)p)==1) return 0;
    i=(*(u8 **)p)[0x22];
    if(i==1) return 0;
    for(;i<6;i++) {
        u8 *record=p+func_022110D4(p,i)*0x4c;
        if(*(unsigned short *)(record+8)!=0 && ((Bits *)(record+0x1b))->high==0 && *(unsigned short *)(record+0x14)!=0) return 1;
    }
    return 0;
}
