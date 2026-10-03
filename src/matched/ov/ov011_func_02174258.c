/*
 * function: func_02174258
 * address:  0x02174258
 * packet:   pkt_ov011_02174258
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02175C58  0x02175C58  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 */

int func_021736D8(void);
void func_02175C58(void *a, int b);
int func_020399A8(void);
typedef unsigned int   u32;
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_02174258(char *a)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    func_02175C58(a + 0x1ac, 0);
    return func_0203D3F8(func_020399A8(), 0, 0x219, 0, 0, 0, 0, 0);
}
