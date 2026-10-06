/*
 * file:     unit_0207312C_p01.c
 * unit:     yes
 * function: func_020733E8, func_02073438
 * address:  0x020733E8
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
 *   SND_PrepareSeq                  0x02089350  arm
 *   SND_SetTrackAllocatableChannel  0x0208948C  arm
 *   SND_GetCurrentCommandTag        0x02089D40  arm
 *   func_02073500                   0x02073500  arm
 *   func_020735EC  0x020735EC  arm
 *   func_02075BAC  0x02075BAC  arm
 *   func_02073760  0x02073760  arm
 */
struct A;
struct Obj02075BAC;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Sub { u8 pad00[0x1c]; u32 f1c; };

struct Obj {
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

extern void SND_PrepareSeq(int playerNo, const void *seqBase, u32 seqOffset, const void *bankData);
extern void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
extern int func_02073500(int a0);
extern u32  SND_GetCurrentCommandTag(void);
extern void func_020735EC(Obj_02073438 *p);
extern void func_02075BAC(struct Obj02075BAC *o, u32 a, u32 b);
extern void func_02073760(struct A *o, u32 v);
void func_02073438(Obj_02073438 *p, int fadeFrame);


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
void func_020733E8(struct Obj *o, const void *seqBase, u32 seqOffset, const void *bankData)
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
        func_020735EC(p);
        return;
    }
    func_02075BAC((struct Obj02075BAC *)(&p->env), 0, fadeFrame);
    func_02073760((struct A *)p, 0);
    p->b2c = 2;
}
