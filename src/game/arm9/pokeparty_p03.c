/*
 * file:     pokeparty_p03.c
 * unit:     yes
 * function: func_02019CF8, func_02019D00, func_02019D30, func_02019D58
 * address:  0x02019CF8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02019BBC  0x02019BBC  thumb
 *   func_02019C90  0x02019C90  thumb
 *   sub_0209E280_Map  0x0209E280  data
 */
typedef unsigned int   u32;

typedef signed int     s32;

typedef unsigned short u16;

extern unsigned int func_02019BBC(unsigned int item);
extern u32 func_02019C90(u32 a, u32 b, u32 k);
unsigned int func_02019CF8(unsigned int item);
u32 func_02019D00(u32 id);
u32 func_02019D30(u32 a, u32 n);
int func_02019D58(u16 a, int b);
extern u16 sub_0209E280_Map[];



/*
 * Plain forwarder to func_02019BBC (ldr r3, =target; bx r3).  Callee of
 * ov170 func_021DD718.
 */
unsigned int func_02019CF8(unsigned int item)
{
    return func_02019BBC(item);
}



/*
 * Neither carries a label in the generated listing.  func_02019D00
 * is a dense switch over 0x74..0x77 whose four arms each return a constant,
 * and the `subs r0, #0x74` in front of the `cmp`/`bhi` is the compiler's
 * normalisation of the range rather than anything the source wrote; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *
 * The range stops at 0x02019D58.  The two unlabelled search loops after it,
 * at 0x02019D58 and 0x02019D84, reproduce every concrete byte but read
 * halfword tables at 0x0209E280 and 0x0209E42C, and each of those addresses
 * appears in exactly one literal pool in the whole image, the one under test,
 * so the literal class discards its only witness and no cut helps.
 */
u32 func_02019D00(u32 id)
{
    switch (id) {
    case 0x74:
        return 1;
    case 0x75:
        return 2;
    case 0x76:
        return 3;
    case 0x77:
        return 4;
    }
    return 0;
}



u32 func_02019D30(u32 a, u32 n)
{
    if (a != 0x28A) {
        if ((s32)n >= (s32)func_02019C90(a, n, 0x20)) {
            n = 0;
        }
        return n;
    }
    if (n >= 2) {
        n = 0;
    }
    return n;
}


/*
 * note:     re-verified 2026-09-21: EXACT*.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 */
int func_02019D58(u16 a, int b)
{
    u16 i;

    if (b != 0) {
        for (i = 0; i < 4; i++)
            if (sub_0209E280_Map[i] == a)
                return 0;
    }
    return b;
}
