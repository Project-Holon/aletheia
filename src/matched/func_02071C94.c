/*
 * function: func_02071C94
 * address:  0x02071C94
 * packet:   pkt_020713C8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The scale-and-negate constructor of the 0x02071CDC family, following
 * 0x02071C14 in docs/notes/pkt_02071B2C.c.txt.  Writes the 0x1000 unit
 * scale into f00/f14, zeroes f04/f10, and derives f30/f34 from the
 * source's f24/f2c and f28/f2e pairs, the first of the two negated.
 *
 * Pin evidence (2.0), measured 2026-09-21: the "kept constants" tell in
 * exactly the stm-merge form its family-mate src/matched/func_02071180.c
 * already carries.  The image materialises the zero LATE, `mov ip, #0`
 * (`00 c0 a0 e3`) at 0x02071CA0, AFTER both `str r2, [r0]` at 0x02071C98
 * and `str r2, [r0, #0x14]` at 0x02071C9C have retired, which is what keeps
 * the f00 and f04 stores separate.  dsi/1.1p1 -O4,p sinks the zero above
 * the f00 store and MERGES the pair into one `stm r0, {r2, ip}`, giving 68
 * bytes against the original's 72 with the whole body shifted by four (56
 * concrete bytes out).  Under the pin the C below is 72 bytes, 0
 * mismatches, no relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02071C94.c \
 *       --func func_02071C94 --addr 0x02071C94 --arm --cc ../2.0/sp2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef int            s32;

struct SRC {
    u8  pad_00[0x24];
    s32 f24;
    s32 f28;
    u16 f2c;
    u16 f2e;
};

struct DST {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

void func_02071C94(struct DST *d, struct SRC *s)
{
    s32 n;

    d->f00 = 0x1000;
    d->f14 = 0x1000;
    d->f04 = 0;

    n = 0 - s->f24;
    d->f30 = n * s->f2c * 16;

    n = s->f28;
    d->f34 = n * s->f2e * 16;

    d->f10 = 0;
}
