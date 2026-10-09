/*
 * file:     unit_0207312C_p02.c
 * unit:     yes
 * function: func_02073344, func_020733DC, func_020733E8, func_02073438, func_02073484
 * address:  0x02073344
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214E464  0x0214E464  data
 *   SND_PrepareSeq                  0x02089350  arm
 *   SND_SetTrackAllocatableChannel  0x0208948C  arm
 *   SND_GetCurrentCommandTag        0x02089D40  arm
 *   func_02073500                   0x02073500  arm
 *   func_020735EC  0x020735EC  arm
 *   func_02075BAC  0x02075BAC  arm
 *   func_02073760  0x02073760  arm
 *   func_02089398    0x02089398  arm
 */
#include "../../matched/include/Obj00513.h"

struct DList;
struct Obj_02073548;
struct Voice;
struct A;
struct Obj02075BAC;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

struct Node { u8 p0[0x3d]; u8 b3d; };

struct Slot { u8 p0[8]; u16 h08; u8 p0a[0x18 - 0xa]; u32 f18; u8 p1c[0x24 - 0x1c]; };

struct Obj_02073344 { struct Node *f0; };

struct Sub { u8 pad00[0x1c]; u32 f1c; };

struct Obj_020733E8 {
    u8  pad00[4];
    struct Sub *f4;
    u8  pad08[0x2c - 8];
    u8  b2c;
    u8  pad2d[2];
    u8  b2f;
    u32 f30;
    u8  pad34[0x3c - 0x34];
    u8  b3c;
};

typedef struct Obj_02073438 {
    u8 pad00[0x1c];
    u8 env[0x2c - 0x1c];
    u8 b2c;
} Obj_02073438;

typedef struct {
    u8 unk00[0x2e];
    u8 unk2e;
    u8 unk2f[0x3c - 0x2f];
    u8 unk3c;
} Obj02073484;

extern void func_02072EA8(u32 * volatile *pp);
extern void *func_02060614(struct DList *list, void *elem);
extern void func_020735EC(struct Node *p);
extern struct Voice *func_02073624(s32 pri);
extern void func_02073548(void *list, struct Obj_02073548 *obj);
extern void func_0207368C(struct Voice *v);
extern void SND_PrepareSeq(int playerNo, const void *seqBase, u32 seqOffset, const void *bankData);
extern void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
extern int func_02073500(int a0);
extern u32  SND_GetCurrentCommandTag(void);
extern void func_02075BAC(struct Obj02075BAC *o, u32 a, u32 b);
extern void func_02073760(struct A *o, u32 v);
extern void func_02089398(int playerNo, int flag);
struct Node *func_02073344(struct Obj_02073344 *o, s32 idx, s32 pri);
void func_020733DC(void *h);
void func_020733E8(struct Obj_020733E8 *o, const void *seqBase, u32 seqOffset, const void *bankData);
void func_02073438(Obj_02073438 *p, int fadeFrame);
void func_02073484(Obj02073484 *p, u8 v);
extern struct Slot g_0214E464[];




/*
 * Pinned ../2.0/sp2 on the documented "kept constants" tell: under 1.1p1 -O4,p
 * the three `return 0` sites and the null argument of func_02060614 CSE into a
 * single hoisted `mov r7, #0`, giving 156 bytes against the original's 152 and
 * permuting the whole callee-saved allocation (obj r4->r6, slot r6->r4,
 * pri r7->r5).  The image instead materialises each zero fresh
 * (`mov r1, #0` at 0x0207337C-4, `moveq r0, #0` at 0x0207338C, 0x0207339C,
 * 0x020733B4).  Four 1.1p1 spellings measured (separate node local, decl
 * reorder, early read of o->f0, explicit (void *)0 cast) all hoist the zero.
 * Under the pin the same C is 152 bytes, 0 concrete mismatches.
 *
 * PROMOTED TO EXACT, 2026-09-21, with NO change to the C.  It was parked at
 * MATCH because the PC24 site at +0x68 had no witness: func_02073624 has
 * exactly one branch anywhere in the image (the `bl` at 0x020733AC inside this
 * very function), so `label` refused it.  0x02073624 is now filed as
 * src/matched/func_02073624.c (104 bytes, shard pkt_02073624, same ../2.0/sp2
 * kept-constants pin), and the site resolves `matched x1`.  All six
 * relocations are attested.
 */
struct Node *func_02073344(struct Obj_02073344 *o, s32 idx, s32 pri)
{
    struct Slot *s = &g_0214E464[idx];
    struct Node *e = o->f0;

    if (e != 0) {
        func_02072EA8((u32 * volatile*)o);
    }
    if (s->h08 >= s->f18) {
        e = func_02060614((struct DList *)s, 0);
        if (e == 0) {
            return 0;
        }
        if (pri < e->b3d) {
            return 0;
        }
        func_020735EC(e);
    }
    e = (struct Node *)func_02073624(pri);
    if (e == 0) {
        return 0;
    }
    func_02073548(s, (struct Obj_02073548 *)e);
    *(struct Obj_02073344 * *)&((struct Obj00513 *)e)->f0 = o;
    o->f0 = e;
    return e;
}



void func_020733DC(void *h){ func_0207368C(h); }




/*
 * Start a sequence on a voice (the NitroSystem sound-player layer over the
 * TwlSDK SND driver): prepare the sequence on the voice's player number,
 * restrict its allocatable channels when the owning player object has a
 * channel mask at +0x1c, reset the voice, record the current command tag and
 * mark it prepared/playing.
 *
 * The 2-byte residue of docs/notes/pkt_020733E8.c.txt (the guard load in r2
 * where the compile used r0) was an ARITY, as that note suspected, but on
 * both callees at once: SND_PrepareSeq takes FOUR arguments (playerNo,
 * seqBase, seqOffset, bankData), so this function forwards its own r1..r3
 * untouched; and SND_SetTrackAllocatableChannel takes THREE (playerNo,
 * trackBitMask, chBitMask), so the guard value in r2 is the channel mask
 * being passed on.  The callers func_02075698 / func_02075794 already pass
 * four arguments.  The pin is ../2.0/sp2 (1.1p1: 9 bytes out).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020733E8.c \
 *       --func func_020733E8 --addr 0x020733E8 --arm --cc ../2.0/sp2
 */
void func_020733E8(struct Obj_020733E8 *o, const void *seqBase, u32 seqOffset, const void *bankData)
{
    struct Sub *s = o->f4;
    SND_PrepareSeq(o->b3c, seqBase, seqOffset, bankData);
    if (s->f1c != 0) {
        SND_SetTrackAllocatableChannel(o->b3c, 0xFFFF, s->f1c);
    }
    func_02073500((int)o);
    o->f30 = SND_GetCurrentCommandTag();
    o->b2f = 1;
    o->b2c = 1;
}




/*
 * Stop a voice's sequence with an optional fade (the NitroSystem sound-player
 * stop shape): nothing to do for a null or idle voice; a zero fade stops at
 * once through func_020735EC; otherwise start the embedded fader at +0x1c
 * toward 0 over `fadeFrame` frames, drop the voice's priority to 0 and mark it
 * releasing (state 2).
 *
 * The four-byte gap in docs/notes/func_02073438.c.txt (the image copies the
 * second argument into r2 before the guard) was the ARITY OF THE FADER CALL:
 * func_02075BAC takes three arguments (fader, target, frames) -- its own body
 * saves r0, r1 AND r2 and stores all three -- so fadeFrame is moved into r2
 * early and passed on.  That note tried forwarding n in place of the 0 and a
 * third parameter on THIS function, not the third argument of the callee.
 * The pin is ../2.0/sp2 (1.1p1 is 80 bytes with a wide push).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02073438.c \
 *       --func func_02073438 --addr 0x02073438 --arm --cc ../2.0/sp2
 */
void func_02073438(Obj_02073438 *p, int fadeFrame)
{
    if (p == 0) return;
    if (p->b2c == 0) return;
    if (fadeFrame == 0) {
        func_020735EC((struct Node *)p);
        return;
    }
    func_02075BAC((struct Obj02075BAC *)(&p->env), 0, fadeFrame);
    func_02073760((struct A *)p, 0);
    p->b2c = 2;
}


/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * Pauses the sequence behind the object when the new value differs from the
 * cached one at +0x2E, then caches it.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02073484.c \
 *       --func func_02073484 --addr 0x02073484 --cc 1.1p1 --arm
 */
void func_02073484(Obj02073484 *p, u8 v)
{
    if (p != 0 && v != p->unk2e) {
        func_02089398(p->unk3c, v);
        p->unk2e = v;
    }
}
