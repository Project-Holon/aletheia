/*
 * function: fseek
 * address:  0x02092004
 * packet:   pkt_02091D38
 * isa:      arm
 * status:   EXACT
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocking: label, no outside witness -- the one wildcard site is +0x00D4
 *           PC24 __fseek, whose only branch in the image is this call
 *           (match.py: "has no witness outside 02092004..02092120").  Cut
 *           does not help: the site is inside the single function, so
 *           --suggest-split has nothing to offer.  Byte-correct as it
 *           stands: converts with no edit the moment 0x02091E44 has a
 *           manifest entry of its own.
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
 *   __fseek  0x02091E44  arm
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
extern s32 __fseek(u32 a0, u32 a1, u32 a2);

s32 fseek(u32 a0, u32 a1, u32 a2)
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
    r = __fseek(a0, a1, a2);
    gMslRefCount[idx]--;
    if (gMslRefCount[idx] == 0) func_02086078(blk);
    return r;
}
