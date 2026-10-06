/*
 * function: func_021D7894
 * address: 0x021D7894
 * packet: pkt_ov093_021D7894
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6360 0x021F6360 data a4
 *   func_020307B0 0x020307B0 arm
 */
typedef struct { unsigned int f0; void *f4; } State;
extern State d_021F6360;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021D7894(void) { if (d_021F6360.f4) { func_020307B0(d_021F6360.f4); d_021F6360.f4 = 0; } }
