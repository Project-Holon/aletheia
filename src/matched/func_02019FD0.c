/*
 * function: func_02019FD0
 * address:  0x02019FD0
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT* note: the 190 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A08E before the next labelled function at 0x0201A090.
 *
 * symbols:
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0200AFD4   0x0200AFD4  thumb
 *
 * The same stat comparison as func_02019DA4, but it reports into the third
 * argument's word with or-bits instead of returning a code: bit 1 for a
 * selector 5 record above the threshold or a selector 6 one below it, bit 2
 * for the range check, bit 6 for the second one, and the return value stays 1
 * unless a bit was set.  The `*a2 |= 2; r = 0;` pair is written out in both
 * arms and the compiler cross-jumps them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02019FD0.c \
 *       --func func_02019FD0 --addr 0x02019FD0 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0200AE54(void *a0, u32 a1);
extern u32 func_0200AFD4(void *a0, u32 a1, u32 a2);

int func_02019FD0(void *a0, void *a1, u32 *a2)
{
    u16 v5 = (u16)func_02017E1C(a1, 5, 0);
    u16 v6 = (u16)func_02017E1C(a1, 6, 0);
    int r = 1;
    int m;
    int s;
    int t;

    if (a0 == 0)
        return r;

    m = func_0200AE54(a0, 4);
    s = func_0200AE54(a0, 5);
    t = func_02017E1C(a1, 0x9E, 0);

    switch (s) {
    case 1:
        if (m > t) {
            r = 0;
            *a2 |= 2;
        }
        break;
    case 2:
        if (m < t) {
            r = 0;
            *a2 |= 2;
        }
        break;
    }

    if (func_0200AFD4(a0, 9, v5) != 0) {
        if (func_02017E1C(a1, 0x4C, 0) == 0) {
            r = 0;
            *a2 |= 4;
        }
    }
    if (func_0200AFD4(a0, 0xA, v6) != 0) {
        r = 0;
        *a2 |= 0x40;
    }
    return r;
}
