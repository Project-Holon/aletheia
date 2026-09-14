/*
 * function: sub_02034714
 * address:  0x02034714
 * packet:   pkt_02034714
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_Sink  0x0214699C  data
 *
 * The assert/panic hook trampoline this territory's `bl 0x2034714` sites
 * all reach (see e.g. sub_02033A3C, which loads an expression string,
 * mov r1,#0x85, a file string, then calls here): if a handler is
 * registered at g_Sink+0xc (the field sub_020346EC in the neighbouring
 * packet never writes), call it. This is the forwarding-call idiom from
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * read in reverse: the call is `h()`, zero C-visible arguments, and it is
 * only because this function never touches r1/r2 (its own `line`/`file`
 * parameters) anywhere else that they survive, unclobbered, into the
 * callee's argument registers. Writing the call as `h(line, file)`
 * forces two `mov`s that are not in the original and breaks the match.
 * `expr`, `line` and `file` are declared to keep the prototype honest for
 * callers but are otherwise dead in this function's own body.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02034714.c \
 *       --func sub_02034714 --addr 0x02034714 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef void (*AssertHandler)(void);

struct Sink {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    AssertHandler handler;
};

extern struct Sink g_Sink;

void sub_02034714(const char *expr, u32 line, const char *file)
{
    AssertHandler h = g_Sink.handler;

    if (h) {
        h();
    }
}
