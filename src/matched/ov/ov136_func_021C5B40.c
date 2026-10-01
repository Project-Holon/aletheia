/*
 * function: func_021C5B40
 * address: 0x021C5B40
 * packet: pkt_ov136_021C5B40
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02009050 0x02009050 thumb
 *   func_02008EF8 0x02008EF8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_02009050(void *,int,int,int);
extern int func_02008EF8(void *);
void func_021C5B40(u8 *p)
{
    unsigned i;
    u8 *q;
    *(u16 *)(*(u8 **)(p+8)+0x2fc)=0;
    for(i=0;i<20;i++) {
        (*(u8 **)(p+8))[0x2e8+i]=255;
        *(void **)(*(u8 **)(p+8)+0x298+i*4)=func_02009050(*(void **)p,0,i,102);
        if(func_02008EF8(*(void **)(*(u8 **)(p+8)+0x298+i*4))==1) {
            (*(u8 **)(p+8))[0x2e8+*(u16 *)(*(u8 **)(p+8)+0x2fc)]=i;
            ++*(u16 *)(*(u8 **)(p+8)+0x2fc);
        }
    }
    q=*(u8 **)(p+8);
    if(*(u16 *)(q+0x2fc)==0) *(u16 *)(q+0x2fe)=0;
    else *(u16 *)(q+0x2fe)=(*(u16 *)(q+0x2fc)-1)/10;
}
