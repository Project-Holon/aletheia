/*
 * unit: yes
 * function: func_0215E31C,func_0215E334
 * address: 0x0215E31C
 * packet: pkt_ov010_0215E31C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   d_02172928 0x02172928 data a1
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern const char d_02172928[];
void *func_0215E31C(u32 heap)
{
    return func_02030734(heap, 32, 1, d_02172928, 45);
}
void func_0215E334(void *p)
{
    func_020307B0(p);
}
