/*
 * function: func_021D8134
 * address: 0x021D8134
 * packet: pkt_ov116_021D8134
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The duplicated 021D8560 pool words require separate extern names;
 * see the duplicated-pool-word idiom.
 * symbols:
 *   func_0201FDA0 0x0201FDA0 thumb
 *   d_021D8560 0x021D8560 data a4
 *   d_021D8560_menu 0x021D8560 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinDat; struct BmpMenu;
extern u8 d_021D8560[];
extern u8 d_021D8560_menu[];
extern struct BmpMenu *func_0201FDA0(const struct WinDat *,u16,u8,u8,u16);
void func_021D8134(u8 *p) { *(u16 *)(d_021D8560+4)=*(u32 *)(p+0x988); *(struct BmpMenu **)(p+0x980)=func_0201FDA0((const struct WinDat *)d_021D8560_menu,*(u32 *)(p+0x988),13,0,*(u16 *)(p+4)); }
