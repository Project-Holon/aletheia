/*
 * function: func_0201F548
 * address:  0x0201F548
 * packet:   pkt_0201F548
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker: 0x0209E8CA (data) - literal x0 outside this range; the table is private to this function.
 *
 * Byte-table read, indexed by the argument.  The table has to be a named
 * array symbol rather than a cast constant: as a constant mwccarm folds the
 * addition but emits the index as the base register, `ldrb r0,[r0,r1]`,
 * where the original encodes the table as Rn.
 *
 * symbols:
 *   data_0209E8CA  0x0209E8CA  data
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201F548.c \
 *       --func func_0201F548 --addr 0x0201F548 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 data_0209E8CA[];

u8 func_0201F548(u32 i)
{
    return data_0209E8CA[i];
}
