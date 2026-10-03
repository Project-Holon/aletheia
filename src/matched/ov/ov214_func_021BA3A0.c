/*
 * unit: no
 * function: func_021BA3A0
 * address: 0x021BA3A0
 * packet: pkt_ov214_021BA3A0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201FDA0 0x0201FDA0 thumb
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct WinDat;struct BmpMenu;extern struct BmpMenu *func_0201FDA0(const struct WinDat *,u16,u8,u8,u16);
void func_021BA3A0(int unused,u8 *p){*(struct BmpMenu **)(p+0x88)=func_0201FDA0((const struct WinDat *)(p+0x80),*(u32 *)(p+0x74),10,0,*(u16 *)p);}
