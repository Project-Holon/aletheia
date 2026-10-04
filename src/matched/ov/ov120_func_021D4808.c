/*
 * function: func_021D4808
 * address: 0x021D4808
 * packet: pkt_ov120_021D4808
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4584 0x021D4584 thumb ov120
 *   func_021D47D4 0x021D47D4 thumb ov120
 */
extern int func_0203CD98(void);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
typedef unsigned short u16;
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_021D4244(int, void (*)(int), int);
extern void func_021D4584(int);
extern void func_021D47D4(int);
void func_021D4808(int a)
{
    if (func_0203CD98() == 0) {
        func_021D4244(a, func_021D4584, 0x2df);
        return;
    }
    if (func_02039CB4((struct Link *)func_020399A8(), 2, 0x22) != 0) {
        if (func_0203D3A8(func_020399A8(), 0x2200, 8, *(char **)(a + 0x48) + 4) != 0)
            func_021D4244(a, func_021D47D4, 0x2e7);
    }
}
