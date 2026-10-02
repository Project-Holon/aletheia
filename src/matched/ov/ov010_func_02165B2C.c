/*
 * function: func_02165B2C
 * address: 0x02165B2C
 * packet: pkt_ov010_02165B2C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021729D4 0x021729D4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_02030734(u32,u32,int,const char *,u16);
extern const char d_021729D4[];
u8 *func_02165B2C(u32 heap) { u8 *p=func_02030734(heap,0xb08,1,d_021729D4,0x1c1); p[0xb04]=0; p[0xb05]=0; return p; }
