/*
 * function: func_02013FA8
 * address:  0x02013FA8
 * packet:   pkt_02013FA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  +0028 ABS32 sub_0209DFC8_Map       : 0209DFC8 (data, from header) has no witness outside 02013FA8..02013FD8
 * symbols:
 *   sub_0209DFC8_Map  0x0209DFC8  data
 */

typedef unsigned int u32;

struct Ent0209DFC8 {
    unsigned short code : 11;
    unsigned short kind : 5;
};

extern struct Ent0209DFC8 sub_0209DFC8_Map[];
extern u32 func_02013A94(u32 key);

u32 func_02013FA8(u32 key)
{
    u32 v = func_02013A94(key);
    u32 i;

    for (i = 0; i < 5; i++) {
        if (v == sub_0209DFC8_Map[i].code)
            return sub_0209DFC8_Map[i].kind;
    }
    return 0xffff;
}
