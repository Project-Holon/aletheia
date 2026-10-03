/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200D6D0
 * packet:   pkt_0200D59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200D6D0
 *
 * 28 bytes, 0x0200D6D0..0x0200D6EC, one function, which carries a label in
 * the generated listing.
 *
 * alias: inside "gds_profile.c"; see src/matched/unit_0200D59C.c for how the
 * name is attested and why the range in front of this one is cut here.
 *
 * A fifteen-byte copy into a freshly allocated block: the same
 * func_020457B0 / func_02045994 pair func_0200D774 uses for the 0x28-byte
 * record.  The size is materialised twice, once as the allocation size and
 * once as the copy length, because both are caller-saved argument registers.
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020457B0(u32 size, u16 tag);
struct Strbuf;
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);

void *func_0200D6D0(const void *src, u32 tag)
{
    void *h = func_020457B0(0xF, tag);

    func_02045994(h, src, 0xF);
    return h;
}
