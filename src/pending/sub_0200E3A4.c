/*
 * function: sub_0200E3A4
 * address:  0x0200E3A4
 * packet:   pkt_0200E3A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 *
 * blocking: unresolved: 02167380 (thumb, from header) has no witness outside 0200E3A4..0200E; unresolved: 02167358 (thumb, from header) has no witness outside 0200E3A4..0200E
 *
 * symbols:
 *   func_02167380  0x02167380  thumb
 *   func_02167358  0x02167358  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_02167380(int id);
extern u32 func_02167358(int id);

u32 sub_0200E3A4(const u8 *bits, int id)
{
    u32 bit  = func_02167380(id);
    u32 n    = func_02167358(id);
    u32 byte = bit >> 3;
    u32 b    = bit & 7;
    u32 out  = 0;
    u32 i    = 0;

    while (n != 0) {
        out |= (u32)((bits[byte] >> b) & 1) << i;
        if (++b > 7) {
            byte++;
            b = 0;
        }
        i++;
        n--;
    }
    return out;
}
