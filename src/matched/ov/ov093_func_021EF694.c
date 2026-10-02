/*
 * function: func_021EF694
 * address:  0x021EF694
 * packet:   pkt_ov093_021EF694
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F6398  0x021F6398  data  a4
 *   func_02045CAC  0x02045CAC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 t[8];
} D;

extern D d_021F6398;
extern void func_02045CAC(u32, u32, u32);

void func_021EF694(u32 a, u32 b)
{
    func_02045CAC(d_021F6398.t[3], b, a);
}
