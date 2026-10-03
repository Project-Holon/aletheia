/*
 * function: func_021E2188
 * address:  0x021E2188
 * packet:   pkt_ov093_021E2188
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(int a, int k, int b);
extern int func_021E89C0(void);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 val);
extern void func_021C88C8(int a, void *b);

void func_021E2188(int u, int a, int b)
{
    u8 *r;

    if (b == func_021D775C(3)) {
        if (func_021D62C4(func_021C7CF4(a, b), 0x23) == 0) {
            r = func_021C88A4(a, 0xc, b);
            *(int *)(r + 4) = 0x23;
            *(int *)(r + 8) = func_021E89C0();
            r[0xf] = b;
            func_021C8838(r + 0x14, 2, 0x259);
            func_021C8860(r + 0x14, b);
            func_021C88C8(a, r);
        }
    }
}
