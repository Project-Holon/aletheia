/*
 * function: func_02075858
 * address:  0x02075858
 * packet:   pkt_02075698
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The per-slot tick of the four 0x17c-byte entries of data_0214EAC0: bit 0
 * gates the slot, bit 2 + f120 runs the reconfigure and flips the pending
 * bits, bit 1 steps the lerp and recomputes the f164 sum out of the s16
 * table data_020A5D08, and bit 3 polls for completion.
 *
 * PINNED ../2.0/sp2 on the "kept branches" tell (docs/FRONTEND-PINS.md),
 * cross-jump form. The image writes the f11c == 0 arm's tail out in full --
 * `mov r0, r7` (`07 00 a0 e1`) at 0x02075884 / `bl func_02075994` at
 * 0x02075888 / `b 0x0207594c` (`2e 00 00 ea`) at 0x0207588C -- although the
 * bit-3 completion arm ends in a byte-identical `mov r0, r7` / `bl
 * func_02075994` pair at 0x02075944/0x02075948. dsi/1.1p1 -O4,p cross-jumps
 * the two, branching the f11c arm straight into the completion arm's pair,
 * giving 264 bytes against the original's 272 with everything after
 * 0x02075884 shifted by eight. An explicit `goto` past the else, the
 * if/else chain and the early-continue spelling all fold the same way.
 * Under the pin the same C is 272 bytes, 0 mismatches: BYTE-CORRECT.
 *
 * CAPPED AT MATCH for lack of an outside witness, not for codegen. Three
 * sites are unattested: the two PC24 to func_02075994, whose only branches
 * image-wide are these two `bl`s inside this function, and the ABS32 at
 * +0x108, whose only pool word image-wide is this function's own at
 * 0x02075960 (inside the 272-byte compared range), so `literal` refuses it.
 * Filing func_02075994 EXACT clears the two PC24 sites but not the ABS32.
 *
 * NOTE for src/pending/func_02072758.c: that file names 0x02075858 as one
 * of its three blocking PC24 sites. This file is byte-correct but stays
 * MATCH, so it does NOT promote func_02072758 -- only a `matched` entry can.
 *
 * symbols:
 *   data_0214EAC0  0x0214EAC0  data
 *   data_020A5D08  0x020A5D08  data
 *   func_02073A60  0x02073A60  arm
 *   func_02073AD0  0x02073AD0  arm
 *   func_02075994  0x02075994  arm
 *   NNS_SndFaderGet  0x02075BD4  arm
 *   NNS_SndFaderUpdate  0x02075C08  arm
 *   NNS_SndFaderIsFinished  0x02075C20  arm
 */

typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned char u8;

struct Slot {
    u8  pad000[0xf0];
    u8  lerp[0x118 - 0xf0];
    s32 b0 : 1;
    s32 b1 : 1;
    s32 b2 : 1;
    s32 b3 : 1;
    s32 brest : 28;
    s32 f11c;
    s32 f120;
    u8  pad124[0x15c - 0x124];
    s32 f15c;
    s32 f160;
    s32 f164;
    u8  pad168[0x17c - 0x168];
};

extern struct Slot data_0214EAC0[4];
extern const s16 data_020A5D08[];

struct A;
struct LerpObj;
struct Obj;
struct Obj75994;
extern void func_02073A60(struct A *a);
extern void func_02073AD0(struct Slot *, s32);
extern void func_02075994(struct Obj75994 *o);
extern s32 NNS_SndFaderGet(struct Obj *o);
extern void NNS_SndFaderUpdate(struct LerpObj *obj);
extern int NNS_SndFaderIsFinished(struct LerpObj *obj);

void func_02075858(void)
{
    s32 i;
    s32 v;
    s32 a, b, c, d;
    struct Slot *s = data_0214EAC0;

    for (i = 0; i < 4; i++) {
        if (s->b0) {
            if (s->f11c == 0) {
                func_02075994((struct Obj75994 *)s);
                goto next;
            } else {
                if (s->b2 && s->f120 != 0) {
                    func_02073A60((struct A *)s);
                    s->b1 = 1;
                    s->b2 = 0;
                }
                if (s->b1) {
                    NNS_SndFaderUpdate((struct LerpObj *)s->lerp);
                    a = data_020A5D08[s->f15c];
                    b = NNS_SndFaderGet((struct Obj *)s->lerp) >> 8;
                    c = s->f160;
                    d = data_020A5D08[b];
                    v = data_020A5D08[c] + (d + a);

                    if (v != s->f164) {
                        func_02073AD0(s, v);
                        s->f164 = v;
                    }
                    if (s->b3) {
                        if (NNS_SndFaderIsFinished((struct LerpObj *)s->lerp) != 0) {
                            func_02075994((struct Obj75994 *)s);
                        }
                    }
                }
            }
        }
next:
        s++;
    }
}
