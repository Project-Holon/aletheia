/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020064B8
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020064B8
 *
 * symbols:
 *   func_02074450  0x02074450  arm
 *   func_0207466C  0x0207466C  arm
 *   func_0208A640  0x0208A640  arm
 *   func_0208A674  0x0208A674  arm
 *
 * Two lookups, each abandoning the function when it comes back NULL, then
 * one call whose third argument is the result of another.
 *
 * The 24 bit mask is a `lsls #8` / `lsrs #8` pair rather than an `ands`,
 * because Thumb has no immediate AND and 0x00FFFFFF would have to come out
 * of a literal pool: two halfwords against six bytes.  That is the same
 * mechanism as `& 0xFFFF` compiling to `lsls #16` / `lsrs #16`, but here
 * there is no integer type of that width, so the shift pair is the mask
 * itself and not a conversion.
 */

typedef unsigned int u32;

extern u32 *func_02074450(u32 a);
extern u32 *func_0207466C(u32 a);
extern void func_0208A640(u32 *a, u32 b, u32 c);
extern u32  func_0208A674(u32 a, u32 b);

int sub_020064B8(u32 a, u32 b, u32 c, u32 d)
{
    u32 *p;
    u32 *q;

    p = func_02074450(a);
    if (p == 0) {
        return 0;
    }
    q = func_0207466C(*p << 8 >> 8);
    if (q == 0) {
        return 0;
    }
    func_0208A640(q, b, func_0208A674(c, d));
    return 1;
}
