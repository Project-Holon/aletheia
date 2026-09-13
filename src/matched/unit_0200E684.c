/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E684
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200E684, sub_0200E6B0
 *
 * symbols:
 *   func_0203F1FC 0x0203F1FC  thumb, not otherwise called in arm9_main
 *
 * alias: sub_0200E684 toggles one flag half of a caller object's field pair
 * addressed by the constant id 0x5c6: it looks the field up through
 * func_0203F1FC, and if the stored halfword at +0x5c6 already equals the
 * looked-up value, rewrites the paired halfword at +0x5c2 with the constant
 * 0x7da and refreshes +0x5c6 with a second lookup.  sub_0200E6B0 is an
 * unlabelled getter returning the constant 0x28, sitting in what disasm.py
 * printed as trailing data after sub_0200E684 because it carries no
 * register-saving prologue; see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E684.c \
 *       --addr 0x0200E684 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0203F1FC(void *obj, u32 id);

void sub_0200E684(void *obj, void *unused)
{
    u32 id = 0x5c6;
    if (*(u16 *)((u8 *)obj + id) == func_0203F1FC(obj, id)) {
        *(u16 *)((u8 *)obj + (id - 4)) = 0x7da;
        *(u16 *)((u8 *)obj + id) = func_0203F1FC(obj, id);
    }
}

u32 sub_0200E6B0(void)
{
    return 0x28;
}
