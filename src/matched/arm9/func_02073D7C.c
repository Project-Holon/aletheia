/*
 * function: NNS_SndMain
 * address:  0x02073D7C
 * packet:   pkt_02073D7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: every concrete byte of the 128 is identical and 5 of the
 * 6 relocations resolve.  The one that does not is the PC24 at +0x44 to
 * NNSi_SndShutdown, this function's own immediate follower at 0x02073DFC: that
 * `bl` is the only branch to the address anywhere in the image, so neither
 * `label` nor `matched` can attest it while 0x02073DFC is unfiled.
 * NNSi_SndShutdown was worked this pass and reached 228 of its 232 bytes with
 * the whole structure right; see docs/notes/NNSi_SndShutdown.c.txt.  Filing it
 * EXACT promotes this file with no C change, and this file in turn is one of
 * the two remaining blockers on src/pending/func_02072758.c.
 *
 * symbols:
 *   gNNSSndSystem     0x0214E9FC  data
 *   NNS_SndFaderUpdate  0x02075C08  arm
 *   NNS_SndFaderIsFinished  0x02075C20  arm
 *   NNSi_SndShutdown  0x02073DFC  arm
 *   NNS_SndFaderGet  0x02075BD4  arm
 *   func_02089638  0x02089638  arm
 */

#include "../include/G_St.h"

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct St St;

extern struct St gNNSSndSystem;
struct LerpObj;
struct Obj;
extern void NNS_SndFaderUpdate(struct LerpObj *obj);
extern int NNS_SndFaderIsFinished(struct LerpObj *obj);
extern void NNSi_SndShutdown(void);
extern s32 NNS_SndFaderGet(struct Obj *o);
extern void func_02089638(u32 a, s32 b, s32 c);

void NNS_SndMain(void)
{
    St *s;
    s32 v;

    s = &gNNSSndSystem;
    if (s->f00 == 0) {
        return;
    }
    if (s->f04 != 0) {
        return;
    }

    NNS_SndFaderUpdate((struct LerpObj *)s->f3c);

    if (s->f4c != 0 && NNS_SndFaderIsFinished((struct LerpObj *)s->f3c) != 0) {
        NNSi_SndShutdown();
        return;
    }

    v = NNS_SndFaderGet((struct Obj *)s->f3c) >> 8;
    if (v == s->f50) {
        return;
    }
    func_02089638(s->f24, v, 0);
    s->f50 = v;
}
