/*
 * unit:     yes
 * function: sub_02045AA8
 * address:  0x02045AA8
 * packet:   pkt_02045AA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_020A7E7C   0x020A7E7C  data
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * The two mutators of the u16 vector sub_020457B0 allocates, folded into one
 * translation unit covering 0x02045AA8..0x02045B38 (both functions and the
 * single trailing pool word).  See src/matched/sub_02045AFC.c for the object
 * layout this pair pins down, in particular why the entries begin at +0x8
 * and why one slot past `capacity` is reserved for a terminator.
 *
 * sub_02045AA8 concatenates one vector onto another, copying src->used + 1
 * halfwords so that the source's terminator becomes the destination's.
 * sub_02045AFC pushes a single entry and re-plants the terminator behind it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045AA8.c \
 *       --addr 0x02045AA8 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct U16Vec {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 entries[1];
};

extern u16 g_020A7E7C;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void sub_02045AA8(struct U16Vec *dst, struct U16Vec *src)
{
    u16 count = src->used;

    if (dst->used + count + 1 > dst->capacity)
        return;

    MI_CpuCopy8(&src->entries[0], &dst->entries[dst->used], (count + 1) * 2);
    dst->used = dst->used + src->used;
}

void sub_02045AFC(struct U16Vec *vec, u16 value)
{
    if (vec->used + 1 >= vec->capacity)
        return;

    vec->entries[vec->used++] = value;
    vec->entries[vec->used] = g_020A7E7C;
}
