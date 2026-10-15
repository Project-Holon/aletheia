/*
 * function: fread
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
 * src/matched/fseek.c (which is the 3-argument one with a three-way
 * id dispatch).  The id here is the FOURTH argument and the dispatch is
 * two-way, `a3 == gMslStream0 ? 2 : 5`, which is what the image's
 * `mov r6,#2 / cmp r7,r4 / movne r6,#5` is.
 *
 * docs/notes/pkt_020916D4.c.txt records an earlier pass that got to 248
 * bytes against 256 and diagnosed the residue as a register tie on the
 * `mul` destination plus an unreachable CSE of the 0x02153B8C base.  Both
 * readings were wrong: the shortfall was an arm structure difference, not
 * an allocator tie.  The sibling's exact shape -- the `cur`/`ref` pair named
 * as two locals in the else arm, the two table stores written out in full in
 * BOTH the then arm and the inner else arm rather than factored, and
 * `gMslRefToken.unk04[0x1b]` re-read at each of its three use sites -- closes
 * it with no permuter run at all.  The `str r3,[r2,r6,lsl #2]` addressing-
 * mode store and the per-site pool reloads the note despaired of follow from
 * writing the arms out rather than from any register hint.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/fread.c \
 *       --func fread --addr 0x020916D4 --arm --cc 1.1p1
 * symbols:
 *   gMslStream0     0x020A8730  data
 *   gMslMutexTable     0x02153BD4  data
 *   gMslRefToken     0x02150FEC  data
 *   gMslRefGen   0x02153B8C  data
 *   gMslRefCount   0x02153BB0  data
 *   OS_TryLockMutex  0x020860D0  arm
 *   OS_LockMutex  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   __fread  0x020917D4  arm
 */
typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int            s32;

struct H { u32 unk00; u32 *unk04; };

extern u8  gMslStream0[];
extern u8  gMslMutexTable[];
extern struct H gMslRefToken;
extern u32 gMslRefGen[];
extern u32 gMslRefCount[];

extern s32 OS_TryLockMutex(void *blk);
extern void OS_LockMutex(void *blk);
extern void func_02086078(void *blk);
struct FILE;
extern unsigned int __fread(void *ptr, unsigned int memb_size, unsigned int num_memb, struct FILE *file);

s32 fread(void *a0, u32 a1, u32 a2, u32 a3)
{
    u32 idx = (a3 == (u32)gMslStream0) ? 2 : 5;
    u8 *blk = gMslMutexTable + idx * 0x18;
    s32 r;

    if (OS_TryLockMutex(blk) == 0) {
        gMslRefGen[idx] = gMslRefToken.unk04[0x1b];
        gMslRefCount[idx] = 1;
    } else {
        u32 cur = gMslRefGen[idx];
        u32 ref = gMslRefToken.unk04[0x1b];

        if (cur == ref) {
            gMslRefCount[idx]++;
        } else {
            OS_LockMutex(blk);
            gMslRefGen[idx] = gMslRefToken.unk04[0x1b];
            gMslRefCount[idx] = 1;
        }
    }
    r = __fread((void *)a0, a1, a2, (struct FILE *)a3);
    gMslRefCount[idx]--;
    if (gMslRefCount[idx] == 0) func_02086078(blk);
    return r;
}
