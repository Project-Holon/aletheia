/*
 * file:     unit_020746C4_p09.c
 * unit:     yes
 * function: func_02074E10, func_02074E9C
 * address:  0x02074E10
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02074450  0x02074450  arm
 *   func_0207466C  0x0207466C  arm
 *   func_02075080  0x02075080  arm
 *   func_020750EC  0x020750EC  arm
 *   func_0207457C  0x0207457C  arm
 *   func_0207482C  0x0207482C  arm
 *   func_020745A4  0x020745A4  arm
 *   DC_StoreRange  0x020862D4  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

union Hdr {
    unsigned w;
    struct { unsigned v : 24; unsigned flag : 1; unsigned rest : 7; } b;
};

extern void *func_02074450(int index);
extern u32 func_0207466C(u32 a);
extern u32 func_02075080(u32 a, u32 b, u32 c);
extern u32 func_020750EC(u32 idx, u32 *heap, int flag);

/*
 * The 0x02074BEC/0x02074C70 sibling for the third handler slot: resolve the
 * object (func_02074450), read its 32-bit header word, and dispatch on the
 * caller's flag bits.  With flag bit 2 set the 24-bit low field of the header
 * is handed to one of two loaders chosen by header bit 24, and a zero result
 * is the error code 9; without it the field goes to the plain lookup
 * func_0207466C and no error check applies (the image's `bl 0x207466c` at
 * 0x02074E84 lands at 0x02074E88, PAST the `cmp r0,#0` / `mov r0,#9`).
 *
 * TWO LEVERS, both required and both previously measured against the wrong
 * front end in docs/notes/pkt_02074CD0.c.txt / docs/notes/pkt_0207533C.c.txt:
 *
 *  - THE HEADER IS READ THROUGH TWO VIEWS OF ONE WORD, so it must be a UNION.
 *    The value is a 24-bit BITFIELD (`o->b.v`): that and only that emits the
 *    image's `lsl r0,r0,#8` / `lsr r0,r0,#8` pair straddling the branch at
 *    0x02074E44/0x02074E54, per
 *    docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md; spelling it
 *    `(w << 8) >> 8` folds to `bic r0, r0, #0xff000000`.  The FLAG is a plain
 *    word read `(o->w >> 24) & 1`, which is the image's `lsr r1,r0,#0x18` /
 *    `tst r1,#1` at 0x02074E3C; taking it from the same bitfield view as a
 *    1-bit member gives `lsl r1,r0,#7` / `lsrs r1,r1,#0x1f` instead (the two
 *    bytes that were still out before the union).  The union is what lets the
 *    two views share the single `ldr r0,[r0]` at 0x02074E34; two separate
 *    pointers cost the whole function, as the note records.
 *
 *  - PIN ../2.0/sp2, the "kept constants" tell of docs/FRONTEND-PINS.md, the
 *    same pin the rest of this cluster carries (func_02074A6C, func_02074A98,
 *    func_02074AC4, func_02074AE8).  The image computes the SECOND and THIRD
 *    call arguments separately inside EACH arm -- `mov r2, r4` / `lsr r0,r0,#8`
 *    at 0x02074E50/0x02074E54 and again at 0x02074E60/0x02074E64 -- and only
 *    the first argument's `mov r1, r5` is hoisted above the branch.  1.1p1
 *    -O4,p hoists all three and cross-jumps the two arms onto one call
 *    sequence, giving 132 bytes against the original's 140 with 67 concrete
 *    bytes out; no source spelling of the two arms moves it, which is what
 *    docs/notes/pkt_02074CD0.c.txt spent its pass measuring.  Under the pin
 *    the SAME C is 140 bytes, 0 mismatches.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02074E10.c \
 *       --func func_02074E10 --addr 0x02074E10 --arm --cc ../2.0/sp2
 */
u32 func_02074E10(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    union Hdr *o;
    u32 r;

    o = func_02074450(a);
    if (o == 0) return 5;
    if (b & 4) {
        if ((o->w >> 24) & 1) r = func_020750EC(o->b.v, (u32 *)c, d);
        else                  r = func_02075080(o->b.v, c, d);
        if (r == 0) return 9;
    } else {
        r = func_0207466C(o->b.v);
    }
    if (out != 0) *out = r;
    return 0;
}

extern u32   func_0207457C(u32 a);
extern u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern int func_020745A4(u32 idx, void *dst_buf, int total_len, u32 offset);
extern void  DC_StoreRange(void *addr, u32 size);

/*
 * The generic "load this resource whole" worker, funnelled into by the four
 * sibling loaders func_02074F3C / func_02074FA8 / func_02075014 / func_02075080,
 * each of which passes its own teardown callback as the second argument.
 * Five steps, each answering 0 on failure: size the entry (func_0207457C),
 * refuse a null output cell, allocate size+0x20 through func_0207482C with the
 * callback / cookie / heap triple, read the whole entry into it, and flush the
 * range with DC_StoreRange before returning the buffer.
 *
 * The read's success test is `!= len`, not `== 0`: the image compares the
 * SIZE against the call result (`cmp r5, r0` at 0x02074F14) rather than the
 * result against zero, which is
 * docs/idioms/cmp-operand-order-names-the-temporary.md -- the size was
 * assigned to a named local first, the read result was not.
 *
 * PIN ../2.0/sp2, the cluster pin (docs/FRONTEND-PINS.md, "kept constants").
 * The image materialises the four early exits' zero FRESH at each
 * (`moveq r0, #0` at 0x02074EC0, 0x02074ED4, 0x02074EF8 and `movne r0, #0` at
 * 0x02074F1C) alongside the separate `mov r3, #0` at 0x02074F0C for the read's
 * fourth argument; 1.1p1 -O4,p CSEs the five into one hoisted register.  Under
 * the pin this C is 160 bytes, 0 mismatches, first compile.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02074E9C.c \
 *       --func func_02074E9C --addr 0x02074E9C --arm --cc ../2.0/sp2
 */
void *func_02074E9C(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    u32 len;
    void *p;

    len = func_0207457C(a);
    if (len == 0) return 0;
    if (out == 0) return 0;
    p = (void *)func_0207482C(out, len + 0x20, b, c, d);
    if (p == 0) return 0;
    if (func_020745A4(a, p, len, 0) != len) return 0;
    DC_StoreRange(p, len);
    return p;
}
