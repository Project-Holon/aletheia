/*
 * unit:     no
 * function: func_0202155C
 * address:  0x0202155C
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02021548      0x02021548  thumb
 *   func_02030734      0x02030734  arm
 *   func_0202155C_File 0x020A73BC  data
 *
 * Allocate the double buffer for one palette-animation slot: two blocks of
 * the same size out of the same heap, tags 142 and 143, then hand both plus
 * the size to the slot setter.
 *
 * The size is the allocator's second argument and the setter's fifth, and
 * it is never reloaded, which is what pins it as a parameter rather than a
 * field of the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202155C.c \
 *       --func func_0202155C --addr 0x0202155C --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct PalAnmSlot {
    void *unk_00;
    void *unk_04;
    u32   size;
    u32   unk_0c;
    u32   unk_10;
};

extern const char func_0202155C_File[];

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *site,
                           u16 tag);
extern void func_02021548(struct PalAnmSlot *slots, u32 idx, void *a, void *b,
                          u32 size);

void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap)
{
    void *a = func_02030734(heap, size, 0, func_0202155C_File, 142);
    void *b = func_02030734(heap, size, 0, func_0202155C_File, 143);
    func_02021548(slots, idx, a, b, size);
}
