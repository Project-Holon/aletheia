/*
 * function: gsiLargeIntAdd
 * address:  0x0217D508
 * packet:   pkt_ov009_0217D508
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiLargeIntAdd (libdwcgscommon.TWL.HYB.a(gslargeint.o))
 *
 * symbols:
 *   func_0217D3AC  0x0217D3AC  arm  ov009
 *   func_02092344  0x02092344  arm
 *   gsiLargeIntTimerExit  0x0217D3F8  arm  ov009
 */

typedef unsigned int u32;
typedef unsigned long long u64;
extern void func_0217D3AC(int id);
extern void gsiLargeIntTimerExit(int id);
extern void *func_02092344(void *dst, const void *src, u32 n);

int gsiLargeIntAdd(u32 *data1, u32 length1, u32 *data2, u32 length2, u32 *dest, u32 *lenout, u32 maxlen)
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
    gsiLargeIntTimerExit(3);
    return carry == 0;
}
