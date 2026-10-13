/*
 * function: NNSi_SndSeqPlayerRelease
 * address:  0x0207368C
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   gSndActiveSeqList     0x0214E018  data
 *   gSndFreeSeqList     0x0214E00C  data
 *   func_020605B4  0x020605B4  arm
 *   func_020604AC  0x020604AC  arm
 *
 * Voice teardown, the counterpart of NNSi_SndAllocFreeSeqPlayer: clear the back-pointer in
 * the owner, unlink from the f04 sub-list, unlink from the f08 sub-list if it
 * has one, then move the node from the active list at 0x0214E018 back to the
 * free list at 0x0214E00C and clear the state byte.
 *
 * The lever, and the whole reason docs/notes/pkt_02073624.c.txt left this one
 * open at 84 bytes: the inner func_020604AC call's second argument is
 * `v->f08`, NOT `v`.  The image's guard load `ldr r1, [r4, #8]` at 0x020736C0
 * IS the argument register -- the `cmp r1, #0` / `beq` pair tests the value in
 * place and the call site then only has to compute r0.  Passing `v` costs a
 * fresh `mov r1, r4` and 4 bytes, and forces the guard load into r0.  Every
 * other call in the body does pass `v`, which is what makes the odd one out
 * easy to miss.  The sub-list base is `(char *)v->f04 + 0xc`, read into r5
 * before the FIRST func_020605B4 call and reused, not re-read.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md), the same
 * one as this packet's NNSi_SndAllocFreeSeqPlayer.c.  The image materialises each zero
 * fresh: `movne r0, #0` at 0x0207369C for the owner pair, `mov r0, #0` at
 * 0x020736B8 for f04, `mov r1, #0` at 0x020736D8 for the f08 pair and
 * `mov r0, #0` at 0x020736FC for b2c.  1.1p1 -O4,p CSEs all four into one
 * hoisted `mov r5, #0`, which costs a further callee-saved register and turns
 * the original's `push {r3, r4, r5, lr}` (`38 40 2d e9`) into
 * `push {r4, r5, r6, lr}` with the sub-list base displaced from r5 to r6; the
 * same 132 bytes with 40 concrete bytes out.  Under the pin the same C is
 * 132 bytes, 0 mismatches.
 */

typedef unsigned char u8; typedef unsigned int u32;

struct Owner { u32 f00; };
struct Sub   { u8 p00[0xc]; struct Voice *f0c; };

struct Voice {
    struct Owner *f00;
    struct Sub   *f04;
    struct Sub   *f08;
    u8  p0c[0x2c - 0x0c];
    u8  b2c;
};

extern char gSndActiveSeqList[];
extern char gSndFreeSeqList[];

struct DList;
extern void func_020605B4(volatile struct DList *list, void *elem);
extern void func_020604AC(void *list, void *node);

void NNSi_SndSeqPlayerRelease(struct Voice *v)
{
    struct Sub *s;

    if (v->f00 != 0) {
        v->f00->f00 = 0;
        v->f00 = 0;
    }
    s = v->f04;
    func_020605B4((volatile struct DList *)s, v);
    v->f04 = 0;
    if (v->f08 != 0) {
        func_020604AC((char *)s + 0xc, v->f08);
        v->f08->f0c = 0;
        v->f08 = 0;
    }
    func_020605B4((volatile struct DList *)gSndActiveSeqList, v);
    func_020604AC(gSndFreeSeqList, v);
    v->b2c = 0;
}
