/*
 * function: IRC_COMPATIBLE_CalcCompatibility
 * address: 0x021B6ECC
 * packet: pkt_ov101_021B6ECC
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: upper/lower clamp is if/else-if; reversed commutative operands preserve original accumulator registers.
 * prototype: 084F4 full body is bx lr; supplied pointer and live pointer return preserved.
 * symbols:
 *   IRC_COMPATIBLE_CalcBirthdayScore 0x021B70A8 thumb ov101
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020084F4 0x020084F4 thumb
 *   IRC_COMPATIBLE_CalcNameSimilarity 0x021B6F9C thumb ov101
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern unsigned char IRC_COMPATIBLE_CalcBirthdayScore(unsigned char *p, unsigned x);
extern u16 *func_020084F4(void *);
extern u32 IRC_COMPATIBLE_CalcNameSimilarity(u16 *, u16 *);
int IRC_COMPATIBLE_CalcCompatibility(u32 a, u32 b, int c, int d, char *x, char *y, int flag, u32 id, int a8)
{
    int base, rate, result;
    u32 sim;
    u16 *first;
    float f;
    base = ((((u32)IRC_COMPATIBLE_CalcBirthdayScore((unsigned char *)x, id) + (u32)IRC_COMPATIBLE_CalcBirthdayScore((unsigned char *)y, id)) >> 1) * 10) / 100;
    a = a * 50 / 100;
    b = b * 40 / 100;
    base += a + b;
    first = func_020084F4(x + 12);
    sim = IRC_COMPATIBLE_CalcNameSimilarity(first, func_020084F4(y + 12));
    if (sim) f = 0.5f + (float)(sim << 12);
    else f = (float)(sim << 12) - 0.5f;
    rate = (int)f / 150;
    if (flag) rate = 0xccd;
    else {
        if (rate > 0x1000) rate = 0x1000;
        else if (rate < 0x800) rate = 0x800;
    }
    result = base + (((100 - base) * rate) >> 12) - (d + c);
    if (result > 100) return 100;
    if (result < 0) result = 0;
    return result;
}
