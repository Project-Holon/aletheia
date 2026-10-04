/*
 * function: func_021D74D8
 * address:  0x021D74D8
 * packet:   pkt_ov125_021D74D8
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-04 (wD1 lane 11): 7 of 72 bytes differ, same length. The original
 * loads x (p+8) into r2 and y (p+0xC) into r3 after the first compared word
 * and keeps the second address in r1; ours puts y in r1 and the address in r3
 * (eors r1,r3 vs eors r3,r1). The xor/orr compare is the shape that matched
 * (an if (a != x || b != y) gives cmp/bne). Final return re-reads p+8. Tried:
 * u64 compare (56), x/y declaration order, xor operand order, unsigned locals,
 * no locals (37), loading the first word into a local (7).
 *
 * symbols:
 *   func_021D85E8  0x021D85E8  arm  ov125
 *   func_0203F1FC  0x0203F1FC  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef unsigned long long u64;

extern int *func_021D85E8(void);
extern u16 func_0203F1FC(const u8 *src, unsigned len);

int func_021D74D8(int unused, char **out)
{
    char *p = (char *)func_021D85E8();
    char *s = p + 4;
    int x, y;

    *out = s + 0xC;
    x = *(int *)(p + 8);
    y = *(int *)(p + 0xC);
    if (((*(int *)(s + 0xC4) ^ x) | (*(int *)(s + 0xC8) ^ y)) != 0) {
        *(int *)(s + 0xC4) = x;
        *(int *)(s + 0xC8) = y;
        *(u16 *)(*out + 0xC0) = func_0203F1FC((u8 *)(*out + 0x80), 0x38);
    }
    return *(int *)(p + 8);
}
