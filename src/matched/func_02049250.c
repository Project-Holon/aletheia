/*
 * unit:     no
 * function: func_02049250
 * address:  0x02049250
 * packet:   pkt_02049250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   func_02034734      0x02034734  arm
 *   func_02078B44      0x02078B44  arm
 *   func_02078B70      0x02078B70  arm
 *   func_02049250_File 0x020A7EE0  data
 *   func_02049250_Msg  0x020A7F18  data
 *
 * Read one member out of an open archive into a fresh heap block.  The
 * handle is an FSFile (0x48 bytes) with the archive's own bookkeeping
 * appended: the FAT offset at +0x4c and the member count at +0x4e, both
 * halfwords, and the image base at +0x48.
 *
 * The FAT entry is a pair of words (start, end) at
 * `fatOffset + 0xc + member * 8`, read into an on-stack two-word buffer;
 * the member's bytes then start at `imageBase + 8 + start` and run
 * `end - start` long.  The difference is written out twice, not cached in a
 * local: the original recomputes `sub r2, r3, r2` after the allocation from
 * two fresh stack loads.
 *
 * The assertion's variadic tail is two values, the count and the member,
 * not one.  The tell is that r3 is never written on the assert path: the
 * `ldrh r3, [r5, #0x4e]` that fed the guard's own `cmp` is still live, so
 * the first variadic argument costs no instruction at all, and only the
 * second reaches the stack.  Declared with a single variadic argument the
 * member lands in r3 instead and the `str r7, [sp]` disappears; see
 * docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md.
 *
 * 0x020A7EE0 is the arc_tool.c anchor this translation unit already uses in
 * func_02048D54; 0x020A7F18 is the assertion message, attested by the
 * terminator of the string in front of it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02049250.c \
 *       --func func_02049250 --addr 0x02049250 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ArcFile {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

extern const char func_02049250_File[];
extern const char func_02049250_Msg[];

extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);
extern void func_02034734(const char *file, u32 line, const char *msg, ...);
extern void func_02078B44(struct ArcFile *arc, u32 pos, u32 origin);
extern void func_02078B70(struct ArcFile *arc, void *dst, u32 size);

void *func_02049250(struct ArcFile *arc, u32 member, u32 heap)
{
    u32 range[2];
    void *buf;

    if (arc->count <= member) {
        func_02034734(func_02049250_File, 613, func_02049250_Msg,
                      arc->count, member);
    }

    func_02078B44(arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70(arc, range, 8);
    func_02078B44(arc, arc->imageBase + 8 + range[0], 0);

    buf = func_02030734(heap, range[1] - range[0], 0, func_02049250_File, 619);
    if (buf != 0) {
        func_02078B70(arc, buf, range[1] - range[0]);
    }
    return buf;
}
