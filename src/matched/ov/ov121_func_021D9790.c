/*
 * function: func_021D9790
 * address: 0x021D9790
 * packet: pkt_ov121_021D9790
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02050ED4 0x02050ED4 arm
 *   func_021D9960 0x021D9960 thumb ov121
 *   func_0203FC28 0x0203FC28 arm
 *   d_021DF598 0x021DF598 data a4
 */
typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);
extern void func_02050ED4(void);
extern void func_021D9960(char *p);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern const unsigned d_021DF598[];
void func_021D9790(char *p) { func_02040588(0,0);func_02050ED4();func_021D9960(p+12);func_0203FC28((struct DispConfig *)d_021DF598); }
