/*
 * file:     unit_0217D3AC_p02.c
 * unit:     yes
 * function: func_0217D508, func_0217D640
 * address:  0x0217D508
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217D3AC  0x0217D3AC  arm  ov009
 *   func_02092344  0x02092344  arm
 *   func_0217D3F8  0x0217D3F8  arm  ov009
 */
typedef unsigned int u32;

typedef unsigned long long u64;

extern void func_0217D3AC(int id);
extern void func_0217D3F8(int id);
extern void *func_02092344(void *dst, const void *src, u32 n);
int func_0217D508(u32 *data1, u32 length1, u32 *data2, u32 length2, u32 *dest, u32 *lenout, u32 maxlen);
int func_0217D640(u32 *src1, u32 length1, u32 *src2, u32 length2, u32 *dest, u32 *lenout);


/*
 * sdk:      gsiLargeIntAdd (libdwcgscommon.TWL.HYB.a(gslargeint.o))
 */
int func_0217D508(u32 *data1, u32 length1, u32 *data2, u32 length2, u32 *dest, u32 *lenout, u32 maxlen)
{
    u64 carry;
    u32 i;
    u32 *longerSrc;
    u32 longerLen;
    u32 shorterLen;

    i = 0;
    carry = 0;
    func_0217D3AC(3);
    if (maxlen < length1 || maxlen < length2)
        return 0;

    if (length1 < length2) {
        shorterLen = length1;
        longerSrc = data2;
        longerLen = length2;
    } else {
        shorterLen = length2;
        longerLen = length1;
        longerSrc = data1;
    }

    for (; i < shorterLen; i++) {
        carry = (u64)data1[i] + data2[i] + carry;
        dest[i] = (u32)carry;
        carry >>= 32;
    }
    while (carry != 0 && i < longerLen) {
        carry = carry + longerSrc[i];
        dest[i] = (u32)carry;
        carry >>= 32;
        i++;
    }
    if (carry != 0) {
        if (maxlen <= i)
            return 0;
        dest[i] = (u32)carry;
        carry = 0;
        i++;
    }
    if (i < longerLen) {
        if (&dest[i] != &longerSrc[i])
            func_02092344(&dest[i], &longerSrc[i], (longerLen - i) * 4);
        i = longerLen;
    }
    *lenout = i;
    func_0217D3F8(3);
    return carry == 0;
}


/*
 * sdk:      gsiLargeIntSub (libdwcgscommon.TWL.HYB.a(gslargeint.o))
 */
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
