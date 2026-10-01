/*
 * function: func_0220BB1C
 * address: 0x0220BB1C
 * packet: pkt_ov197_0220BB1C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F114 0x0202F114 thumb
 *   func_0202F138 0x0202F138 thumb
 */
extern unsigned func_0202F114(const unsigned char *,unsigned);
extern unsigned short func_0202F138(unsigned);
void func_0220BB1C(char *p)
{
    unsigned i;
    for(i=0;i<46;i++) {
        if(func_0202F114(*(const unsigned char **)(*(char **)p+0x10),i)==1) {
            *(unsigned short *)(p+0x150+*(unsigned char *)(p+0x535)*4)=func_0202F138(i);
            *(unsigned short *)(p+0x152+*(unsigned char *)(p+0x535)*4)=1;
            (*(unsigned char *)(p+0x535))++;
        }
    }
    *(unsigned char *)(p+0x539)=(*(unsigned char *)(p+0x535)-1)/6;
}
