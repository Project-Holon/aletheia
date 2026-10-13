/*
 * function: func_02074E9C
 * address:  0x02074E9C
 * packet:   pkt_02074A34
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNS_SndArcGetFileSize  0x0207457C  arm
 *   func_0207482C  0x0207482C  arm
 *   NNS_SndArcReadFile  0x020745A4  arm
 *   DC_StoreRange  0x020862D4  arm
 *
 * The generic "load this resource whole" worker, funnelled into by the four
 * sibling loaders func_02074F3C / func_02074FA8 / func_02075014 / func_02075080,
 * each of which passes its own teardown callback as the second argument.
 * Five steps, each answering 0 on failure: size the entry (NNS_SndArcGetFileSize),
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

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32   NNS_SndArcGetFileSize(u32 a);
extern u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern int NNS_SndArcReadFile(u32 idx, void *dst_buf, int total_len, u32 offset);
extern void  DC_StoreRange(void *addr, u32 size);

void *func_02074E9C(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    u32 len;
    void *p;

    len = NNS_SndArcGetFileSize(a);
    if (len == 0) return 0;
    if (out == 0) return 0;
    p = (void *)func_0207482C(out, len + 0x20, b, c, d);
    if (p == 0) return 0;
    if (NNS_SndArcReadFile(a, p, len, 0) != len) return 0;
    DC_StoreRange(p, len);
    return p;
}
