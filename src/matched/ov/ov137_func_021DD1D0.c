/*
 * function: func_021DD1D0
 * address: 0x021DD1D0
 * packet: pkt_ov137_021DD1D0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020433E0 0x020433E0 arm
 *   d_021E1B40 0x021E1B40 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern const u32 d_021E1B40[];
void func_021DD1D0(void) {func_020433E0((const struct DispVram *)d_021E1B40);}
