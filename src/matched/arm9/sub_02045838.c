/*
 * unit:     no
 * address:  0x02045838
 * packet:   pkt_020452E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: STRBUF_Copy
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * Copies the live part of one u16-array object into another, refusing the
 * copy if the destination cannot hold it. The guard is `capacity <=
 * used`, not `<`, so the destination needs strictly more capacity than
 * the source has entries; the extra slot is the +0x8 stamp, which the
 * copy carries along by starting two bytes before the entry array and
 * moving (used + 1) halfwords.
 *
 * See src/matched/STRBUF_Create.c for the object layout. The trailing
 * `dst->used = src->used` re-reads the field rather than reusing the
 * cached value the guard and the length computation share: the two
 * objects are unrelated pointers, so the MI_CpuCopy8 call may alias
 * src->used and the load cannot be hoisted across it. Writing the tail as
 * an assignment from the cached local instead loses that reload and four
 * bytes with it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_Copy.c \
 *       --func STRBUF_Copy --addr 0x02045838 --cc 1.1p1 --arm
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

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src)
{
    u16 used;

    used = src->used;
    if (dst->capacity <= used) {
        return;
    }
    MI_CpuCopy8(&src->stamp, &dst->stamp, (used + 1) * 2);
    dst->used = src->used;
}
