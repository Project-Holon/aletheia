/*
 * unit: no
 * function: func_021E0640
 * address: 0x021E0640
 * packet: pkt_ov137_021E0640
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047E88 0x02047E88 arm
 *   func_0207DD24 0x0207DD24 arm
 *   d_021E1D80 0x021E1D80 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern u16 func_02047E88(struct Util *,const struct Setup *);
extern void func_0207DD24(u16,int,int,int,int);
extern const struct Setup d_021E1D80;
void func_021E0640(u8 *p){*(u32 *)(p+0xda4)=func_02047E88(*(struct Util **)(p+0xaf4),&d_021E1D80);func_0207DD24(0,0,32767,0,0);}
