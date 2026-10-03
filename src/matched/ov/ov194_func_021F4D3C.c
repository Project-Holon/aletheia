/*
 * function: func_021F4D3C
 * address: 0x021F4D3C
 * packet: pkt_ov194_021F4D3C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: caller consumes 021F4D20 r0; full forwarder leaves 0204A1BC allocation result live despite own void declaration.
 * symbols:
 *   d_021F5798 0x021F5798 data a4
 *   func_021F4D20 0x021F4D20 thumb ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021F5798[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, u32, u32);
extern u32 func_021F4D20(u32, u32);
u32 *func_021F4D3C(u32 heap)
{
    u32 *p;
    int i = 0;
    p = func_02030734(heap, 20, 0, d_021F5798, 147);
    func_02082BCC(p, 0, 20);
    for (; i < 5; i++)
        p[i] = func_021F4D20(i, heap);
    return p;
}
