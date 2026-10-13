/*
 * function: STRBUF_SetString
 * address:  0x02045924
 * packet:   pkt_02045924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sStrbufEnd  0x020A7E7C  data
 *
 * strbuf.c's `strcpy`-into-a-bounded-buffer: the terminator is the halfword
 * at 0x020A7E7C (0xFFFF), the buffer's capacity is the halfword at +0 and
 * the count is kept at +2, with the halfword array starting at +8.  The
 * first copy stops on the terminator, the second on a full buffer, and the
 * terminator is always written at the end - which is why the exit block is
 * shared and why the count is re-read there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetString.c \
 *       --func STRBUF_SetString --addr 0x02045924 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Strbuf {
    u16     cap;            /* +0x00 */
    u16     n;              /* +0x02 */
    u8      pad04[4];
    u16     buf[1];         /* +0x08 */
};

extern u16 sStrbufEnd;

void STRBUF_SetString(struct Strbuf *o, const u16 *src)
{
    o->n = 0;
    while (*src != sStrbufEnd) {
        if (o->n >= o->cap - 1)
            break;
        o->buf[o->n++] = *src;
        src++;
    }
    o->buf[o->n] = sStrbufEnd;
}
