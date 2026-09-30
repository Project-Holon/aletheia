/*
 * function: func_021BEB78
 * address: 0x021BEB78
 * packet: pkt_ov110_021BEB78
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3978 0x021C3978 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const u8 d_021C3978[][4];
int func_021BEB78(u8 *p) {
    u16 v=*(u16 *)(p+76);
    u16 n=v;
    if(v==254) n=12;
    if(v!=254) {
        *(u16 *)(p+78)=v;
        if(*(u16 *)(p+56)&64) { *(u16 *)(p+76)=d_021C3978[n][0]; return 1; }
        if(*(u16 *)(p+56)&128) { *(u16 *)(p+76)=d_021C3978[n][1]; return 1; }
        if(*(u16 *)(p+56)&32) { *(u16 *)(p+76)=d_021C3978[n][2]; return 1; }
        if(*(u16 *)(p+56)&16) { *(u16 *)(p+76)=d_021C3978[n][3]; return 1; }
    } else {
        *(u16 *)(p+78)=254;
        if(*(u16 *)(p+56)&64) { *(u16 *)(p+76)=11; return 1; }
        if(*(u16 *)(p+56)&128) { *(u16 *)(p+76)=2; return 1; }
    }
    return 0;
}
