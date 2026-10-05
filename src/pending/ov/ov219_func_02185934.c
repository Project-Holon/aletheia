/*
 * function: func_02185934
 * address: 0x02185934
 * packet: pkt_ov219_02185934
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-04, wave D3 lane 17): DIFF, size 404 matches, no relocations. Semantics decoded
 *   from the listing: p+0xC2F4 / +0xC2F8 are x / y (short in a word), +0xC31C u16 mode,
 *   +0xC30C u16 toggle, +0xC320 key word, +0xC330 / +0xC334 stick words, step d0/d1 by
 *   0x55 / 0xa multiply or 0x200 / 0x20; keys 0x20/0x10 move y (clamps -10208 / -13184),
 *   0x40/0x80 move x (clamps 0x3E00 / -15872 in mode 1, 0x2020 / 0x1300 otherwise).
 *   Residue: register colouring. The original copies p into r3 (adds r3,r0,#0) and keeps the
 *   constant 0xC2F4 in r0 as an index register; other offsets are formed from it with
 *   adds r1,r0,#0; adds r1,#0x2c, while 0xC31C is reloaded from the pool at each use. Mine
 *   keeps p in r0 and the constant in r3, spills one local to [sp] and differs in the
 *   shared multiply block. Not tried yet: a real struct pointer with named fields (separate
 *   offset constant per use), declaration order of x, y, d0, d1, and loading c (+0xC320)
 *   once into a local (the original does mov ip,r1 for the 0x20 test only).
 * note (2026-10-05, wave D4 lane 08): DIFF, 177 diff lines, 408 bytes (original 404). Block layout now follows the
 *   original: the mul label sits in the mode==0 branch (m = 0x55 falls in, mode!=0 does m = 0xa; goto mul), the y moves
 *   are `if (mode == 1) W += d0; else if (y < K) W += d0;` (the bne; b branch-to-branch), d0/d1 are int (signed bge/ble
 *   on x +- d1), += / -= forms (the stores reload the word; p moves to r3 as in the original), locals declared d0, d1, m,
 *   res, x, y (gives the exact prologue up to +0x20). Residue: the original loads +0xC320 into r1 and keeps the constant
 *   1 alive in r4 (reused for 1 << 9 = 0x200); the draft loads it into r4 and rematerialises 1 twice (the 4 extra bytes),
 *   then d0/d1/x registers rotate (orig d0 r0, d1 r1, x r2). Tried: c = W(0xC320) assigned in the condition (same),
 *   a reused for it (worse), u32 k = 1 for the masks and k << 9 (same, propagated), u16 a/b (same), the constant 0xC2F4
 *   in a local o (worse).
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#define W(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

int func_02185934(u8 *p, u32 a, u32 b)
{
    int d0, d1;
    u32 m;
    int res = 0;
    int x = (short)W(0xC2F4);
    int y = (short)W(0xC2F8);

    if ((a & 1) || (W(0xC320) & 1)) {
        if (H(0xC31C) == 1) {
            if (H(0xC30C) == 0)
                H(0xC30C) = 1;
            else
                H(0xC30C) = 0;
        }
        return 1;
    }
    if (H(0xC30C) == 0) {
        if (W(0xC330) != 0 || W(0xC334) != 0) {
            m = 0x55;
mul:
            d0 = (u16)(W(0xC330) * m);
            d1 = (u16)(W(0xC334) * m);
        } else {
            d0 = 0x200;
            d1 = 0x200;
        }
    } else {
        if (W(0xC330) != 0 || W(0xC334) != 0) {
            m = 0xa;
            goto mul;
        }
        d0 = 0x20;
        d1 = 0x20;
    }
    if ((b & 0x20) || (W(0xC320) & 0x20)) {
        if (H(0xC31C) == 1) {
            W(0xC2F8) += d0;
        } else if (y < -10208) {
            W(0xC2F8) += d0;
        }
        res = 1;
    }
    if ((b & 0x10) || (W(0xC320) & 0x10)) {
        if (H(0xC31C) == 1) {
            W(0xC2F8) -= d0;
        } else if (y > -13184) {
            W(0xC2F8) -= d0;
        }
        res = 1;
    }
    if ((b & 0x40) || (W(0xC320) & 0x40)) {
        if (H(0xC31C) == 1) {
            if (x + d1 >= 0x3E00)
                W(0xC2F4) = 0x3E00;
            else
                W(0xC2F4) += d1;
        } else if (x < 0x2020) {
            W(0xC2F4) += d1;
        }
        res = 1;
    }
    if ((b & 0x80) || (W(0xC320) & 0x80)) {
        if (H(0xC31C) == 1) {
            if (x - d1 <= -15872)
                W(0xC2F4) = -15872;
            else
                W(0xC2F4) -= d1;
        } else if (x > 0x1300) {
            W(0xC2F4) -= d1;
        }
        res = 1;
    }
    return res;
}
