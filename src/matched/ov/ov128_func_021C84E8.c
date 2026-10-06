/*
 * function: func_021C84E8
 * address: 0x021C84E8
 * packet: pkt_ov128_021C84E8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C8388 0x021C8388 thumb ov128
 *   func_021C87A0 0x021C87A0 thumb ov128
 *   func_021C6BCC 0x021C6BCC thumb ov128
 *   func_021C6B50 0x021C6B50 thumb ov128
 *   func_021C867C 0x021C867C thumb ov128
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned long long u64;
extern unsigned long long func_021C8388(s16 *p, u8 *q);
extern int func_021C87A0(s16 *);
extern void func_021C6BCC(u8 *p, u8 *q, int idx, unsigned heap);
extern void func_021C6B50(void **p, unsigned long long value);
extern void func_021C867C(u8 *, u8 *, int, int);
int func_021C84E8(u8 *p, u8 *a, u8 *b, int c)
{
    u64 value = func_021C8388((s16 *)p, a);
    func_021C6BCC(b, a, (a + func_021C87A0((s16 *)p))[0x18], c);
    if (value != 0) {
        func_021C6B50((void **)b, value);
        func_021C867C(p, b, 0x3c, c);
    } else {
        func_021C867C(p, b, 0x44, c);
    }
    return 1;
}
