/*
 * function: func_0204B324
 * address:  0x0204B324
 * packet:   pkt_0204B324
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
 *   func_0204D048  0x0204D048  arm
 *
 * Same request-builder shape as sub_0204B294: a 0x20-byte request is staged
 * on the stack from three of the singleton's parallel tables (0x40-byte
 * records at +0x10c, 0x18-byte records at +0x110, 0x14-byte records at
 * +0x114), then dispatched by func_0204D048, which is sub_0204CFDC's
 * five-argument sibling.
 *
 * The last two arguments come back off the caller's own stack with `ldrh`,
 * which is what names those two u16; the fifth arrives with a plain `ldr`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B324.c \
 *       --func func_0204B324 --addr 0x0204B324 --cc 1.1p1 --arm
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
struct Obj;
struct Req;
extern struct Obj *func_0204D048(void *owner, const struct Req *position,
                                void *request, u32 space, u16 heap);

void func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g)
{
    struct Request req;

    sub_0204CFA4(&req, i, j, &g_02146A74->tc[i], &g_02146A74->ta[j],
                 g_02146A74->tb[k].unk_08, g_02146A74->tb[k].unk_0c);
    func_0204D048((void *)owner, (const struct Req *)e, &req, f, g);
}
