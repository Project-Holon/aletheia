/*
 * function: func_021C5AA8
 * address: 0x021C5AA8
 * packet: pkt_ov136_021C5AA8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 */
typedef unsigned char u8;
extern void func_02045808(void *);
extern void func_02027FD8(void *);
void func_021C5AA8(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_02045808(*(void **)(*(u8 **)(p + 8) + 0x314 + i * 12));
    func_02045808(*(void **)(*(u8 **)(p + 8) + 0x344));
    func_02045808(*(void **)(*(u8 **)(p + 8) + 0x350));
    func_02027FD8(*(void **)(*(u8 **)(p + 8) + 0x30c));
}
