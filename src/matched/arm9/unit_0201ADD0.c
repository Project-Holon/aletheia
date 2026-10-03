/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201ADD0
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201ADD0, sub_0201ADE4
 *
 * symbols:
 *   sub_0201ADE4_File  0x020A7310  data
 *
 * sub_0201ADD0 is a second, smaller wrapper around sub_0201AFD4 (see
 * src/matched/unit_0201ADA4.c for why it is not merged with that file); here
 * the result goes straight to one handler call with a literal id of 0x12.
 *
 * sub_0201ADE4 constructs an object from the debug allocator,
 * func_02030734(obj_hint, size, zero, file, line), with the __FILE__
 * argument an ABS32 into the packed string area rather than a locally
 * emitted string (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 * The string is "poke_personal.c" at 0x020A7310, attested by the `string`
 * class off the terminator of "pokeparty.c" just before it; both sit in the
 * same run of Pokemon-data file names as "poke_tool.c", "poke_regulation.c"
 * and "shinka_check.c" starting at 0x020A72E4, which is the strongest single
 * clue to this packet's subsystem: species/personal-data records, not the
 * WCM/NHTTP wireless code the neighbouring packets' sdk_calls hint at.  It
 * then forwards to sub_0201ADA4 (src/matched/unit_0201ADA4.c) and returns the
 * newly allocated object.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ADD0.c \
 *       --addr 0x0201ADD0 --thumb
 */

typedef unsigned int u32;

extern void *sub_0201AFD4(void *a, void *b);
extern void  func_02048F4C(void *c, u32 id, void *arg);

void sub_0201ADD0(void *a, void *b, void *c)
{
    void *r = sub_0201AFD4(a, b);

    func_02048F4C(c, 0x12, r);
}

extern void *func_02030734(void *obj, u32 size, u32 zero, const char *file, u32 line);
extern void sub_0201ADA4(void *a, void *b, void *c);
extern const char sub_0201ADE4_File[];

void *sub_0201ADE4(void *a, void *b, void *c)
{
    void *obj = func_02030734(c, 0x3C, 0, sub_0201ADE4_File, 0x76);

    sub_0201ADA4(a, b, obj);
    return obj;
}
