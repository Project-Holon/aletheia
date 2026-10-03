/*
 * function: func_0216BB18
 * address:  0x0216BB18
 * packet:   pkt_ov010_0216BB18
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0200C37C  0x0200C37C  thumb
 *   func_0203F524  0x0203F524  arm
 *   func_020891E0  0x020891E0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void *func_0200C0F0(void *sys);
struct Blk34;
extern u8 func_0200C32C(struct Blk34 *p);
extern unsigned long long func_0200C37C(struct Blk34 *p);
extern u64 func_0203F524();
extern void func_020891E0();

int func_0216BB18(void *sys)
{
    u32 a[7];
    void *r4;
    u64 t;

    r4 = func_0200C0F0(sys);
    if (func_0200C32C(r4) == 0) {
        return 0;
    }
    t = func_0200C37C(r4);
    func_020891E0(a + 3, a, func_0203F524() - t);
    if (a[3] != 0 || a[4] > 1 || a[5] > 1) {
        return 24;
    }
    return (u16)a[0];
}
