/*
 * function: func_021B6F9C
 * address: 0x021B6F9C
 * packet: pkt_ov101_021B6F9C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: equal declared before count fixes the two spilled counter slots; literal double assignments reproduce the lower-bound stores.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`lower1 = 0x30f4;` before `lower1 = 0x30a1;`; `lower2 = 0x30f4;` before
 * `lower2 = 0x30a1;`). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 *
 * symbols:
 *   func_021B7090 0x021B7090 thumb ov101
 *   func_02045A98 0x02045A98 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021B7090(u32, u32);
extern u16 func_02045A98(void);
u32 func_021B6F9C(u16 *p, u16 *q)
{
    u32 a, b, bits1, bits2;
    u32 equal, count, lower1, lower2;
    a = *p;
    b = *q;
    if (a >= 0x30a1 && a <= 0x30f4) a -= 0x60;
    if (b >= 0x30a1 && b <= 0x30f4) b -= 0x60;
    bits1 = func_021B7090(a, 8);
    bits2 = func_021B7090(b, 8);
    count = 0;
    equal = 0;
    lower1 = 0x30a1;
    lower2 = 0x30a1;
    for (;;) {
        if (bits1 == 0) {
            a = *++p;
            if (a == func_02045A98()) break;
            if (a >= lower1 && a <= 0x30f4) a -= 0x60;
            bits1 = func_021B7090(a, 8);
        }
        if (bits2 == 0) {
            b = *++q;
            if (b == func_02045A98()) break;
            if (b >= lower2 && b <= 0x30f4) b -= 0x60;
            bits2 = func_021B7090(b, 8);
        }
        if (bits1 == 0 || bits2 == 0) continue;
        if (((a >> bits1) & 1) == ((b >> bits2) & 1)) ++equal;
        ++count;
        --bits1;
        --bits2;
    }
    return equal * 100 / count;
}
