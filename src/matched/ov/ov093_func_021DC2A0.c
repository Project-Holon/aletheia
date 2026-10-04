/*
 * function: func_021DC2A0
 * address:  0x021DC2A0
 * packet:   pkt_ov093_021DC2A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_0201C314  0x0201C314  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021B9A24(u32 a, u32 b);
extern u32 func_0201C314(u16 id);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DC2A0(int u, void *a, u32 b)
{
    u8 *e;
    u8 c;
    if (b == func_021D775C(4)) {
        c = func_021D775C(3);
        if (func_021B9A24(b, c) != 0
            && b != c
            && func_0201C314(func_021D775C(0x12)) != 0
            && func_021D76BC(0x40, 1) != 0) {
            e = func_021C88A4(a, 4, b);
            *(u32 *)e |= 1 << 23;
            func_021C8838(e + 4, 2, 0x1d5);
            func_021C8860((struct S *)(e + 4), b);
            func_021C88C8(a, e);
        }
    }
}
