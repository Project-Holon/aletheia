/*
 * file:     unit_02064CBC.c
 * unit:     no
 * function: func_02064CBC
 * address:  0x02064CBC
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The reset twin of NNSi_G2dMCAnimUpdateBank / sub_02064B68: clears the u16 at +0x30,
 * runs func_0206469C over the object with its +0x1c word, raises the +0x0c
 * state to 1, then walks every record of the multi-cell bank and resets its
 * cell animation.  Same two layouts as the rest of the family (kind 1 is the
 * 0x5c-stride node array with its count at header +2, anything else the
 * 0x28-stride cell array with its count at header +0 and each record's
 * pointer in its word 0).
 *
 * Pinned to ../2.0/sp2 on the "kept constants" tell: the image rematerialises
 * each loop's stride into a fresh register inside the loop body (`mov r7,
 * #0x5c` at 0x02064D00, `mov r7, #0x28` at 0x02064D40) and re-reads the header
 * pointer at +0x34 on every back edge; dsi/1.1p1 -O4,p keeps stride and header
 * live in callee-saved registers, 168 bytes against the original's 180 and 135
 * concrete out.  Under the pin the same C is 180 bytes, 0 mismatches.  See
 * docs/FRONTEND-PINS.md.
 *
 * symbols:
 *   func_0206469C  0x0206469C  arm
 *   func_020643A4  0x020643A4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct NodeHdr { u16 pad_00; u16 count; };
struct CellHdr { u16 count; };

struct Obj {
    u8    pad_00[0x0c];
    u32   f0c;
    u8    pad_10[0x0c];
    u32   f1c;
    u8    pad_20[0x10];
    u16   f30;
    u8    pad_32[2];
    void *f34;
    u8    pad_38[4];
    u32   f3c;
    void *f40;
};

struct Obj0206469C;
extern void func_0206469C(struct Obj0206469C *o, void *bank);
struct CellAnim;
extern void func_020643A4(struct CellAnim *anim);

void func_02064CBC(struct Obj *x)
{
    u16 i;

    x->f30 = 0;
    func_0206469C((struct Obj0206469C *)x, (void *)x->f1c);
    x->f0c = 1;

    if (x->f3c == 1) {
        void *base = x->f40;

        for (i = 0; i < ((struct NodeHdr *)x->f34)->count; i++) {
            func_020643A4((struct CellAnim *)((u8 *)base + i * 0x5c));
        }
    } else {
        void *base = x->f40;

        for (i = 0; i < ((struct CellHdr *)x->f34)->count; i++) {
            func_020643A4(*(void **)((u8 *)base + i * 0x28));
        }
    }
}
