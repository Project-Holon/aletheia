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
 * symbols:
 *   tbl_0209DFC8  0x0209DFC8  data
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02013FA8.c \
 *       --func func_02013FA8 --addr 0x02013FA8 --cc 1.1p1 --thumb
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

extern struct Ent tbl_0209DFC8[5];
extern u32 func_02013A94(u32 id);

u32 func_02013FA8(u32 id)
{
    u32 r = func_02013A94(id);
    u32 i;

    for (i = 0; i < 5; i++) {
        if (r == tbl_0209DFC8[i].key) {
            return tbl_0209DFC8[i].val;
        }
    }
    return 0xffff;
}
