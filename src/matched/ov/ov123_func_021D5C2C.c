/*
 * function: func_021D5C2C
 * address: 0x021D5C2C
 * packet: pkt_ov123_021D5C2C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021DAC20 0x021DAC20 data ov123 a4
 */
extern char *g_021DAC20;
int func_021D5C2C(char *p){if(*(int *)(p+0xd0)&&*(int *)(p+0xc8))return 1;if(*(int *)(g_021DAC20+0xb0)&&*(int *)(p+0xb4))return 1;return 0;}
