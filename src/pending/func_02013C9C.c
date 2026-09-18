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
 * symbols:
 *   tbl_0209E026  0x0209E026  data
 *
 * blocker:  data_table - 0x0209E026 is named in the image only by
 *           the pool word inside this range.  Same finding as
 *           src/matched/unit_02013C10.c's header.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02013C9C.c \
 *       --func func_02013C9C --addr 0x02013C9C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;

struct Ent {
    u16 key : 11;
    u16 val : 5;
};

extern struct Ent tbl_0209E026[0x14];
extern u32 func_02013A94(u32 id);

u32 func_02013C9C(u32 id)
{
    u32 r = func_02013A94(id);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        if (r == tbl_0209E026[i].key) {
            return tbl_0209E026[i].val;
        }
    }
    return ~0u;
}
