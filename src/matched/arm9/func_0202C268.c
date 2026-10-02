/*
 * function: func_0202C268
 * address:  0x0202C268
 * packet:   pkt_0202C268
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scans the object's count entries (func_0202C240 is the count) looking for
 * the one whose sub_0202C340 value equals the caller's second argument, and
 * returns the entry's sub_0202C244 value.  The index is truncated to a byte
 * before it is passed, which is what the lsls/lsrs pair says.  Unlabelled in
 * the listing and absent from the worklist; filed from the bytes.
 *
 * symbols:
 *   func_0202C240  0x0202C240  thumb
 *   sub_0202C244   0x0202C244  thumb
 *   sub_0202C340   0x0202C340  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C268.c \
 *       --func func_0202C268 --addr 0x0202C268 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8   func_0202C240(u8 *p);
extern u32  sub_0202C244(u8 *p, u32 i);
extern u32  sub_0202C340(u32 p);

u32 func_0202C268(u8 *p, u32 v)
{
    int n = func_0202C240(p);
    int i;

    for (i = 0; i < n; i++) {
        u32 r = sub_0202C244(p, (u8)i);

        if (v == sub_0202C340(r)) {
            return r;
        }
    }
    return 0;
}
