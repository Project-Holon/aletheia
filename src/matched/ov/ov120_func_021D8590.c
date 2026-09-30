/*
 * function: func_021D8590
 * address: 0x021D8590
 * packet: pkt_ov120_021D8590
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_020355C4 0x020355C4 arm
 *   func_02045808 0x02045808 arm
 *   func_021D7710 0x021D7710 thumb ov120
 *   func_02051B84 0x02051B84 arm
 *   d_021D8AF0 0x021D8AF0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020457B0(u32, u32);
extern void func_02045CAC(void *, u16, void *);
extern void *func_0202800C(void *, void *, u32, u32, u8, u8, u32, u32, u16);
extern int func_020355C4(void);
extern void func_02028218(void *, int);
extern void func_02045808(void *);
extern void func_021D7710(u8 *);
extern void *func_02051B84(const void *, int, int, u16);
extern const int d_021D8AF0[];
void func_021D8590(u8 *p, int a, int b)
{
    void *q = func_020457B0(100, *(u16 *)(p + 0xc8));
    *(void **)(p + 0xa8) = q;
    func_02045CAC(*(void **)(p + 12), 15, q);
    *(u16 *)(p + 0xac) = 0x39e3;
    *(int *)(p + 0xb0) = 0;
    *(void **)(p + 0xc4) = func_0202800C(*(void **)(p + 0xc0), p + 0xa8, 10, 21, 12, 3, 0, 1, *(u16 *)(p + 0xc8));
    if (!func_020355C4()) func_02028218(*(void **)(p + 0xc4), 1);
    func_02045808(*(void **)(p + 0xa8));
    func_021D7710(p);
    *(void **)(p + 8) = func_02051B84(d_021D8AF0, a, b, *(u16 *)(p + 0xc8));
}
