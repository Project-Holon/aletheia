/*
 * function: func_02073438
 * address:  0x02073438
 * packet:   pkt_02073098
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020735EC  0x020735EC  arm
 *   func_02075BAC  0x02075BAC  arm
 *   func_02073760  0x02073760  arm
 *
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
typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Obj_02073438 {
    u8 pad00[0x1c];
    u8 env[0x2c - 0x1c];
    u8 b2c;
} Obj_02073438;

extern void func_020735EC(Obj_02073438 *p);
struct A;
struct Obj02075BAC;
extern void func_02075BAC(struct Obj02075BAC *o, u32 a, u32 b);
extern void func_02073760(struct A *o, u32 v);

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
