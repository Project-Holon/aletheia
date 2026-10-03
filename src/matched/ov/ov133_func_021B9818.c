/*
 * function: func_021B9818
 * address: 0x021B9818
 * packet: pkt_ov133_021B9818
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Duplicate only the byte-store statement in the if/else; its merged tail retains the branch to next that a pre-store selection removes.
 */
typedef unsigned char u8;
typedef unsigned short u16;
void func_021B9818(u8 *p)
{
    unsigned i;
    *(int *)(p+0x183c)=1;
    *(u16 *)(p+0x1844)=0;
    p[0x1846]=1;
    i=5;
    do {
        if(*(int *)(*(u8 **)(p+(unsigned)i*4+0x1434)+12)!=1) break;
        i=(u16)(i+1);
        if(i==*(u16 *)(p+0xa8)) i=0;
    } while(i!=5);
    if(i==0) p[0x1847]=*(u16 *)(p+0xa8)-1;
    else p[0x1847]=i-1;
    *(int *)(p+12)=0;
}
