/*
 * unit:     no
 * function: func_02091D38
 * address:  0x02091D38
 * packet:   pkt_02091D38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The one-argument member of the refcounted-resource wrapper family
 * (src/matched/func_02092004.c is the three-argument one, and
 * src/matched/func_020916D4.c the four-argument one with a two-way dispatch).
 * Three-way id dispatch on a0, block base 0x02153BD4 with a 0x18 stride, the
 * two parallel arrays arr_02153B8C / arr_02153BB0, and the reference token
 * g_02150FEC.unk04[0x1b].
 *
 * docs/notes/pkt_02091D38.c.txt left this at 265 of 268 bytes with a
 * three-instruction residue on the equality compare, and named the fix it had
 * not tried: bind BOTH sides to named locals in a nested if/else inside the
 * outer else, ARRAY ELEMENT FIRST --
 *
 *     u32 cur = arr_02153B8C[idx];
 *     u32 ref = g_02150FEC.unk04[0x1b];
 *     if (cur == ref) ... else ...
 *
 * not an `else if` on the bare expression.  Two live named temporaries on the
 * compare is what lands arr in r1 and the field in r0; the `else if` spelling
 * canonicalises either operand order to the swapped pair.  That spelling
 * closes it, exactly as the note predicted from 0x02092004.
 *
 * g_02150FEC is a two-word object whose SECOND word is the pointer: the pool
 * word is 0x02150FEC itself, so the field must be reached through
 * `g_02150FEC.unk04`, never through a symbol named for 0x02150FF0.  The three
 * id constants are ADDRESSES compared against a0, so they are declared as
 * objects and their address taken; declaring them `u32` makes the compiler
 * dereference them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02091D38.c \
 *       --func func_02091D38 --addr 0x02091D38 --arm --cc 1.1p1
 *
 * symbols:
 *   g_020A8730     0x020A8730  data
 *   g_020A877C     0x020A877C  data
 *   g_020A87C8     0x020A87C8  data
 *   g_02153BD4     0x02153BD4  data
 *   g_02150FEC     0x02150FEC  data
 *   arr_02153B8C   0x02153B8C  data
 *   arr_02153BB0   0x02153BB0  data
 *   func_020860D0  0x020860D0  arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_02091CBC  0x02091CBC  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct H { u32 unk00; u32 *unk04; };

extern u8  g_020A8730[];
extern u8  g_020A877C[];
extern u8  g_020A87C8[];
extern u8  g_02153BD4[];
extern struct H g_02150FEC;
extern u32 arr_02153B8C[];
extern u32 arr_02153BB0[];

extern s32 func_020860D0(void *blk);
extern void func_02086028(void *blk);
extern void func_02086078(void *blk);
struct P02091CBC;
extern int func_02091CBC(struct P02091CBC *p);

s32 func_02091D38(u32 a0)
{
    u32 idx = (a0 == (u32)g_020A8730) ? 2 : (a0 == (u32)g_020A877C) ? 3
            : (a0 == (u32)g_020A87C8) ? 4 : 5;
    u8 *blk = g_02153BD4 + idx * 0x18;
    s32 r;

    if (func_020860D0(blk) == 0) {
        arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
        arr_02153BB0[idx] = 1;
    } else {
        u32 cur = arr_02153B8C[idx];
        u32 ref = g_02150FEC.unk04[0x1b];

        if (cur == ref) {
            arr_02153BB0[idx]++;
        } else {
            func_02086028(blk);
            arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
            arr_02153BB0[idx] = 1;
        }
    }
    r = func_02091CBC((struct P02091CBC *)a0);
    arr_02153BB0[idx]--;
    if (arr_02153BB0[idx] == 0) func_02086078(blk);
    return r;
}
