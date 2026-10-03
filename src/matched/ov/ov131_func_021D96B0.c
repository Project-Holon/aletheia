/*
 * function: func_021D96B0
 * address: 0x021D96B0
 * packet: pkt_ov131_021D96B0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021DC844 0x021DC844 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021DC844[];
u8 *func_021D96B0(u8 *a)
{
    u8 *p;
    u8 i;
    p=func_02030734(*(u16 *)a,296,0,d_021DC844,315);
    *(u32 *)(p+0)=0;
    *(u32 *)(p+4)=0;
    *(u32 *)(p+8)=0;
    *(u32 *)(p+16)=0;
    *(u32 *)(p+20)=0;
    *(u32 *)(p+24)=0;
    *(u32 *)(p+36)=0;
    p[42]=5;
    p[41]=255;
    if ((*(u8 **)(a+8))[13]==2 && *(u16 *)(*(u8 **)(a+8)+20)!=0) p[43]=5;
    else p[43]=4;
    for(i=0;i<5;i++) {
        p[0xb0+i*24]=255;
        *(u32 *)(p+0xb4+i*24)=0;
    }
    return p;
}
