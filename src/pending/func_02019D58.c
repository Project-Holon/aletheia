/*
 * function: func_02019D58
 * address:  0x02019D58
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  0209E280 literal - its only pool word is this function's own, inside the compared range; every concrete byte is right (MATCH*).
 *
 * symbols:
 *   g_0209E280   0x0209E280  data
 *
 * A four-entry halfword scan: returns 0 on a hit and the second argument
 * otherwise, and the whole scan sits behind an a1 != 0 guard that shares the
 * tail return.  The index is a u16, so the increment carries the lsls #16 /
 * lsrs #16 pair and the bound test is `blo`.  The table pointer is this
 * function's own pool word, which lands exactly at the end of the 40-byte
 * extent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02019D58.c \
 *       --func func_02019D58 --addr 0x02019D58 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 g_0209E280[];

int func_02019D58(u32 a0, int a1)
{
    u16 i;

    if (a1 != 0) {
        for (i = 0; i < 4; i++) {
            if (a0 == g_0209E280[i])
                return 0;
        }
    }
    return a1;
}
