/*
 * function: func_021D8E7C
 * address:  0x021D8E7C
 * packet:   pkt_ov093_021D8E7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

struct Hd { u32 lo : 23; u32 flag : 1; u32 hi : 8; };

void func_021D8E7C(int u, void *a, u32 b, u32 c, u8 d)
{
    u8 *r;

    if (c != func_021D59B4(func_021C7CF4((int *)((int)a), b), 0x13)) {
        r = func_021C88A4(a, 0x39, b);
        r[4] = b;
        r[5] = c;
        ((struct Hd *)r)->flag = d;
        func_021C8838(r + 8, 2, 0xde);
        func_021C8860((struct S *)(r + 8), b);
        func_021C88C8(a, r);
    }
}
