/*
 * unit:     no
 * function: ftell
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
 * (src/matched/fseek.c is the three-argument one, and
 * src/matched/fread.c the four-argument one with a two-way dispatch).
 * Three-way id dispatch on a0, block base 0x02153BD4 with a 0x18 stride, the
 * two parallel arrays gMslRefGen / gMslRefCount, and the reference token
 * gMslRefToken.unk04[0x1b].
 *
 * docs/notes/pkt_02091D38.c.txt left this at 265 of 268 bytes with a
 * three-instruction residue on the equality compare, and named the fix it had
 * not tried: bind BOTH sides to named locals in a nested if/else inside the
 * outer else, ARRAY ELEMENT FIRST --
 *
 *     u32 cur = gMslRefGen[idx];
 *     u32 ref = gMslRefToken.unk04[0x1b];
 *     if (cur == ref) ... else ...
 *
 * not an `else if` on the bare expression.  Two live named temporaries on the
 * compare is what lands arr in r1 and the field in r0; the `else if` spelling
 * canonicalises either operand order to the swapped pair.  That spelling
 * closes it, exactly as the note predicted from 0x02092004.
 *
 * gMslRefToken is a two-word object whose SECOND word is the pointer: the pool
 * word is 0x02150FEC itself, so the field must be reached through
 * `gMslRefToken.unk04`, never through a symbol named for 0x02150FF0.  The three
 * id constants are ADDRESSES compared against a0, so they are declared as
 * objects and their address taken; declaring them `u32` makes the compiler
 * dereference them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/ftell.c \
 *       --func ftell --addr 0x02091D38 --arm --cc 1.1p1
 *
 * symbols:
 *   gMslStream0     0x020A8730  data
 *   gMslStream1     0x020A877C  data
 *   gMslStream2     0x020A87C8  data
 *   gMslMutexTable     0x02153BD4  data
 *   gMslRefToken     0x02150FEC  data
 *   gMslRefGen   0x02153B8C  data
 *   gMslRefCount   0x02153BB0  data
 *   OS_TryLockMutex  0x020860D0  arm
 *   OS_LockMutex  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   __ftell  0x02091CBC  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct H { u32 unk00; u32 *unk04; };

extern u8  gMslStream0[];
extern u8  gMslStream1[];
extern u8  gMslStream2[];
extern u8  gMslMutexTable[];
extern struct H gMslRefToken;
extern u32 gMslRefGen[];
extern u32 gMslRefCount[];

extern s32 OS_TryLockMutex(void *blk);
extern void OS_LockMutex(void *blk);
extern void func_02086078(void *blk);
struct P02091CBC;
extern int __ftell(struct P02091CBC *p);

s32 ftell(u32 a0)
{
    u32 idx = (a0 == (u32)gMslStream0) ? 2 : (a0 == (u32)gMslStream1) ? 3
            : (a0 == (u32)gMslStream2) ? 4 : 5;
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
    r = __ftell((struct P02091CBC *)a0);
    gMslRefCount[idx]--;
    if (gMslRefCount[idx] == 0) func_02086078(blk);
    return r;
}
