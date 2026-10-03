/*
 * function: func_021EF1FC
 * address: 0x021EF1FC
 * packet: pkt_ov170_021EF1FC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035BA4 0x02035BA4 arm
 *   func_02035CB8 0x02035CB8 arm
 *   d_021F0024 0x021F0024 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02035BA4(const void*);
extern unsigned func_02035CB8(unsigned*,unsigned*);
extern const u8 d_021F0024[];
int func_021EF1FC(unsigned*a,unsigned*b){if(func_02035BA4(d_021F0024)!=-1){func_02035CB8(a,b);return 1;}return 0;}
