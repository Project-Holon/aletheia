/*
 * function: func_02013C9C
 * address:  0x02013C9C
 * packet:   pkt_02013C9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0028 ABS32 sub_0209E026_Map       : 0209E026 (data, from header) has no witness outside 02013C9C..02013CC8
 * symbols:
 *   sub_0209E026_Map  0x0209E026  data
 */

typedef unsigned int u32;

struct Ent0209E026 {
    unsigned short code : 11;
    unsigned short kind : 5;
};

extern struct Ent0209E026 sub_0209E026_Map[];
extern u32 func_02013A94(u32 key);

int func_02013C9C(u32 key)
{
    u32 r = func_02013A94(key);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        if (r == sub_0209E026_Map[i].code)
            return sub_0209E026_Map[i].kind;
    }
    return -1;
}
