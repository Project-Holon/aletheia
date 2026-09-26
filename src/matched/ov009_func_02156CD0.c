/*
 * function: func_02156CD0
 * address:  0x02156CD0
 * packet:   pkt_02156CD0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of func_021DA434 (ov175) +0002. Coherent
 * Thumb code only in ov009 (ov010 holds the tail of another function), so the
 * ov009 shard makes that site attest as `matched`.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int g_021A8264;

int func_02156CD0(void)
{
    int *p = (int *)g_021A8264;

    if (p != 0) {
        if ((u32)(*(int *)((char *)p + 0x754) - 9) <= 1)
            return 1;
    }
    return 0;
}
