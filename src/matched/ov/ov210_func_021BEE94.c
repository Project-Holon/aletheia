/*
 * function: func_021BEE94
 * address:  0x021BEE94
 * packet:   pkt_ov210_021BEE94
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC3E8 0x021BC3E8 thumb ov210
 *   func_0204A48C 0x0204A48C arm
 *   d_021C0990 0x021C0990 data a4 ov210
 */

typedef unsigned int u32;
typedef struct { u32 w[7]; } Tbl;
extern const Tbl d_021C0990;

struct Cfg;
extern void *func_021BC3E8(void);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);

void func_021BEE94(void)
{
    Tbl tbl = d_021C0990;

    func_0204A48C((const struct Cfg *)(&tbl), (u32)func_021BC3E8(), 0x7b);
}
