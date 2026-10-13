/*
 * unit:     yes
 * function: STRBUF_Append
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
 * The two mutators of the u16 vector STRBUF_Create allocates, folded into one
 * translation unit covering 0x02045AA8..0x02045B38 (both functions and the
 * single trailing pool word).  See src/matched/STRBUF_AppendChar.c for the object
 * layout this pair pins down, in particular why the entries begin at +0x8
 * and why one slot past `capacity` is reserved for a terminator.
 *
 * STRBUF_Append concatenates one vector onto another, copying src->used + 1
 * halfwords so that the source's terminator becomes the destination's.
 * STRBUF_AppendChar pushes a single entry and re-plants the terminator behind it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02045AA8.c \
 *       --addr 0x02045AA8 --arm
 */

#include "../include/G_AllocStamp.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct U16Vec {
    u16 capacity;
    u16 used;
    u32 magic;
    u16 entries[1];
};

extern struct AllocStamp g_020A7E7C;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void STRBUF_Append(struct U16Vec *dst, struct U16Vec *src)
{
    u16 count = src->used;

    if (dst->used + count + 1 > dst->capacity)
        return;

    MI_CpuCopy8(&src->entries[0], &dst->entries[dst->used], (count + 1) * 2);
    dst->used = dst->used + src->used;
}

void STRBUF_AppendChar(struct U16Vec *vec, u16 value)
{
    if (vec->used + 1 >= vec->capacity)
        return;

    vec->entries[vec->used++] = value;
    vec->entries[vec->used] = (*(u16 *)&g_020A7E7C);
}
