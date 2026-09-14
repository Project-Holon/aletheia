/*
 * function: func_02025B94
 * address:  0x02025B94
 * packet:   pkt_02025774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02025B3C  0x02025B3C  thumb
 *   func_02025BA0  0x02025BA0  thumb
 *
 * A two-stage lookup: map a caller value to a record index with
 * func_02025B3C (src/matched/sub_02025B3C.c), then map that index to a
 * message/asset id with func_02025BA0 (src/matched/sub_02025BA0.c). The
 * first call's result is left in its return register and flows straight
 * into the second call's argument.
 *
 * This is the blocker for src/pending/sub_0201F094.c's wordset.c setter,
 * which is promoted alongside this file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02025B94.c \
 *       --func func_02025B94 --addr 0x02025B94 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 func_02025B3C(u32 key);
extern u32 func_02025BA0(u32 idx);

u32 func_02025B94(u32 a)
{
    return func_02025BA0(func_02025B3C(a));
}
