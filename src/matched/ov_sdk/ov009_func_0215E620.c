/*
 * function: SOCLi_MemCpy
 * address:  0x0215E620
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Consume up to `len` bytes from a two-segment ring object into `dst`: the
 * head segment is `[+0x10]/len[+0x14]`, the wrapped tail `[+0x18]/len[+0x1c]`.
 * A request longer than the head drops the tail entirely (n = len, m = 0),
 * otherwise the tail is clamped to what is left.  Both segments copied with
 * the byte copier at 0x02082EA4, and the two cursors advanced in place.
 * Returns the number of bytes produced.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02082EA4(void *a, u8 *b, int n);

struct Ring {
    u8   pad_00[0x10];
    u8  *head;      /* +0x10 */
    int  head_len;  /* +0x14 */
    u8  *tail;      /* +0x18 */
    int  tail_len;  /* +0x1c */
};

int SOCLi_MemCpy(u8 *dst, int len, struct Ring *r)
{
    int n;
    int m;

    n = r->head_len;
    m = r->tail_len;
    if (n > len) {
        n = len;
        m = 0;
    } else if (m > len - n) {
        m = len - n;
    }
    if (n > 0) {
        func_02082EA4(r->head, dst, n);
        r->head += n;
        r->head_len -= n;
    }
    if (m > 0) {
        func_02082EA4(r->tail, dst + n, m);
        r->tail += m;
        r->tail_len -= m;
    }
    return n + m;
}
