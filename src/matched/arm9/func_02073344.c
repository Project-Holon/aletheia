/*
 * function: NNSi_SndPlayerAllocSeqPlayer
 * address:  0x02073344
 * packet:   pkt_0207312C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   gSndPlayers  0x0214E464  data
 *   NNS_SndHandleReleaseSeq  0x02072EA8  arm
 *   NNSi_SndPlayerInsertSeqPlayer  0x02073548  arm
 *   NNSi_SndSeqPlayerStopNow  0x020735EC  arm
 *   NNSi_SndAllocFreeSeqPlayer  0x02073624  arm
 *   NNS_FndGetNextListObject  0x02060614  arm
 *
 * Pinned ../2.0/sp2 on the documented "kept constants" tell: under 1.1p1 -O4,p
 * the three `return 0` sites and the null argument of NNS_FndGetNextListObject CSE into a
 * single hoisted `mov r7, #0`, giving 156 bytes against the original's 152 and
 * permuting the whole callee-saved allocation (obj r4->r6, slot r6->r4,
 * pri r7->r5).  The image instead materialises each zero fresh
 * (`mov r1, #0` at 0x0207337C-4, `moveq r0, #0` at 0x0207338C, 0x0207339C,
 * 0x020733B4).  Four 1.1p1 spellings measured (separate node local, decl
 * reorder, early read of o->f0, explicit (void *)0 cast) all hoist the zero.
 * Under the pin the same C is 152 bytes, 0 concrete mismatches.
 *
 * PROMOTED TO EXACT, 2026-09-21, with NO change to the C.  It was parked at
 * MATCH because the PC24 site at +0x68 had no witness: NNSi_SndAllocFreeSeqPlayer has
 * exactly one branch anywhere in the image (the `bl` at 0x020733AC inside this
 * very function), so `label` refused it.  0x02073624 is now filed as
 * src/matched/NNSi_SndAllocFreeSeqPlayer.c (104 bytes, shard pkt_02073624, same ../2.0/sp2
 * kept-constants pin), and the site resolves `matched x1`.  All six
 * relocations are attested.
 */
#include "../include/Obj00513.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef signed int s32;

struct Node { u8 p0[0x3d]; u8 b3d; };
struct Slot { u8 p0[8]; u16 h08; u8 p0a[0x18 - 0xa]; u32 f18; u8 p1c[0x24 - 0x1c]; };
struct Obj { struct Node *f0; };

extern struct Slot gSndPlayers[];
struct DList;
struct Obj_02073548;
struct Voice;
extern void NNS_SndHandleReleaseSeq(u32 * volatile *pp);
extern void *NNS_FndGetNextListObject(struct DList *list, void *elem);
extern void NNSi_SndSeqPlayerStopNow(struct Node *p);
extern struct Voice *NNSi_SndAllocFreeSeqPlayer(s32 pri);
extern void NNSi_SndPlayerInsertSeqPlayer(void *list, struct Obj_02073548 *obj);

struct Node *NNSi_SndPlayerAllocSeqPlayer(struct Obj *o, s32 idx, s32 pri)
{
    struct Slot *s = &gSndPlayers[idx];
    struct Node *e = o->f0;

    if (e != 0) {
        NNS_SndHandleReleaseSeq((u32 * volatile*)o);
    }
    if (s->h08 >= s->f18) {
        e = NNS_FndGetNextListObject((struct DList *)s, 0);
        if (e == 0) {
            return 0;
        }
        if (pri < e->b3d) {
            return 0;
        }
        NNSi_SndSeqPlayerStopNow(e);
    }
    e = (struct Node *)NNSi_SndAllocFreeSeqPlayer(pri);
    if (e == 0) {
        return 0;
    }
    NNSi_SndPlayerInsertSeqPlayer(s, (struct Obj_02073548 *)e);
    *(struct Obj * *)&((struct Obj00513 *)e)->f0 = o;
    o->f0 = e;
    return e;
}
