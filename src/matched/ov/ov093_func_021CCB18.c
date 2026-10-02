/*
 * function: func_021CCB18
 * address: 0x021CCB18
 * packet: pkt_ov093_021CCB18
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Once-300 permuter expands the byte-source local and binds rpos
 *        separately before the two loads; retain unsigned full-word cursor.
 *        The signed 32-bit temporary preserves its input bits; convert back
 *        to u32 before every modular address sum, then cast the final address.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 wpos;
    u32 rpos;
    u8 buf[3000];
} Buf;

u32 func_021CCB18(Buf *p)
{
    const u8 *q;
    u16 v;
    int tmp;
    tmp = p->rpos;
    q = (const u8 *)((u32)p + p->rpos);
    v = (*(const u8 *)((u32)p + (u32)tmp + 8) << 8) |
        *(const u8 *)((u32)p + p->rpos + 9);
    p->rpos += 2;
    return v;
}
