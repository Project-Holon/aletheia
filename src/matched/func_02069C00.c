/*
 * function: func_02069C00
 * address:  0x02069C00
 * packet:   pkt_02069BA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The halfword post-increment reader over the bit reader's byte cursor
 * (+0x00), the unlabelled leaf after func_02069BA0 (seeded start).  The
 * cursor must be read into a typed u16 pointer and post-incremented; the
 * u8-pointer spelling `p = b->cur; b->cur = p + 2; return *(u16 *)p;`
 * schedules the store before the load (7 bytes).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Bits {
    u8 *cur;
    signed char have;
    unsigned char acc;
} Bits;

u16 func_02069C00(Bits *b)
{
    u16 *p = (u16 *)b->cur;
    u16 v = *p++;
    b->cur = (u8 *)p;
    return v;
}
