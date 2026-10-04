/*
 * function: func_02174E20
 * address:  0x02174E20
 * packet:   pkt_ov012_02174E20
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

struct Entry;

extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void func_02174E20(void)
{
    func_0203D3F8((u32)func_020399A8(), 0, 0x1508, 0, 0, 1, 0, 0);
}
