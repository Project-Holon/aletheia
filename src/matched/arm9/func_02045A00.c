/*
 * function: STRBUF_SetChars
 * address:  0x02045A00
 * packet:   pkt_02045924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8   0x02082D44  arm
 *
 * Append n halfwords to a counted buffer: the count is the halfword at +2,
 * the current length is the halfword at +0, the data starts at +8, and the
 * whole thing is halfword-indexed, which is why the copy size is `n * 2`.
 * A null count and an over-long count are both refused, each as its own
 * predicated early return on the entry compare (`movs` for the first, a
 * `pophi` for the unsigned second).
 *
 * The stored count is one less than n, and it is computed from the incoming
 * value rather than by re-reading the field, so it is a subtraction on r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetChars.c \
 *       --func STRBUF_SetChars --addr 0x02045A00 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Buf {
    u16 len;
    u16 count;
    u32 unk_04;
    u8  data[0];
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void STRBUF_SetChars(struct Buf *buf, const void *src, u32 n)
{
    if (n == 0)
        return;
    if (n > buf->len)
        return;

    MI_CpuCopy8(src, buf->data, n * 2);
    buf->count = n - 1;
}
