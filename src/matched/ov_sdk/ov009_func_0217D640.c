/*
 * function: func_0217D640
 * address:  0x0217D640
 * packet:   pkt_ov009_0217D640
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiLargeIntSub (libdwcgscommon.TWL.HYB.a(gslargeint.o))
 *
 * symbols:
 *   func_0217D3AC  0x0217D3AC  arm  ov009
 *   func_0217D3F8  0x0217D3F8  arm  ov009
 */

typedef unsigned int u32;
typedef unsigned long long u64;
extern void func_0217D3AC(int id);
extern void func_0217D3F8(int id);

int func_0217D640(u32 *src1, u32 length1, u32 *src2, u32 length2, u32 *dest, u32 *lenout)
{
    u64 borrow = 0;
    u32 i;
    u32 shorter = (length1 < length2) ? length1 : length2;
    i = 0;

    func_0217D3AC(4);
    for (; i < shorter; i++) {
        borrow = (u64)src2[i] - src1[i] - borrow;
        dest[i] = (u32)borrow;
        borrow = (borrow >> 63);
    }
    for (; i < length2; i++) {
        borrow = (u64)src2[i] - borrow;
        dest[i] = (u32)borrow;
        borrow = (borrow >> 63);
    }
    if (borrow != 0) {
        func_0217D3F8(4);
        return 0;
    }
    for (; i < length1; i++) {
        if (src1[i] != 0) {
            func_0217D3F8(4);
            return 0;
        }
    }
    *lenout = length2;
    func_0217D3F8(4);
    return 1;
}
