/*
 * function: func_021DF984
 * address: 0x021DF984
 * packet: pkt_ov137_021DF984
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020433E0 0x020433E0 arm
 *   func_02045088 0x02045088 arm
 *   d_021E1EA4 0x021E1EA4 data a4
 */
typedef unsigned short u16;
struct DispVram;extern const struct DispVram d_021E1EA4;
extern void func_020433E0(const struct DispVram *);extern void func_02045088(u16);
void func_021DF984(char *p){func_020433E0(&d_021E1EA4);func_02045088(114);}
