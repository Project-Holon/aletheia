/*
 * function: func_021BE43C
 * address: 0x021BE43C
 * packet: pkt_ov209_021BE43C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD8F4 0x021BD8F4 thumb ov209
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_021BD8F4(char *p, u32 idx);
void func_021BE43C(char *p)
{
    unsigned i;
    *(u16 *)(p+0xc28)=0;
    *(u16 *)(p+0xc2a)=0;
    for(i=10;i<26;i++)if(func_021BD8F4((char *)((int)p),i))*(u16 *)(p+0xc28)|=(u16)(1<<(i-10));
    for(i=26;i<42;i++)if(func_021BD8F4((char *)((int)p),i))*(u16 *)(p+0xc2a)|=(u16)(1<<(i-26));
}
