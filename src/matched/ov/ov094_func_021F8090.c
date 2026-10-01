/*
 * function: func_021F8090
 * address:  0x021F8090
 * packet:   pkt_ov094_021F8090
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   func_02207288 0x02207288 thumb ov094
 * extent: Already matched followers begin at 0x021F80E4.
 */
typedef unsigned int u32;
extern char *d_0220AF20;
extern void func_02207288(u32 obj, u32 a, u32 b, u32 mode, u32 c);

void func_021F8090(u32 a, u32 b, u32 c)
{
    switch (*(u32 *)(d_0220AF20 + 0x1BC)) {
    case 2:
        func_02207288(*(u32 *)(d_0220AF20 + 0x1A4), a, b, 2, c);
        break;
    case 3:
        func_02207288(*(u32 *)(d_0220AF20 + 0x1A4), a, b, 3, c);
        break;
    default:
        func_02207288(*(u32 *)(d_0220AF20 + 0x1A4), a, b, 0, c);
        break;
    }
}
