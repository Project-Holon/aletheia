/*
 * function: func_021D9E08
 * address:  0x021D9E08
 * packet:   pkt_ov093_021D9E08
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021D85C0   0x021D85C0  thumb ov093
 *   func_0201BEB8   0x0201BEB8  thumb
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 raw; } Slot;
typedef struct { u8 b; } Byte;

extern int func_021D775C(int a);
extern int func_021D85C0(int a, int b);
extern int func_0201BEB8(u16 id, u32 bit);
extern void *func_021C88A4(int a, int k, int b);
extern void func_021C88C8(int a, void *p);

void func_021D9E08(int a, int b, int c, Slot d, Byte e)
{
    u8 *p;
    u32 m = 4;

    if (b != func_021D775C(4))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    if (func_0201BEB8(func_021D775C(0x12), 0) == 0)
        return;
    if (func_021D85C0(a, e.b) == 0)
        return;
    p = func_021C88A4(a, 0xc, b);
    *(u32 *)p |= m << 21;
    *(u32 *)(p + 4) = c;
    *(u32 *)(p + 8) = d.raw;
    *(u8 *)(p + 0xc) = 0;
    *(u8 *)(p + 0xf) = func_021D775C(3);
    func_021C88C8(a, p);
}
