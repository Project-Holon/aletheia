/*
 * unit:     no
 * address:  0x020457B0
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020457B0
 *
 * symbols:
 *   sub_02030734  0x02030734  arm
 *   g_020A7E7C    0x020A7E7C  data
 *
 * The constructor of the u16-array object, and a clean specimen of the
 * debug-allocator calling convention this whole family is built on:
 *
 *   sub_02030734(heapId, size, clear, site, tag)
 *
 * The fifth argument is a u16 passed on the stack, which the callee reads
 * back with a halfword load at [sp, #0x18]; here it is 100. It looks like
 * a __LINE__-style debug tag, but that is not established: the fourth
 * argument, which would be the matching __FILE__, is 0x020A7E80, and that
 * address is above the arm9 static image end (0x020A6800, from
 * layout/layout.json), so it is BSS, not a string constant in a packed
 * string area. Whatever the pair means, it is not the literal
 * __FILE__/__LINE__ shape of
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md, and it is
 * deliberately not written as such here.
 *
 * The allocation size, 2 * capacity + 0xa, is what pins the object
 * layout: a 0xa-byte header followed by capacity u16 entries.
 *
 *   +0x00  u16  capacity
 *   +0x02  u16  used
 *   +0x04  u32  magic, 0xECD2F8B6 while live
 *   +0x08  u16  stamp, copied from g_020A7E7C
 *   +0x0a  u16  entries[capacity]
 *
 * The zero that becomes the allocator's third argument is the same
 * register that later stores `used = 0`, so the two share one `mov
 * r4, #0`; writing the third argument as a named local instead splits
 * them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020457B0.c \
 *       --func sub_020457B0 --addr 0x020457B0 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct U16Vec {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 stamp;
    u16 entries[1];
};

/*
 * The global based at 0x020A7E7C is one small object, not two independent
 * words: sub_020457B0 loads 0x020A7E80 out of a pool as the allocator's
 * fourth argument, and that word is this symbol plus four
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading it as a separate object splits one symbol into two and loses
 * the relocation: 0x020A7E80 has exactly one pool reference image-wide
 * and so no witness of its own, while the base has thirty-six.
 */
struct AllocStamp {
    u16  value;      /* 0x020A7E7C, the stamp every object copies to +0x8 */
    u16  pad;
    char site[1];    /* 0x020A7E80, the allocator's fourth argument */
};

extern struct AllocStamp g_020A7E7C;
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);

struct U16Vec *sub_020457B0(u32 capacity, u32 heapId)
{
    struct U16Vec *vec;

    vec = (struct U16Vec *)sub_02030734(heapId, capacity * 2 + 0xa, 0,
                                        g_020A7E7C.site, 100);
    vec->magic = 0xB6F8D2ECu;
    vec->capacity = (u16)capacity;
    vec->used = 0;
    vec->stamp = g_020A7E7C.value;
    return vec;
}
