/*
 * unit: no
 * function: func_021E04C4
 * address: 0x021E04C4
 * packet: pkt_ov137_021E04C4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E1CB0 0x021E1CB0 data a4
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct Cfg;struct CharBuf;struct Bank;struct Util;struct Setup;struct Ctx;
extern int TOUCHPANEL_HitTrg(const void *);
extern const u8 d_021E1CB0[];
int func_021E04C4(char *a0){if(TOUCHPANEL_HitTrg(d_021E1CB0)!=-1)return 1;return 0;}
