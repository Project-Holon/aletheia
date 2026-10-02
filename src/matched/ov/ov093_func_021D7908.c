/*
 * function: func_021D7908
 * address: 0x021D7908
 * packet: pkt_ov093_021D7908
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0462 0x021F0462 data a1
 *   _s32_div_f 0x0209C0A4 arm
 */
extern unsigned char d_021F0462[][2];
extern int _s32_div_f(int, int);
unsigned char func_021D7908(int a, int i) { unsigned int v = _s32_div_f(a*d_021F0462[i][0], d_021F0462[i][1]); if(v>100) v=100; return v; }
