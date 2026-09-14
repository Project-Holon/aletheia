/*
 * function: func_020242A4
 * address:  0x020242A4
 * packet:   pkt_02023A50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The common slot initialiser shared by func_02024344 and the four arms of
 * func_020242D8 (src/matched/unit_020242D8.c): store the id, zero the
 * flag halfword at +2, then a two-iteration loop seeds the trailing
 * halfwords at +4 and +6 with a shared 0xFFFF sentinel. The loop counter
 * is signed (the original's `blt`, not `blo`, on a literal trip count of
 * 2); an unsigned counter compiles to `blo` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020242A4.c \
 *       --func func_020242A4 --addr 0x020242A4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int             s32;

void func_020242A4(void *obj, u32 id)
{
    u16 *p = (u16 *)obj;
    s32 i;

    p[0] = (u16)id;
    p[1] = 0;
    for (i = 0; i < 2; i++) {
        p[i + 2] = 0xFFFF;
    }
}
