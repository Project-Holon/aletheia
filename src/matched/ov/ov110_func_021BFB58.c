/*
 * function: func_021BFB58
 * address: 0x021BFB58
 * packet: pkt_ov110_021BFB58
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   func_021BC898 0x021BC898 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BC898(u8 *p);
int func_021BFB58(u8 *p) {
    if(*(u32 *)(p+0x88)==0) {
        if(func_021BC898(p+0x4c)) return 1;
        else return 0;
    } else return 1;
}
