/*
 * function: func_021BD25C
 * address:  0x021BD25C
 * packet:   pkt_ov088_021BD25C
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: site +002C (func_020351F8, arm) has no witness outside the
 * compared range and is not in layout/symbols_sdk.json; every other byte is
 * right. Needs a second caller or an SDK table entry.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020071EC  0x020071EC  thumb
 *   func_020351F8  0x020351F8  arm
 *   d_021BDA0C     0x021BDA0C  data  ov088  a4
 *   d_021BD3B9     0x021BD3B9  data  ov088  a1
 */

extern int func_02030734(int, int, int, int, int);
extern int func_020071EC(int);
extern void func_020351F8(int, int);

void *func_021BD25C(int a, int b)
{
    char *r4 = (char *)func_02030734(a, 0x10, 1, 0x021BDA0C, 0x45);
    *(int *)r4 = b;
    if (func_020071EC(b) == 1) {
        r4[7] = 1;
    } else {
        func_020351F8(0x021BD3B9, (int)r4);
    }
    return r4;
}
