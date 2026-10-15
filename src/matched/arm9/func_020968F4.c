/*
 * function: __str2dec
 * address:  0x020968F4
 * packet:   pkt_02096670
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decimal string to the packed digit record the bcd family shares: clear the
 * flag byte, store the caller's halfword parameter at +2, convert up to 32
 * digits into the byte array at +5, then decide whether the value is in range.
 * A string whose first unconsumed character is below '5' is accepted as is,
 * above '5' is rejected through MSL_C_LIB_IncrementDigits, and exactly '5' is accepted
 * only when some later digit is non-zero or the last converted digit is odd.
 *
 * The pointer is unsigned throughout: `const char *` gives `ldrsb` and signed
 * `poplt`/`ble` comparisons where the original has `ldrb` and the unsigned
 * `poplo`/`bhi`.
 *
 * Two spellings are pinned:
 *
 *  - all three rejection paths jump to one `tail` label, so the file has a
 *    single `bl 02096620`; writing the call out in each arm leaves three
 *    copies and 56 bytes of diff.
 *  - the trailing-zero scan is entered with `c = s[1]; s++;`, which is what
 *    the original's two-instruction entry (`ldrb r2, [r1, #1]` then `add r1,
 *    r1, #1`) is: the load is formed against the not-yet-incremented pointer
 *    and the increment follows.  The equivalent `s++; c = *s;` compiles to
 *    `add r1, r1, #1; ldrb r2, [r1]` - same length, same value, different
 *    order - and every later branch then targets an address four bytes off.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/__str2dec.c \
 *       --func __str2dec --addr 0x020968F4 --cc 1.1p1 --arm
 *   EXACT, 156 bytes, 1 relocation site, resolved.
 *
 * symbols:
 *   MSL_C_LIB_IncrementDigits  0x02096620  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct P020968F4 {
    u8  f00;
    u8  pad01;
    u16 f02;
    u8  f04;
    u8  f05[32];
};

extern void MSL_C_LIB_IncrementDigits(u8 *p, int idx);

void __str2dec(struct P020968F4 *p, const u8 *s, u16 v)
{
    int i;
    u8 c;

    p->f02 = v;
    p->f00 = 0;
    i = 0;
    while (i < 32 && *s != 0) {
        p->f05[i] = (u8)(*s++ - '0');
        i++;
    }
    p->f04 = (u8)i;
    if (*s == 0)
        return;
    if (*s < 5)
        return;
    if (*s > 5)
        goto tail;
    c = s[1];
    s++;
    while (c != 0) {
        if (c != '0')
            goto tail;
        c = *++s;
    }
last:
    if ((p->f05[i - 1] & 1) == 0)
        return;
tail:
    MSL_C_LIB_IncrementDigits((u8 *)p, p->f04);
}
