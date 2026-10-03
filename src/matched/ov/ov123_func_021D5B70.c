/*
 * function: func_021D5B70
 * address: 0x021D5B70
 * packet: pkt_ov123_021D5B70
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021DAC20 0x021DAC20 data ov123 a4
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_020307B0 0x020307B0 arm
 */
extern char *g_021DAC20;
extern void func_02156DE0(int a, int b);
extern void func_020307B0(void *);
void func_021D5B70(char *p){if(g_021DAC20){func_02156DE0(0,0);func_020307B0(*(void **)(p+0xb8));func_020307B0(p);g_021DAC20=0;}}
