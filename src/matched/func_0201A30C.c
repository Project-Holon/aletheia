/*
 * function: func_0201A30C
 * address:  0x0201A30C
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT* note: the 70 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A352, then two unlabelled 12-byte argument-shuffling tail-call thunks at 0x0201A354 (calls 0x02048F60 with (0x69, a, b)) and 0x0201A364 (calls 0x02048F4C with (b, 0x69, a)), each followed by its own pool word, before the next labelled function at 0x0201A374.
 *
 * symbols:
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0201AB28   0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_02019B58   0x02019B58  thumb
 *
 * Guarded sweep over a record array: only when the object reports state zero
 * does it walk the records and act on those whose 0xA9 flag is set.  The
 * bound is re-evaluated at the bottom of the loop, so it stays a call in the
 * condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A30C.c \
 *       --func func_0201A30C --addr 0x0201A30C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32  func_0200AE54(void *a0, u32 a1);
extern u32  func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern void func_02019B58(void *p);

void func_0201A30C(void *a0, void *a1)
{
    int i;

    if (func_0200AE54(a0, 0x11) != 0)
        return;

    for (i = 0; i < (int)func_0201AA18(a1); i++) {
        void *e = func_0201AB28(a1, i);

        if (func_02017E1C(e, 0xA9, 0) != 0)
            func_02019B58(e);
    }
}
