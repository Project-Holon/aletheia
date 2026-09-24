/*
 * function: func_021E203C
 * address:  0x021E203C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *
 * Return the +0x28 field when the +0x6c sub-object test is zero, else 3.
 */

extern int func_02021ED8(int);


int func_021E203C(void *p)
{
    if (func_02021ED8(*(int *)(*(int *)((char *)p + 0x2c) + 0x6c)) == 0)
        return *(int *)((char *)p + 0x28);
    return 3;
}

/*
 * Blocked: 24 of 24 compiled bytes identical to the image (the image's
 * function is 52 bytes; the tail is padding + the next function's pool).
 * The single residue is the THM_CALL at +0x08 to 0x02021ED8, which
 * match.py reports as "no witness outside 021E203C..021E2054" -- the
 * same missing-callee class as 0x02012F98, 0x0207D63C, 0x0202616C,
 * 0x0204B5AC, 0x02021540, 0x020257C4, 0x02025D14.  No caller-side
 * spelling can move this; declare the target thumb/arm or not at all and
 * the verdict is unchanged.
 */
