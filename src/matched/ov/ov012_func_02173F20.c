/*
 * function: func_02173F20
 * address: 0x02173F20
 * packet: pkt_ov012_02173F20
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D4D0 0x0203D4D0 arm
 *   func_021840A8 0x021840A8 thumb ov022
 */
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D4D0(u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_021840A8(u32);
void func_02173F20(void *p, u32 a)
{
    u32 entry;
    u32 size;
    entry = (u32)func_020399A8();
    size = func_021840A8(entry);
    func_0203D4D0(entry, a, 0x1410, size, (u32)p, 1, 0, 0);
}
