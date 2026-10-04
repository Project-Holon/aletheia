/*
 * function: func_02074894
 * address:  0x02074894
 * packet:   pkt_020737C0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The close path for one handle: func_02061184 decides whether the key is
 * still live (0 when not), func_020749F8 reports drain progress (the caller
 * gets remaining count - 1 when it advanced), and only when the drain is
 * complete does func_020611D4 unlink the key, after which the call still
 * answers -1.
 *
 * PINNED ../2.0/sp2, the same pin three cluster siblings carry
 * (func_02073AD0, func_02073B3C, func_02073CA0). docs/notes/func_02074894.c.txt
 * recorded this exact C as a 30-byte DIFF (76 vs 80) under dsi/1.1p1 and listed
 * six rejected respellings of the tail. The residue was never in the C: 1.1p1
 * shares the constant 0 between func_020611D4's second argument and the `-1`
 * return, parking it in a callee-saved register (`mov r4,#0` ... `sub r0,r4,#1`)
 * and widening the prologue by a push slot, where the image rematerialises
 * `mov r1,#0` and `mvn r0,#0`. That is the repeated-small-constant tell of
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md.
 * Under the pin the note's own C is 76 bytes, 0 concrete mismatches.
 *
 * All three call sites resolve by `label`, so nothing further was needed.
 *
 * symbols:
 *   func_02061184  0x02061184  arm
 *   func_020749F8  0x020749F8  arm
 *   func_020611D4  0x020611D4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074894.c \
 *       --func func_02074894 --addr 0x02074894 --cc ../2.0/sp2 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;

typedef struct S {
    u32  f00;        /* 0x00 -- owner/key word */
    char pad_04[8];
    u16  f0c;        /* 0x0c -- slot count */
} S;

struct H;
extern int func_02061184(struct H *h, u32 a1);
extern s32 func_020749F8(S *p);
struct NNSiFndHeapHead;
extern int func_020611D4(struct NNSiFndHeapHead *heap, u32 tagName);

s32 func_02074894(S *p)
{
    if (func_02061184((struct H *)p->f00, p->f0c) == 0) {
        return -1;
    }
    if (func_020749F8(p) != 0) {
        return p->f0c - 1;
    }
    func_020611D4((void *)p->f00, 0);
    return -1;
}
