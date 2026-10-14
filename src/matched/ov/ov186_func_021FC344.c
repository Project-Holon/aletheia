/*
 * function: BR_RES_GetCharFileId
 * address: 0x021FC344
 * packet: pkt_ov186_021FC344
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D48 0x02200D48 data a1
 *   d_022008A0 0x022008A0 data a4
 */
extern char d_02200D48[];
extern const unsigned d_022008A0[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
unsigned short BR_RES_GetCharFileId(unsigned i) { if(i>=8)func_02034714(d_02200D48,0,d_02200D48);return d_022008A0[i]; }
