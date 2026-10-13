/*
 * unit:     no
 * address:  0x02045808
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: STRBUF_Delete
 *
 * symbols:
 *   sub_020307B0  0x020307B0  arm
 *
 * The destructor of the u16-array object STRBUF_Create builds: it kills
 * the 0xECD2F8B6 liveness magic at +0x4 and then tail-calls the family's
 * generic free at 0x020307B0, which is the counterpart of the allocation
 * entry at 0x02030734 (it is also what BMP_WIN_Delete finishes with).
 * Clearing the magic before the free is what makes a stale pointer
 * detectable rather than merely dangling.
 *
 * The tail call is the usual shape for this compiler: one section per
 * function means no displacement branch is available, so the target
 * becomes a pool word and a bx
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). The pool word at
 * 0x02045818 is the whole reason the listing extent runs to 0x0204581C.
 *
 * layout/symbols_sdk.json carries the name ENV_SetResourceSet for
 * 0x020307B0. That looks like a signature-matcher false positive rather
 * than a real SDK export (0x020307B0 is game code in arm9_main and its
 * only observed role here is teardown), so the canonical sub_ name is
 * used instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Delete.c \
 *       --func STRBUF_Delete --addr 0x02045808 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct U16Vec {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 stamp;
    u16 entries[1];
};

extern u32 sub_020307B0(void *p);

void STRBUF_Delete(struct U16Vec *vec)
{
    vec->magic = 0;
    sub_020307B0(vec);
}
