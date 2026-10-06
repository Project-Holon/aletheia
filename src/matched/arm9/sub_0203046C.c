/*
 * unit:     no
 * address:  0x0203046C
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_0203046C
 *
 * Checked heap-id lookup returning the heap's u16 record field (the one
 * sub_0202FC20 reads, the +0xc halfword of the per-heap record), or 0xffff
 * if the id is out of range; see src/matched/sub_02030428.c for the shared
 * preamble.
 *
 *   u16 sub_0203046C(u32 heapId)
 *
 * Two details pin the C here:
 *
 *  - The failure return is `rsb r0, r0, #0x10000`, not a fresh constant.
 *    r0 already holds the 1 that was stored as the result code, and the
 *    compiler rematerialises 0xffff as 0x10000 - 1 off it rather than
 *    spending a pool word, so the literal in the source really is 0xffff
 *    and the result-code store really does precede it.
 *  - The `lsl #16` / `lsr #16` pair on the success path is the u16 return
 *    type truncating a wider callee result, so sub_0202FC20 must be
 *    declared here as returning `int`, not `u16`. src/matched/unit_0202FBAC.c
 *    declares it `u16` (correct for its own body, which returns a halfword
 *    load); the truncation only appears at this call site.
 *
 * symbols:
 *   g_EnvModule     0x02146954  data
 *   sub_0202FC20    0x0202FC20  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203046C.c \
 *       --func sub_0203046C --addr 0x0203046C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct EnvEntry {
    void *ptr00;
    u32 field04;
    u32 field08;
    u16 field0c;
    u8  field0e;
};

struct EnvModule {
    struct EnvEntry *entries;
    u8 *ids;
    u16 count;
    u16 field0a;
    u16 field0c;
    u16 error;
};

extern struct EnvModule g_EnvModule;
extern u16 sub_0202FC20(u32 idx);

u16 sub_0203046C(u32 heapId)
{
    heapId &= 0x7FFF;
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        goto fail;
    }
    g_EnvModule.error = 0;
    return (int)sub_0202FC20(heapId);

fail:
    return 0xFFFF;
}
