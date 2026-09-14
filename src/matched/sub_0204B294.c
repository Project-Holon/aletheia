/*
 * function: sub_0204B294
 * address:  0x0204B294
 * packet:   pkt_0204B0C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   sub_0204CFA4   0x0204CFA4  arm
 *   sub_0204CFDC   0x0204CFDC  arm
 *
 * Build a 0x20-byte request on the stack out of three of the singleton's
 * parallel tables, then dispatch it.  The singleton at 0x02146A74 carries
 * three table pointers in a row: 0x40-byte records at +0x10c, 0x18-byte
 * records at +0x110 and 0x14-byte records at +0x114.
 *
 * The global is read once and every index is computed off that one load,
 * because nothing between them can store to it; the two index multiplies
 * are real `mla`s against a register-held 0x18 and 0x14, since neither
 * size is a power of two, while the 0x40-byte stride folds into the
 * addressing as `add r3, r3, ip, lsl #6`.
 *
 * The `lsl #16` / `lsr #16` pairs on the two index arguments are the
 * narrowing casts sub_0204CFA4's u16 parameters force at the call site,
 * not evidence that this function's own parameters are u16: the same
 * values are used untruncated as table indices a few instructions
 * earlier.  Reading them the other way (declaring the parameters u16)
 * would have to truncate before the multiplies too.
 *
 * The last two arguments come back off the caller's own stack with
 * `ldrh`, which is what names those two u16.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B294.c \
 *       --func sub_0204B294 --addr 0x0204B294 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RecC {
    u8 pad_00[0x40];
};

struct RecA {
    u8 pad_00[0x18];
};

struct RecB {
    u8  pad_00[8];
    u32 unk_08;
    u32 unk_0c;
    u8  pad_10[4];
};

struct Sys {
    u8           pad_000[0x10c];
    struct RecC *tc;
    struct RecA *ta;
    struct RecB *tb;
};

struct Request {
    u8 b[0x20];
};

extern struct Sys *g_02146A74;

extern void sub_0204CFA4(struct Request *out, u16 i, u16 j, struct RecC *c,
                         struct RecA *a, u32 x, u32 y);
extern void sub_0204CFDC(u32 owner, u32 e, struct Request *req, u16 f, u16 g);

void sub_0204B294(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g)
{
    struct Request req;

    sub_0204CFA4(&req, i, j, &g_02146A74->tc[i], &g_02146A74->ta[j],
                 g_02146A74->tb[k].unk_08, g_02146A74->tb[k].unk_0c);
    sub_0204CFDC(owner, e, &req, f, g);
}
