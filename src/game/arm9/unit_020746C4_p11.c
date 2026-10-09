/*
 * file:     unit_020746C4_p11.c
 * function: func_020750EC
 * address:  0x020750EC
 * packet:   pkt_02074A34
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0207466C  0x0207466C  arm
 *   func_020745A4  0x020745A4  arm
 *   func_020742FC  0x020742FC  arm
 *   func_0207482C  0x0207482C  arm
 *   func_020752D4  0x020752D4  arm
 *   func_02074694  0x02074694  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   DC_StoreRange  0x020862D4  arm
 *   d_0214EA54     0x0214EA54  data  a4
 *   d_0214EA54_hdr 0x0214EA54  data  a4
 *
 * The fifth leaf loader of the sound-archive cluster, the one whose payload
 * is a wave-archive offset table that has to be split: unless the entry is
 * already resident (func_0207466C returns non-zero, which is returned as is)
 * read the 0x3c-byte header into the scratch object at 0x0214EA54, take the
 * table size (count at +0x38, four bytes per entry), allocate header + two
 * tables + 0x20 with func_020752D4 as the teardown callback, read header and
 * table, move the table up by its own size (MI_CpuCopy8), clear the first
 * copy (MI_CpuFill8), flush the whole block and publish it when `flag` is
 * set.  The returned word is the error code or the block, in ONE variable
 * (the image returns both from r5 through one shared `mov r0, r5` exit).
 *
 * WHAT CLOSED IT (wave 12; the old note parked it as own-pool-only data):
 *  - 0x0214EA54 now resolves by sole-ref/data (the BRIEF's 2026-09-21
 *    widening); the old "literal, no outside witness" park no longer applies.
 *  - Pin ../2.0/sp2 (also EXACT under sp2p2).  1.1p1 is 296 bytes, 251 out.
 *  - The image pools the SAME word 0x0214EA54 TWICE (0x020751E8 and
 *    0x020751EC), one for the read destination and one for the count load.
 *    mwcc merges pool entries per symbol, so a single extern (plain or read
 *    through a volatile cast) gives one word and a 260-byte body.  Two
 *    extern names pinned at the one address give the image's two words;
 *    both relocations name 0x0214EA54 exactly.  This is a modelling device
 *    for the duplicate pool word, not a claim that two objects exist.
 *  - The call result compared against `sz + 0x3c` is a named local (`n`), so
 *    it reaches cmp's left operand (docs/idioms/cmp-operand-order-names-the-temporary.md).
 *  - DECLARATION ORDER: `sz` declared LAST.  With it first the table size and
 *    the r/p word trade r4/r5/r6 (9..18 bytes out); the permuter's anneal
 *    found the decl-order swap, and the minimal readable form is this one.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct ArcHdr {
    u32 pad[0xe];
    u32 count;                  /* +0x38 entries in the offset table   */
    u32 off[1];                 /* +0x3c the table, count words        */
};

extern struct ArcHdr d_0214EA54;
extern struct ArcHdr d_0214EA54_hdr;

extern u32   func_0207466C(u32 idx);
extern int func_020745A4(u32 idx, void *dst_buf, int total_len, u32 offset);
struct Global;
extern u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern struct Global *func_020742FC(void);
extern void func_020752D4(int a, int b, int c, int d);
extern void func_02074694(u32 idx, u32 val);
extern void  MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern void  DC_StoreRange(void *addr, u32 size);

u32 func_020750EC(u32 idx, u32 *heap, int flag)
{
    u32 r;
    u32 n;
    u32 total;
    u32 cookie;
    struct ArcHdr *p;
    u32 sz;

    r = func_0207466C(idx);
    if (r == 0) {
        if (func_020745A4(idx, &d_0214EA54, 0x3c, 0) != 0x3c)
            return 0;
        sz = d_0214EA54_hdr.count * 4;
        total = sz * 2;
        if (heap == 0)
            return 0;
        if (flag != 0)
            cookie = (u32)func_020742FC();
        else
            cookie = 0;
        p = (struct ArcHdr *)func_0207482C(heap, total + 0x5c, (u32)func_020752D4, cookie, idx);
        if (p == 0)
            return 0;
        n = func_020745A4(idx, p, sz + 0x3c, 0);
        if (n != sz + 0x3c)
            return 0;
        MI_CpuCopy8(p->off, &p->off[p->count], sz);
        MI_CpuFill8(p->off, 0, sz);
        DC_StoreRange(p, total + 0x3c);
        if (flag != 0)
            func_02074694(idx, (u32)p);
        r = (u32)p;
    }
    return r;
}
