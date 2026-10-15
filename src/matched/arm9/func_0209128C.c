/*
 * function: MSL_C_LIB_SetTwlFlag
 * address:  0x0209128C
 * packet:   pkt_02091284
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The image keeps BOTH arms predicated (`movne r1, #1` ... `moveq r1, #0`).
 * A single `x != 0` test lets 1.1p1 drop the first predicate (plain
 * `mov r1, #1`, one byte out, ~80 spellings in docs/notes/MSL_C_LIB_SetTwlFlag.c.txt).
 * A two-term `&&` condition goes through the short-circuit if-conversion
 * path, which predicates both arms; the redundant second test is folded away
 * afterwards, leaving the single `cmp r0, #0`.  Same shape in 1.1p1 matched
 * code: src/matched/GFL_NET_SYSTEM_InitDevice.c (`if (a && b) flag = 1;`).
 *
 * symbols:
 *   gMslTwlFlag  0x02153B88  data
 */
typedef unsigned char u8;

extern u8 gMslTwlFlag;

void MSL_C_LIB_SetTwlFlag(int x)
{
    u8 v;

    if (x && x) {
        v = 1;
    } else {
        v = 0;
    }
    gMslTwlFlag = v;
}
