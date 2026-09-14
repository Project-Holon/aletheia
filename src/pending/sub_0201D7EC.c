/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * function: func_0201D7EC
 * address:  0x0201D7EC
 * packet:   pkt_0201D7EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0201D7EC_File  0x020A7358  data
 *   func_0201D854       0x0201D854  thumb
 *   func_0201DA00       0x0201DA00  thumb
 *
 * gf_font.c's constructor, and the function that names the file: it allocates
 * 0x94 bytes through the debug allocator at 0x02030734 passing 0x020A7358 and
 * line 192, and the bytes at 0x020A7358 spell "gf_font.c".  0x94 is also
 * exactly the size the field offsets this packet uses imply, +0x90 being the
 * last word.  On a successful allocation it opens the font resource
 * (func_020490F4, stored at +0x50), remembers the resource id at +0x54, runs
 * the metrics/buffer initialiser func_0201D854 and then the format selector
 * func_0201DA00; a failed allocation returns NULL with nothing else done.
 *
 * Every concrete byte is reproduced.  The file-name string resolves on the
 * `literal` class, six pool words elsewhere hold 0x020A7358.  The two internal
 * calls do not, and the block is structural rather than accidental:
 *
 *   - func_0201D854 and func_0201DA00 have no caller anywhere in the image
 *     except this function, so the `label` class has no witness outside the
 *     compared range.  The only cure is to have them local, which means a unit
 *     spanning 0x0201D7EC..0x0201DA24.
 *   - that unit is capped anyway: it would contain func_0201DA00, whose
 *     dispatch-table word 0x0209E73C has no second witness image-wide (see
 *     src/pending/sub_0201DA00.c).
 *
 * So the cure for one half is the poison for the other, and neither is the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201D7EC.c \
 *       --func func_0201D7EC --addr 0x0201D7EC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern const char func_0201D7EC_File[];

extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);
extern void *func_020490F4(u32 id, u32 heap);
extern void  func_0201D854(void *obj, u32 resid, u32 flag, u32 heap);
extern void  func_0201DA00(void *obj, u32 fmt, u32 heap);

struct Font {
    u32   pad00[20];
    void *unk50;
    u32   unk54;
};

struct Font *func_0201D7EC(u32 id, u32 resid, u32 fmt, u32 flag, u32 heap)
{
    struct Font *f;

    f = (struct Font *)func_02030734(heap, 0x94, 0, func_0201D7EC_File, 192);
    if (f != 0) {
        f->unk50 = func_020490F4(id, heap);
        f->unk54 = resid;
        func_0201D854(f, resid, flag, heap);
        func_0201DA00(f, fmt, heap);
    }
    return f;
}
