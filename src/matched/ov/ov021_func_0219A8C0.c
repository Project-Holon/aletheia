/*
 * function: func_0219A8C0
 * address:  0x0219A8C0
 * packet:   pkt_ov021_0219A8C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5D4  0x0216D5D4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0219B358  0x0219B358  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0216D5D4(void *p);
extern u16 func_021642A4(int i);
extern void func_0216D600(u32, u16);
extern int func_0219B358(u32);
extern void func_0216D5E0(int a0, int a1);

int func_0219A8C0(u32 a, u8 *b)
{
    u32 cur = func_0216D5D4((void *)a);
    if (b[1] == 1)
        cur = func_021642A4((u16)cur);
    func_0216D600(a, cur);
    if (func_0219B358(a) == 0)
        func_0216D5E0((u32)a, (u16)cur);
    b[0] = 1;
    return 1;
}
