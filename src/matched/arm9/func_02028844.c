/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_02028844
 * address:  0x02028844
 * packet:   pkt_02028844
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: all 88 concrete bytes are right, 3 of 7 relocations
 * resolve.  func_02028760, func_02029F14 and the callback pointer
 * func_02028CB0 have exactly one reference image-wide, this function's.  The
 * fourth blocker is the __FILE__ pointer: the string "field_sound_system.c"
 * at 0x020A7590 is preceded by a table of pointers rather than by another
 * string's terminator, so the `string` class cannot fix its start, exactly
 * the case docs/idioms/a-string-after-a-data-table-has-no-witness.md
 * describes.  That one caps the file at MATCH regardless of the C.
 *
 * The string does settle the translation unit's name: field_sound_system.c.
 *
 * field_sound_system.c: the constructor.  Allocates the 0xB8-byte system out
 * of the caller's heap through the debug allocator (the fourth and fifth
 * arguments are the __FILE__ pointer into the packed string area and the
 * literal line number, the line number being the pooled small constant that
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md warns
 * about reading as a symbol), initialises it from the caller's descriptor,
 * builds the two owned sub-objects at +0xA4 and +0xA8, and registers the
 * per-frame callback at func_02028CB0.
 *
 * +0xA4 is stored and then read back for the second construction rather than
 * kept live, which is the tell that the source spells the second argument
 * `s->unkA4` and not the value it just stored.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02028CD4  0x02028CD4  thumb
 *   func_02028760  0x02028760  thumb
 *   func_02029F14  0x02029F14  thumb
 *   func_02005D08  0x02005D08  thumb
 *   func_02028CB0  0x02028CB0  thumb
 *   g_020A7590     0x020A7590  data
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02028844.c \
 *       --func func_02028844 --addr 0x02028844 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sys {
    u8    pad_00[0xa4];
    void *unkA4;   /* 0xa4 */
    void *unkA8;   /* 0xa8 */
};

extern const char g_020A7590[];

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_02028CD4(struct Sys *s, void *desc);
extern void *func_02028760(u32 heap, u32 kind);
extern void *func_02029F14(u32 heap, void *owner);
extern void  func_02005D08(void (*cb)(void));
extern void  func_02028CB0(void);

struct Sys *func_02028844(void *desc, u32 heap)
{
    struct Sys *s;

    s = func_02030734(heap, 0xb8, 1, g_020A7590, 331);
    func_02028CD4(s, desc);
    s->unkA4 = func_02028760(heap, 0);
    s->unkA8 = func_02029F14(heap, s->unkA4);
    func_02005D08(func_02028CB0);
    return s;
}
