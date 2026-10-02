/*
 * function: func_021EECD8
 * address:  0x021EECD8
 * packet:   pkt_ov093_021EECD8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F6398  0x021F6398  data  a4
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
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
extern void func_0201ED04(u32);
extern void func_02045808(u32);
extern void func_02045C04(u32);

void func_021EECD8(void)
{
    int i;

    func_0201ED04(d_021F6398.f8);
    func_02045808(d_021F6398.fc);
    for (i = 0; i < 8; i++)
        func_02045C04(d_021F6398.t[i]);
}
