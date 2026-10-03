/*
 * function: func_06899CA4
 * address: 0x06899CA4
 * packet: pkt_ov095_06899CA4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: signed bytes, enum zero, const source pointer preserve codegen;
 *       trailing two-byte alignment padding.
 * symbols:
 *   func_06899CCC 0x06899CCC thumb ov095
 */
typedef signed char s8;
typedef unsigned int u32;
extern int func_06899CCC(u32, u32);
void func_06899CA4(const s8 *p, u32 a)
{
    enum { ZERO = 0 } zero = ZERO;
    *(s8 *)(p + 0x8c) = zero;
    *(s8 *)(p + 0x8d) = -16;
    *(s8 *)(p + 0x8e) = zero - 1;
    func_06899CCC(*(const u32 *)(p + 0xb0), a);
}
