/*
 * function: func_020612C8
 * address:  0x020612C8
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206123C   0x0206123C  arm
 *
 * The tail `bl func_0206123C` at 0x020612E0 was the file's only MATCH site:
 * 0x0206123C had no `label` witness, because this call is the only branch to
 * it in the image.  Now that src/matched/func_0206123C.c is an EXACT entry,
 * the site resolves as `matched` and the file is EXACT (with a trailing `*`
 * for the unlabelled follower at 0x0206127C).
 *
 * The guard is an unsigned compare (`cmp r1, r2` / `movhi r0, #0` / `pophi`),
 * so the second parameter is `u32`, and the loaded field is passed on as r0:
 * `return func_0206123C(p);` -- the value handed back is the callee's own
 * result, which is why the call is not a tail call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020612C8.c \
 *       --func func_020612C8 --addr 0x020612C8 --arm --cc 1.1p1
 *   MATCH, 32 bytes, 1 relocation site, 0 resolved.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Inner020612C8 {
    u32 w[10];
    u32 unk28;
};

struct Obj020612C8 {
    u32 unk0;
    struct Inner020612C8 *inner;
};

extern int func_0206123C(void *p);

int func_020612C8(struct Obj020612C8 *o, u32 i)
{
    struct Inner020612C8 *p = o->inner;

    if (i > p->unk28) {
        return 0;
    }
    return func_0206123C(p);
}
