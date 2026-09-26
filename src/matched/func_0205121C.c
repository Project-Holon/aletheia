/*
 * function: func_0205121C
 * address:  0x0205121C
 * packet:   pkt_0205121C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Truncating forwarding wrapper: zero-extend the third argument to u16 and
 * tail-call func_02048F60.  The ARM9 listing emits it as a .word run (no
 * func_ label), so a `matched` entry is the only witness its callers can
 * use.
 *
 * symbols:
 *   func_02048F60  0x02048F60  arm
 */

typedef unsigned int u32;

extern int func_02048F60(u32 archive_id, u32 member, u32 heap);

int func_0205121C(u32 a, u32 b, u32 c)
{
    return func_02048F60(a, b, (unsigned short)c);
}
