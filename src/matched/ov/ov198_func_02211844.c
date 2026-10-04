/*
 * function: func_02211844
 * address: 0x02211844
 * packet: pkt_ov198_02211844
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 0221189A..0221189C is zero alignment padding.
 * symbols:
 *   func_02210EFC 0x02210EFC thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 */
typedef unsigned char u8;
extern int func_02210EFC(char **p);
extern int func_022110D4(u8 *,int);
int func_02211844(u8 *p)
{
    u8 count,i,bound;
    if(func_02210EFC((char **)((unsigned)p))==1) return 0;
    bound=(*(u8 **)p)[0x22];
    if(bound==1) return 0;
    count=0;
    for(i=0;i<bound;i++) {
        if(*(unsigned short *)(p+func_022110D4(p,i)*0x4c+0x14)==0) {
            count++;
            if(count==2) return 1;
        }
    }
    return 0;
}
