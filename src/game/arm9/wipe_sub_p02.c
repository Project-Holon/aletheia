/*
 * function: func_02021FD8
 * address:  0x02021FD8
 * packet:   pkt_02021D50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02021F64   0x02021F64  thumb
 *
 * Thin forwarding wrapper: picks channel `idx` out of the 0x14-byte record
 * array, advances both of its pointers by `c` halfwords, and hands them to
 * the RGB555 blend loop at 0x02021F64 (see docs/notes/func_02021F64.c.txt --
 * that function is still a documented DIFF, so this wrapper's own
 * relocation is attested by the `label` class, not by a matched entry).
 * Arguments 5 and 6 arrive on the caller's stack and must be u8 / u16, which
 * is what makes them `ldrb [r5]` and `ldrh [r5, #4]`.
 *
 * EXACT* only: 42 bytes compiled, the listing extent is 44 -- the two extra
 * bytes are the `00 00` alignment halfword at 0x02022002, not a follower.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Chan02021FD8 {
    u16 *src;
    u16 *dst;
    u32 f8;
    u32 fc;
    u32 f10;
};

extern void func_02021F64(u16 *src, u16 *dst, u32 count, u8 weight, u16 color);

/*
 * Thin forwarding wrapper: picks channel `idx` out of the 0x14-byte record
 * array, advances both of its pointers by `c` halfwords, and hands them to
 * the RGB555 blend loop at 0x02021F64 (see docs/notes/func_02021F64.c.txt --
 * that function is still a documented DIFF, so this wrapper's own
 * relocation is attested by the `label` class, not by a matched entry).
 * Arguments 5 and 6 arrive on the caller's stack and must be u8 / u16, which
 * is what makes them `ldrb [r5]` and `ldrh [r5, #4]`.
 *
 * EXACT* only: 42 bytes compiled, the listing extent is 44 -- the two extra
 * bytes are the `00 00` alignment halfword at 0x02022002, not a follower.
 */
void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count,
                   u8 weight, u16 color)
{
    func_02021F64(p[idx].src + c, p[idx].dst + c, count, weight, color);
}
