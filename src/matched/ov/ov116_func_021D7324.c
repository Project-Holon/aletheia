/*
 * function: func_021D7324
 * address: 0x021D7324
 * packet: pkt_ov116_021D7324
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045A98 0x02045A98 arm
 *   func_02045A90 0x02045A90 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_02045A98(void);
struct U16Vec;
extern u16 *func_02045A90(struct U16Vec *vec);
u32 func_021D7324(u8 *p) {
    u16 end=func_02045A98();
    u16 *s=func_02045A90(*(void **)(*(u8 **)(p+0x1840)+32));
    u32 value=0;
    u16 i=0;
    while(s[i]!=end) {
        u16 d=(u16)(s[i]-48);
        if(d>=10) d=(u16)(s[i]-0xff10);
        value *= 10;
        value += d;
        i++;
    }
    return value;
}
