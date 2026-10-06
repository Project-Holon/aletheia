/*
 * file:     unit_020746C4_p02.c
 * unit:     yes
 * function: func_02074894, func_020748E0
 * address:  0x02074894
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
 *   func_02061184  0x02061184  arm
 *   func_020749F8  0x020749F8  arm
 *   func_020611D4  0x020611D4  arm
 *   func_02074770  0x02074770  arm
 *   func_0206062C  0x0206062C  arm
 *   func_020605B4  0x020605B4  arm
 *   func_02074A34  0x02074A34  arm
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
struct Table;
extern int func_020749F8(struct Table *t);
struct NNSiFndHeapHead;
extern int func_020611D4(struct NNSiFndHeapHead *heap, u32 tagName);

/*
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
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074894.c \
 *       --func func_02074894 --addr 0x02074894 --cc ../2.0/sp2 --arm
 */
s32 func_02074894(S *p)
{
    if (func_02061184((struct H *)p->f00, p->f0c) == 0) {
        return -1;
    }
    if (func_020749F8((struct Table *)p) != 0) {
        return p->f0c - 1;
    }
    func_020611D4((void *)p->f00, 0);
    return -1;
}

struct Node { u8 pad00[8]; u32 f08; u32 f0c; u32 f10; u32 f14; };
struct Obj  { u32 f00; u8 list[8]; u16 f0c; };

extern void  func_02074770(struct Obj *o);
extern void *func_0206062C(void *list, void *cur);
extern void  func_020605B4(void *list, void *node);
extern void  func_02074A34(void);

/*
 * Bounded sibling of func_02074770: drains request lists while the key k is
 * below the live count at +0x0C (k == 0 forwards to func_02074770), then
 * func_020611D4(f00, k), func_02074A34 once if any callback ran,
 * func_02061184(f00, f0c) and func_020749F8(o).
 *
 * Two levers closed the 19-byte floor of docs/notes/pkt_02074894.c.txt:
 *  1. The null cursor of each outer iteration's SECOND func_0206062C is the
 *     node cursor n itself (n = 0 at entry and 0 again whenever the inner walk
 *     ends), not a literal 0.  That is the image's `mov r1, r8` with r8 = n,
 *     and it is what lets one zero serve n, any and the head cursor.
 *  2. Declaration order a, any, n (a in r6, any in r7), per
 *     docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 */
void func_020748E0(struct Obj *o, s32 k)
{
    void *a;
    u32 any;
    struct Node *n;

    n   = 0;
    any = 0;
    if (k == 0) { func_02074770(o); return; }

    while (k < o->f0c) {
        a = func_0206062C(o->list, 0);
        n = (struct Node *)func_0206062C(a, n);
        while (n != 0) {
            if (n->f0c != 0) {
                ((void (*)(void *, u32, u32, u32))n->f0c)
                    ((u8 *)n + 0x20, n->f08, n->f10, n->f14);
                any = 1;
            }
            n = (struct Node *)func_0206062C(a, n);
        }
        func_020605B4(o->list, a);
    }

    func_020611D4((struct NNSiFndHeapHead *)o->f00, k);
    if (any != 0) func_02074A34();
    func_02061184((struct H *)o->f00, o->f0c);
    func_020749F8((struct Table *)o);
}
