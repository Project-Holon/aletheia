/*
 * function: func_0206E9A4
 * address:  0x0206E9A4
 * packet:   pkt_0206E9A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 6 bytes of 92: the size, both guards (as gotos) and the shared `mov r0,#0; bx lr` tail are right; the original's `mla r1, r0, r1, r2` leaves the entry in r1 and the following `mov r1,#0`/`cmp r1,#0`/`ldrne r0,[r1]` use it, this spelling gives mwccarm r0 (and `mla r0, r1, r0, r2`).  Flipping the product's operand order and declaring the entry as a pointer both come out the same
 *
 * Same table family as src/pending/func_0206EACC.c, one indirection deeper:
 * the halfword at +0xC of the block offsets a word table whose entry is added
 * to p, and the entry found in the block at q + 8 (count byte at q + 9, table
 * offset halfword at q + 0xE, four-byte entries after the stride word) is
 * itself an offset back into the block.
 *
 * The null test is on the *computed* pointer q + 8 and both guards are
 * `goto`s, not `return 0`s: as returns this front end predicates the body and
 * the original's `beq`/`bcs` branches disappear.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206E9A4.c \
 *       --func func_0206E9A4 --addr 0x0206E9A4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *func_0206E9A4(u8 *p, u32 idx)
{
    u8 *q;
    u8 *h;
    u32 off;
    u32 ent;

    if (p == 0)
        goto ret0;
    q = p + *(u32 *)(p + *(u16 *)(p + 0xC));
    h = q + 8;
    if (h == 0)
        goto fail;
    if (idx >= *(u8 *)(q + 9))
        goto fail;
    off = *(u16 *)(q + 0xE);
    ent = *(u16 *)(h + off) * idx + ((u32)h + off + 4);
    goto end;
fail:
    ent = 0;
end:
    if (ent != 0)
        return q + *(u32 *)ent;
ret0:
    return 0;
}
