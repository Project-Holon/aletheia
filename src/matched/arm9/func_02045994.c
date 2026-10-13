/*
 * function: STRBUF_SetStringN
 * address:  0x02045994
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
 * strbuf.c's bounded copy of a counted string: refuse anything longer than
 * the buffer, copy until the source's own terminator shows up or the last
 * usable slot is filled, and only when the whole source was copied (the
 * count landed exactly on n-1) append the terminator.  The `n > cap` guard
 * is a predicated `pophi`, and the final conditional store is the ARM
 * `ldreq`/`addeq`/`strheq` triple.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_SetStringN.c \
 *       --func STRBUF_SetStringN --addr 0x02045994 --cc 1.1p1 --arm
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

void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len)
{
    u32 i;

    if (len > o->cap)
        return;

    for (i = 0; i < len - 1; i++) {
        o->buf[i] = src[i];
        if (o->buf[i] == sStrbufEnd)
            break;
    }

    o->n = i;
    if (i == len - 1)
        o->buf[len - 1] = sStrbufEnd;
}
