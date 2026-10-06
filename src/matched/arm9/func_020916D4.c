/*
 * function: func_020916D4
 * address:  0x020916D4
 * packet:   pkt_020916D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A refcounted-resource wrapper: the 4-argument twin of
 * src/matched/func_02092004.c (which is the 3-argument one with a three-way
 * id dispatch).  The id here is the FOURTH argument and the dispatch is
 * two-way, `a3 == g_020A8730 ? 2 : 5`, which is what the image's
 * `mov r6,#2 / cmp r7,r4 / movne r6,#5` is.
 *
 * docs/notes/pkt_020916D4.c.txt records an earlier pass that got to 248
 * bytes against 256 and diagnosed the residue as a register tie on the
 * `mul` destination plus an unreachable CSE of the 0x02153B8C base.  Both
 * readings were wrong: the shortfall was an arm structure difference, not
 * an allocator tie.  The sibling's exact shape -- the `cur`/`ref` pair named
 * as two locals in the else arm, the two table stores written out in full in
 * BOTH the then arm and the inner else arm rather than factored, and
 * `g_02150FEC.unk04[0x1b]` re-read at each of its three use sites -- closes
 * it with no permuter run at all.  The `str r3,[r2,r6,lsl #2]` addressing-
 * mode store and the per-site pool reloads the note despaired of follow from
 * writing the arms out rather than from any register hint.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020916D4.c \
 *       --func func_020916D4 --addr 0x020916D4 --arm --cc 1.1p1
 * symbols:
 *   g_020A8730     0x020A8730  data
 *   g_02153BD4     0x02153BD4  data
 *   g_02150FEC     0x02150FEC  data
 *   arr_02153B8C   0x02153B8C  data
 *   arr_02153BB0   0x02153BB0  data
 *   func_020860D0  0x020860D0  arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_020917D4  0x020917D4  arm
 */
typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int            s32;

struct H { u32 unk00; u32 *unk04; };

extern u8  g_020A8730[];
extern u8  g_02153BD4[];
extern struct H g_02150FEC;
extern u32 arr_02153B8C[];
extern u32 arr_02153BB0[];

extern s32 func_020860D0(void *blk);
extern void func_02086028(void *blk);
extern void func_02086078(void *blk);
struct FILE;
extern unsigned int func_020917D4(void *ptr, unsigned int memb_size, unsigned int num_memb, struct FILE *file);

s32 func_020916D4(void *a0, u32 a1, u32 a2, u32 a3)
{
    u32 idx = (a3 == (u32)g_020A8730) ? 2 : 5;
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
    r = func_020917D4((void *)a0, a1, a2, (struct FILE *)a3);
    arr_02153BB0[idx]--;
    if (arr_02153BB0[idx] == 0) func_02086078(blk);
    return r;
}
