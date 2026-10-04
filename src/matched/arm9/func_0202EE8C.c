/*
 * function: func_0202EE8C
 * address:  0x0202EE8C
 * packet:   pkt_0202EE0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  ABS32 unk_0202F0A5 at +0x3C: layout/data_objects.txt line 180 records
 *           0x0202F0A5 as a `pool` row whose only referrer sites image-wide are the
 *           pool word at 0x0202EEC8 (listed twice, once per unit listing), which lies
 *           INSIDE this function's own 0x0202EE8C..0x0202EECC extent.  A lone
 *           reference never contributes its own start, so sole-ref/data refuses it
 *           exactly as `literal` and `label` do.  No other src/matched or src/pending
 *           file declares the address either, so `matched` has nothing to offer.
 *           Contrast 0x0202F099 (line 179), the sibling tag func_0202EE30 uses: that
 *           one also has a referrer at 0x0202F034, outside any one function, plus a
 *           data-symbol declaration from two EXACT files, which is why the sibling
 *           resolves and this one cannot.  Unblocks the moment any function outside
 *           this extent references the tag, or a matched file declares it.
 *
 * Sibling of func_0202EE30 (src/matched, EXACT): the same 0x1c-byte IconRec, built
 * through the func_020311B8 node allocator instead of func_02030734.  The node is
 * stashed at +4 and +0 is zeroed, the mirror image of func_0202EE30, which registers
 * an owner into +0 and zeroes +4.  Struct layout: docs/families/time_icon.h.
 *
 * Every concrete byte of the 64-byte extent is right; the sole wildcard is the tag
 * above.  NOTE: docs/notes/pkt_0202EE0C.c.txt recorded this same C as DIFF with a
 * five-instruction scheduling residue (the saved-argument loads scheduled before the
 * copy of the call result).  That residue is GONE as of 2026-09-21: the identical
 * source now compiles to 64 bytes with 0 concrete mismatches.  The note's residue
 * table is stale; its prediction that the tag would cap the file at MATCH is not.
 *
 * symbols:
 *   unk_0202F0A5   0x0202F0A5  data  a1
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_0202EECC  0x0202EECC  thumb
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_0202EE8C.c \
 *       --func func_0202EE8C --addr 0x0202EE8C --cc 1.1p1 --thumb
 */
#include "../include/Obj08812.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8   unk_0202F0A5[];
extern void *func_020311B8(u32 a, u8 *tag, u32 size, u32 flags);
struct S02030FB4;
extern void *func_02031290(struct S02030FB4 *p);
extern void func_0202EECC(u8 *p, void *a1, u8 a2, u8 a3, u16 a4);

u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e)
{
    void *v;
    u8 *r;

    v = func_020311B8(a, unk_0202F0A5, 0x1c, 0);
    r = func_02031290(v);
    func_0202EECC(r, b, c, d, e);
    ((struct Obj08812 *)r)->f4 = (u32)v;
    ((struct Obj08812 *)r)->f0 = 0;
    ((struct Obj08812 *)r)->f18 = 1;
    return r;
}
