/*
 * function: func_02094A60
 * address:  0x02094A60
 * packet:   pkt_020949F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * strcspn, in the MSL string module this pseudo-family is made of
 * (func_020949F4 strncmp, func_02094A28 strchr, func_02094B20 strstr).
 * Builds a 32-byte bitmap of the reject set on the stack, then scans the
 * subject until a member is hit, returning the index of that byte.
 *
 * TWO SPELLINGS ARE LOAD-BEARING, and both were missed by the two earlier
 * lanes recorded in docs/notes/func_02094A60.c.txt and
 * docs/notes/pkt_02094A60.c.txt, which between them left this at
 * DIFF / 188 bytes against 192 / 124 concrete bytes out:
 *
 *  - The character is `int c`, NOT `u8 c`.  The original masks it with a
 *    separate `and ip, r4, #0xff` whose result lives across the pointer
 *    load and indexes the map as `ldrb r3, [lr, ip, asr #3]` -- an
 *    ARITHMETIC shift, which is what an `int` shift compiles to.  With
 *    `u8 c` the cast is a no-op, the mask disappears, the map index folds
 *    into the load and the function loses four bytes and a saved register
 *    (`push {r4, lr}` for the original's `push {r3, r4, r5, lr}`).  This
 *    one change alone takes the body from 124 concrete bytes out to 10,
 *    size-exact, with every byte from +0x30 to the epilogue identical.
 *
 *  - The clear loop's COUNTER must be declared BEFORE the cursor
 *    (`u32 i = 8;` then `u8 *p = map;`).  This is
 *    docs/idioms/declaration-order-decides-which-register-a-local-gets.md:
 *    the original puts the cursor in ip and the counter in r3
 *    (`add ip, sp, #0` / `mov r3, #8` / ... / `subs r3, r3, #1`), and the
 *    reverse declaration order hands them the opposite pair, the residual
 *    10 bytes.  `int i` instead of `u32 i` is 160 bytes out: the signed
 *    counter costs a separate `cmp`/`bgt` in place of `subs`/`bne`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02094A60.c \
 *       --func func_02094A60 --addr 0x02094A60 --cc 1.1p1 --arm
 *   EXACT, 192 bytes, no relocation sites.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

int func_02094A60(const u8 *s, const u8 *reject)
{
    u8 map[32];
    u32 i = 8;
    u8 *p = map;
    int c;
    const u8 *p_reject;
    const u8 *p_s;

    do {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    } while (--i);

    c = *reject;
    p_reject = reject + 1;

    if (c != 0) {
        do {
            map[(u8)c >> 3] |= (u8)(1 << (c & 7));
            c = *p_reject++;
        } while (c != 0);
    }

    c = *s;
    p_s = s + 1;

    if (c != 0) {
        do {
            if (map[(u8)c >> 3] & (u8)(1 << (c & 7))) {
                break;
            }
            c = *p_s++;
        } while (c != 0);
    }

    return (u32)(p_s - s) - 1;
}
