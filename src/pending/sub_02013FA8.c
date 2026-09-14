/*
 * function: sub_02013FA8
 * address:  0x02013FA8
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   sub_02013A94       0x02013A94  thumb
 *   sub_02013FA8_Table 0x0209DFC8  data
 *
 * Every concrete byte reproduces; the one relocation (the table's address)
 * caps at MATCH.  0x0209DFC8 is a fixed five entry table, each entry an
 * 11 bit key and a 5 bit value packed into one halfword; the only pool
 * word anywhere in the image that names this address is this function's
 * own, so the honesty rule in docs/MATCHING.md refuses the witness.
 * Parked here per src/pending/README.md until something else in the image
 * references the table.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02013FA8.c \
 *       --func sub_02013FA8 --addr 0x02013FA8 --cc 1.1p1 --thumb
 *
 * The `matched` class does not reach it either: an EXACT entry attests the code
 * it reproduced, never a data object one of its instructions loads, and
 * 0x0209DFC8 is a table.  Only another reference to the table closes this.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02013FA8Entry {
    u16 key : 11;
    u16 val : 5;
};

extern u32 sub_02013A94(u32 id);
extern const struct Sub02013FA8Entry sub_02013FA8_Table[];

u32 sub_02013FA8(u32 id)
{
    u32 rid = sub_02013A94(id);
    u32 i;

    for (i = 0; i < 5; i++) {
        if (rid == sub_02013FA8_Table[i].key)
            return sub_02013FA8_Table[i].val;
    }
    return 0xFFFF;
}
