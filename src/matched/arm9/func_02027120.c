/*
 * function: func_02027120
 * address:  0x02027120
 * packet:   pkt_02027120
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 20 bytes. Stores two bytes at +5 and +6 of the block that g_02146940 points
 * to and sets the flag byte at +0x62 (reached as +4 then +0x5E: a nested
 * record at +4, written through a pointer local `q = &s->sub`; direct
 * `s->sub.flag` folds to +0x62). Filed in wave D6 as the unlabelled leaf that ov219
 * func_02183D14 calls.
 *
 * symbols:
 *   g_02146940     0x02146940  data
 */

typedef unsigned char  u8;

struct Sub {
    u8 a;
    u8 b;
    u8 c;
    u8 pad[0x5B];
    u8 flag;
};

struct Blk {
    u8 pad[4];
    struct Sub sub;
};

extern struct Blk *g_02146940;

void func_02027120(u8 a, u8 b)
{
    struct Blk *s = g_02146940;
    struct Sub *q = &s->sub;
    s->sub.b = a;
    s->sub.c = b;
    q->flag = 1;
}
