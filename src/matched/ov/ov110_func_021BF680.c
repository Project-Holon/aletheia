/*
 * function: func_021BF680
 * address: 0x021BF680
 * packet: pkt_ov110_021BF680
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02024464 0x02024464 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02024464(void *,int);
int func_021BF680(u8 *p) {
    switch(*(u32 *)(p+4)) {
    case 0: if(*(u16 *)(p+16)!=65535) return 1; else return 0;
    case 1: if(*(u16 *)(p+16)!=65535 && *(u16 *)(p+18)!=65535) return 1; else return 0;
    case 2: return func_02024464(p+8,42);
    }
    return 0;
}
