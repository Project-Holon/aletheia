/*
 * function: func_021FC36C
 * address: 0x021FC36C
 * packet: pkt_ov186_021FC36C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D48 0x02200D48 data a1
 *   d_02200880 0x02200880 data a4
 */
extern char d_02200D48[];
extern const unsigned d_02200880[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
unsigned short func_021FC36C(unsigned i) { if(i>=8)func_02034714(d_02200D48,0,d_02200D48);return d_02200880[i]; }
